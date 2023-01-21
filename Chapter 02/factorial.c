#include <stdio.h>

int factorial_re(n) {
    if (n == 1) {
        return 1;
    }else {
        return n * factorial_re(n-1);
    }
}

int factorial(n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main(void) {
    int n = 10;
    printf("%d\n", factorial_re(n));
    printf("%d\n", factorial(n));
    
    return 0;
}