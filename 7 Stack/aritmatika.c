/*
    NIM         : 18221072
    Nama        : Hilmi Baskara Radanto
    Tanggal     : 23 Oktober 2022
    Topik       : Pra-praktikum 7
    Deskripsi   : Implementasi aritmatika h
*/

#include "aritmatika.h"

boolean isOperator(char input){
/* Proses: Mengecek apakah input merupakan operator */
/*         input adalah operator jika input merupakan salah
           satu dari berikut:
                - +
                - -
                - *
                - /
*/
    return (input == '+' || input == '-' || input == '*' || input == '/');
}

int hitung(int angka1, int angka2, char op){
/* Proses: Menghitung ekspresi */
/*
    Contoh input / output:
    angka1 : 2
    angka2 : 10
    op     : -

    return : -8 (penjelasan: 2 - 10 = 8)
*/
    int result;
    if (op == '+') result = angka1 + angka2;
    else if (op == '-') result = angka1 - angka2;
    else if (op == '*') result = angka1 * angka2;
    else if (op == '/') result = angka1 / angka2;

    return result;
}

int eval(char *input, int length){
/* Proses: Menghitung keseluruhan ekspresi */
/* I.S. input adalah string. setiap operand dipastikan < 10 */
/*
    Contoh input / output:
    input   : 23+
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 2 + 3)

    input   : 9423+*5/-
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 9-(4*(2+3))/5)
*/
    Stack s;
    CreateEmpty(&s);

    // Memindahkan string ke stack
    infotype num1;
    infotype num2;

    for (int i = 0; i < length; i++){

        if (isOperator(input[i]) == false){
            Push(&s, input[i] - '0');
        } else {
            Pop(&s, &num2);
            Pop(&s, &num1);

            Push(&s, hitung(num1, num2, input[i]));
        }

    }
    

    return InfoTop(s);
}