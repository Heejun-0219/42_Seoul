#include "push_swap.h"

#include <stdio.h>

int *list_data_copy(t_list *a, int size)
{
    int *data;
    int i;

    data = (int *)malloc(sizeof(int) * size);
    if (!data)
        exit(-1);
    i = 0;
    while (a != NULL)
    {
        data[i++] = a->content;
        a = a->next;
    }
    return (data);
}



int *count_lis(int *data, int size, int *max)
{
    int *step;
    int i;
    int j;

    step = (int *)malloc(sizeof(int) * size);
    if (!step)
        exit(-1); // 리스트 프리
    i = 0;
    while (i < size)
    {
        step[i] = 1;
        i++;
    }
    i = 1;
    while (i < size)
    {
        j = 0;
        while (j < i)
        {
            if(data[i] > data[j] && step[i] < step[j] + 1)
                step[i] = step[j] + 1;
            j++;
        }
        i++;
    }
    i = 0;
    while (i < size)
        if (*max < step[i++])
            *max = step[i - 1];
    printf("LIS: ");
    i = size - 1;
    while (i >= 0) {
        if (step[i] == *max) {
            printf("%d ", data[i]);
            (*max)--;
        }
        i--;
    }
    printf("\n");
    return 0;
}
