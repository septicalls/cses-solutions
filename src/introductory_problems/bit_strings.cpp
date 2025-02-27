#include <iostream>

#define ll long long
#define nl '\n'

const int MOD = 1e9 + 7;

int main(void) {

    ll n;
    std::cin >> n;

    ll result = 1LL, base = 2LL;
    while (n > 0) {
        if (n & 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        n >>= 1;
    }

    std::cout << result << nl;

}
