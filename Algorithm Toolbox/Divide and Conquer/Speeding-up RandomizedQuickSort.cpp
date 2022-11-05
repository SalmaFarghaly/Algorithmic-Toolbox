#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
#define lp(i,n) for(int i=0;i<n;i++)
#define lp1(i,n) for(int i=1;i<n;i++)
#define lpv(v) for(int i=0;i<v.size();i++)
#define lpvst(o,v) for(int i=o;i<v.size();i++)

pii Partition3(vi & vec,int l,int r) {
	int m1 = l, m2 = l, j= -1,pivot = vec[l];
	for (int i = l + 1; i <= r; i++) {
		if (vec[i] < pivot) {
			swap(vec[m1], vec[i]);
			m2++;
			swap(vec[i],vec[m2]);
			j++;
			m1++;
		}
		else if (vec[i] == pivot) {
			m2++;
			swap(vec[i],vec[m2]);
		}
	}
	return make_pair(m1,m2);
}

void RandomizedQuickSort(vi & vec,int l , int r) {
	if (l >= r)
		return;
	int k = l + (std::rand() % (r - l + 1));
	swap(vec[k],vec[l]);
	pii ans = Partition3(vec,l,r);
	RandomizedQuickSort(vec,l, ans.first - 1);
	RandomizedQuickSort(vec, ans.second +1,r);
}

int main() {
	int n;
	cin >> n;
	vi vec(n, 0);
	lp(i, n) {
		cin >> vec[i];
	}
	RandomizedQuickSort(vec,0,n-1);
	lp(i, n) {
		cout << vec[i] << " ";
	}
	return 0;
}