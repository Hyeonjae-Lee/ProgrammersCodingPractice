/* 2015112119 ÀÌÇöÀç */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

int dp[60003];

int solution(int n) {
	int answer = 0;

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] % 1000000007) + (dp[i - 2] % 1000000007);
		dp[i] %= 1000000007;
	}

	answer = dp[n];
	return answer;
}

int main() {
	solution(4);
}