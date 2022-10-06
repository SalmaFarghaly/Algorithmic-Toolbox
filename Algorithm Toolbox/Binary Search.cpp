#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> vi;
#define lp(i,n) for(int i=0;i<n;i++)
#define lp1(i,n) for(int i=1;i<n;i++)
#define lpv(v) for(int i=0;i<v.size();i++)

int main() {
	int n,m;
	cin >> n;
	vi sortedArr(n,0);
	lp(i, n) {
		cin >> sortedArr[i];
	}
	cin >> m;
	vi queries(m,0);
	lp(i, m) {
		cin >> queries[i];
	}
	lp(i, m) {
		int lo = 0;
		int hi = n - 1;
		int found = -1;
		while (hi >= lo) {
			int mid = (lo + hi) / 2;
			if (sortedArr[mid] == queries[i]) {
				found = mid;
				break;
			} 
			else if (sortedArr[mid] > queries[i]) {
				hi = mid - 1;
			} 
			else {
				lo = mid + 1;
			}
		}
		cout << found << " ";
	}
	return 0;
}