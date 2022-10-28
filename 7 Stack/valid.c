/*
    NIM         : 18221072
    Nama        : Hilmi Baskara RAdanto
    TAnggal     : 24 OKtober 2022
    TOpik       : Praktikum 7
    Deskripsi   : Implementasi valid.h
*/

#include "valid.h"

Stack validParantheses(char* input, int length){
/* Proses: Memasukkan parantheses (dari input) yang valid secara berurutan ke dalam Stack */
/* I.S. input adalah string, yang berisi parantheses baik secara acak maupun teratur, dan panjang dari string */
/* Contoh input dan hasil parantheses yang valid:
    1. () 2 -> ()
    2. []) 3 -> []
    3. {[} 3 -> --kosong--
    4. ()[]{} 6 -> ()[]{}
*/
    Stack stack;
    CreateEmpty(&stack);

    // Memindahkan string ke stack
    for (int i = 1; i < length; i++){

        if (input[i-1] == '(' && input[i] == ')'){
            Push(&stack, input[i-1]);
            Push(&stack, input[i]);
        } else if (input[i-1] == '[' && input[i] == ']') {
            Push(&stack, input[i-1]);
            Push(&stack, input[i]);
        } else if (input[i-1] == '{' && input[i] == '}') {
            Push(&stack, input[i-1]);
            Push(&stack, input[i]);
        }

    }

    return stack;
}