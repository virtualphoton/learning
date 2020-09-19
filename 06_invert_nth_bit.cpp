int main(){
        int num, pos;
        std::cin >> num >> pos;
        std::cout << (num & ~(1 << pos)) << '\n';
}