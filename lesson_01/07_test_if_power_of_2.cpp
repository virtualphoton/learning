#include <iostream>

using std::cout;

int main() {
    int num;
    std::cin >> num;
    int is_power = 0;
    for (int _ = 0; _ < 32; _ += 1) {
        is_power ^= num;
        num >>= 1;
    }
    cout << ((is_power & 1 and !(num>>31 & 1)) ? "yes":"no");
    return 0;
}
