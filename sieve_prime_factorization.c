#include <stdio.h>

int lowest_prime_factor[3000000]; // create an array of say 3 million integers to start off with
void prime_factorize_precomputation(int MAX_LIMIT) {
    for (int i = 2; i <= MAX_LIMIT; i++) {
        if(lowest_prime_factor[i] != 0)
            continue; // not a prime number
        for(int j = i; j <= MAX_LIMIT; j += i) {
            lowest_prime_factor[j] = i;
        }
    }
}


void factorize(int num) {
    while(num > 1) {
        printf("%d ", lowest_prime_factor[num]);
        num /= lowest_prime_factor[num];
    }
    printf("\n");
}
int main() {
    prime_factorize_precomputation(300000);
    factorize(15); // prints: 5 3
    factorize(9932); // prints: 191 13 2 2
    factorize(815); // prints: 163 5
    factorize(9931); // prints: 9931
}
