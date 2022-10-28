//Nama : Saul Sayers
//NIM  : 13520094
//Kelas: K02 Alstrukdat
//PRAKTIKUM 6

#include <stdio.h>
#include "tokenmachine.h"

boolean endToken;
Token currentToken;

void ignoreBlank(){
    while(currentChar == BLANK)
    {
        adv();
    }
}

void startToken() {
    start();
    ignoreBlank();
    if(currentChar == MARK) {
        endToken = true;
    }
    else{
        endToken = false;
        salinToken();
    }
}

void advToken(){
    ignoreBlank();
    if(currentChar == MARK) {
        endToken = true;
    }
    else{
        salinToken();
        ignoreBlank(); 
    }
}

void salinToken(){
    currentToken.val = 0;
    if(!(currentChar == '/' || currentChar == '*' || currentChar == '+' || currentChar == '-' || currentChar == '^')){
        currentToken.tkn = 'b';
        while(currentChar!=MARK && currentChar!=BLANK){
            currentToken.val *= 10;
            currentToken.val += ((int)currentChar - 48);
            adv();
        }
    } 
    else if((currentChar != BLANK) && (currentChar != MARK)){
        currentToken.tkn = currentChar;
        currentToken.val = -1;
        adv();
    }
}

/*int main(){
startToken();
    printf("<'%c', %d>\n", currentToken.tkn, currentToken.val);
    while(!endToken){
        advToken();
        printf("<'%c', %d>\n", currentToken.tkn, currentToken.val);
    }
}*/