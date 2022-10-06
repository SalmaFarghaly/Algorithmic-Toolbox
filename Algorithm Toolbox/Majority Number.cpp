#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
#define lp(i,n) for(int i=0;i<n;i++)
#define lp1(i,n) for(int i=1;i<n;i++)
#define lpv(v) for(int i=0;i<v.size();i++)

int main() {
	int n, m;
	cin >> n;
	vi sortedArr(n, 0);
	lp(i, n) {
		cin >> sortedArr[i];
	}
	sort(sortedArr.begin(), sortedArr.end());

	// We are sure that the most repeated element exist at mid
	// so we want to know what is the elemet at mid and
	// get its first occ and last occ
	int lo = 0;
	int hi = n - 1;
	int lowerbound = (lo + hi) / 2;
	int mostRep = sortedArr[lowerbound];
	while (hi >= lo) {
		int mid = (lo + hi) / 2;
		if (sortedArr[mid] == mostRep) {
			lowerbound = mid;
			hi = mid - 1;
		}
		else if (sortedArr[mid] > mostRep) {
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}

	lo = 0;
	hi = n - 1;
	int upperbound = (lo + hi) / 2;
	while (hi >= lo) {
		int mid = (lo + hi) / 2;
		if (sortedArr[mid] == mostRep) {
			upperbound = mid;
			lo = mid + 1;
		}
		else if (sortedArr[mid] > mostRep) {
			hi = mid - 1;
		}
		else {
			lo = mid + 1;
		}
	}
	cout << (upperbound - lowerbound + 1 > n / 2) ? 1 : 0;
	return 0;
}