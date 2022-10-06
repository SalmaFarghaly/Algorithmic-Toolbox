#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

typedef vector<int> vi;
typedef vector<int>::iterator vecIt;

void get_fibonacci_cycle(long long n, int m, vi& cycle) {
    cycle.push_back(0);
    cycle.push_back(1);

    if (n <= 1)
        return;

    int previous = 0;
    int current = 1;
    vector<int> tempCycle;
    bool foundCycle = 0, checkCycle = 0;
    int numChecks = 2, validChecks = 0;
    int i = 2;
    while (validChecks != numChecks && i <= n) {
        int tmp_previous = previous % m;
        previous = current % m;
        current = (tmp_previous + current % m) % m;
        if (checkCycle) {
            tempCycle.push_back(current);
            if (current == cycle[i % cycle.size()])
                validChecks++;
            else {
                validChecks = 0;
                checkCycle = 0;
                cycle.insert(cycle.end(), tempCycle.begin(), tempCycle.end());
                tempCycle.clear();
            }
        }
        else if (current == 0) {
            checkCycle = 1;
            numChecks = cycle.size() - 1;
            tempCycle.push_back(current);
        }
        else {
            cycle.push_back(current);
        }
        i++;
    }

    return;
}

int last_digit_of_fib(long long n, vi& cycle) {
    get_fibonacci_cycle(n, 10, cycle);
    return cycle[n%cycle.size()] ;
}

int main() {
    long long n, m;
    std::cin >> n;
    vi cycle1, cycle2;
    int s1 = last_digit_of_fib(n, cycle1);
    int s2 = cycle1[(n-1)%cycle1.size()];
    int ans = ((s1 + s2) % 10)* s1;
    cout << ans % 10;
    return 0;
}