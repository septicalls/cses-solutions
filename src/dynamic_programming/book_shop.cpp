#include <vector>
#include <iostream>

int main(void) {

    int n, x;
    std::cin >> n >> x;

    std::vector<int> prices(n);
    std::vector<int> pages(n);

    for (int i = 0; i < n; i++) {
        std::cin >> prices[i];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> pages[i];
    }

    std::vector<long> dp(x + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = x; j >= prices[i]; j--) {
            dp[j] = std::max(dp[j], pages[i] + dp[j - prices[i]]);
        }
    }

    std::cout << dp[x] << '\n';
}