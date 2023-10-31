#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ogrenci {
    int no;
    char isim[50];
    int yas;
    struct ogrenci* next;
};

// Yeni ��renci d���m� olu�turma
struct ogrenci* yeniOgrenci(int no, const char* isim, int yas) {
    struct ogrenci* ogrenci = (struct ogrenci*)malloc(sizeof(struct ogrenci));
    ogrenci->no = no;
    strncpy(ogrenci->isim, isim, sizeof(ogrenci->isim));
    ogrenci->yas = yas;
    ogrenci->next = NULL;
    return ogrenci;
}

// ��renci d���m�n� ekrana yazd�rma
void ogrenciYazdir(struct ogrenci* ogrenci) {
    printf("%d - %s - %d\n", ogrenci->no, ogrenci->isim, ogrenci->yas);
}

int main() {
    struct ogrenci* head = NULL;  // Ba�l� listenin ba��

    for (int i = 1; i <= 5; i++) {
        int no, yas;
        char isim[50];

        printf("Ogrenci No: ");
        if (scanf("%d", &no) != 1) {
            printf("Gecersiz ogrenci numarasi girdiniz. Cikis yapiliyor.\n");
            break;
        }

        printf("Ogrenci Isim: ");
        scanf("%s", isim);

        printf("Ogrenci Yas: ");
        if (scanf("%d", &yas) != 1) {
            printf("Gecersiz ogrenci yasi girdiniz. Cikis yapiliyor.\n");
            break;
        }

        struct ogrenci* ogrenci = yeniOgrenci(no, isim, yas);

        if (head == NULL) {
            head = ogrenci;
        } else {
            struct ogrenci* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = ogrenci;
        }
    }

    // Ba�l� liste �zerinde dola�arak ��renci bilgilerini yazd�rma
    printf("Ogrenci Bilgileri:\n");
    struct ogrenci* current = head;
    while (current != NULL) {
        ogrenciYazdir(current);
        current = current->next;
    }

    // Ba�l� liste belle�i temizle
    current = head;
    while (current != NULL) {
        struct ogrenci* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

