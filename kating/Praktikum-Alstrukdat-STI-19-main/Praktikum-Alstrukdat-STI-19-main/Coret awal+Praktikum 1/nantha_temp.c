#include <stdio.h>
int main(){
    char blocks[3] = {'i','t','b'}; // Asumsi alamat block 4434
    char* ptr = &blocks[0];
    char temp;

    temp = blocks[0]; // temp = 'i'
    temp = *(blocks+ 2); // temp= blocks[2] = 'b'
    temp = *(ptr +1); // temp = blocks[1] = 't'
    temp = *ptr; //temp = 'i'

    ptr = blocks + 1; // ptr = 4434 + 1 = 4435 = &blocks[1] 
    temp = *ptr; // temp = 't'
    temp = *(ptr +1); // temp = 'b' 
    
    ptr = blocks; //ptr =  4434
    printf("%c, %c, %c, %c, %d\n", blocks[0], blocks[1], blocks[2], temp, ptr);
    temp = *++ptr; // temp = *(1+ptr) = *(4435) = 't'
    printf("%c, %c, %c, %c, %d\n", blocks[0], blocks[1], blocks[2], temp, ptr);
    temp = ++*ptr; // temp = 1+*(ptr) = 1+'t' = 'u'
    printf("%c, %c, %c, %c, %d\n", blocks[0], blocks[1], blocks[2], temp, ptr);
    temp = *ptr++; // temp = *(ptr) = 'u' ; ptr+1 = 4436; 
    printf("%c, %c, %c, %c, %d\n", blocks[0], blocks[1], blocks[2], temp, ptr);
    temp = *ptr; // temp = *(4436) = 'b'
    printf("%c, %c, %c, %c, %d\n", blocks[0], blocks[1], blocks[2], temp, ptr);
    return 0;
}