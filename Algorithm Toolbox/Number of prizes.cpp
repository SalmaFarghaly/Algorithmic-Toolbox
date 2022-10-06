#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define lp(i,n) for(int i=0;i<n;i++)
#define lp1(i,n) for(int i=1;i<n;i++)

int main() {
	int n;
	cin >> n;
	vi ans;
	int start = 1, rem = n;
	while (rem != 0) {
		if (start < rem - start || rem == start) {
			ans.push_back(start);
			rem -= start;
		} 
		start++;
	}
	cout << ans.size() << endl;
	lp(i, ans.size()) {
		cout << ans[i] << " ";
	}
	return 0;
}