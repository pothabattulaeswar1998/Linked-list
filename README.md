# Linked-list
linked list program
/*************** Eswar_218*************/

/********* Linked list program for 11 16 18 41 44 ************/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
        int data;
        struct Node *next;
};

int main()

{
        struct Node *head = (struct Node*)malloc(sizeof(struct Node));
        struct Node *num = (struct Node*)malloc(sizeof(struct Node));
        struct Node *num1 = (struct Node*)malloc(sizeof(struct Node));
        struct Node *num2 = (struct Node*)malloc(sizeof(struct Node));
        struct Node *num3 = (struct Node*)malloc(sizeof(struct Node));

        head->data = 11;
        num->data = 16;
        num1->data = 18;
        num2->data = 41;
        num3->data = 44;

        head->next = num;
        num->next = num1;
        num1->next = num2;
        num2->next = num3;
        num3->next = NULL;

        struct Node *temp = head;

        while(temp != NULL)
        {
                printf("The linked values are = %d\n",temp->data);

                temp = temp->next;
        }

        return 0;
}
