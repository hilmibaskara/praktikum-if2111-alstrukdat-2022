// NAMA      : Saul Sayers
// NIM       : 13520094
// Tanggal   : 25 November 2021
// Topik     : Invertbintree
// Deskripsi : Implementasi Binary Tree dalam bahasa C

#include <stdio.h>
#include "bintree.h"
#include <stdlib.h>

void invertBtree(BinTree *p)
{
    Address sementara;
    if (isBinary(*p))
    {
        sementara = LEFT(*p);
        LEFT(*p) = RIGHT(*p);
        RIGHT(*p) = sementara;
        invertBtree(&LEFT(*p));
        invertBtree(&RIGHT(*p));
    }
    else if (isUnerLeft(*p))
    {
        RIGHT(*p) = LEFT(*p);
        LEFT(*p) = NULL;
        invertBtree(&RIGHT(*p));
    }
    else if (isUnerRight(*p))
    {
        LEFT(*p) = RIGHT(*p);
        RIGHT(*p) = NULL;
        invertBtree(&LEFT(*p));
    }
}

