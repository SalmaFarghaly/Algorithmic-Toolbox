#include <iostream>
using namespace std;
#include <vector>
#include <utility>
#include <algorithm>

typedef vector<pair<int,int>> vpii;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define lp(i,n) for(int i=0;i<n;i++)
#define lp1(i,n) for(int i=1;i<n;i++)

int main() {
	int n;
	cin >> n;
	vpii segments;
	lp(i,n){
		int x, y;
		cin >> x >> y;
		segments.push_back(pii(x,y));
	}
	// comparison that returns true if first is less than second
	sort(segments.begin(), segments.end(), [](pii const& pr1, pii const& pr2)
		{ return pr2.second > pr1.second; });
	vi ans;
	int point = segments[0].second;
	ans.push_back(point);
	lp1(i, n) {
		if (point < segments[i].first) {
			point = segments[i].second;
			ans.push_back(point);
		}
	}
	cout << ans.size() << endl;
	lp(i, ans.size())
		cout << ans[i] << " ";
	return 0;
}