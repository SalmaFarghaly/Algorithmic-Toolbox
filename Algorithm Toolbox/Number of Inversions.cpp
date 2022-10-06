#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> vi;
#define lp(i,n) for(int i=0;i<n;i++)
#define lp1(i,n) for(int i=1;i<n;i++)
#define lpv(v) for(int i=0;i<v.size();i++)
#define lpvst(o,v) for(int i=o;i<v.size();i++)

vi MergeArrays(const vi A, const vi B, int & ans) {
	vi res(A.size() + B.size());
	int i = 0,j = 0,k = 0;
	while (i < A.size() && j < B.size()) {
		if (A[i] > B[j]) {
			res[k] = B[j];
			ans += A.size() - i;
			j++;
		}
		else {
			res[k] = A[i];
			i++;
		}
		k++;
	}
	for (; i < A.size(); i++) {
		res[k++] = A[i];
	}
	for (; j < B.size(); j++) {
		res[k++] = B[j];
	}
	return res;
}

vi MergeSort(vi vec,int & ans) {
	if (vec.size() == 1)
		return vec;
	int limit = vec.size() / 2;
	vi A = MergeSort(vi(vec.begin(),vec.begin() + limit), ans);
	vi B = MergeSort(vi(vec.begin() + limit , vec.end()), ans);
	vi res = MergeArrays(A,B,ans);
	return res;
}

int main() {
	int n;
	cin >> n;
	vi vec(n,0);
	lp(i, n) {
		cin >> vec[i];
	}
	int ans = 0;
	MergeSort(vec,ans);
	cout << ans;
	return 0;
}