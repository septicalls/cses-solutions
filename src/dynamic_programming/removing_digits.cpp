#include <iostream>

int main(void) {

    int n, count = 0;
    std::cin >> n;

    while (n > 0) {
        int m = n, max = 0;

        while (m > 0) {
            max = std::max(max, m % 10);
            m /= 10;
        }

        n -= max;
        count++;
    }

    std::cout << count << '\n';

}