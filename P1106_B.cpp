#include "bits/stdc++.h";

using namespace std;

string n;
int k, mark = 0, len, first = 0;

char find_min(int left, int right) {
	char min = n[left];
	mark = left + 1;
	for (int i = mark; i <= right;i++) {
		if (min > n[i]) {
			min = n[i];
			mark = i+1;
		}
	}
	return min;
}

int main() {
	cin >> n >> k;
	len = n.length();
	
	for (int i = 0; i < (len - k); i++) { // len - k 代表留下的数 
		char tmp = find_min(mark, k+i);
		
		if (tmp == '0' && first == 0) {
			continue;
		}
		first = 1;
		cout  << tmp;
	}
	if (first == 0) {
		cout  << 0;
	}
	
	return 0;
}
