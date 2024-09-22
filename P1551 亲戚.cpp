#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int n,m,p;

vector<int> nums[5005]; 
string result[5005];

 
 
int main(){

 	cin >> n >> m >> p;
 	for(int i =1;i<= m;i++){
 		int t1,t2;
 		cin >> t1 >> t2;
 		nums[t1].push_back(t1);
 		nums[t2].push_back(t2);
 		nums[t1].push_back(t2);
 		nums[t2].push_back(t1);
	}
	
	
	
	for(int i =1;i<=p;i++){
		int t1,t2;
		cin >> t1 >> t2;
		string flag = "No";
		unordered_set<int> temp;
		for(int j=0;j<nums[t1].size();i++){
			temp.insert(nums[t1][j]);	
		}
		for(int j=0;j<nums[t2].size();i++){
			temp.insert(nums[t2][j]);	
		}
		if (temp.size() == nums[t1].size + nums[t2].size) {
			result[i] = "No";
		} else {
			result[i] = "Yes";
		}
	}
	
 	for (int i=1;i<=p;i++){
		cout << result[i] << endl; 
	}
 	
	return 0;
}
