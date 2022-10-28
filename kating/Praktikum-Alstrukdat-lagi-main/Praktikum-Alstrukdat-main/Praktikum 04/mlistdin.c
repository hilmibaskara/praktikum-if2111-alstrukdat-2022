//Nama   : Saul Sayers
//NIM    : 13520094
//Kelas  : K02
//Praktikum 4 

#include <stdio.h>
#include "listdin.h"

int main() {
    ListDin L,sementara ;
    int op,capacity,Q,i,capacitybaru ;
    ElType num;
    scanf("%d", &capacity);
    CreateListDin(&L, capacity);
    readList(&L);
    scanf("%d", &Q);
    for (i=0;i<Q;i++) {
        scanf("%d", &op);
        if (op == 1) {
            scanf(" %d", &num);
            if (NEFF(L) == CAPACITY(L)) {
                printf("list sudah penuh\n");
            }
            else {
                insertLast(&L, num);
                printf("%d ", CAPACITY(L));
                displayList(L);
                printf("\n");
            }
        }
        else if (op == 2) {
            scanf(" %d", &num);
            growList(&L, num);
            printf("%d ", CAPACITY(L));
            displayList(L);
            printf("\n");
        }
        else if (op == 3) {
            scanf(" %d", &num);
            if (NEFF(L) < num) {
                printf("list terlalu kecil\n");
            }
            else {
                capacitybaru = CAPACITY(L) - num ;
                copyList(L, &sementara) ;
                CAPACITY(sementara) = capacitybaru;
                if (capacitybaru < NEFF(L)) {
                    NEFF(sementara) = capacitybaru;
                }
                free(BUFFER(L));
                CAPACITY(L) = 0;
                NEFF(L) = 0;
                copyList(sementara, &L);
                printf("%d ", CAPACITY(L));
                displayList(L);
                printf("\n");
            }
        }
        else {
            compactList(&L);
            printf("%d ", CAPACITY(L));
            displayList(L);
            printf("\n");
        }
    }
    return 0;
}