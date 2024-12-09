#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node
{
    int data;
    struct node *next;
};

// Queue structure
struct queue
{
    struct node *front;
    struct node *rear;
};

// Function prototypes
void create_queue(struct queue **q);
struct queue *insert(struct queue *q, int val);
struct queue *delete_element(struct queue *q);
struct queue *display(struct queue *q);
int peek(struct queue *q);

int main()
{
    struct queue *q = NULL;
    int val, option;

    create_queue(&q);

    do
    {
        printf("\n*****MAIN MENU*****");
        printf("\n 1. INSERT");
        printf("\n 2. DELETE");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nEnter the number to insert in the queue: ");
            scanf("%d", &val);
            q = insert(q, val);
            break;
        case 2:
            q = delete_element(q);
            break;
        case 3:
            val = peek(q);
            if (val != -1)
                printf("\nThe value at the front of the queue is: %d", val);
            break;
        case 4:
            q = display(q);
            break;
        case 5:
            printf("\nExiting...");
            break;
        default:
            printf("\nInvalid option! Please try again.");
        }
    } while (option != 5);

    return 0;
}

// Function to initialize the queue
void create_queue(struct queue **q)
{
    *q = (struct queue *)malloc(sizeof(struct queue));
    (*q)->front = NULL;
    (*q)->rear = NULL;
}

// Function to insert an element into the queue
struct queue *insert(struct queue *q, int val)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nMemory allocation failed!");
        return q;
    }
    ptr->data = val;
    ptr->next = NULL;

    if (q->front == NULL)
    {
        q->front = ptr;
        q->rear = ptr;
    }
    else
    {
        q->rear->next = ptr;
        q->rear = ptr;
    }
    return q;
}

// Function to display the elements of the queue
struct queue *display(struct queue *q)
{
    struct node *ptr = q->front;

    if (ptr == NULL)
    {
        printf("\nQUEUE IS EMPTY");
    }
    else
    {
        printf("\nQueue elements: ");
        while (ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
    return q;
}

// Function to delete an element from the queue
struct queue *delete_element(struct queue *q)
{
    if (q->front == NULL)
    {
        printf("\nUNDERFLOW - Queue is empty.");
        return q;
    }

    struct node *ptr = q->front;
    q->front = q->front->next;

    printf("\nThe value being deleted is: %d", ptr->data);
    free(ptr);

    if (q->front == NULL)
        q->rear = NULL;

    return q;
}

// Function to get the front element of the queue
int peek(struct queue *q)
{
    if (q->front == NULL)
    {
        printf("\nQUEUE IS EMPTY");
        return -1;
    }
    else
    {
        return q->front->data;
    }
}
