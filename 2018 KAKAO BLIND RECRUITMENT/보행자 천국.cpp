/* 2015112119 이현재 */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

int MOD = 20170805;

pair<int, int> dp[505][505];
int directionCheck[505][505];

struct direction {
	int x = 0;
	int y = 0;
	int direc = 0;
};

int M, N;

bool checkRange(int a, int b) {
	return (a < M && b < N && a >= 0 && b >= 0);
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
	int answer = 0;
	N = n;
	M = m;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {

			dp[i][j].first %= 20170805;

			if (dp[i][j].second == 0 && i ==0 && j == 0) {

				if (checkRange(i, j + 1)) {
					dp[i][j + 1].first = dp[i][j].first + 1;
					dp[i][j + 1].second = 1;
				}if (checkRange(i + 1, j)) {
					dp[i + 1][j].first = dp[i][j].first + 1;
					dp[i + 1][j].second = -1;
				}

			}
			else {

				if (city_map[i][j] == 0) { // 0이면 어느 방향에라도 갈수있다.
					if (checkRange(i, j + 1) && city_map[i][j + 1] != 1 ) {

						// i + 1에서 더 갈수있는지 확인해야한다.
						if (city_map[i][j + 1] == 2 && checkRange(i, j + 2)) { // 2이고 
							dp[i][j + 1].first = max(dp[i][j].first, dp[i][j + 1].first);
							dp[i][j + 1].second = 1;
						}
						if (city_map[i][j + 1] == 0) {
							dp[i ][j + 1].first = dp[i][j].first + dp[i ][j + 1].first;
							dp[i ][j + 1].second = 1;
						}

					}
					if (checkRange(i + 1, j) && city_map[i + 1][j] != 1) {

						// i + 1에서 더 갈수있는지 확인해야한다.
						if (city_map[i + 1][j] == 2 && checkRange(i + 2, j) ) { // 2이고 
							dp[i + 1][j].first = max(dp[i][j].first, dp[i + 1][j].first);
							dp[i + 1][j].second = -1;
						}
						if (city_map[i + 1][j] == 0) {
							dp[i + 1][j].first = dp[i][j].first + dp[i + 1][j].first;
							dp[i + 1][j].second = -1;
						}
					}
				}
				else if (city_map[i][j] == 2) {// 2이면 특정 방향만 갈수있다.
					if (dp[i][j].second == 1) { // 왼족에서 왔다는거니까 오른족만 가능
						if (checkRange(i, j + 1) && city_map[i][j + 1] != 1) {

							// i + 1에서 더 갈수있는지 확인해야한다.
							if (city_map[i][j + 1] == 2 && checkRange(i, j + 2)) { // 2이고 
								dp[i][j + 1].first = max(dp[i][j].first, dp[i][j + 1].first);
								dp[i][j + 1].second = 1;
							}
							if (city_map[i][j + 1] == 0) {
								dp[i][j + 1].first = dp[i][j].first + dp[i][j + 1].first;
								dp[i][j + 1].second = 1;
							}
						}
					}
					else if (dp[i][j].second == -1) { //위쪽에서 왔다니까 아래쪽만 가능
						if (checkRange(i + 1, j) && city_map[i + 1][j] != 1) {

							// i + 1에서 더 갈수있는지 확인해야한다.
							if (city_map[i + 1][j] == 2 && checkRange(i + 2, j)) { // 2이고 
								dp[i + 1][j].first = max(dp[i][j].first, dp[i + 1][j].first);
								dp[i + 1][j].second = -1;
							}
							if (city_map[i + 1][j] == 0) {
								dp[i + 1][j].first = dp[i][j].first + dp[i + 1][j].first;
								dp[i + 1][j].second = -1;
							}

						}
					}
				}
			}
		}
	}

	answer = dp[m - 1][n - 1].first;

	return answer;
}

int main() {
	vector<vector<int>> city_map = { {0,2,0,0,0,2}, {0,0,2,0,1,0},{1,0,0,2,2,0} };
	//vector<vector<int>> city_map = { {0,0,0}, {0,0,0},{0,0,0} };
	solution(3, 6, city_map);
}