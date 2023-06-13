#include <stdio.h>
#include <string.h>

int main() {
    char source[] = "Hello, World!";
    char destination[20];

    // Copy the contents of source to destination
    memcpy(destination, source, strlen(source) + 1);

    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
}