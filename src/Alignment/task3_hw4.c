#include <stdio.h>


struct Struct {
    char a;
    int b;
    double c;
};


#pragma pack(1)
struct PackedStruct1 {
    char a;
    int b;
    double c;
};


#pragma pack(2)
struct PackedStruct2 {
    char a;
    int b;
    double c;
};


#pragma pack(4)
struct PackedStruct4 {
    char a;
    int b;
    double c;
};

#pragma pack() 

int main() {
    struct Struct p;
    struct PackedStruct1 p1;
    struct PackedStruct2 p2;
    struct PackedStruct4 p3;

    printf("Size of Struct (without #pragma pack): %lu\n", sizeof(p));
    printf("Address of p.a: %p\n", &p.a);
    printf("Address of p.b: %p\n", &p.b);
    printf("Address of p.c: %p\n", &p.c);

    printf("\nSize of PackedStruct1 (with #pragma pack(1)): %lu\n", sizeof(p1));
    printf("Address of p1.a: %p\n", &p1.a);
    printf("Address of p1.b: %p\n", &p1.b);
    printf("Address of p1.c: %p\n", &p1.c);

    printf("\nSize of PackedStruct2 (with #pragma pack(2)): %lu\n", sizeof(p2));
    printf("Address of p2.a: %p\n", &p2.a);
    printf("Address of p2.b: %p\n", &p2.b);
    printf("Address of p2.c: %p\n", &p2.c);

    printf("\nSize of PackedStruct4 (with #pragma pack(4)): %lu\n", sizeof(p3));
    printf("Address of p3.a: %p\n", &p3.a);
    printf("Address of p3.b: %p\n", &p3.b);
    printf("Address of p3.c: %p\n", &p3.c);

    return 0;
}

