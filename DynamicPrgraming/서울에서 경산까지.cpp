#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int dp[103];
int checktime = 0;
vector <pair<int, int>> vec(102);
vector<vector<int>> trav;
int sizea;

int answer1 = 0;

int solve(int a, int time) {

	if (a == sizea) return 0;
	if (time <= 0) return -9999;
	if (dp[a] != -1) return dp[a];

	int& check = dp[a];

	if (time >= trav[a][0] && solve(a + 1, time - trav[a][0]) != -99999) {
		check = max(check, solve(a + 1, time - trav[a][0]) + trav[a][1]);
	}
	if (time >= trav[a][2] && solve(a + 1, time - trav[a][2]) != -99999) {
		check = max(check, solve(a + 1, time - trav[a][2]) + trav[a][3]);
	}

	return check;
}

int dp1[100][100001];
int walk[100][2];
int cycle[100][2];
int N, K;

int go(int a, int timeleft) {
	if (a == N) return 0;
	if (timeleft <= 0) return -9999;

	int& check = dp1[a][timeleft];
	if (check != -1) return check;

	check = -9999;
	if (timeleft >= trav[a][0] && go(a + 1, timeleft - trav[a][0]) != -9999) {
		check = max(check, go(a + 1, timeleft - trav[a][0]) + trav[a][1]);
	}
	if (timeleft >= trav[a][2] && go(a + 1, timeleft - trav[a][2]) != -9999) {
		check = max(check, go(a + 1, timeleft - trav[a][2]) + trav[a][3]);
	}

	return check;
}

int solution(int k, vector<vector<int>> travel) {
	int answer = 0;
	trav = travel;
	sizea = travel.size();
	memset(dp, -1, sizeof(dp));
	checktime = k;

	answer = go(0, k);

	return answer;
}

int main() {
	int K = 3000;
	vector<vector<int>> travel = { {1000,2000,300,700}, {1100,1900,400,900}, {900,1800,400,700}, {1200,2300,500,1200} };
	memset(dp1, -1, sizeof(dp1));
	N = travel.size();
	cout << solution(K, travel)<<endl;
	//cout << go(0, K);
}