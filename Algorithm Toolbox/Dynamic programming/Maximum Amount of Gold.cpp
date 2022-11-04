#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>
using namespace std;

typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<int>> vii;
typedef pair<int, int> pii;

#define lp(i,n) for(int i=0;i<n;i++)
#define lp1(i,n) for(int i=1;i<n;i++)
#define lpv(v) for(int i=0;i<v.size();i++)
#define lpvst(o,v) for(int i=o;i<v.size();i++)

int main() {
	int w,n;
	cin >> w >> n;
	vi golds(n, 0);
	lpv(golds) {
		cin >> golds[i];
	}
	vii table(n+1,vi(w+1,0));
	for (int i = 1; i <= w; i++) {
		for (int j = 1; j <= n; j++) {
			table[j][i] = table[j-1][i];
			if (golds[j-1] <= i) {
				table[j][i] = max(table[j][i],golds[j-1] + table[j - 1][i - golds[j - 1]]);
			}
		}
	}
	cout << table[n][w];
	return 0;
}