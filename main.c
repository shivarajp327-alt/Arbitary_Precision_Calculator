#include "dll.h"

void print_list(Dlist *head,Dlist *tail)
{
    if(head->data == '-')
    {
        printf("%c",head->data);
        head = head->next;
    }
    while(head!=NULL)
    {
        printf(" %d",head->data);
        head = head->next;
    }
}

int main(int argc,char *argv[])
{
    if(argc != 4)
    {
        printf("Invalid no of arguments\n");
        return FAILURE;
    }
    Dlist *head1 = NULL;
    Dlist *tail1 = NULL;
    Dlist *head2 = NULL;
    Dlist *tail2 = NULL;

    if(node_creation(&head1,&tail1,argv[1]) == FAILURE)
    {
        return FAILURE;
    }
   // print_list(head1,tail1);
    if(node_creation(&head2,&tail2,argv[3]) == FAILURE)
    {
        return FAILURE;
    }
   // print_list(head2,tail2);
     calculator(head1,tail1,head2,tail2,argv[2][0]);
}