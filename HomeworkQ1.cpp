#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertNode(struct Node **head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else if (value % 2 != 0) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int main() {
    int value;
    struct Node* head = NULL;

    printf("Verileri listeye eklemek için sayýlarý girin (çýkmak için -1 girin): ");

    while (1) {
        scanf("%d", &value);
        if (value == -1)
            break;
        insertNode(&head, value);
    }

    struct Node* current = head;
    printf("Baslangic: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("Liste sonu\n");

    // Belleði temizle
    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

