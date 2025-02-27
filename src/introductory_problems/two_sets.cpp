#include <vector>
#include <numeric>
#include <iostream>
#include <iterator>
#include <algorithm>

#define ll long long
#define nl '\n'

int main(void) {

    ll n;
    std::cin >> n;

    ll sum = n * (n + 1) / 2;

    if (sum % 2) {
        std::cout << "NO\n";
        return 0;
    }

    ll target = sum / 2, running_sum = 0;
    std::vector<ll> set_A, set_B;

    for (ll i = n; i > 0; i--) {
        if (running_sum + i <= target) {
            running_sum += i;
            set_A.push_back(i);
        } else {
            set_B.push_back(i);
        }
    }

    std::cout << "YES\n";
    for (const auto& set : {set_A, set_B}) {
        std::cout << set.size() << nl;
        std::copy(set.begin(), set.end(), std::ostream_iterator<ll>(std::cout, " "));
        std::cout << nl;
    }

}
