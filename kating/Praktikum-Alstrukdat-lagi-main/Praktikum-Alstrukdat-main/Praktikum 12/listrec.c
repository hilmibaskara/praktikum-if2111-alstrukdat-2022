// NAMA      : Saul Sayers
// NIM       : 13520094
// Tanggal   : 18 November 2021
// Topik     : ADT Linked List secara rekursif
// Deskripsi : Implementasi ADT Linked list secara rekursif dalam bahasa C

#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"
#include "boolean.h"

Address newNode(ElType x) 
{
    Address baru = (Address) malloc(sizeof(Node));
    if (baru!=NULL) {
        INFO(baru) = x;
        NEXT(baru) = NULL;
    }
    return baru;
}

boolean isEmpty(List l)
{
    return (l == NULL);
}

int isOneElmt(List l)
{
    boolean bener = 0;
    if (l != NULL)
    {
        if (NEXT(l) == NULL)
        {
            bener = 1;
        }
    }
    return bener ;
}

ElType head(List l)
{
    return INFO(l);
}

List tail(List l)
{
    return NEXT(l);
}

List konso(List l, ElType e)
{
    Address baru ;
    baru = newNode(e);
    if (baru != NULL) {
        NEXT(baru) = l;
        l = baru;
    }
    return l;
}

List konsb(List l, ElType e)
{
    Address alamat, akhir,baru ;
    if (l == NULL) {
        baru = newNode(e);
        if (baru != NULL) {
            NEXT(baru) = l;
            l = baru;
        }
    }
    else {
        alamat = newNode(e) ;
        if (alamat != NULL) {
            akhir = l ;
            while (NEXT(akhir) != NULL ) {
                akhir = NEXT(akhir);
            }
            NEXT(akhir) = alamat;
        }
    }
    return l;
}

int length(List l)
{
    if (isEmpty(l))
    {
        return 0;
    }
    else
    {
        return 1 + length(tail(l));
    }
}

void displayList(List l)
{
    if (!isEmpty(l))
    {
        printf("%d\n", head(l));
        displayList(tail(l));
    }
}

ElType maxList (List l) 
{
    if (!isOneElmt(l))
    {
        if (head(l) < maxList(tail(l))) 
        {
            return maxList(tail(l));
        }
        else 
        {
            return head(l);
        }
    }
    else
    {
        return head(l) ;
    }
}

ElType minList (List l) 
{
    if (!isOneElmt(l))
    {
        if (head(l) > minList(tail(l))) 
        {
            return minList(tail(l));
        }
        else 
        {
            return head(l);
        }
    }
    else
    {
        return head(l) ;
    }
}

ElType sumList (List l) 
{
    if (isEmpty(l))
    {
        return 0;
    }
    else 
    {
        return sumList(tail(l)) + head(l);
    }
}

float averageList (List l) 
{
    return (((float) sumList(l)) / ((float) length(l))) ;
}

List inverseList (List l) 
{
    if (isEmpty(l)) 
    {
        return l;
    } 
    else 
    {
        return konsb(inverseList(tail(l)), head(l));
    }
}

void splitPosNeg (List l, List *l1, List *l2) 
{
    if (isEmpty(l))
    {
		*l2 = NULL;
        *l1 = NULL;
	}
    else
    {
        splitPosNeg(tail(l), l1, l2);
        if (head(l) >= 0)
        {
            *l1 = konso(*l1, head(l));
        }   
        else 
        {
            *l2 = konso(*l2, head(l));	
        }
    }
}

void splitOnX (List l, ElType x, List *l1, List *l2) 
{
    if (isEmpty(l))
    {
		*l2 = NULL;
        *l1 = NULL;
	}
    else
    {
        splitOnX(tail(l), x, l1, l2);
        if (head(l) >= x)
        {
            *l2 = konso(*l2, head(l));	
        }   
        else 
        {
            *l1 = konso(*l1, head(l));
        }
    }
}

int compareList (List l1, List l2) 
{
    if (isEmpty(l1) && isEmpty(l2)) 
    {
        return 0 ;
    }
    else if (isEmpty(l2)) 
    {
        return 1;
    }
    else if (isEmpty(l1)) 
    {
        return -1;
    }
    else if (head(l1) < head(l2)) 
    {
        return -1;
    }
    else if (head(l1) > head(l2)) 
    {
        return 1;
    }
    else
    {
        return compareList(tail(l1), tail(l2));
    }
}

boolean Search (List l, ElType X)
{
    if (!isEmpty(l)) 
    {
        if (head(l) == X) 
        {
            return true;
        }
        else
        {
            return Search(tail(l), X);
        }
    }
    else
    {
        return false;
    }
}

boolean isAllExist (List l1, List l2)
{
	if (isEmpty(l1)) 
    {
        return false;
    } 
    boolean ada = Search(l2,head(l1));
    if (ada) 
    {
        if (!isEmpty(tail(l1))) 
        {
            return isAllExist(tail(l1), l2);
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}