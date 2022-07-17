#include <stdio.h>

void prime_factorize(int n) {
    for(int i = 2; i <= n; i++) {
        while(n % i == 0) {
            printf("%d ", i);
            n /= i;
        }
    }
    printf("\n");
}

int main() {
    prime_factorize(15);
    // prints: 3 5
    prime_factorize(9931);
    // prints: 9931
    prime_factorize(86825);
    // prints: 5 5 23 151
}
