#include <stdio.h>

struct Str1 {
    char a;
    int b;
    double c;
};

struct Str2 {
    double c;
    int b;
    char a;
};

int main() {
    struct Str1 s1;
    struct Str2 s2;

    
    printf("Size of Str1: %lu\n", sizeof(s1));
    printf("Address of s1.a: %p\n", &s1.a);
    printf("Address of s1.b: %p\n", &s1.b);
    printf("Address of s1.c: %p\n", &s1.c);

    
    printf("Size of Str2: %lu\n", sizeof(s2));
    printf("Address of s2.c: %p\n", &s2.c);
    printf("Address of s2.b: %p\n", &s2.b);
    printf("Address of s2.a: %p\n", &s2.a);

    return 0;
}

