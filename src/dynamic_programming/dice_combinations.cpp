#include <vector>
#include <iostream>

int main(void) {

    int n;
    std::cin >> n;

    std::vector<long> dp{1, 1, 2, 4, 8, 16, 32};

    if (n > 6) {
        for (int i = 7; i <= n; i++) {
            dp.push_back(
               (dp[i - 1] +
                dp[i - 2] +
                dp[i - 3] +
                dp[i - 4] +
                dp[i - 5] +
                dp[i - 6]) % 1'000'000'007
            );
        }
    }

    std::cout << dp[n] % 1'000'000'007 << '\n';

}