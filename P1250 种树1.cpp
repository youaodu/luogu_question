#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct node {
	ll left,right,t;
} ts[51234];

bool cmp(node t1, node t2) {
	return t1.left < t2.left;
}
ll n,m,total;
ll region[31234];
int main() {
	cin >> n >> m;
	for (int i =1; i<= m; i++) {
		cin >> ts[i].left >> ts[i].right >> ts[i].t;
	}
	sort(ts + 1, ts + m + 1, cmp);

	for(int i = 1; i<= m; i++) {
		int use = ts[i].t;

		for(int j = ts[i].left; j<= ts[i].right; j++) {
			if (region[j] == 1) {
				use --;
			}

		}

		for(int j= ts[i].right; use > 0; j--) {
			if(region[j] == 1) continue;
			region[j] = 1;
			use--;
			total++;
		}
	}

	cout << total;

	return 0;
}
