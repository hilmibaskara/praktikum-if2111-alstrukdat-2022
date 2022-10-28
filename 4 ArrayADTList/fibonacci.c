/*
NIM         : 18221072
Nama        : Hilmi Baskara Radanto
Tanggal     : 26 September 2022
Topik       : Pra-praktikum 4
Deskripsi   : Implementasi fibonacci.h
*/

#include "fibonacci.h"
#include <stdio.h>
#include <stdlib.h>

// Deret bilangan fibonacci adalah deret angka yang susunan angkanya
// merupakan penjumlahan dari dua angka sebelumnya.
// Contoh:
// Fib 0: 1
// Fib 1: 1
// Fib 2: 1 + 1 = 2
// Fib 3: 2 + 1 = 3
// Fib 4: 3 + 2 = 5
// Fib 5: 5 + 3 = 8

// Menerima argument sebuah integer n dan mengembalikan
// nilai suku ke-n dari deret fibonacci ke argumen result
// Contoh:
// n = 5
// Nilai argumen result = 8
int fibonacci(n){
    int result;
    if (n == 0 || n == 1){
        result = 1;
    } else {
        result = fibonacci(n-1) + fibonacci(n-2);
    }
    return result;
}

void fibonacci1(int n, int *result){
    (*result) = fibonacci(n);
}

// Menerima argument sebuah integer n dan mengembalikan
// nilai suku ke-n dari deret fibonacci
int fibonacci2(int n){
    return fibonacci(n);
}

// Menerima argument sebuah integer n
// Output adalah argumen result yang bertipe pointer int digunakan sebagai array
// Tuliskan semua nilai deret fibonacci dari 0 - n ke argumen result
// n = 5
// result = [1, 1, 2, 3, 5, 8]
void fibonacci3(int n, int *result)
{
    int i;
    for (i = 0; i <= n; i++)
    {
        result[i] = fibonacci2(i);
    }
}