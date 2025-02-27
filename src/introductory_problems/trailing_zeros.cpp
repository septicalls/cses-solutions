#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

#define ll long long
#define nl '\n'

int main(void) {

    ll n;
    std::cin >> n;

    ll zeroes = 0, power = 5;

    while (power <= n) {
        zeroes += n / power;
        power *= 5;
    }

    std::cout << zeroes << nl;

}
