#include <bits/stdc++.h>
using namespace std;
int i;
typedef unsigned long long ull;
typedef long long ll;
ull ans[90];
// from kactl, https://github.com/dtlavendar/kactl/blob/main/content/number-theory/ModPow.h
// https://github.com/dtlavendar/kactl/blob/main/content/number-theory/ModMulLL.h
// https://github.com/dtlavendar/kactl/blob/main/content/number-theory/MillerRabin.h
ull modmul(ull a, ull b, ull M) {
    assert(M >= 1);
    ll ret = a * b - M * ull(1.L / M * a * b);
    return ret + M * (ret < 0) - M * (ret >= (ll)M);
}

ull modpow(ull b, ull e, ull M) {
    assert(M >= 1);
    ull ans=1;
    for(; e; b = modmul(b,b,M),e/=2)
        if(e & 1) ans=modmul(ans,b,M);
    return ans;
}

bool prime(ull n) {
    if (n < 2 || n % 6 % 4 != 1) 
        return (n | 1) == 3;
    ull A[]= {2,325,9375,28178,450775,9780504,1795265022}, s = __builtin_ctzll(n-1), d = n >> s;
    for(ull a : A) {
        ull p=modpow(a%n,d,n),i=s;
        while (p != 1 && p != n - 1 && a % n && i--) {
            assert(n >= 1);
            p=modmul(p,p,n);
        }
        if (p != n-1 && i != s) return 0;
    }
    return 1;
    // works for all 64 bit integers
}
ull gcd(ull x, ull y) {
    return y == 0 ? x : gcd(y, x % y);
}
ull gcd1(ull x, ull y) {
    int k = 1;
    if (!x)
        return y;
    else if (!y)
        return x;
    int p = min(__builtin_ctzll(x), __builtin_ctzll(y)); 
    x >>= p;
    y >>= p;
    while(true) {
        if (x < y)
            swap(x, y);
        x -= y;
        if (!x)
            return y << p;
        x >>= __builtin_ctzll(x);
    }
    return -1;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ull abs(ull v) {
    return v < 0 ? -v : v;
}
ull pollard_rho(ull n, ull c=1) {
    assert(n >= 4);
    assert(c<=n);
    if(n < 4) {
        printf("%llu ", n);
        exit(0);
    }
    auto f=[&](ull x) -> ull { return (modmul(x,x,n)+1); };
    ull x = c, y = c;
    ull d = 1;
    while(d == 1) {
        x = f(x);
        y = f(f(y));
        d = gcd1(abs(x - y), n);
    }
    if (d == n) {
        return pollard_rho(n,c+1);
    } else {
        return d;
    }
}
void factorize(ull num) {
    if(num == 1) {
        assert(false);
        return;
    } else {
        if (prime(num)) {
            assert(i <= 80);
            ans[i++]=num;
        } else {
            while(num % 2 == 0) {
                num /= 2;
                ans[i++]=2;
            }
            ull d = pollard_rho(num);
            assert(d != 0);
            factorize(num / d);
            factorize(d);
        }
    }
}
void solve() {
    ull n;
    scanf("%llu", &n);
    factorize(n);
    printf("# primes: %d\n", i);
    for (int k = 0; k < i; k++) {
        printf("%llu ", ans[k]);
    }
    i = 0;
    memset(ans,0,sizeof ans);
    printf("\n");
}
int main() {
    for (int i = 0; i < 100; i++)
        solve();
}
