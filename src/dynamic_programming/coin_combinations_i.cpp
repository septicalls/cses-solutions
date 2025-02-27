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

    for (int i = 1; i <= x; i++) {
        for (auto c : coins) {
            if (i < c) continue;
            dp[i] += dp[i - c] % 1'000'000'007;
        }
    }

    std::cout << dp[x] % 1'000'000'007 << '\n';

}