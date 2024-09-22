#include "bits/stdc++.h"
using namespace std;
int n,k;
long long nums[1000005];
long long pres[1000005];
int main() {
	cin >> n >> k;
	for(int i=2;i<=n;i++){
		cin >> nums[i];
	}
	for(int i =2;i<=n;i++) {
		pres[i] = nums[i] + pres[i - 1];
	}
	long long m = 0;
	for(int i = 1; i<= n;i++) {
		m = max(pres[i+k] - pres[i], m);
	}
	cout << pres[n] - m;

	return 0;
}
