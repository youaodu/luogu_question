#include <bits/stdc++.h>
using namespace std;

int n,p;
int scores[5000005];
int cha[5000005];

bool cmp (int a, int b){
	return a < b;
}

/**
  # 语文成绩

## 题目背景

语文考试结束了，成绩还是一如既往地有问题。

## 题目描述

语文老师总是写错成绩，所以当她修改成绩的时候，总是累得不行。她总是要一遍遍地给某些同学增加分数，又要注意最低分是多少。你能帮帮她吗？

## 输入格式

第一行有两个整数 $n$，$p$，代表学生数与增加分数的次数。

第二行有 $n$ 个数，$a_1 \sim a_n$，代表各个学生的初始成绩。

接下来 $p$ 行，每行有三个数，$x$，$y$，$z$，代表给第 $x$ 个到第 $y$ 个学生每人增加 $z$ 分。

## 输出格式

输出仅一行，代表更改分数后，全班的最低分。

## 样例 #1

### 样例输入 #1

```
3 2
1 1 1
1 2 1
2 3 1
```

### 样例输出 #1

```
2
```

## 提示

对于 $40\%$ 的数据，有 $n \le 10^3$。

对于 $60\%$ 的数据，有 $n \le 10^4$。

对于 $80\%$ 的数据，有 $n \le 10^5$。

对于 $100\%$ 的数据，有 $n \le 5\times 10^6$，$p \le n$，学生初始成绩 $ \le 100$，$z \le 100$。
  */

int main() {
	cin >> n >> p;
	// init score
	for(int i =1;i<= n;i++) {
		cin >> scores[i];
		cha[i] = scores[i] - scores[i - 1];
	}
	
	// 差分数组
	for(int i =1;i<=p;i++){
		int x,y,z;
		cin >> x >> y >> z;
		cha[x] += z;
		if (y + 1 <= n){
			cha[y+1] -= z; 
		}
	}
	
	// 对差分数组做前缀和操作还原原数组，并获得最小值
	int min = 101;
	for(int i=1;i<=n;i++){
		cha[i] += cha[i - 1];
		if (cha[i] < min) {
			min = cha[i];
		}
	}
	
	cout << min;
}
