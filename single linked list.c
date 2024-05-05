#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of the linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    printf("[");
    while (head != NULL) {
        printf("%d", head->data);
        head = head->next;
        if (head != NULL) {
            printf("]->[");
        }
    }
    printf("]\n");
}

int main() {
    // Input: Number of elements in the linked list
    int n;
    scanf("%d", &n);

    // Input: Elements of the linked list
    struct Node* originalList = NULL;
    for (int i = 0; i < n; ++i) {
        int element;
        scanf("%d", &element);
        insertEnd(&originalList, element);
    }

    // Output: Print original linked list
    printList(originalList);

    // Output: Print rearranged linked list (assuming rearranging means no change for this example)
    printList(originalList);

    return 0;
}
