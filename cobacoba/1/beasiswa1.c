#include <stdio.h>
#include "boolean.h"

int main()
{
    float ip,sal;
    int cat;

    scanf("%f %f", &ip, &sal);

    (ip < 3.5) ? (
        (sal >= 1 && sal < 5) ? (
            (ip >= 2.0)? (cat = 3) : (cat = 2)
        ):(
            (sal < 1) ? (cat = 1) : (cat = 0)
        )) :(
            cat = 4
        );
        
    printf("%d\n", cat);
    return 0;
}