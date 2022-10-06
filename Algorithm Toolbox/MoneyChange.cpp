#include<iostream>
using namespace std;

int main() {
	int m;
	cin >> m;
	// any number mod 5 depeends only on last digit in number So there is
	// no diff between n mod 10 mod 5 and n mod 5
	cout << (m / 10) + ((m % 10) / 5) + (m % 5);
	return 0;
}