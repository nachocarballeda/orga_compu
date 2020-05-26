#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *vec, size_t len)
{
    if (len > 1)
    {
        int mid = len / 2;
        int *left = (int *)malloc(mid * sizeof(int));
        int *right = (int *)malloc((len - mid) * sizeof(int));
        for (int i = 0; i < mid; i++)
            left[i] = vec[i];
        for (int i = mid; i < len; i++)
            right[i - mid] = vec[i];
        merge_sort(left, mid);
        merge_sort(right, len - mid);
        int i, j, k;
        i = 0;
        j = 0;
        k = 0;
        while (i < mid && j < len - mid)
        {
            if (left[i] < right[j])
                vec[k++] = left[i++];
            else
                vec[k++] = right[j++];
        }
        while (i < mid)
            vec[k++] = left[i++];
        while (j < len - mid)
            vec[k++] = right[j++];
        free(left);
        free(right);
    }
}

int main(void) {
  int vec[]={123,-124,-10,124,124,5,54,6,7,8,90,98,54,2123};
  merge_sort(vec, sizeof(vec)/sizeof(int));
  return 0;
}
