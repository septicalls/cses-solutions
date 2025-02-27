#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

#define ll long long
#define nl '\n'

int main(void) {

    ll n;
    std::cin >> n;

    for (ll i = 0; i < n; i++) {
        ll a, b;
        std::cin >> a >> b;

        if ((a + b) % 3 == 0 && std::min(a, b) >= std::max(a, b) / 2) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

}
