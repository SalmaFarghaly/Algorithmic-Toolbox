#include <iostream>
#include<vector>
using namespace std;

int get_fibonacci_last_digit_fast(long long n, int m) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current = 1;
    vector<int> cycle,tempCycle;
    cycle.push_back(0);
    cycle.push_back(1);
    bool foundCycle = 0,checkCycle=0;
    int numChecks = 2,validChecks = 0;
    int i = 2;
    while(validChecks != numChecks && i<=n) {
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
                cycle.insert(cycle.end(), tempCycle.begin(),tempCycle.end());
                tempCycle.clear();
            }
        }
        else if(current == 0) {
            checkCycle = 1;
            numChecks = cycle.size() - 1;
            tempCycle.push_back(current);
        }
        else {
            cycle.push_back(current);
        }
        i++;
    }

    return cycle[n%cycle.size()];
}

int main() {
    long long n;
    int m;
    std::cin >> n >> m;
    int c = get_fibonacci_last_digit_fast(n, m);
    std::cout << c << '\n';
    return 0;
}
