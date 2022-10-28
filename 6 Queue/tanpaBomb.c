#include "tanpaBomb.h"
#include <stdlib.h>

Queue tanpaBomb(Queue queue, ElType bomb){
/* Mengembalikan sebuah queue yang sudah tidak memiliki nilai bomb */

/*
    Contoh input:
        queue : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
        bomb : 3
    Contoh output: [2,4,5,6]

    Contoh input:
        queue : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
        bomb : 7
    Contoh output: [2,3,4,5,6]

*/
    // 1. bikin queue baru
    // 2. enqueue nilai yg bukan bomb, if bomb skip
    Queue queue_temp;
    CreateQueue(&queue_temp);
    int length_queue = length(queue);
    
    for (int i = 0; i < length_queue; i++){
        ElType val;
        dequeue(&queue, &val);
        if (val != bomb) enqueue(&queue_temp, &val);
    }

    copyQueue(&queue_temp, &queue);
}

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
