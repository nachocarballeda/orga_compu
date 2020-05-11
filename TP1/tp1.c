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
    char input[4096];                 // 4 KB
    ssize_t a = read(0, input, 4096); // 4 KB buffer

    // Remove spaces
    int i, x;
    for (i = x = 0; input[i]; ++i)
        if (input[i] != ' ' || (i > 0 && (input[i - 1] != ' ' && input[i - 1] != '\n')))
            input[x++] = input[i];
    input[x] = '\0';

    int vector[2048]; // 2 KB
    i = 0;
    int j = 0;
    char *number = strtok(input, " \n");
    while (number != NULL)
    {
        printf("%s", number);
        // char *newLine = strstr(number, '\n');
        // if (newLine)
        //     vector[i] = number;
        // if (number[0] == '\n')
        // {
        //     printf("NUEVA LINEA");
        //     number++;
        //     merge_sort(vector, i);
        //     printf("ORDENADO: ");
        //     printArray(vector, i);
        //     vector[0] = (int)strtol(number, (char **)NULL, 10);
        //     i = 1;
        // }
        // else
        // {
        //     // printf("SIZE: %ld\n", strlen(number));
        //     // if (number[strlen(number) - 1] == '\0')
        //     // {
        //     //     number[strlen(number) - 1] = '\0';
        //     //     vector[i] = (int)strtol(number, (char **)NULL, 10);
        //     //     merge_sort(vector, i+1);
        //     //     printf("ORDENADO: ");
        //     //     printArray(vector, i+1);
        //     // }
        //     vector[i] = (int)strtol(number, (char **)NULL, 10);
        //     i++;
        // }
        // printArray(vector, i);
        number = strtok(NULL, " \n");
    }

    // int vec[] = {12, 11, 13, 5, -7, 6, 7, 9, 24, 342, 5, 5, 6, 7, 8, 8, -2, -1512, -6, 34, 3, 4, 5, 7};
    // merge_sort(vec, 24);
    // printArray(vec, 24);
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
        merge_sort(vec, mid);
        merge_sort(vec + mid, len - mid);
        if (vec[mid - 1] > vec[mid])
        {
            int start = 0;
            while (start < mid && mid < len)
            {
                if (vec[mid] < vec[start])
                {
                    int value = vec[mid];
                    int index = mid;
                    while (index != start)
                    {
                        vec[index] = vec[index - 1];
                        index--;
                    }
                    vec[start] = value;
                    mid++;
                }
                start++;
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
