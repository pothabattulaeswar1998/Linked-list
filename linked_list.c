#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void add(struct node **head, int data)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->next = *head;
    *head = new;
}

void print(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void print_address(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL){
        printf("%d\t %p\t %p\n",temp->data,&(temp->data),temp->next);
        temp = temp->next;
    }
}

void reverse(struct node **head)
{
    struct node *cur = *head;
    struct node *prev = NULL,*next = NULL;
    while(cur !=NULL){
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}

void last(struct node **head)
{
    struct node *new,*temp;
    new = (struct node *)malloc(sizeof(struct node));
    int data;
    if(new == NULL)
    {
        printf("Not inserted\n");
    }
    else
    {
        printf("\nEnter the last element to insert:");
        scanf("%d",&data);
        new->data = data;
        temp = *head;
        if(temp == NULL){
                new->data = data;
                *head = NULL;
                printf("Element has inserted in the last\n");
                        }
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = NULL;
        }
}

void random_insert(struct node **head)
{
    struct node *new,*temp;
    new = (struct node*)malloc(sizeof(struct node));
    int data,i,loc;
    if(new == NULL){
        printf("Node not inserted\n");
    }
    else
    {
    printf("\nenter the element to insert:");
    scanf("%d",&data);
    new->data = data;
    printf("\nEnter the position to insert the element:");
    scanf("%d",&loc);
    temp = *head;
    for(i=1; i<loc-1; i++)
    {
        temp = temp->next;
        if(temp == NULL){
            printf("Not able to insert the element the entered position not in range\n");
            return;
        }
    }
    new->next = temp->next;
    temp->next = new;
    printf("\nElement has inserted in the entered position\n");
}
}

int main()
{
    struct node *head = NULL;
    int data,n,i,s;
    printf("Enter the size of linked list:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter %d value:",i+1);
        scanf("%d",&data);
        add(&head, data);
    }
    printf("\nForward linked list\n");
    print(head);
    reverse(&head);
    printf("\nReverse linked list\n");
    print(head);
    last(&head);
    printf("\nElement has inserted in the last\n"); 
    print(head);
    printf("\nEnter the element to insert in the begining:");
    scanf("%d",&s);
    add(&head,s);
    printf("\nElement has inserted in the Begining\n");
    print(head);
    random_insert(&head);
    print(head);
    printf("\nAddress of single linked list \n");
    print_address(head);

    printf("Linked list program");

    return 0;
}

