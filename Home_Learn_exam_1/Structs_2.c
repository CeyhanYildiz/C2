#include <stdio.h>
#include <string.h>

#include <stdlib.h>
//  Student :
//      - name (string)
//      - id (string)
//      - age (int)
//      - grades (int array)

typedef struct  
{
    char name[50];
    char id[10];
    int age;
    int grades[5];
} Student ;

typedef struct 
{
    int x;
    int y;
} Point;

typedef struct
{
    int *array;
} Data;

void printf_student(Student student);

// void printf_points(Points points [10]);
void printf_points(Point points []);
// void printf_points(Points *points );



int main (void)
{
    // struct Student kevin; ( zonder typedef)
    Student kevin;
    
    strcpy(kevin.name, "Kevin");
    strcpy(kevin.id, "000123123");
    kevin.age = 40;
    kevin.grades[1] = 1;
    kevin.grades[1] = 2;
    kevin.grades[1] = 3;
    kevin.grades[1] = 4;
    kevin.grades[1] = 5;


    printf_student(kevin);

    Point p1 = {5, 10};
    Point p2 = 
    {   
        .y = 8,
        .x = 2
    };


    printf("p1.x ; %d\n",p1.x);
    printf("p1.y ; %d\n",p1.y);

    printf("p2.x ; %d\n",p2.x);
    printf("p2.y ; %d\n",p2.y);
    
    p1 = p2; // Memory copy

    printf("p1.x ; %d\n",p1.x);
    printf("p1.y ; %d\n",p1.y);

    Point points[10];

    for (int i = 0; i < 10; i++)
    {
        points[i].x = i;
        points[i].x = 10 - i;
    }

    printf_points(points);

    Data x;
    Data y;

    x.array = malloc(sizeof(int) * 5);
    y.array = malloc(sizeof(int)* 5);

    x.array[0] = 1;
    x.array[1] = 2;
    x.array[2] = 3;
    x.array[3] = 4;
    x.array[4] = 5;

    y.array[0] = 9;
    y.array[1] = 9;
    y.array[2] = 9;
    x.array[3] = 9;
    y.array[4] = 9;


    x = y; // to Pointer to the same array that  y is pointing 

        for ( int i = 0 ; i < 10 ; i++)
        {
            printf("x.array[%d] = %d\n", i , x.array[i] );
        }

        x.array[0] = 10;  //  y.array[0] = 10;

        for ( int i = 0 ; i < 10 ; i++)
        {
            printf("x.array[%d] = %d\n", i , y.array[i] );  // y.array[0] = 10;
        }

    return 0;
}

void printf_student(Student student)
{
    printf("Name: %s\n", student.name);
    printf("ID: %s\n", student.id);
    printf("Age: %d\n", student.age);
    printf("Grades: ");
    for ( int i = 0 ; i < 5; i++)
    {
        printf("%d ",student.grades[i]);
    }
    printf("\n");
}

void printf_points(Point points [])
{
    for ( int i = 0; i < 10 ; i++)
    {
        printf("p%d = (%d,%d)\n", i , points[i].x, points[i].y );
    }
}