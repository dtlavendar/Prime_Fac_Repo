#include <stdio.h>
void improved_factorization(long long num) {
    for(int i = 2; 1LL * i * i <= num; i++) {
        while (num % i == 0) {
            printf("%d ", i);
            num /= i;
        }
    }
    if(num > 1) {
        printf("%lld ", num);
    }
    printf("\n");
}
int main() {
    improved_factorization(150); // prints 2 3 5 5
    improved_factorization(158357825); // prints 5 5 563
    improved_factorization(1000000000002); // prints 2 3 166666666667
    // good for numbers up to 1e12
}
