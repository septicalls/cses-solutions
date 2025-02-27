#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

#define ll long long
#define nl '\n'

int main(void) {

    ll n;
    std::cin >> n;

    if (n == 1) {
        std::cout << "1" << nl;
        return 0;
    } else if (n < 4) {
        std::cout << "NO SOLUTION" << nl;
        return 0;
    }

    ll i = 2;

    while (i <= n) {
        std::cout << i << ' ';
        i += 2;
    }

    i = 1;

    while (i <= n) {
        std::cout << i << ' ';
        i += 2;
    }

    std::cout << nl;

}
