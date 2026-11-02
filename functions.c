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
            if((ret = compare_lists(head1,tail1,head2,tail2)) == NO_SWAP)
            {
                sub_operation(head1,tail1,head2,tail2,&headR,&tailR);
            }
            else if((ret = compare_lists(head1,tail1,head2,tail2)) == SWAP)
            {
                sub_operation(head2,tail2,head1,tail1,&headR,&tailR);
                insert_first(&headR,&tailR,'-');
            }
            display_result(head1,tail1,head2,tail2,headR,tailR,oper);
        break;

        case 'x':
        case 'X':
            multiply_operation(head1,tail1,head2,tail2,&headR,&tailR);

        break;

        // case '/':
        //     divide_operation(head1,tail1,head2,tail2,&headR,&tailR);
        //     display_result(head1,tail1,head2,tail2,headR,tailR,oper);
        // break;

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

int delete_list(Dlist **head,Dlist **tail)
{
    if(*head == NULL)
        return FAILURE;
        
    while(*head != NULL)
    {
        Dlist *temp = *head;
        (*head)->prev = NULL;
        *head = (*head)->next;
        free(temp);
    }
    *head = NULL;
    *tail = NULL;
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

void get_list_len(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,int *list1_count,int *list2_count)
{
    while(head1 != NULL)
    {
        (*list1_count)++;
        head1 = head1->next;
    }
     while(head2 != NULL)
    {
        (*list2_count)++;
        head2 = head2->next;
    }
}
int compare_lists(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2)
{
    int list1_len =0,list2_len =0;
    get_list_len(head1,tail1,head2,tail2,&list1_len,&list2_len);
    if(list1_len < list2_len)
        return SWAP;
    else if(list1_len > list2_len)
        return NO_SWAP;
    else if(list1_len == list2_len)
    {
        while(head1->data == head2->data)
        {
            head1 = head1->next;
            head2 = head2->next;
            if(head1 == NULL && head2 == NULL)
                return NO_SWAP;
        }
       if(head1->data < head2->data)
            return SWAP;
        else if(head1->data > head2->data)
            return NO_SWAP;
    }
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
void remove_zero(Dlist **head,Dlist **tail)
{
    while((*head)->data == 0)
    {
        Dlist *temp = *head;
        *head=(*head)->next;
        (*head)->prev=NULL;
        free(temp);
    }
}