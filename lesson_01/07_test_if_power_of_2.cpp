#include <iostream>

using std::cout;

int main() {
    int num;
    std::cin >> num;
    num = num & (num-1);
    std::cout << (num? "no":"yes");
    return 0;
}
