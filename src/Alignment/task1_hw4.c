#include <stdio.h>

int main() {
    int i;
    char c;
    double d;
    short s;

    
    printf("Size of int: %lu\n", sizeof(i));
    printf("Size of char: %lu\n", sizeof(c));
    printf("Size of double: %lu\n", sizeof(d));
    printf("Size of short: %lu\n", sizeof(s));

    
    printf("Address of int: %p\n", &i);
    printf("Address of char: %p\n", &c);
    printf("Address of double: %p\n", &d);
    printf("Address of short: %p\n", &s);

    return 0;
}


