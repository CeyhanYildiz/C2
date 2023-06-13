#include <stdio.h>

struct Person {
    char name[64];
    int age;
};

void updateStruct(struct Person *p, int age);


int main(int argc, char **argv)
{
    struct Person lowlevellearning;
    updateStruct(&lowlevellearning , 100);

    return 0;
}

void updateStruct(struct Person *p, int age)
{
    p->age = age;
}