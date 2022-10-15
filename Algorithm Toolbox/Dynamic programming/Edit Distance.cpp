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
	string str1, str2;
	cin >> str1 >> str2;
	vector<vi> matrix (str2.length()+1, vi (str1.length()+1, 0));

	for (int i = 1; i <= str1.length(); i++)
		matrix[0][i] = matrix[0][i - 1] + 1;
	for (int i = 1; i <= str2.length(); i++)
		matrix[i][0] = matrix[i-1][0] + 1;

	for (int i = 1; i <= str2.length(); i++) {
		for (int j = 1; j <= str1.length(); j++) {
			if (str2[i - 1] == str1[j - 1]) {
				matrix[i][j] = matrix[i - 1][j - 1];
			}
			else {
				matrix[i][j] = 1 + min(min(matrix[i][j - 1], matrix[i - 1][j]),
					matrix[i - 1][j - 1]);
			}
		}
	}
	cout << matrix[str2.length()][str1.length()];
	return 0;
}