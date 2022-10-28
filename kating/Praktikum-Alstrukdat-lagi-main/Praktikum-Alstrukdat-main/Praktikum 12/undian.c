// NAMA      : Saul Sayers
// NIM       : 13520094
// Tanggal   : 18 November 2021
// Topik     : Undian.c
// Deskripsi : Implementasi ADT Linked list secara rekursif dalam bahasa C melalui undian.c

#include <stdio.h>
#include <stdlib.h>
#include "listrec.h"
#include "boolean.h"

List reverseList(List l) 
{
    if (isEmpty(l)) 
    {
        return l;
    } 
    else 
    {
        return konsb(reverseList(tail(l)), head(l));
    }
}

List splitBeforeX(List l, ElType x)
{
    if (isEmpty(l))
    {
		return l;
	}
    else
    {
        if (head(l) == x)
        {
            return NULL;
        }   
        else 
        {
            return konso(splitBeforeX(tail(l), x), head(l));
        }
    }
}

List splitOddIndex(List l) 
{
    if (isEmpty(l))
    {
        return l ;
    }
    else if (isEmpty(tail(l)))
    {
        return konso(tail(l), head(l));
    }
    else
    {
        konso(splitOddIndex(tail(tail(l))), head(l));
    }
}

List splitEvenIndex(List l)
{
    if (isEmpty(l))
    {
        return l;
    }
    else {
        List baru = tail(l);
        return splitOddIndex(baru);
    }
}

int main() 
{
    int elemen, selesai = 0;
    char pilihan;
    List undian = NULL;

    while (!selesai) 
    {
        scanf(" %c", &pilihan);
        if (pilihan == 'X')
        {
            if (!isEmpty(undian))
            {
                displayList(undian);
            }
            else
            {
                printf("Semua gugur\n");
            }
            selesai = 1;
        }
        else if (pilihan == 'O' && !isEmpty(undian))
        {
            undian = splitOddIndex(undian);
        }
        else if (pilihan == 'E' && !isEmpty(undian))
        {
            undian = splitEvenIndex(undian);
        }
        else if (pilihan == 'B')
        {
            scanf("%d", &elemen);
            undian = konsb(undian, elemen);
        }
        else if (pilihan == 'F')
        {
            scanf("%d", &elemen);
            undian = konso(undian, elemen);
        }
        else if (pilihan == 'R' && !isEmpty(undian))
        {
            undian = reverseList(undian);
        }
        else if (pilihan == 'P')
        {
            scanf(" %d", &elemen);
            if (!isEmpty(undian))
            {
                undian = splitBeforeX(undian, elemen);
            }
        }
    }
    return 0;
}