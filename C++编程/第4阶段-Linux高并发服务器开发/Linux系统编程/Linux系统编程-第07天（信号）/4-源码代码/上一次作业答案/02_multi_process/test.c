#include <stdio.h>
#include <string.h>


int main()
{
    char *p = NULL;
	char buf[100];
	p = buf;
	strcpy(p, "hello mike");
	printf("p = %s\n", p);

    return 0;
}
