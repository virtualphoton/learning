#include <iostream>

int main() {
    int num, pos;
    std::cin >> num >> pos;
    std::cout << (num >> pos & 1) << '\n';
    return 0;
}
