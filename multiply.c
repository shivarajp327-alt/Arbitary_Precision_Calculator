#include "dll.h"

void multiply_operation(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR)
{
    Dlist *re1_head = NULL;
    Dlist *re1_tail = NULL;
    Dlist *re2_head = NULL;
    Dlist *re2_tail = NULL;
    Dlist *temp2 = tail2;
    for(int count=0;temp2 != NULL;count++)
    {
        int carry = 0;
        Dlist *temp1 = tail1;
        for(int i=0;i<count ;i++)
        {
            insert_first(&re2_head,&re2_tail,0);
        }
        if(count == 0)
        {
            while(temp1 != NULL)
            {
                int data = (temp1->data * temp2->data) + carry;
                temp1 = temp1->next;
                carry = data/10;
                insert_first(&re1_head,&re1_tail,data%10);
            }
        }
        else
        {
            while(temp1 != NULL)
            {
                int data = (temp1->data * temp2->data) + carry;
                temp1 = temp1->next;
                carry = data/10;
                insert_first(&re2_head,&re2_tail,data%10);
            }
        }
        if(count == 0)
            insert_first(&re1_head,&re1_tail,carry);
        else
            insert_first(&re2_head,&re2_tail,carry);

        if(re1_head != NULL && re2_head != NULL)
        {
            add_operation(re1_head,re1_tail,re2_head,re2_tail,headR,tailR);
            delete_list(&re1_head,&re1_tail);
            delete_list(&re2_head,&re1_tail);
            re1_head = *headR;
            re1_tail = *tailR;
            headR = NULL;
            tailR = NULL;
        }
        temp2 = temp2->prev;
    }
    display_result(head1,tail1,head2,tail2,re1_head,re1_tail,'x');
}