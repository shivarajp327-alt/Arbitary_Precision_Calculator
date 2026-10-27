#include "dll.h"
int node_creation(Dlist **head,Dlist **tail,char *str)
{
    for(int i=0;str[i]!=0 ;i++)
    {
        int data = str[i] - 48;
        insert_last(head,tail,data);
    }
    return SUCCESS;
}
int insert_last(Dlist **head,Dlist **tail,int data)
{
    if(*head == NULL && *tail == NULL)
    {
        Dlist *newnode = malloc(sizeof(Dlist));
        if(newnode == NULL)
        return FAILURE;
        newnode->data = data;
        newnode->prev = NULL;
        newnode->next = NULL;
        *head = newnode;
        *tail = newnode;
        return SUCCESS;
    }
    Dlist *newnode = malloc(sizeof(Dlist));
        if(newnode == NULL)
        return FAILURE;
        newnode->data = data;
        newnode->prev = NULL;
        newnode->next = NULL;
        newnode->prev = *tail;
        (*tail)->next = newnode;
        *tail = newnode;
    return SUCCESS; 
}
