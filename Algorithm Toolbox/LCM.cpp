#include<iostream>
using namespace std;

int gcd(int a, int b) {
	if (b == 0)
		return a;
	a = a % b;
	return gcd(b, a);
}

int main() {
	int a, b;
	cin >> a >> b;
	long long ans = (long long)a * b;
	ans /= gcd(a, b);
	cout << ans;
	return 0;
}