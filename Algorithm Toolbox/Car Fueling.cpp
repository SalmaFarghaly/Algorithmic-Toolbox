#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

#define all(v) ((v).begin()),((v).end())
#define lp(i,n) for(int i=0;i<n;i++)


typedef vector<int> vi;
typedef vector<double> vd;


int main() {
	int d, m,n;
	cin >> d >> m >> n;
	vi stops(n,0);
	lp(i, n) {
		cin >> stops[i];
	}
	stops.push_back(d);
	int ans = 0,cur = 0,tank = m,nxt=0;
	while (nxt <= n) {
		if (stops[nxt] - cur > tank) {
			if (stops[nxt] - cur > m) {
				cout << -1;
				return 0;
			}
			ans++;
			tank = m;
		} 
		tank -= stops[nxt] - cur;
		cur = stops[nxt];
		nxt++;
	}
	cout << ans;
	return 0;
}