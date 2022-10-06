#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int getMaxNumIdx(const vector<int>& numbers) {
    int maxIdx = -1;
    for (int i = 0; i < numbers.size(); i++)
        maxIdx = (maxIdx == -1 || numbers[maxIdx] < numbers[i]) ? i : maxIdx ;
    return maxIdx;
}

long long MaxPairwiseProductFast(vector<int>& numbers) {
    long long max_product = 0;

    int maxIdx1 = getMaxNumIdx(numbers);
    int num1 = numbers[maxIdx1];
    numbers[maxIdx1] = -1;

    int maxIdx2 = getMaxNumIdx(numbers);
    numbers[maxIdx1] = num1;

    return (long long) numbers[maxIdx1] * numbers[maxIdx2];
}

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                (long long) numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

int main() {
    /*while (true) {
        int n = rand() % 10 + 2;
        vector<int> vec;
        for (int i = 0; i < n; i++)
            vec.push_back(rand() % 100);
        long long res1 = MaxPairwiseProduct(vec);
        long long res2 = MaxPairwiseProductFast(vec);
        cout << n << "\n";
        for (int i = 0; i < n; i++)
            cout << vec[i] << " ";
        cout << "\n";
        if (res1 != res2) {
            cout << "Wrong answer " << res1 << ' ' << res2 << "\n";
        }
        else {
            cout << "OK\n";
        }
    }*/
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    std::cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}
