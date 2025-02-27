#include <iostream>

int main(void) {

    long n;
    std::cin >> n;

    std::cout << n;

    while (n > 1) {
        n = (n % 2) ? (n * 3) + 1 : n / 2;
        std::cout << ' ' << n;
    }

    std::cout << '\n';

}