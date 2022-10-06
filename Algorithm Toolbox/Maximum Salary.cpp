#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> vi;
#define lp(i,n) for(int i=0;i<n;i++)
#define lp1(i,n) for(int i=1;i<n;i++)
#define lpv(v) for(int i=0;i<v.size();i++)

bool isBetter2(int num1, int num2) {
	if (num1 == -1)
		return true;
	string str1 = to_string(num1) + to_string(num2);
	string str2 = to_string(num2) + to_string(num1);
	return str2.compare(str1) > 0;
}

bool isBetter(int num1,int num2) {
	if (num1 == -1)
		return true;
	string str1 = to_string(num1);
	string str2 = to_string(num2);
	lp(i,max(str1.length(), str2.length())) {
		int str1Idx = i % str1.length();
		int str2Idx = i % str2.length();
		if (str1[str1Idx] > str2[str2Idx]) {
			return false;
		} 
		else if (str2[str2Idx] > str1[str1Idx]) {
			return true;
		}
 	}
	return false;
}

int main() {
	int n;
	cin >> n;
	vi num(n, 0);
	lpv(num){
		cin >> num[i];
	}
	string ans;
	while (!num.empty()) {
		int max = -1;
		int idx = 0;
		lpv(num) {
			if (isBetter2(max, num[i])) {
				max = num[i];
				idx = i;
			}
		}
		ans += to_string(max);
		num.erase(num.begin()+idx);
	}
	cout << ans;
	return 0;
}