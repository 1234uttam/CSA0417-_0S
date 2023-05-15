#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int printOdds() {
    int i;
    for (i = 1; i <= 10; i++) {
        if (i % 2 != 0) {
            printf("Odd: %d\n", i);
        }
    }
}

int printEvens() {
    int i;
    for (i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            printf("Even: %d\n", i);
        }
    }
}

int printMultiplesOf3() {
    int i;
    for (i = 1; i <= 10; i++) {
        if (i % 3 == 0) {
            printf("Multiple of 3: %d\n", i);
        }
    }
}

int printMultiplesOf5() {
    int i;
    for (i = 1; i <= 10; i++) {
        if (i % 5 == 0) {
            printf("Multiple of 5: %d\n", i);
        }
    }
}

int main()
{
  
    printf("%d",printMultiplesOf5());
    printf("%d",printMultiplesOf3());
    printf("%d",printEvens());
    printf("%d",printOdds());
    
}

