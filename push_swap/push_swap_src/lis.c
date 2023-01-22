#include "push_swap.h"

int *list_data_copy(t_list *a, int size)
{
    int *data;
    int i;

    data = (int *)malloc(sizeof(int) * size);
    if (!data)
        exit(-1);
    while (a != NULL)
    {
        data[i++] = a->content;
        a = a->next;
    }
    return (data);
}

int *return_lis(int *data, int *step, int size, int max)
{
    int *lis;

    lis = (int *)malloc(sizeof(int) * max);
    if (!lis)
        exit(-1);
    
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
    }
     
}
