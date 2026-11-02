#include "dll.h"

void divide_operation(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR)
{
    Dlist *head3 = NULL;
    Dlist *tail3 = NULL;
    Dlist *re_head = NULL;
    Dlist *re_tail = NULL;
    Dlist *temp1 = head1;

    while(temp1 != NULL)
    {
        int ret,count = 0;
        Dlist *temp2 = head2;

        insert_last(&head3,&tail3,temp1->data);
        temp1 = temp1->next;
        remove_zero(&head3);

        while((ret = compare_lists(head3,tail3,temp2,tail2)) == NO_SWAP)
        {
            sub_operation(head3,tail3,temp2,tail2,&re_head,&re_tail);
            count++; 
            delete_list(&head3,&tail3);
            
            head3 = re_head;
            tail3 = re_tail;
            re_head = NULL;
            re_tail = NULL;
            remove_zero(&head3);
        }
        insert_last(headR,tailR,count);
    }
}