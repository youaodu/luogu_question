#include "bits/stdc++.h"
using namespace std;


int main () {
	long long n, x, result = 0;
	cin >> n >> x;
	long long data[100005];
	for (int i = 1; i<= n; i++){
		cin >> data[i];
	}
	
	for (int i = 2; i <= n; i++){
		int tmp = (data[i] + data[i - 1]) - x;
		if (tmp > 0) {
			// data i ¹»¼õ¾Í¼õ 
			if (data[i] >= tmp) {
				data[i] -= tmp;
				result += tmp;
				continue;
			}
			tmp -= data[i];
			data[i] = 0; 
			result += data[i];
			data[i-1] -= tmp;
			result += tmp;
		}
	}
	cout << result;
	
	return 0;
}
