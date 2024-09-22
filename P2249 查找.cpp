#include <bits/stdc++.h>
using namespace std;

 
struct n1 {
	long long num;
	long long idx;
} ns[1000005];

long long n;
long long m;
long long ms[100005];

bool cmp(n1 a, n1 b) {
	return a.num < b.num;
}

long long binSearch(long long p){
	int l = 1;
	int r = n;
	while(l <= r) {
		int mid = l + (r - l) / 2;
		if (p == ns[mid].num) {
			return ns[mid].idx;
		} else if (p > ns[mid].num) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return -1;
}

int main() {
	
	cin >> n >> m;
	cin >> ns[1].num;
	ns[1].idx=1;
	for(int i = 2;i <= n; i++){
		cin >> ns[i].num;
		if (ns[i].num == ns[i-1].num) {
			ns[i].idx = ns[i-1].idx;
		} else {
			ns[i].idx = i;
		}
	}
	
	for(int i =1; i<=m;i++){
		cin >> ms[i];
	}
	
	for(int i = 1; i<=m; i++){
		cout << binSearch(ms[i]) << " ";
	}
	
	return 0;
}
