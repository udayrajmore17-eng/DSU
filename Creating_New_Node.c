#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
struct Node *head = NULL;
void insert_beg(void);
void insert_end(void);
void display(void);
int main(void)
{
    int a;
    while (1)
    {
        printf("\n\n1. Insert at beginning");
        printf("\n2. Insert at ending");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &a);
        switch (a)
        {
            case 1:
                insert_beg();
                break;

            case 2:
                insert_end();
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice!");
        }
    }
    return 0;
}
void insert_beg(void)
{
    struct Node *newnode;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        printf("\nMemory allocation failed!");
        return;
    }
    printf("\nEnter data: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
    printf("\nNode inserted at beginning.");
}
void insert_end(void)
{
    struct Node *newnode;
    struct Node *temp;
    newnode = (struct Node *)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        printf("\nMemory allocation failed!");
        return;
    }
    printf("\nEnter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newnode;
    }
    printf("\nNode inserted at ending.");
}
void display(void)
{
    struct Node *temp;
    if (head == NULL)
    {
        printf("\nLinked list is empty.");
        return;
    }
    temp = head;
    printf("\nLinked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}