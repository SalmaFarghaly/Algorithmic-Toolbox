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
	int n1, n2, t;
	cin >> n1;
	vi vec1(n1, 0);
	lp(i, n1) {
		cin >> vec1[i];
	}
	cin >> n2;
	vi vec2(n2, 0);
	lp(i, n2) {
		cin >> vec2[i];
	}
	vector<vi> matrix(vec2.size() + 1, vi(vec1.size() + 1, 0));

	for (int i = 1; i <= vec2.size(); i++) {
		for (int j = 1; j <= vec1.size(); j++) {
			if (vec2[i - 1] == vec1[j - 1]) {
				matrix[i][j] = 1 + matrix[i-1][j-1];
			} 
			else {
				matrix[i][j] = max(max(matrix[i][j - 1], matrix[i - 1][j]),
					matrix[i - 1][j - 1]);
			}
		}
	}
	cout << matrix[vec2.size()][vec1.size()];
	return 0;
}