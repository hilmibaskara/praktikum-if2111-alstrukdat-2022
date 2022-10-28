// NAMA      : Saul Sayers
// NIM       : 13520094
// Tanggal   : 24 Oktober 2021
// Topik     : ADT Linked List Double Pointer
// Deskripsi : Implementasi ADT List Double Pointer dalam bahasa C

#include <stdio.h>
#include <stdlib.h>
#include "list_dp.h"

boolean isEmpty(List l){
    return ((FIRST(l) == NULL) && (LAST(l) == NULL));
}

void CreateList(List *l){
    FIRST(*l) = NULL;
    FIRST(*l) = NULL;
}

Address allocate(ElType val){
    Address baru;
    baru = (Address) malloc(1 * sizeof(Node)); 
    if (baru != NULL) {
        INFO(baru) = val;
        NEXT(baru) = NULL;
        PREV(baru) = NULL;
    }
    return baru;
}

void deallocate (Address p){
    free(p) ;
}

Address search(List l, ElType val){
    Address awal;
    boolean ketemu = false;
    awal = FIRST(l);
    while(awal != NULL && !ketemu) {
        if(INFO(awal) == val) {
            ketemu = true;
        }
        else{
            awal = NEXT(awal);
        }
    }
    return awal;
}

void insertFirst(List *l, ElType val){
    Address baru ;
    baru = allocate(val);
    if (baru != NULL) {
        if(isEmpty(*l)) {
            FIRST(*l) = baru;
            LAST(*l) = baru;
        }
        else {
            NEXT(baru) = FIRST(*l);
            PREV(FIRST(*l)) = baru;
            FIRST(*l) = baru;
        }
    }
}

void insertLast(List *l, ElType val){
    Address baru ;
    baru = allocate(val);
    if (baru != NULL) {
        if(isEmpty(*l)) {
            FIRST(*l) = baru;
            LAST(*l) = baru;
        }
        else {
            PREV(baru) = LAST(*l);
            NEXT(LAST(*l)) = baru;
            LAST(*l) = baru;
        }
    }
}

void insertAfter(List *L, Address p, Address pRec){
    if (NEXT(pRec) != NULL) {
        PREV(NEXT(pRec)) = p;
    }
    else {
        LAST(*L) = p;
    }
    NEXT(p) = NEXT(pRec);
    PREV(p) = pRec;
    NEXT(pRec) = p;
}

void deleteFirst(List *l, ElType *val){
    Address alamat = FIRST(*l);
    *val = INFO(alamat);
    if (NEXT(alamat) == NULL) {
        FIRST(*l) = NULL;
        LAST(*l) = NULL;
        free(alamat);
    }
    else {
        FIRST(*l) = NEXT(alamat);
        PREV(NEXT(alamat)) = NULL;
        free(alamat);
    }
}

void deleteLast(List *l, ElType *val){
    Address alamat = LAST(*l);
    *val = INFO(alamat);
    if (PREV(alamat) == NULL) {
        FIRST(*l) = NULL;
        LAST(*l) = NULL;
        free(alamat);
    }
    else {
        LAST(*l) = PREV(alamat);
        NEXT(PREV(alamat)) = NULL;
        free(alamat);
    }
}

void deleteAfter(List *l, Address *pDel, Address pRec){
    *pDel = NEXT(pRec);
    NEXT(pRec) = NEXT(NEXT(pRec));
    if (NEXT(*pDel) != NULL) {
        PREV(NEXT(*pDel)) = pRec;
    }
    else {
        LAST(*l) = pRec;
    }
}

void displayList(List l){
    Address alamat = FIRST(l) ;
    printf("[");
    if (!isEmpty(l)) {
        while (NEXT(alamat) != NULL) {
            printf("%d,", INFO(alamat));
            alamat = NEXT(alamat);
        }
        printf("%d", INFO(alamat));
    }
    printf("]");
}

void displayListBackwards(List l){
    Address alamat = LAST(l) ;
    printf("[");
    if (!isEmpty(l)) {
        while (PREV(alamat) != NULL) {
            printf("%d,", INFO(alamat));
            alamat = PREV(alamat);
        }
        printf("%d", INFO(alamat));
    }
    printf("]");
}

