#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ogrenci {
    char isim[40];
    struct ogrenci* next;
};

struct ogrenci* head = NULL;

void addStart(const char* name) {
    struct ogrenci* add = (struct ogrenci*)malloc(sizeof(struct ogrenci));
    strncpy(add->isim, name, sizeof(add->isim));
    add->next = head;
    head = add;
}

void findLongestName() {
    if (head == NULL) {
        printf("Liste bos.\n");
        return;
    }

    struct ogrenci* temp = head;
    char longestName[40];
    int maxLength = 0;

    while (temp != NULL) {
        int currentLength = strlen(temp->isim);
        if (currentLength > maxLength) {
            maxLength = currentLength;
            strncpy(longestName, temp->isim, sizeof(longestName));
        }
        temp = temp->next;
    }

    printf("En uzun isim: %s - uzunluk: %d\n", longestName, maxLength);
}

int main() {
    addStart("Ali");
    addStart("Veli");
    addStart("Ahmet");
    addStart("Mehmet");
    addStart("Ayse");
    addStart("Fatma");

    findLongestName();

    // Baðlý liste belleði temizle
    while (head != NULL) {
        struct ogrenci* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
