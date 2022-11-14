/*
    NIM         : 18221072
    Nama        : Hilmi Baskara Radanto
    Tanggal     : 13 November 2022
    Topik       : Praktikum 10
    Deskripsi   : Soal 3 - Elemene ke n
*/

#include <stdio.h>
#include "listsirkuler.h"

int ElemenKeN(List L, int r) {
    address p = L.First;
    int ctr = 0;
    while (ctr != r){
        p = Next(p);
        ctr++;
    }
    return Info(p);
}

int main(){
  List L;
  int r, value;
  scanf("%d", &value);
  while (value != 0){
    InsVLast(&L, value);
    scanf("%d", &value);
  }
  scanf("%d", &r);
  if (IsEmpty(L)) printf("List Kosong\n");
  else printf("%d\n", ElemenKeN(L, r));
  return 0;
}