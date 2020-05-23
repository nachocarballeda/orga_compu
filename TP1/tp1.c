#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void split();
void printArray(int A[], int size);
void merge_sort(int *vec, size_t len);

int main()
{
    // char input[4096];                 // 4 KB
    // ssize_t a = read(0, input, 4096); // 4 KB buffer

    // // Remove spaces
    // int i, x;
    // for (i = x = 0; input[i]; ++i)
    //     if (input[i] != ' ' || (i > 0 && (input[i - 1] != ' ' && input[i - 1] != '\n')))
    //         input[x++] = input[i];
    // input[x] = '\0';

    // int vector[2048]; // 2 KB
    // i = 0;
    // int j = 0;
    // char *number = strtok(input, " \n");
    // while (number != NULL)
    // {
    //     printf("%s", number);
    //     // char *newLine = strstr(number, '\n');
    //     // if (newLine)
    //     //     vector[i] = number;
    //     // if (number[0] == '\n')
    //     // {
    //     //     printf("NUEVA LINEA");
    //     //     number++;
    //     //     merge_sort(vector, i);
    //     //     printf("ORDENADO: ");
    //     //     printArray(vector, i);
    //     //     vector[0] = (int)strtol(number, (char **)NULL, 10);
    //     //     i = 1;
    //     // }
    //     // else
    //     // {
    //     //     // printf("SIZE: %ld\n", strlen(number));
    //     //     // if (number[strlen(number) - 1] == '\0')
    //     //     // {
    //     //     //     number[strlen(number) - 1] = '\0';
    //     //     //     vector[i] = (int)strtol(number, (char **)NULL, 10);
    //     //     //     merge_sort(vector, i+1);
    //     //     //     printf("ORDENADO: ");
    //     //     //     printArray(vector, i+1);
    //     //     // }
    //     //     vector[i] = (int)strtol(number, (char **)NULL, 10);
    //     //     i++;
    //     // }
    //     // printArray(vector, i);
    //     number = strtok(NULL, " \n");
    // }

    int vec[] = {12, 11, 13, 5, -7, 6, 7, 9, 24, 342, 5, 5, 6, 7, 8, 8, -2, -1512, -6, 34, 3, 4, 5, 7};
    merge_sort(vec, sizeof(vec) / sizeof(vec[0]));
    printArray(vec, sizeof(vec) / sizeof(vec[0]));
    return 0;
}

void split()
{
}

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

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
