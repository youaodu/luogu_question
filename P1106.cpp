#include "bits/stdc++.h";
using namespace std;

bool compare(int a, int b) {
	return a < b;
}

int main() {
	string num;
	int del;
	cin >> num >> del;
	
	// 转换为数字数组
	int nums[num.length()];
	int result[num.length()];
	int resultIdx = 1;
	for(int i = 0; i < num.length(); i++) {
		nums[i] = num[i] + '0';
		result[i] = -1;
	}
	
	// 在有限的位置寻找最小的数
	int min = ~(1 << 31), minIdx = -1;
	for(int i =0;i < del;i++) {
		if (nums[i] < min) {
			minIdx = i;
			min = nums[i];
			result[0] = nums[i];
		}
	}
	
	del -= (minIdx + 1);
	while (del > 0) {
		int max = -1;
		int maxIdx = -1;
		for (int i = (minIdx + 1); i < num.length() - (minIdx + 1); i++) {
			if (nums[i] > max) {
				max = nums[i];
				maxIdx = i;
			} 
		}
		result[resultIdx] = nums[maxIdx];
		resultIdx++;
	}
	
	// 转换整数
	int tmp = 0;
	int mul = 1;
	for (int i =0; i < (resultIdx + 1); i++) {
		tmp += result[i] * mul;
		mul *= 10;
	} 
	
	cout << "" << tmp;
	return 0;
}
