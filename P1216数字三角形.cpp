#include <bits/stdc++.h>
using namespace std;

int r;
int table[1005][1005];
long long result[1005][1005];

// 递归方法
int computeMax(int i, int j) {
	// 已经算过的节点就不需要再算一次了。
	if (result[i][j] > -1) {
		return result[i][j];
	}

	// 如果+1大于r的话，代表着已经是最后一行或者最后一列了。
	if (i + 1 > r || j + 1 > r) {
		return table[i][j];
	}

	// 计算左边的值
	int left = computeMax(i + 1, j);
	// 计算右边的值
	int right = computeMax(i + 1, j+1);
	// 将计算过的值缓存下来
	result[i][j] = max(left, right) + table[i][j];
	return result[i][j];
}

int main() {
	cin >> r;
	for(int i =1; i<=r;i++) {
		for (int j=1; j<=i; j++) {
			cin >> table[i][j];
			result[i][j] = -1;
		}
	}
	cout << computeMax(1,1);
	return 0;
}
