#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

#define ll long long
#define nl '\n'

int main(void) {

    ll n;
    std::cin >> n;

    std::vector<ll> nums(n);
    for (ll i = 0LL; i < n; i++) {
        std::cin >> nums[i];
    }

    std::sort(nums.begin(), nums.end());

}
