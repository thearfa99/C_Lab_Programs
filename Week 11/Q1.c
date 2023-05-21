/*

Ordered Singly Linked List

Write a C program to create an ordered singly linked list (ascending order) and write functions to perform the following operations.
i) Display
ii) Sum of alternate nodes
iii) Sum of nodes with even data
iv) Sum of nodes with odd data
v) DestroyList

Use the following function prototypes:
NODE* orderedSLL(NODE* head,int ele);
void display(NODE *head);
int sumAlternate(NODE *head);//starting from first node
int sumEvenData(NODE *head);
int sumOddData(NODE *head);
NODE* freeList(NODE* head);

You may use the below client code:
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *next;
}NODE;

NODE* orderedSLL(NODE* head,int ele);
void display(NODE *head);
int sumAlternate(NODE *head);
int sumEvenData(NODE *head);
int sumOddData(NODE *head);
NODE* freeList(NODE* head);

int main()
{
	NODE *head=NULL;
	int n;
	int ele;
	int sum;
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&ele);
		head=orderedSLL(head,ele);
	}
	display(head);
	printf("\n");
	sum=sumAlternate(head);
	printf("%d\n",sum);
	sum=sumEvenData(head);
	printf("%d\n",sum);
	sum=sumOddData(head);
	printf("%d\n",sum);

	head=freeList(head);
}

Input Format:
First line: n – number of elements (n>0)
Second line: n integers separated by space

Output Format:
First line: Numbers in ordered sll separated by space
Second line: integer – representing sum of alternate nodes starting from first node
Third line: integer – representing sum of even data elements
Fourth line: integer – representing sum of odd data elements

Testcase

Input:
5
5 4 3 2 1

Output:
1 2 3 4 5 
9
6
9

*/

//Solution:
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int info;
    struct node *next;
} NODE;

NODE* orderedSLL(NODE* head, int ele);
void display(NODE* head);
int sumAlternate(NODE* head);
int sumEvenData(NODE* head);
int sumOddData(NODE* head);
NODE* freeList(NODE* head);

int main()
{
    NODE* head = NULL;
    int n;
    int ele;
    int sum;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ele);
        head = orderedSLL(head, ele);
    }
    display(head);
    printf("\n");
    sum = sumAlternate(head);
    printf("%d\n", sum);
    sum = sumEvenData(head);
    printf("%d\n", sum);
    sum = sumOddData(head);
    printf("%d\n", sum);

    head = freeList(head);
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
            current = current->next;
        
        newNode->next = current->next;
        current->next = newNode;
    }

    return head;
}

void display(NODE* head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    NODE* current = head;
    while (current != NULL)
    {
        printf("%d ", current->info);
        current = current->next;
    }
}

int sumAlternate(NODE* head)
{
    int sum = 0;
    int count = 1;
    NODE* current = head;
    
    while (current != NULL)
    {
        if (count % 2 == 1)
            sum += current->info;
        
        count++;
        current = current->next;
    }
    
    return sum;
}

int sumEvenData(NODE* head)
{
    int sum = 0;
    NODE* current = head;
    
    while (current != NULL)
    {
        if (current->info % 2 == 0)
            sum += current->info;
        
        current = current->next;
    }
    
    return sum;
}

int sumOddData(NODE* head)
{
    int sum = 0;
    NODE* current = head;
    
    while (current != NULL)
    {
        if (current->info % 2 == 1)
            sum += current->info;
        
        current = current->next;
    }
    
    return sum;
}

NODE* freeList(NODE* head)
{
    NODE* current = head;
    
    while (current != NULL)
    {
        NODE* temp = current;
        current = current->next;
        free(temp);
    }
    
    return NULL;
}