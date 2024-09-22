#include<bits/stdc++.h>

using namespace std;

struct coin {
	int m, v; // m: 重量  v: 总价值 
	double avg;
} cs[105];
bool compare(coin c1, coin c2) {
	return c1.avg > c2.avg;
}
int main(){
	int n,t; // n: 几堆金币   t: 背包总容量 
	int currentW = 0; // 当前已装重量 
	double currentR = 0; // 当前的价格 
	cin >> n >> t;
	// 录入金币的容量 
	for (int i = 0; i < n; i++) {
		cin >> cs[i].m >> cs[i].v;
		// 计算这堆金币的单价 用于排序 
		cs[i].avg = 1.0 * cs[i].v / cs[i].m;
	}
	// 对金币进行排序 
	sort(cs, cs + n, compare);
	
	for (int i = 0; i < n; i++) {
		if (currentW < t) {
			// 需要装的容量 - 当前的容量 大于该堆金币的总重量意味着可以直接装。 
			if ((t - currentW) > cs[i].m) {
				currentW += cs[i].m;
				currentR += (0.0 + cs[i].v);
			} else {
				// 反之装不下了，那就直接用当前堆的金币填满背包就可以 
				currentR += (t-currentW) * cs[i].avg;
				break;
			}
		}
		
	}
	printf("%.2f", currentR);
	return 0;
}
