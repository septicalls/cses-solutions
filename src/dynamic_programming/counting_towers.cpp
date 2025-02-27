#include <vector>
#include <iostream>

#define MAX_HEIGHT (1'000'000 + 1)
const int MOD = 1e9 + 7;

int main() {
    int t;
    std::cin >> t;

    std::vector<int> tests(t);
    for (int i = 0; i < t; i++) {
        std::cin >> tests[i];
    }

    std::vector<std::vector<long>> dp(2, std::vector<long> (MAX_HEIGHT, 0));
    dp[0][1] = 1L;
    dp[1][1] = 1L;

    for (int i = 2; i <= MAX_HEIGHT; i++) {
        dp[0][i] = (2 * dp[0][i - 1] + dp[1][i - 1]) % MOD;
        dp[1][i] = (4 * dp[1][i - 1] + dp[0][i - 1]) % MOD;
    }

    for (const auto n : tests) {
        std::cout << (dp[0][n] + dp[1][n]) % MOD << '\n';
    }

    return 0;
}
