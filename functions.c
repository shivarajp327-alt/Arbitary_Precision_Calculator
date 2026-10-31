#include "dll.h"

void calculator(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,char oper)
{
    Dlist *headR = NULL;
    Dlist *tailR = NULL;
    int ret;
    switch (oper)
    {
        case '+':
            add_operation(head1,tail1,head2,tail2,&headR,&tailR);
            display_result(head1,tail1,head2,tail2,headR,tailR,oper);
            break;

        case '-':
           // sub_operation(head1,tail1,head2,tail2,&headR,&tailR);
        default:
        printf("Invalid operator\n");
    }
    
}

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
int insert_first(Dlist **head,Dlist **tail,int data)
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
        newnode->next = *head;
        (*head)->prev = newnode;
        *head = newnode;
    return SUCCESS; 
}
void display_result(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist *headR,Dlist *tailR,char oper)
{
    print_list(head1,tail1);
    printf("\n");
    printf("%c \n",oper);
    print_list(head2,tail2);
    printf("\n");
    printf("= \n");
    print_list(headR,tailR);
    printf("\n");
}
