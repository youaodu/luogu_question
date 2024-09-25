#include <bits/stdc++.h>
using namespace std;

struct apple {
	int h;
	int tili;
} as[5005];

bool cmp(apple a, apple b) {
	return a.tili < b.tili;
}

int main() {
	int n, tili,g1,g2;
	cin >> n >> tili >> g1 >> g2;
	for(int i =1; i<= n; i++){
		cin >> as[i].h >> as[i].tili;
	}
	
	sort(as + 1, as+n+1, cmp);
	
	g1 += g2;
	int total = 0;
	for (int i = 1; i<=n;i++) {
		if (tili >= as[i].tili && as[i].h <= g1) {
			tili -= as[i].tili;
			total++;
		}
	}
	cout << total;
	
	return 0;
}