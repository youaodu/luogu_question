#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
	return a < b;
}

int main() {
	int n;
	priority_queue<int, vector<int>, greater<int> > nums; 
	cin >> n;
	
	for (int i=1;i <= n;i++){
		int tmp;
		cin >> tmp;
		nums.push(tmp);
	}
	
	int total = 0;
	for (int i=2;i<=n;i++){
		int a = nums.top();
		nums.pop();
		int b = nums.top();
		nums.pop();
		total += a + b;
		nums.push(a+b);
	}	
	
	
	cout << total;
	

	return 0;
}
