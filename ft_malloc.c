#include "cube.h"

void add_alloc(t_alloc **head, char *content)
{
    t_alloc *new = calloc(sizeof(t_alloc), 1);
    new->pointer = content;
    new->next = NULL;
    if (*head == NULL)
    {
        *head = new;
        return;
    }
    t_alloc *current = *(head);
    while (current->next)
        current = current->next;
    current->next = new;
}

void    lstclear(t_alloc *head)
{
    t_alloc *tmp;
    while (head)
    {
        free(head->pointer);
        tmp = head;
        head = head->next;
        free(tmp);
    }
}

void *ft_malloc(size_t bytes, int action)
{
    static t_alloc *head;
    if (action == ALLOC)
    {
        void *alloc;
        alloc = calloc(bytes, 1);
        if (!alloc)
            ft_malloc(0, FREE);
        add_alloc(&head, alloc);
        return (alloc);
    }
    else
    {
        lstclear(head);
        exit(errno);
    }
    return (NULL);
}

void lstaddback(t_map **head, char *content)
{

    t_map *new = ft_malloc(sizeof(t_map), ALLOC);
    new->row = content;
    new->next = NULL;
    if (*head == NULL)
    {
        *head = new;
        return;
    }
    t_map *current = *(head);
    while (current->next)
        current = current->next;
    current->next = new;
}
