/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int data;
    struct node* next;
};

struct node* Sirala(struct node* head) {
    int i;
    int n = 100; 

    int* p = (int*)malloc(n * sizeof(int));
    struct node* current = head;

    // Diziye rastgele sayýlar ekler
    for (i = 0; i < n; i++) {
        p[i] = (rand() % 1000) + 1;
    }

    // Diziyi büyükten küçüðe sýralar(Bubble sort metodunu  kullandým)
    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j] < p[j + 1]) {
                int temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Sýralanmýþ diziyi baðlý listede saklar
    for (i = 0; i < n; i++) {
        current->data = p[i];
        if (i < n - 1) {
            current->next = (struct node*)malloc(sizeof(struct node));
            current = current->next;
        }
    }

    current->next = NULL;

    return head;
}

int main() {
    srand(time(NULL));
    struct node* head = (struct node*)malloc(sizeof(struct node));

    head = Sirala(head);

    struct node* current = head;
    printf("Siralanmis dizi:\n");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}
