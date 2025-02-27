#include <vector>
#include <iostream>

int main(void) {

    int n, x;
    std::cin >> n >> x;

    std::vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        std::cin >> coins[i];
    }

    std::vector<long> dp(x + 1, 0);
    dp[0] = 1;

    for (auto c : coins) {
        for (int i = c; i <= x; i++) {
            dp[i] += dp[i - c] % 1'000'000'007;
        }
    }

    std::cout << dp[x] % 1'000'000'007 << '\n';

}