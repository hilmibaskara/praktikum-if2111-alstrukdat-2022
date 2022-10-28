/*
    NIM         : 18221072
    Nama        : Hilmi Baskara Radanto
    Tanggal     : 23 Oktober 2022
    Topik       : Praktikum 6
    Deskripsi   : Problem solving pada restoran ibu Gra pada restoran.c
*/

#include "queue.h"

int main(){
    // Membuat queue
    Queue q;
    CreateQueue(&q);

    // Deklarasi variabel
    int n;
    int time;
    int count = 0;
    int min = 99999;
    int max = (-99999);

    // Menerima input pertama
    scanf("%d", &n);

    while (n != 0){
        if (n == 1){
            scanf("%d", &time);
            if (time > 0){
                enqueue(&q, time);
            }
        }
        else if (n == 2){
            if (isEmpty(q) == false){
                int val;
                dequeue(&q, &val);

                if (val < min){
                    min = val;
                }

                if (val > max){
                    max = val;
                }

                count += 1;
            }
        }

        scanf("%d", &n);
    }

    if (count == 0){
        min = 0;
        max = 0;
    }

    printf("%d\n", count);
    printf("%d\n", min);
    printf("%d\n", max);

    return 0;
}