/*

Merge 2 ordered Singly Linked Lists

Write a C program to create two ordered singly linked lists (ascending order) and merge them into an ordered singly linked list.
Implement the following functions: (Any number of helper functions may be used)
NODE* orderedSLL(NODE *head,int ele);
void display(NODE *head);
NODE* merge(NODE *head1,NODE *head2,NODE *head3);
NODE* freeList(NODE *head);

Note: If the list is empty, display the message "Empty List" in display function.

You may use the below client code:
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}NODE;

NODE* orderedSLL(NODE *head,int ele);
void display(NODE *head);
NODE* merge(NODE *head1,NODE *head2,NODE *head3);
NODE* freeList(NODE *head);

int main()
{
	NODE *head1=NULL,*head2=NULL,*head3=NULL;
	int n1,n2,ele;
	
	scanf("%d",&n1);
	for(int i=0;i<n1;i++)
	{
		scanf("%d",&ele);
		head1=orderedSLL(head1,ele);
	}
	
	scanf("%d",&n2);
	for(int i=0;i<n2;i++)
	{
		scanf("%d",&ele);
		head2=orderedSLL(head2,ele);
	}
	
	display(head1);
	printf("\n");
	display(head2);
	printf("\n");
	head3=merge(head1,head2,head3);
	display(head3);
	printf("\n");
	
	head1=freeList(head1);
	head2=freeList(head2);
	head3=freeList(head3);
}

Input format:
First line: n – number of elements in list1 (n>=0)
Second line: n integers separated by space
Third line: n – number of elements in list2 (n>=0)
Fourth line: n integers separated by space

Output Format:
First line: Numbers in ordered sll1 separated by space
Second line: Numbers in ordered sll2 separated by space
Third line: Numbers in ordered sll3 separated by space

Note: If the list is empty, display the message "Empty List"

Testcase

Input:
3
2 4 6
3
5 3 1

Output:
2 4 6 
1 3 5 
1 2 3 4 5 6 

*/

//Solution:
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node* next;
} NODE;

NODE* orderedSLL(NODE* head, int ele);
void display(NODE* head);
NODE* merge(NODE* head1, NODE* head2, NODE* head3);
NODE* freeList(NODE* head);

int main()
{
    NODE* head1 = NULL;
    NODE* head2 = NULL;
    NODE* head3 = NULL;
    int n1, n2, ele;

    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &ele);
        head1 = orderedSLL(head1, ele);
    }

    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &ele);
        head2 = orderedSLL(head2, ele);
    }

    display(head1);
    printf("\n");
    display(head2);
    printf("\n");
    head3 = merge(head1, head2, head3);
    display(head3);
    printf("\n");

    head1 = freeList(head1);
    head2 = freeList(head2);
    head3 = freeList(head3);

    return 0;
}

NODE* orderedSLL(NODE* head, int ele)
{
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    newNode->info = ele;
    newNode->next = NULL;

    if (head == NULL || ele < head->info)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        NODE* current = head;
        while (current->next != NULL && current->next->info < ele)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    return head;
}

void display(NODE* head)
{
    if (head == NULL)
    {
        printf("Empty List");
        return;
    }

    NODE* current = head;
    while (current != NULL)
    {
        printf("%d ", current->info);
        current = current->next;
    }
}

NODE* merge(NODE* head1, NODE* head2, NODE* head3)
{
    NODE* current1 = head1;
    NODE* current2 = head2;

    while (current1 != NULL && current2 != NULL)
    {
        if (current1->info <= current2->info)
        {
            head3 = orderedSLL(head3, current1->info);
            current1 = current1->next;
        }
        else
        {
            head3 = orderedSLL(head3, current2->info);
            current2 = current2->next;
        }
    }

    while (current1 != NULL)
    {
        head3 = orderedSLL(head3, current1->info);
        current1 = current1->next;
    }

    while (current2 != NULL)
    {
        head3 = orderedSLL(head3, current2->info);
        current2 = current2->next;
    }

    return head3;
}

NODE* freeList(NODE* head)
{
    NODE* current = head;
    while (head != NULL)
    {
        head = head->next;
        free(current);
        current = head;
    }
    return NULL;
}