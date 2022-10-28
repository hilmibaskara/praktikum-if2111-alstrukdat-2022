// NAMA      : Saul Sayers
// NIM       : 13520094
// Tanggal   : 24 Oktober 2021
// Topik     : ADT Linked List Circular
// Deskripsi : Implementasi ADT List Circular dalam bahasa C

#include <stdio.h>
#include <stdlib.h>
#include "list_circular.h"

boolean isEmpty(List l){
    return FIRST(l) == NULL;
}

void CreateList(List *l){
    FIRST(*l) = NULL;
}

Address allocate(ElType val){
    Address baru;
    baru = (Address) malloc(1 * sizeof(ElmtList));
    if (baru != NULL) {
        INFO(baru) = val;
        NEXT(baru) = NULL;
    }
    return baru;
}

void deallocate(Address P){
    free(P);
}

Address search(List l, ElType val){
    Address awal;
    boolean ketemu;
    if (isEmpty(l)) {
        ketemu = false;
    }
    else {
        awal = FIRST(l);
        while (NEXT(awal) != FIRST(l) && INFO(awal) != val) {
            awal = NEXT(awal);
        }
        ketemu = INFO(awal) == val;
    }
    if (!ketemu) {
        awal = NULL;
    }
    return awal;
}

boolean addrSearch(List l, Address p){
    Address awal;
    boolean ketemu;
    if (isEmpty(l)) {
        ketemu = false;
    }
    else {
        awal = FIRST(l);
        while (NEXT(awal) != FIRST(l) && awal != p) {
            awal = NEXT(awal);
        }
        ketemu = awal == p;
    }
    return ketemu;
}

void insertFirst(List *l, ElType val){
    Address awal, akhir ;
    awal = allocate(val) ;
    if (awal != NULL) {
        if (isEmpty(*l)) {
            NEXT(awal) = awal;
        }
        else {
            akhir = FIRST(*l);
            while (NEXT(akhir) != FIRST(*l)) {
                akhir = NEXT(akhir);
            }
            NEXT(awal) = FIRST(*l);
            NEXT(akhir) = awal;
        }
        FIRST(*l) = awal;
    }
}


void insertLast(List *l, ElType val){
    Address awal, akhir;
    if (isEmpty(*l)) {
        insertFirst(l,val);
    }
    else {
        awal = allocate(val);
        if (awal != NULL) {
            akhir = FIRST(*l);
            while (NEXT(akhir) != FIRST(*l)) {
                akhir = NEXT(akhir);
            }
            NEXT(akhir) = awal;
            NEXT(awal) = FIRST(*l);
        }
    }
}

void deleteFirst(List *l, ElType *val){
    Address awal, akhir;
    awal = FIRST(*l); 
    *val = INFO(awal); 
    if (NEXT(FIRST(*l)) == FIRST(*l)) { /* satu elemen */
        FIRST(*l) = NULL;
    } 
    else {
        akhir = FIRST(*l);
        while (NEXT(akhir) != FIRST(*l)) {
            akhir = NEXT(akhir);
        } 
        FIRST(*l) = NEXT(FIRST(*l)); NEXT(akhir) = FIRST(*l);
    }
    free(awal);
}

void deleteLast(List *l, ElType *val){
    Address akhir, sebelumakhir; 
    akhir = FIRST(*l);
    sebelumakhir = NULL;
    while (NEXT(akhir) != FIRST(*l)) {
        sebelumakhir = akhir; 
        akhir = NEXT(akhir);
    } 
    if (sebelumakhir == NULL) { 
        FIRST(*l) = NULL; 
    } 
    else { 
        NEXT(sebelumakhir) = FIRST(*l);
    }
    *val = INFO(akhir);
    free(akhir);
}

void displayList(List l){
    Address alamat = FIRST(l) ;
    printf("[");
    if (!isEmpty(l)) {
        /*printf("%d,", INFO(alamat));
        alamat = NEXT(alamat);*/
        while (NEXT(alamat) != FIRST(l)) {
            printf("%d,", INFO(alamat));
            alamat = NEXT(alamat);
        }
        printf("%d", INFO(alamat));
    }
    printf("]");
}

