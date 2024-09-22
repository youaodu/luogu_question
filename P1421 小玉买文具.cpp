#include <bits/stdc++.h>
using namespace std;

int main() {
	string a,b;
	cin >> a >> b;
	string combinedStr = a+b; 
	int result = 0;
    istringstream iss(combinedStr);
    iss >> result;
	
	cout << result / 19 << "";
	return 0;
}
