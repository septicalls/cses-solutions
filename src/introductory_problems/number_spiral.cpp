#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

#define ll long long
#define nl '\n'

int main(void) {

    ll n;
    std::cin >> n;

    while (n --> 0) {
        ll x, y;
        std::cin >> x >> y;

        auto max{std::max(x, y)};
        auto diagonal{max * (max - 1) + 1};
        auto offset{(y - x) * ((max % 2 == 0) ? -1 : 1)};
        std::cout << diagonal + offset << nl;
    }

}
