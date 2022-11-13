/*
	NIM			: 18221072
	Nama		: Hilmi Baskara Radanto
	TAnggal		: 07 NOvember 2022
	Topik		: Praktikum 9 - List Linear
	Deskripsi	: SOAL 2 - Fibonacci
*/

#include <stdio.h>
#include "listlinier.h"

int main() {
    List fibo; CreateEmpty(&fibo);
	infotype input_el, el1, el2, sum_fib;

    scanf("%d", &input_el);

    if (input_el == 0) PrintInfo(fibo);
	else if (input_el == 1) {
        scanf("%d", &el1);

        InsVLast(&fibo, el1);
        PrintInfo(fibo);

    } else {
        scanf("%d", &el1);
        scanf("%d", &el2);

        InsVLast(&fibo, el1);
        InsVLast(&fibo, el2);

        for (int i = 0; i < (input_el - 2); i++) {
            sum_fib = el1;
            sum_fib += el2;
            InsVLast(&fibo, sum_fib);
            el1 = el2;
            el2 = sum_fib;
        }

        PrintInfo(fibo);
    }

    return 0;
}