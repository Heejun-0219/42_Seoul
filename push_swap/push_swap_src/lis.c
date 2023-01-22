#include "push_swap.h"

int *return_lis(t_list *a, int *step, int size, int max)
{

}

int *count_lis(t_list *a, int size, int *max)
{
    int *step;
    int i;
    int j;
    t_list *tmp;
    t_list *start;

    step = (int *)malloc(sizeof(int) * size);
    if (!step)
        exit(-1);
    i = 0;
    while (i < size)
        step[i++] = 1;
    i = 0;
    start = a;
    while (i < size)
    {
        j = i;
        tmp = a;
        while (j < size)
        {
            if (a->content < tmp->content && step[i] == step[j])
            {
                step[j]++;
                if (step[j] > *max)
                    *max = step[j];
            }
            tmp = tmp->next;
            j++;
        }
        a = a->next;
        i++;
    }
    a = start;
    return (return_lis(a, step, size, *max));   
}
