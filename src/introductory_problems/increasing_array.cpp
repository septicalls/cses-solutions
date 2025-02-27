#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

#define ll long long
#define nl '\n'

int main(void) {

    int n;
    std::cin >> n;

    std::vector<ll> nums(n);
    for (std::size_t i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    ll moves = 0;

    for (std::size_t i = 1; i < n; i++) {
        if (nums[i] < nums[i - 1]) {
            moves += nums[i - 1] - nums[i];
            nums[i] = nums[i - 1];
        }
    }

    std::cout << moves << nl;

}