#include "push_swap.h"

int find_distance(int index, int size)
{
    if (index > size / 2)
        index -= size;
    return (index);
}

int find_sector(t_list *a, int a_size, int content)
{
    const t_list *last = ft_lstlast(a);
    int i;

    //최댓값 최솟값 찾기
    if (content < a->content && content > last->content)
        return (0);
    i = 0;
    while (!(content > a->content && content < (a->next)->content))
    {
        a = a->next;
        i++;
    }
    return (find_distance(i, a_size));    
}