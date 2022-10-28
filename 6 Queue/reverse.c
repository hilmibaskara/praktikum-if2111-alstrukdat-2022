/*
NIM         : 18221072
Nama        : Hilmi Baskara Radanto
Tanggal     : 15 Oktober 2022
Topik       : PraPraktikum 6 - Queue Soal 3
Deskripsi   : Implementasi reverse.h
*/

#include <stdio.h>
#include "circular_queue.h"

// Proses: Memindahkan tiap elemen q1 ke q2 dengan urutan yang terbalik
// I.S.: q1 tidak kosong, q2 kosong. q1 dan q2 memiliki panjang yang sama
// F.S.: q1 kosong, q2 berisi elemen-elemen yang tadinya milik q1 dengan urutan yang terbalik
void transferReverse(Queue* q1, Queue* q2){
    IdxType tempTail = q1->TAIL;

    q2->TAIL = q1->TAIL+1;
    q2->HEAD = q1->HEAD;

    while(q2->TAIL >= q2->HEAD){
        q2->TAIL -= 2;
        Push(q2, Pop(q1));
    }

    q2->TAIL = tempTail;
}