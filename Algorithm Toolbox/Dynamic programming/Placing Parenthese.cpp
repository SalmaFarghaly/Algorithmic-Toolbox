#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;

#define lp(i,n) for(int i=0;i<n;i++)
#define lp1(i,n) for(int i=1;i<n;i++)
#define lpv(v) for(int i=0;i<v.size();i++)
#define lpvst(o,v) for(int i=o;i<v.size();i++)

struct node {
	long long mxm = LLONG_MIN;
	long long mnm = LLONG_MAX;
};

void MinAndMax(int i,int j, vector<vector<node>> & matrix,string exp) {
	long long mxm = LLONG_MIN, mnm = LLONG_MAX;
	for (int k = i; k <= j-1 ;k++) {
		switch (exp[2*k + 1]) {
		case '*' :
			mxm = max(mxm, matrix[i][k].mxm * matrix[k+1][j].mxm);
			mxm = max(mxm, matrix[i][k].mxm * matrix[k+1][j].mnm);
			mxm = max(mxm, matrix[i][k].mnm * matrix[k+1][j].mxm);
			mxm = max(mxm, matrix[i][k].mnm * matrix[k+1][j].mnm);

			mnm = min(mnm, matrix[i][k].mxm * matrix[k+1][j].mxm);
			mnm = min(mnm, matrix[i][k].mxm * matrix[k+1][j].mnm);
			mnm = min(mnm, matrix[i][k].mnm * matrix[k+1][j].mxm);
			mnm = min(mnm, matrix[i][k].mnm * matrix[k+1][j].mnm);
			break;
		case '+' :
			mxm = max(mxm, matrix[i][k].mxm + matrix[k+1][j].mxm);
			mxm = max(mxm, matrix[i][k].mxm + matrix[k+1][j].mnm);
			mxm = max(mxm, matrix[i][k].mnm + matrix[k+1][j].mxm);
			mxm = max(mxm, matrix[i][k].mnm + matrix[k+1][j].mnm);

			mnm = min(mnm, matrix[i][k].mxm + matrix[k+1][j].mxm);
			mnm = min(mnm, matrix[i][k].mxm + matrix[k+1][j].mnm);
			mnm = min(mnm, matrix[i][k].mnm + matrix[k+1][j].mxm);
			mnm = min(mnm, matrix[i][k].mnm + matrix[k+1][j].mnm);
			break;

		default :
			mxm = max(mxm, matrix[i][k].mxm - matrix[k+1][j].mxm);
			mxm = max(mxm, matrix[i][k].mxm - matrix[k+1][j].mnm);
			mxm = max(mxm, matrix[i][k].mnm - matrix[k+1][j].mxm);
			mxm = max(mxm, matrix[i][k].mnm - matrix[k+1][j].mnm);

			mnm = min(mnm, matrix[i][k].mxm - matrix[k+1][j].mxm);
			mnm = min(mnm, matrix[i][k].mxm - matrix[k+1][j].mnm);
			mnm = min(mnm, matrix[i][k].mnm - matrix[k+1][j].mxm);
			mnm = min(mnm, matrix[i][k].mnm - matrix[k+1][j].mnm);
			break;
		}
	}
	matrix[i][j].mxm = mxm;
	matrix[i][j].mnm = mnm;
}

int main() {
	string exp;
	cin >> exp;
	int n = (exp.length() + 1) / 2;
	vector<vector<node>> matrix (n,vector<node>(n,node()));
	for (int i = 0,j = 0; i < n; i++,j+=2) {
		matrix[i][i].mxm = exp[j] - '0';
		matrix[i][i].mnm = exp[j] - '0';
	}
	for (int s = 1; s <= n - 1; s++) {
		int i = 0;
		while (i + s < n) {
			MinAndMax(i, i + s, matrix, exp);
			i++;
		}
	}
	cout << matrix[0][n - 1].mxm;
	return 0;
}