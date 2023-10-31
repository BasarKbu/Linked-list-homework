#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ogrenci {
    char isim[40];
    struct ogrenci* next;
};

struct ogrenci* head = NULL;

void ekle(const char* isim) {
    struct ogrenci* yeni = (struct ogrenci*)malloc(sizeof(struct ogrenci));
    strncpy(yeni->isim, isim, sizeof(yeni->isim));
    yeni->next = head;
    head = yeni;
}

int ara(const char* arananIsim) {
    struct ogrenci* current = head;
    while (current != NULL) {
        if (strcmp(current->isim, arananIsim) == 0) {
            return 1;  // Ýsim bulundu
        }
        current = current->next;
    }
    return 0;  // Ýsim bulunamadý
}

int main() {
    ekle("Ali");
    ekle("Veli");
    ekle("Ahmet");
    ekle("Mehmet");
    ekle("Ayse");
    ekle("Fatma");

    char aranan[40];
    printf("Aranacak ismi giriniz: ");
    scanf("%s", aranan);

    if (ara(aranan)) {
        printf("%s liste kayitlarinda bulunuyor.\n", aranan);
    } else {
        printf("%s liste kayitlarinda bulunmuyor.\n", aranan);
    }

    // Baðlý liste belleði temizle
    while (head != NULL) {
        struct ogrenci* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

