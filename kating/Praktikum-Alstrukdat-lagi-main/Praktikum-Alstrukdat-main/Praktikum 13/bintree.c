// NAMA      : Saul Sayers
// NIM       : 13520094
// Tanggal   : 12 November 2021
// Topik     : Binary Trees
// Deskripsi : Implementasi Binary Tree dalam bahasa C

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree)
{
    BinTree baru = (BinTree) malloc (sizeof(BinTree));
    if (baru != NULL) 
    {
        ROOT(baru) = root;
        LEFT(baru) = left_tree;
        RIGHT(baru) = right_tree;
    }

    return baru;
}

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p)
{
    *p = NewTree(root, left_tree, right_tree);
}

Address newTreeNode(ElType val)
{
    Address baru = (Address) malloc(sizeof(TreeNode));
    if (baru!=NULL) {
        ROOT(baru) = val;
        RIGHT(baru) = NULL;
        LEFT(baru) = NULL;
    }
    return baru;
}

void deallocTreeNode (Address p)
{
    free(p);
}

boolean isTreeEmpty (BinTree p)
{
    return p == NULL;
}


boolean isOneElmt (BinTree p)
{
    if (isTreeEmpty(p)) 
    {
        return false;
    } 
    else 
    {
        return ((LEFT(p) == NULL) && (RIGHT(p) == NULL));
    }
}

boolean isUnerLeft (BinTree p)
{
    if (isTreeEmpty(p)) 
    {
        return false;
    } 
    else 
    {
        return ((LEFT(p) != NULL) && (RIGHT(p) == NULL));
    }
}

boolean isUnerRight (BinTree p)
{
    if (isTreeEmpty(p)) 
    {
        return false;
    } 
    else 
    {
        return ((LEFT(p) == NULL) && (RIGHT(p) != NULL));
    }
}

boolean isBinary (BinTree p)
{
    if (isTreeEmpty(p)) 
    {
        return false;
    } 
    else 
    {
        return ((LEFT(p) != NULL) && (RIGHT(p) != NULL));
    }
}

void printPreorder(BinTree p)
{
    printf("(");
    if (!isTreeEmpty(p)) 
    {
        printf("%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
    }
    printf(")");
}

void printInorder(BinTree p)
{
    printf("(");
    if (!isTreeEmpty(p)) 
    {
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
    }
    printf(")");
}

void printPostorder(BinTree p)
{
    printf("(");
    if (!isTreeEmpty(p)) 
    {
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d", ROOT(p));
    }
    printf(")");
}

void CatatPrintTree(BinTree p, int h, int baris) 
{
    if(!isTreeEmpty(p)){
        int i;
        for (i = 0; i < baris*h; i++)
        {
            printf(" ");
        }
        printf("%d\n", ROOT(p));
        CatatPrintTree(LEFT(p), h, baris + 1);
        CatatPrintTree(RIGHT(p), h, baris + 1);
    }
}

void printTree(BinTree p, int h)
{
    CatatPrintTree(p, h, 0);
}