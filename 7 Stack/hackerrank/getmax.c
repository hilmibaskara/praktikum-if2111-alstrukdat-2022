#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define boolean unsigned char
#define true 1
#define false 0

#define Nil -1
#define MaxEl 100

typedef int infotype;
typedef int address;

typedef struct { 
  infotype T[MaxEl]; /* tabel penyimpan elemen */
  address TOP;  /* alamat TOP: elemen puncak */
} Stack;

#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

int main(){
    scanf("%d", )
}



void CreateEmpty(Stack *S){
    S->TOP = Nil;
}

boolean IsEmpty(Stack S){
    return (Top(S) == Nil);
}

boolean IsFull(Stack S){
    return (Top(S) == (MaxEl-1));
}

void Push(Stack * S, infotype X){
    Top(*S) += 1;
    InfoTop(*S) = X;
}

void Pop(Stack * S, infotype* X){
    *X = InfoTop(*S);
    Top(*S) -= 1;
}