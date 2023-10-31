#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ogrenci {
    char isim[40];
    struct Ogrenci* next;
};

struct Ogrenci* head = NULL;

void ekle(const char* isim) {
    struct Ogrenci* yeni = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    strncpy(yeni->isim, isim, sizeof(yeni->isim));
    yeni->next = head;
    head = yeni;
}

void sil(const char* isim) {
    struct Ogrenci* current = head;
    struct Ogrenci* onceki = NULL;

    while (current != NULL) {
        if (strcmp(current->isim, isim) == 0) {
            if (onceki != NULL) {
                onceki->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return; // Ýsmi bulduk ve sildik, iþlemi sonlandýr.
        }
        onceki = current;
        current = current->next;
    }
}

void listele() {
    struct Ogrenci* current = head;
    while (current != NULL) {
        printf("%s\n", current->isim);
        current = current->next;
    }
}

int main() {
    ekle("Ali");
    ekle("Veli");
    ekle("Ahmet");
    ekle("Mehmet");
    ekle("Ayse");
    ekle("Fatma");

    printf("Liste:\n");
    listele();

    char silinecekIsim[40];
    printf("Silinecek ismi giriniz: ");
    scanf("%s", silinecekIsim);

    sil(silinecekIsim);

    printf("Liste guncellendi:\n");
    listele();

    // Belleði temizle
    while (head != NULL) {
        struct Ogrenci* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}


