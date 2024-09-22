#include <bits/stdc++.h>
using namespace std;

struct game{
	int left;
	int right;
} gs[1000005];

bool cmp(game a, game b) {
	return a.right < b.right;
}

int main() {
	int n, total=0;
	cin >> n;
	
	for(int i =1;i<=n;i++){
		cin >> gs[i].left >> gs[i].right;
	}
	
	sort(gs + 1, gs+n+1, cmp);
	
	int ct = -1;
	for (int i =1; i<= n;i++){
		if (gs[i].left >= ct) {
			ct = gs[i].right;
			total++;
		}
	}
	
	cout << total;
	return 0;
}
