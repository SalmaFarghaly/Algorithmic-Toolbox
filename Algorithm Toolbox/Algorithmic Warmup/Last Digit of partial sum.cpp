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

int last_digit_of_sum(long long n, vi& cycle) {
    get_fibonacci_cycle(++n, 10, cycle);
    if (cycle.size() > n) {
        return accumulate(cycle.begin(), cycle.begin() + n, 0) % 10;
    }
    int c = accumulate(cycle.begin(), cycle.end(), 0);
    c %= 10;
    c *= (n / cycle.size());
    c %= 10;
    if (n % cycle.size())
        c += accumulate(cycle.begin(), cycle.begin() + n % cycle.size(), 0);
    return c % 10;
}

int main() {
    long long n,m;
    std::cin >> n >> m;
    vi cycle1,cycle2;
    int s1 = last_digit_of_sum(n-1,cycle1);
    int s2 = last_digit_of_sum(m, cycle2);
    if (s2 < s1)
        cout << (s2 + 10 - s1) % 10;
    else
        cout << abs(s2 - s1)% 10;
    return 0;
}