/* 2015112119 ÀÌÇöÀç */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>
#include <bitset>
#include <string.h>

using namespace std; 

int dp[100004];

int solution(int n, vector<int> money) {
	int answer = 0;

	for (int k = money[0]; k <= n; k+=money[0]) {
		dp[k] = 1;
	}

	dp[0] = 1;

	
	for (int i = 1; i < money.size(); i++) {
		for (int k = 0; k <= n; k++) {
			if (k >= money[i]) {
				dp[k] += (dp[k - money[i]]);
				dp[k] % 1000000007;
			}
		}
	}

	answer = dp[n];

	return answer;
}

int main() {
	vector<int> money = { 1,2,5 };
	int n = 5;

	solution(n, money);
}