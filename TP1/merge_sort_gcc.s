merge_sort:
        .frame  $fp,48,$31              # vars= 16, regs= 2/0, args= 16, gp= 8
        .mask   0xc0000000,-4
        .fmask  0x00000000,0
        .set    noreorder
        .cpload $25
        .set    nomacro
        addiu   $sp,$sp,-48
        sw      $31,44($sp)
        sw      $fp,40($sp)
        move    $fp,$sp
        .cprestore      16
        sw      $4,48($fp)
        sw      $5,52($fp)
        lw      $2,52($fp)
        sltu    $2,$2,2
        bne     $2,$0,$L17
        nop

        lw      $2,52($fp)
        srl     $2,$2,1
        sw      $2,24($fp)
        lw      $2,24($fp)
        move    $5,$2
        lw      $4,48($fp)
        lw      $2,%got(merge_sort)($28)
        move    $25,$2
        .reloc  1f,R_MIPS_JALR,merge_sort
1:      jalr    $25
        nop

        lw      $28,16($fp)
        lw      $2,24($fp)
        sll     $2,$2,2
        lw      $3,48($fp)
        addu    $4,$3,$2
        lw      $2,24($fp)
        lw      $3,52($fp)
        subu    $2,$3,$2
        move    $5,$2
        lw      $2,%got(merge_sort)($28)
        move    $25,$2
        .reloc  1f,R_MIPS_JALR,merge_sort
1:      jalr    $25
        nop

        lw      $28,16($fp)
        lw      $3,24($fp)
        li      $2,1073676288                   # 0x3fff0000
        ori     $2,$2,0xffff
        addu    $2,$3,$2
        sll     $2,$2,2
        lw      $3,48($fp)
        addu    $2,$3,$2
        lw      $3,0($2)
        lw      $2,24($fp)
        sll     $2,$2,2
        lw      $4,48($fp)
        addu    $2,$4,$2
        lw      $2,0($2)
        slt     $2,$2,$3
        beq     $2,$0,$L17
        nop

        sw      $0,28($fp)
        b       $L12
        nop

$L16:
        lw      $2,24($fp)
        sll     $2,$2,2
        lw      $3,48($fp)
        addu    $2,$3,$2
        lw      $3,0($2)
        lw      $2,28($fp)
        sll     $2,$2,2
        lw      $4,48($fp)
        addu    $2,$4,$2
        lw      $2,0($2)
        slt     $2,$3,$2
        beq     $2,$0,$L13
        nop

        lw      $2,24($fp)
        sll     $2,$2,2
        lw      $3,48($fp)
        addu    $2,$3,$2
        lw      $2,0($2)
        sw      $2,36($fp)
        lw      $2,24($fp)
        sw      $2,32($fp)
        b       $L14
        nop

$L15:
        lw      $2,32($fp)
        sll     $2,$2,2
        lw      $3,48($fp)
        addu    $2,$3,$2
        lw      $4,32($fp)
        li      $3,1073676288                   # 0x3fff0000
        ori     $3,$3,0xffff
        addu    $3,$4,$3
        sll     $3,$3,2
        lw      $4,48($fp)
        addu    $3,$4,$3
        lw      $3,0($3)
        sw      $3,0($2)
        lw      $2,32($fp)
        addiu   $2,$2,-1
        sw      $2,32($fp)
$L14:
        lw      $3,32($fp)
        lw      $2,28($fp)
        bne     $3,$2,$L15
        nop

        lw      $2,28($fp)
        sll     $2,$2,2
        lw      $3,48($fp)
        addu    $2,$3,$2
        lw      $3,36($fp)
        sw      $3,0($2)
        lw      $2,24($fp)
        addiu   $2,$2,1
        sw      $2,24($fp)
$L13:
        lw      $2,28($fp)
        addiu   $2,$2,1
        sw      $2,28($fp)
$L12:
        lw      $3,28($fp)
        lw      $2,24($fp)
        slt     $2,$3,$2
        beq     $2,$0,$L17
        nop

        lw      $3,24($fp)
        lw      $2,52($fp)
        sltu    $2,$3,$2
        bne     $2,$0,$L16
        nop

$L17:
        nop
        move    $sp,$fp
        lw      $31,44($sp)
        lw      $fp,40($sp)
        addiu   $sp,$sp,48
        jr      $31
        nop

        .set    macro
        .set    reorder
        .end    merge_sort
        .size   merge_sort, .-merge_sort
        .rdata
        .align  2
$LC2:
        .ascii  "%d \000"
        .text
        .align  2
        .globl  printArray
        .set    nomips16
        .set    nomicromips
        .ent    printArray
        .type   printArray, @function
