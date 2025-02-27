#include <string>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define ll long long
#define nl '\n'

int main(void) {

    std::string s;
    std::cin >> s;

    std::unordered_map<char, std::size_t> freq;
    for (const auto &c : s) {
        freq[c]++;
    }

    std::string odd, prefix;
    int odd_count = 0;

    for (const auto [ch, count] : freq) {
        if (count % 2) {
            odd_count++;
            odd = std::string(count, ch);
        }
    }

    if (odd_count > 1) {
        std::cout << "NO SOLUTION\n";
        return 0;
    }

    for (const auto [ch, count] : freq) {
        if (count % 2) continue;
        prefix += std::string(count / 2, ch);
    }

    std::string reverse(prefix);
    std::reverse(prefix.begin(), prefix.end());
    std::cout << prefix + odd + reverse << nl;

}
