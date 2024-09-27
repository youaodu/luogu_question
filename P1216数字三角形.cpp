#include <bits/stdc++.h>
using namespace std;

int r;
int table[1005][1005];
long long result[1005][1005];

int computeMax(int i, int j) {
	if (result[i][j] > -1) {
		return result[i][j];
	}
	if (i + 1 > r || j + 1 > r) {
		return table[i][j];
	}
	int left = computeMax(i + 1, j);
	int right = computeMax(i + 1, j+1);
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