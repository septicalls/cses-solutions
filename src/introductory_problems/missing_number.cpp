#include <iostream>

int main(void) {

    long long n;
    std::cin >> n;

    long long sum = n * (n + 1) / 2;

    while (n --> 1) {
        int m;
        std::cin >> m;
        sum -= m;
    }

    std::cout << sum << '\n';

}