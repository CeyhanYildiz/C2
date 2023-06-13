
#include <stdio.h>
#include <stdlib.h>

void sayhello()
{
    printf("Hello\n");
}

int main(void) {

    sayhello();

    int x = 0xFEEDBEEF;
    int y;
    void *p = malloc(sizeof(int)); // point to noting ? we just don't know if its char or int

    int *ip = &x;
    //p = ip;
    *ip = 0x00C0FFEE;
    // *p = 0xDEADBEEF; // cant dereafrends 
    *(int*)p = 0xDEADBEEF; //can dereafrends
    printf("sizeof(void*) = %zu\n",sizeof(p));
    printf("sizeof(int*) = %zu\n",sizeof(ip));


    printf(" p --> %p (%x)\n",p, *(int*)p);
    printf(" ip --> %p(%x)\n",ip, *ip);
    free(p);
  return 0;
}
