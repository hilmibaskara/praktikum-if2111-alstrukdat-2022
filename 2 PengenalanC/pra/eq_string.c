#include <ctype.h>
#include <stdio.h>
#include <string.h>
 
int main()
{
    char word1[100];
    char word2[100];
    int i;
    int check = 1;
    scanf("%s", word1);
    scanf("%s", word2);
    for(i = 0; i < 100; i++){
        word1[i] = toupper(word1[i]);
    }
    for(i = 0; i < 100; i++){
        word2[i] = toupper(word2[i]);
    }
    if (strcmp(word1,word2) == 0){
        printf("Ya\n");
    } else {
        printf("Tidak\n" );
    }
    return 0;
}