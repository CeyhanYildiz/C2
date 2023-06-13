#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char *heapMemory = malloc(100);

    if (NULL == heapMemory) {
        perror("malloc failed bruh");
    }
    
    return 0;
}