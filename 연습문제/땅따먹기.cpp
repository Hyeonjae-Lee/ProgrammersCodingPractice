#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;

vector<vector<int> > land2;

int dfs(int depth, int a, int sum) {//a´Â ¿­
	
	if (depth >= land2.size()) {
		return sum;
	}

	int answer = 0;

	for (int i = 0; i < 4; i++) {
		if (i != a) {
			answer = max(answer, dfs(depth + 1, i, sum + land2[depth][a]));
		}
	}

	return answer;
}

int dp[100001][4];

int solution(vector<vector<int>> land)
{
	land2 = land;
	int answer = 0;

	for (int j = 0; j < 4; j++) {
		dp[0][j] = land[0][j];
	}
	 
	for (int i = 0; i < land.size()-1; i++) {
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				if(k != j) dp[i + 1][k] = max(dp[i][j] + land[i + 1][k], dp[i + 1][k]);
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		answer = max(answer, dp[land.size() - 1][i]);
	}

	return answer;
}

int main() {
	
	vector<vector<int>> land = { {1,2,3,5},{5,6,7,8},{4,3,2,1} };
	//vector<vector<int>> land = { {9,5,2,3}, {9,8,6,7}, {8,9,7,1}, {100,9,8,1} };
	cout << solution(land);

}