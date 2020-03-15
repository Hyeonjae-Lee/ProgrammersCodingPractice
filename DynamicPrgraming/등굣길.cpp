#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[102][102];

int x, y;

bool check(int a, int b) {
	return (a > 0 && b > 0 && a <= y && b <= x);
}

int solution(int m, int n, vector<vector<int>> puddles) {
	int answer = 0;
	for (int i = 0; i < puddles.size(); i++) dp[puddles[i][1]][puddles[i][0]] = -1;
	
	x = m;
	y = n;
	dp[1][1] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (dp[i][j] != -1) {
				if (check(i, j + 1) && dp[i][j + 1] > -1) {
					dp[i][j + 1] += dp[i][j];
					dp[i][j + 1] %= 1000000007;
				}
				if (check(i + 1, j) && dp[i + 1][j] > -1) {
					dp[i + 1][j] += dp[i][j];
					dp[i][j + 1] %= 1000000007;
				}
			}
		}
	}

	answer += dp[n][m];

	return answer;
}


int main() {
	vector<vector<int>> puddles = { {2,2} };
	solution(4, 3,  puddles);
}