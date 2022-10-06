#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <numeric>
using namespace std;

#define all(v) ((v).begin()),((v).end())
#define lp(i,n) for(int i=0;i<n;i++)

typedef vector<long long> vi;

int main() {
	int n;
	cin >> n;
	vi prices(n,0);
	vi clicks(n,0);
	lp(i, n) { cin >> prices[i]; }
	lp(i, n) { cin >> clicks[i]; }
	sort(all(prices));
	sort(all(clicks));
	long long temp = 0;
	long long ans = inner_product(all(prices),clicks.begin(),temp);
	cout << ans;
	return 0;
}