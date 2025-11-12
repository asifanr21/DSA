#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node* createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(0);
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void createList() {
    int n, data;
    printf("Enter number of nodes to create: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        struct node *newNode = createNode(data);

        if (head == NULL) {
            head = newNode;
        } else {
            struct node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

void insertAtB(int data) {
    struct node *newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

void delete_begin() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void delete_end() {
    struct node *temp, *prev = NULL;

    if (head == NULL) {
        printf("empty\n");
        return;
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    } else {
        temp = head;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = NULL;
        free(temp);
    }
}

void delete_pos(int pos) {
    struct node *temp, *prev;
    int i;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos == 1) {
        temp = head;
        head = head->next;
        free(temp);
        return;
    }

    temp = head;
    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void display() {
    struct node *temp = head;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, data, pos;

    while (1) {
        printf("1. Create Linked List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Display List\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete at Position\n");
        printf("6. Delete from End\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createList();
                break;
            case 2:
                printf("Enter at beginning: ");
                scanf("%d", &data);
                insertAtB(data);
                break;
            case 3:
                display();
                break;
            case 4:
                delete_begin();
                break;
            case 5:
                printf("Enter the position : ");
                scanf("%d", &pos);
                delete_pos(pos);
                break;
            case 6:
                delete_end();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid Choice\n");
        }
    }
}
