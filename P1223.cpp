#include "bits/stdc++.h"
using namespace std;

struct people{
	int time;
	int idx;
} ps[1005];

bool cmp(people a, people b){
	return a.time < b.time;
}

int main() {
	int n;
	long long totalTime = 0;
	cin >> n;
	for(int i = 1;i<=n;i++) {
		cin >> ps[i].time;
		ps[i].idx = i;
	}
	
	sort(ps + 1, ps+n+1,cmp);
	
	for (int i = 1;i<=n;i++){
		cout << ps[i].idx << " ";
		totalTime += ((n - i) * ps[i].time);
	}
	cout << endl;
	printf("%.2f", (0.0 + totalTime) / n);
	return  0;
}
