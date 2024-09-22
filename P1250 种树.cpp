#include<bits/stdc++.h>
using namespace std;

struct tree {
	int left;
	int right;
	int t;
} ts[5005];

bool cmp(tree t1, tree t2){
	return t1.right < t2.right;
}

int main() {
	int n, m, total = 0;
	cin >> n >> m;
	int region[n+5];
	for (int i =1;i<=n;i++) region[i]=0;

	for (int i =1;i<= m;i++) {
		cin >> ts[i].left >> ts[i].right >> ts[i].t;
	}

	sort(ts + 1, ts + m + 1, cmp);
	for(int i = 1;i<= m; i++) {
		// 扫描一遍是否有种过的树
		int use = ts[i].t;
		for(int j = ts[j].left; j<= ts[j].right;j++) {
			if (region[j] == 1) {
				use--;
			}
		}
		// 种树
		for(int j= ts[j].right; use > 0; j--) {
			if (region[j] == 1) continue;
			region[j] = 1;
			use--;
			total++;
		} 
	}

	cout << total;

	return 0;
}
