#include <vector>
#include <iostream>

int main(void) {

    int n, x;
    std::cin >> n >> x;

    std::vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        std::cin >> coins[i];
    }

    std::vector<int> dp(x + 1, x + 1);
    dp[0] = 0;

    for (int i = 1; i <= x; i++) {
        for (auto c : coins) {
            if (i < c) continue;
            dp[i] = std::min(dp[i], dp[i - c] + 1);
        }
    }

    if (dp[x] == x + 1) dp[x] = -1;
    std::cout << dp[x] << '\n';

}