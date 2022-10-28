/*
NIM         : 18221072
Nama        : Hilmi Baskara Radanto
Tanggal     : 17 OKtober 2022
Topik       : Praktikum 6 Soal 1
Deskripsi   : Implementasi tanpaBomb.h
*/

#include "copyqueue.h"

// Menyalin queue.
/* Proses: Menyalin isi dari queueInput ke queueOutput */
/* I.S. queueInput mungkin kosong, tabel penampung elemen queueInput TIDAK penuh */
/* F.S. queueOutput memiliki isi queue yang sama */
/*
    Contoh input:
    queueInput : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
    queueOutput: queue kosong

    Contoh output:
    queueInput:  [2,3,4,5,6]
    queueOutput: [2,3,4,5,6]
*/

/*
    Catatan
    - Hati-hati jangan sampai algoritma Anda mengubah hasil akhir dari queueInput juga.
      Elemen di queueInput harus tetap sama setelah algoritma dijalankan.
    Hint
    - Buat queue baru selain queueInput dan queueOutput untuk tempat penyimpanan
      queueInput sementara.
*/
void copyQueue(Queue *queueInput, Queue *queueOutput){

	if (isEmpty(*queueInput) == false){
		// queue TIDAK penuh
		if (isFull(*queueInput) == false){

			int len_queue = length(*queueInput);

			// menyimpan nilai awal index head dan last dari queueInput
			int first = IDX_HEAD(*queueInput);
			int last = IDX_TAIL(*queueInput);

			// melakukan copy berdasarkan prosedur enqueue dan dequeue
			// tapi hal ini membuat queueInput head dan lastnya berubah
			for(int i = 0; i < len_queue; i++){

				ElType temp_val = 0;

				dequeue(queueInput, &temp_val);
				enqueue(queueOutput, temp_val);

			}

			// mengembalikan head dan last dari queueInput seperti semula
			IDX_HEAD(*queueInput) = first;
			IDX_TAIL(*queueInput) = last;

		}	

	}

}




