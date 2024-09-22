#include "bits/stdc++.h"

using namespace std;


int main() {
	int n;
	int nums[100005];
	cin >> n >> nums[1];
	if (n == 1) {
		cout << nums[1];
		return 0;
	}
	
	int max1 = nums[1];
	int maxIdx = 1;
	for (int i =2; i<= n; i++) {
		cin >> nums[i];
		if (nums[i] > max1) {
			max1 = nums[i];
			maxIdx = i;
		}
	}
	
	int max2 = nums[maxIdx - 2];
	for (int i = maxIdx - 1; i <= maxIdx + 2;i++) {
		if (i == maxIdx || i > n) continue;
		max2 = max(nums[i], max2);
	} 
	
	cout << (max1 * max2);
	return 0;
}
