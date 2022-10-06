#include <iostream>
using namespace std;

int get_fibonacci_last_digit_fast(long long n,int m) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous % m;
        previous = current % m;
        current = (tmp_previous + current % m) % m;
    }

    return current;
}

int main() {
    long long n;
    int m;
    std::cin >> n >> m;
    int c = get_fibonacci_last_digit_fast(n,m);
    std::cout << c << '\n';
    return 0;
}
