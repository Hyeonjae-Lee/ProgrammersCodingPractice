#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <string.h>
#include <unordered_set>
#include <queue>

using namespace std;

//dp���� 
//dp[1] = �κй迭 1�� �г�Ƽ �� �ּڰ�
//dp[2] = �κй迭 2�� �г�Ƽ �� �ּڰ�

int arr[3001];
int dp[3002];
int n, k, min1 = 9999999, max1 = 0;
vector<int> vec;

bool check[3001];

int func(int depth) {
	
	if (depth = k) {
		return 0;
	}
	if (dp[depth] != 0) {
		return dp[depth];
	}

	for (int i = 0; i < n; i++) {
		//dp[depth] = max(func(depth + 1))
	}
	

}

int main() {
	
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		max1 = max(max1, arr[i]);
		min1 = min(min1, arr[i]);
	}

	sort(arr, arr + n);
	int answer = 0;
	for (int i = 0; i < k; i++) {
		
	}

	cout << func(0);
}