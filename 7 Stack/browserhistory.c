/*
    NIM         : 18221072
    Nama        : Hilmi Baskara RAdanto
    Tanggal     : 24 OKtober 2022
    TOpik       : Praktikum 7
    Deskripsi   : implementasi browserhistory.h
*/

#include "browserhistory.h"


void browserHistoryVisit(Stack *openedTab, Stack *history, char *url)
{
    Push(openedTab, url);
    Push(history, url);

}

char *currentUrl(Stack *openedTab){
    return InfoTop(*openedTab);
}


char *browserHistoryBack(Stack *openedTab, Stack *history, int steps){
    infotype url;
    for (int i = 0; i < steps; i++){
        Pop(openedTab, &url);
        Push(history, url);
    }
    return currentUrl(openedTab);
}

char *browserHistoryForward(Stack *openedTab, Stack *history, int steps){
/**
 * return url yang sedang dibuka setelah maju ke depannya
 * I.S. openedTab tidak mungkin kosong,
 *      banyak steps yang ditempuh tidak boleh lebih banyak
 *      dari banyaknya url yang pernah dibuka
 * F.S. url adalah nilai elemen TOP yang lama, TOP bertambah 1
 */
    infotype url;
    for (int i = 0; i < steps; i++){
        Pop(history, &url);
        Push(openedTab, url);
    }
    return currentUrl(openedTab);
}

void browserHistoryFree(Stack *history){
/**
 * Mengosongkan history
 * I.S. history tidak mungkin kosong
 * F.S. history kosong
 */
    CreateEmpty(history);
}