#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 

#include "add.h"
#include "sub.h"
#include "mul.h"
#include "div.h"


int main(void)
{
    int x = 15;
    int y = 3;

    printf("x + y = %d\n", add(x, y));
    printf("x - y = %d\n", sub(x, y));
    printf("x * y = %d\n", mul(x, y));
    printf("x / y = %d\n", mydiv(x, y));

    return 0;
}
