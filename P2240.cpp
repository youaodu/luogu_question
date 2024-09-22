#include<bits/stdc++.h>

using namespace std;

struct coin {
	int m, v; // m: ����  v: �ܼ�ֵ 
	double avg;
} cs[105];
bool compare(coin c1, coin c2) {
	return c1.avg > c2.avg;
}
int main(){
	int n,t; // n: ���ѽ��   t: ���������� 
	int currentW = 0; // ��ǰ��װ���� 
	double currentR = 0; // ��ǰ�ļ۸� 
	cin >> n >> t;
	// ¼���ҵ����� 
	for (int i = 0; i < n; i++) {
		cin >> cs[i].m >> cs[i].v;
		// ������ѽ�ҵĵ��� �������� 
		cs[i].avg = 1.0 * cs[i].v / cs[i].m;
	}
	// �Խ�ҽ������� 
	sort(cs, cs + n, compare);
	
	for (int i = 0; i < n; i++) {
		if (currentW < t) {
			// ��Ҫװ������ - ��ǰ������ ���ڸöѽ�ҵ���������ζ�ſ���ֱ��װ�� 
			if ((t - currentW) > cs[i].m) {
				currentW += cs[i].m;
				currentR += (0.0 + cs[i].v);
			} else {
				// ��֮װ�����ˣ��Ǿ�ֱ���õ�ǰ�ѵĽ�����������Ϳ��� 
				currentR += (t-currentW) * cs[i].avg;
				break;
			}
		}
		
	}
	printf("%.2f", currentR);
	return 0;
}
