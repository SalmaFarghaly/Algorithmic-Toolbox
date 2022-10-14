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

int main() {
	// Operations :: +1 , x2 , x3
	int n;
	cin >> n;
	vector <vi> path;
	vi numbers(n + 1, 0);
	path.push_back(vi(1,0));
	path.push_back(vi(1,1));
	int cur = 1;
	for (int i = 2; i <= n; i++) {
		int ans = numeric_limits<int>::max();
		if (i % 2 == 0) {
			ans = numbers[i / 2];
		}
		if (i % 3 == 0) {
			ans = min(ans, numbers[i / 3]);
		}
		numbers[i] = min(ans, numbers[i - 1]);
		if (i % 2 == 0 && numbers[i] == numbers[i / 2]) {
			path.push_back(vi(path[i/2]));
		}
		else if (i % 3 == 0 && numbers[i] == numbers[i / 3]) {
			path.push_back(vi(path[i/3]));
		}
		else {
			path.push_back(vi(path[i-1]));
		}
		path[i].push_back(i);
		numbers[i]++;
	}
	cout << path[n].size() - 1 << endl;
	lpv(path[n]) {
		cout << path[n][i] << " ";
	}
	return 0;
}