#include "graph.h"

qnode *create_new_queue_node(pnode d, int p)
{
    qnode *temp = (qnode *)malloc(sizeof(qnode));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;
    return temp;
}

int is_empty(qnode **head)
{
    return (*head) == NULL;
}

pnode pop(qnode **head)
{
    pnode temp = (*head)->data;
    qnode *t = *head;
    (*head) = (*head)->next;
    free(t);
    return temp;
}

void push(qnode **head, pnode d, int p)
{
    qnode *start = (*head);
    qnode *temp = create_new_queue_node(d, p);
    if (is_empty(head))
    {
        (*head) = temp;
        return;
    }
    if ((*head)->priority > p)
    {
        temp->next = *head;
        (*head) = temp;
    }
    else
    {
        while (start->next != NULL && start->next->priority < p)
                start = start->next;

        temp->next = start->next;
        start->next = temp;
    }
}

