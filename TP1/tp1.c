#include <stdio.h>

void printArray(int A[], int size);
void merge_sort(int *vec, size_t len);

int main(int argc)
{
    int vec[] = {12, 11, 13, 5, 6, 7, 9, 24, 342, 5, 5, 6, 7, 8, 8, -2, -1512, -6, 34, 3, 4, 5, 7};
    merge_sort(vec, 23);
    printArray(vec, 23);
    return 0;
}

void merge_sort(int *vec, size_t len)
{
    if (len > 1)
    {
        int mid = len / 2;
        merge_sort(vec, mid);
        merge_sort(vec + mid, len - mid);
        if (vec[mid - 1] > vec[mid])
        {
            int start = 0;
            while (start < mid && mid < len)
            {
                if (vec[start] <= vec[mid])
                    start++;
                else
                {
                    int value = vec[mid];
                    int index = mid;
                    while (index != start)
                    {
                        vec[index] = vec[index - 1];
                        index--;
                    }
                    vec[start] = value;
                    start++;
                    mid++;
                }
            }
        }
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
