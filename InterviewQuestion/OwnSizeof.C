#include <stdio.h>

/* my sizeof won't work(won't compile itself for data types (int, float, char, double)
 1, 2, 2.3, 'A'
 or a + b, 2 + 3
 Own sizeof will work for only variables */ 

#define mySizeof(type) ((char *)(&type + 1) - (char *)(&type))

int main() {
    int a = 4;
    printf("Size: %d\n", mySizeof(a));
    return 0;
}
