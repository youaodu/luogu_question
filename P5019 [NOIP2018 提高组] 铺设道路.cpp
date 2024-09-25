#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, nums[100005];
	
	cin >> n;
	for(int i =1;i<= n;i++) {
		cin >> nums[i]; 
	}
	
	int total = nums[1];
	for (int i =2;i <= n;i++) {
		if (nums[i] > nums[i -1]) {
			total += nums[i] - nums[i - 1];
		}
	}
	
	cout << total;
	
	return 0;
}