#ifndef DLL_H
#define DLL_L

#include<stdio.h>
#include<stdlib.h>

#define FAILURE -1
#define SUCCESS 0

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}Dlist;

int node_creation(Dlist **head,Dlist **tail,char *str);
int insert_last(Dlist **head,Dlist **tail,int data);
void print_list(Dlist *head,Dlist *tail);

#endif