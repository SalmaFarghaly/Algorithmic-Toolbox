#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

#define all(v) ((v).begin()),((v).end())
#define lp(i,n) for(int i=0;i<n;i++)


typedef vector<int> vi;
typedef vector<double> vd;

struct obj{
	int cost;
	int weight;

	obj(int c, int w) {
		cost = c;
		weight = w;
	}

	// less than operator,
	bool operator< (const obj &other) const {
		return cost < other.cost;
	}
};

int most_exp(vd& exp) {
	int idx = 0;
	lp(i, exp.size()) {
		if (exp[idx] < exp[i])
			idx = i;
	}
	return (exp[idx] == -1) ? -1 : idx;
}

int main() {
	int n, cap;
	cin >> n >> cap;
	vector<obj> objs;
	vd exp;
	lp(i, n) {
		int c, w;
		cin >> c >> w;
		obj o(c,w);
		objs.push_back(o);
		exp.push_back((double)c / w);
	}
	int t = 0,idx = most_exp(exp);
	double value = 0;
	while (t < cap && idx != -1) {
		int temp = min(cap - t, objs[idx].weight);
		t += temp;
		value += (double)objs[idx].cost * temp / (double)objs[idx].weight;
		exp[idx] = -1;
		idx = most_exp(exp);

	}
	std::cout << std::fixed;
	std::cout << std::setprecision(4);
	cout << value;
	return 0;
}