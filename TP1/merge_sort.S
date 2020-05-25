#include <regdef.h>
#include <syscall.h>
    .text
    .ent merge_sort
    .globl merge_sort
merge_sort:
    .frame      fp, 40, ra
    subu        sp, sp, 40
    .cprestore  24
    sw          gp, 24(sp)
    sw          fp, 28(sp)
    sw          ra, 32(sp)
    move        fp, sp
    # 40 = &vec
    # 44 = len
    # 16 = &right
    # 20 = &left
    sw          a0, 40(fp)          # 40 = &vec
    sw          a1, 44(fp)          # 44 = len

    lw          t0, 44(fp)          # t0 = len
    bleu        t0, 1, fin          # if (len <= 1) => fin

    srl         t1, t0, 1           # t1 = mid = len / 2

create_left_righ:
    mul         a0, t1, 4           # a0 = mid * sizeof(int)
    jal         mymalloc
    sw          v0, 20(fp)          # 20 = left
    lw          t0, 44(fp)          # t0 = len
    srl         t1, t0, 1           # t1 = mid = len / 2
    subu        t1, t0, t1          # t1 = len - mid
    mul         a0, t1, 4           # a0 = (len -  mid) * sizeof(int)
    jal         mymalloc
    sw          v0, 16(fp)          # 16 = right

    move        t0, zero            # t0 = i
    lw          t1, 44(fp)          # t1 = len
    srl         t1, t1, 1           # t1 = mid = len / 2
    lw          t2, 40(fp)          # t2 = &vec
    lw          t3, 20(fp)          # t3 = &left

for_1:
    bgeu        t0, t1, prep_for_2  # if i >= mid => exit
    mul         t4, t0, 4           # t4 = i * 4
    addu        t5, t3, t4          # t5 = &left[i]
    addu        t6, t2, t4          # t6 = &vec[i]
    lw          t6, 0(t6)           # t6 = vec[i]
    sw          t6, 0(t5)           # left[i] = t6 = vec[i]
    addiu       t0, t0, 1           # i++
    b           for_1

prep_for_2:
    lw          t0, 44(fp)          # t0 = len
    move        t3, t1              # t3 = i = mid
    lw          t4, 16(fp)          # t4 = &right

for_2:
    bgeu        t3, t0, recursion   # if i >= len => exit
    subu        t5, t3, t1          # t5 = i - mid
    mul         t5, t5, 4           # t5 = t5 * 4 = (i - mid) * 4
    addu        t5, t4, t5          # t5 = &right[i - mid]
    mul         t6, t3, 4           # t6 = i * 4
    addu        t6, t2, t6          # t6 = &vec[i]
    
    lw          t7, 0(t6)           # t7 = vec[i]
    sw          t7, 0(t5)           # right[i] = t7 = vec[i]
    addiu       t3, t3, 1           # i++
    b           for_2

recursion:
    lw          a0, 20(fp)          # a0 = &left
    lw          a1, 44(fp)          # a1 = mid
    srl         a1, a1, 1           # a1 = mid = len / 2
    jal         merge_sort

    lw          a0, 16(fp)          # a0 = &right
    lw          a1, 44(fp)          # a1 = mid
    srl         a1, a1, 1           # a1 = mid = len / 2
    lw          t1, 44(fp)          # t1 = len
    subu        a1, t1, a1          # a1 = len - mid
    jal         merge_sort

merge:
    lw          t0, 40(fp)          # t0 = &vec
    lw          t1, 20(fp)          # t1 = &left
    lw          t2, 16(fp)          # t2 = &right
    lw          t3, 44(fp)          # t3 = len
    srl         t4, t3, 1           # t4 = mid
    move        t5, zero            # t5 = i = 0
    move        t6, zero            # t6 = j = 0
    move        t7, zero            # t7 = k = 0

while_1:
    bgeu        t5, t4, while_2     # if i >= mid => while_2
    subu        t8, t3, t4          # t8 = len - mid
    bgeu        t6, t8, while_2     # if j >= len - mid => while_2
    mul         t8, t5, 4           # t8 = i * 4
    addu        t8, t1, t8          # t8 = &left[i]
    lw          t8, 0(t8)           # t8 = left[i]
    mul         t9, t6, 4           # t9 = j * 4
    addu        t9, t2, t9          # t9 = &right[j]
    lw          t9, 0(t9)           # t9 = right[j]
    bge         t8, t9, else        # if left[i] >= right[j] => else
if:
    mul         t9, t7, 4           # t9 = k * 4
    addu        t9, t0, t9          # t9 = &vec[k]
    sw          t8, 0(t9)           # vec[k] = left[i]
    addu        t5, t5, 1           # i++
    b           kpp
else:
    mul         t8, t7, 4           # t8 = k * 4
    addu        t8, t0, t8          # t8 = &vec[k]
    sw          t9, 0(t8)           # vec[k] = right[j]
    addu        t6, t6, 1           # j++
    b           kpp
kpp:
    addu        t7, t7, 1           # k++
    b           while_1

while_2:
    bgeu        t5, t4, start_while_3 # if i >= mid => start_while_3
    mul         t8, t5, 4           # t8 = i * 4
    addu        t8, t1, t8          # t8 = &left[i]
    lw          t8, 0(t8)           # t8 = left[i]
    mul         t9, t7, 4           # t9 = k * 4
    addu        t9, t0, t9          # t9 = &vec[k]
    sw          t8, 0(t9)           # vec[k] = left[i]
    addu        t7, t7, 1           # k++
    addu        t5, t5, 1           # i++
    b           while_2

start_while_3:
    subu        t5, t3, t4          # t5 = len - mid

while_3:
    bgeu        t6, t5, free        # if j >= len - mid => free
    mul         t8, t6, 4           # t8 = j * 4
    addu        t8, t2, t8          # t8 = &right[j]
    lw          t8, 0(t8)           # t8 = right[j]
    mul         t9, t7, 4           # t9 = k * 4
    addu        t9, t0, t9          # t9 = &vec[k]
    sw          t8, 0(t9)           # vec[k] = right[j]
    addu        t7, t7, 1           # k++
    addu        t6, t6, 1           # j++
    b           while_3

free:
    move        a0, t1              # a0 = &left
    jal         myfree              # myfree(&left)

    lw          a0, 16(fp)          # a0 = &right
    jal         myfree              # myfree(&right)

fin:
    lw          gp, 24(sp)
    lw          fp, 28(sp)
    lw          ra, 32(sp)
    addu        sp, sp, 40
    jr          ra
    .end        merge_sort
