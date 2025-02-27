#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define LL long long
#define NL '\n'

int main(void) {

    std::string sequence;
    std::cin >> sequence;

    LL count = 0, repetitions = 0;

    for (std::size_t i = 0; i < sequence.size(); i++) {
        count = (sequence[i] == sequence[i - 1]) ? count + 1 : 1;
        repetitions = std::max(repetitions, count);
    }

    std::cout << repetitions << NL;

}