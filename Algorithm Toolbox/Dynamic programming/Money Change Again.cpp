#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;

#define lp(i,n) for(int i=0;i<n;i++)
#define lp1(i,n) for(int i=1;i<n;i++)
#define lpv(v) for(int i=0;i<v.size();i++)
#define lpvst(o,v) for(int i=o;i<v.size();i++)

int calDemoniations(int* arr, int n, int money) {
	vi vec(money + 1, 0);
	for (int i = 0; i <= money; i++) {
		int mnm = std::numeric_limits<int>::max();
		bool found = 0;
		for (int j = 0; j < n; j++) {
			if (i >= arr[j]) {
				mnm = min(mnm, vec[i - arr[j]]);
				found = 1;
			}
		}
		if (found)
			vec[i] = mnm + 1;
	}
	return vec[money];
}

int main() {
	int n = 3, money;
	int arr[] = { 1,3,4 };
	cin >> money;
	cout << calDemoniations(arr, n, money);
	return 0;
}