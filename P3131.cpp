#include "bits/stdc++.h"
#include <vector>
using namespace std;

int n;

int main() {
	cin >> n;
	int nums[50005];
	int pres[50005];
	vector<long long> p[10];
	for (int i =1;i<=n;i++){
		cin >> nums[i];
	}
	
	// qiu qian zhui he
	for(int i = 1;i<=n;i++){
		pres[i] = pres[i - 1] + nums[i];
	}
	
	p[0].push_back(0);
	for(int i = 1;i<=n;i++){
		p[pres[i] % 7].push_back(i);
	}
	
	long long res=0;
	for(int i=0;i<7;i++){
		if (p[i].empty()) continue;
		else {
			res = max(res, p[i].back() - p[i].front());			
		}
	}
	
	cout << "" << res;
	return 0;
}
