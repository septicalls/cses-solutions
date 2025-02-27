#include <string>
#include <vector>
#include <iostream>

const int MOD = 1e9 + 7;

int count(std::string& word, std::vector<std::string>& dict, std::size_t index, std::vector<int>& memo) {
    if (index == word.size()) return 1;
    if (memo[index] != -1) return memo[index];

    int ways = 0;

    for (const auto& d : dict) {
        if (word.compare(index, d.size(), d) == 0) {
            ways = (ways + count(word, dict, index + d.size(), memo)) % MOD;
        }
    }

    return memo[index] = ways;
}

int main(void) {

    std::string word;
    std::cin >> word;

    int k;
    std::cin >> k;

    std::vector<std::string> dict(k);

    for (int i = 0; i < k; i++) {
        std::cin >> dict[i];
    }

    std::vector<int> memo(word.size(), -1);
    std::cout << count(word, dict, static_cast<std::size_t>(0), memo) << '\n';

}