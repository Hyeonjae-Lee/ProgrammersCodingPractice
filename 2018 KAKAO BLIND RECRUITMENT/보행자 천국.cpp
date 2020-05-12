/* 2015112119 ������ */

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

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
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

				if (city_map[i][j] == 0) { // 0�̸� ��� ���⿡�� �����ִ�.
					if (checkRange(i, j + 1) && city_map[i][j + 1] != 1 ) {

						// i + 1���� �� �����ִ��� Ȯ���ؾ��Ѵ�.
						if (city_map[i][j + 1] == 2 && checkRange(i, j + 2)) { // 2�̰� 
							dp[i][j + 1].first = max(dp[i][j].first, dp[i][j + 1].first);
							dp[i][j + 1].second = 1;
						}
						if (city_map[i][j + 1] == 0) {
							dp[i ][j + 1].first = dp[i][j].first + dp[i ][j + 1].first;
							dp[i ][j + 1].second = 1;
						}

					}
					if (checkRange(i + 1, j) && city_map[i + 1][j] != 1) {

						// i + 1���� �� �����ִ��� Ȯ���ؾ��Ѵ�.
						if (city_map[i + 1][j] == 2 && checkRange(i + 2, j) ) { // 2�̰� 
							dp[i + 1][j].first = max(dp[i][j].first, dp[i + 1][j].first);
							dp[i + 1][j].second = -1;
						}
						if (city_map[i + 1][j] == 0) {
							dp[i + 1][j].first = dp[i][j].first + dp[i + 1][j].first;
							dp[i + 1][j].second = -1;
						}
					}
				}
				else if (city_map[i][j] == 2) {// 2�̸� Ư�� ���⸸ �����ִ�.
					if (dp[i][j].second == 1) { // �������� �Դٴ°Ŵϱ� �������� ����
						if (checkRange(i, j + 1) && city_map[i][j + 1] != 1) {

							// i + 1���� �� �����ִ��� Ȯ���ؾ��Ѵ�.
							if (city_map[i][j + 1] == 2 && checkRange(i, j + 2)) { // 2�̰� 
								dp[i][j + 1].first = max(dp[i][j].first, dp[i][j + 1].first);
								dp[i][j + 1].second = 1;
							}
							if (city_map[i][j + 1] == 0) {
								dp[i][j + 1].first = dp[i][j].first + dp[i][j + 1].first;
								dp[i][j + 1].second = 1;
							}
						}
					}
					else if (dp[i][j].second == -1) { //���ʿ��� �Դٴϱ� �Ʒ��ʸ� ����
						if (checkRange(i + 1, j) && city_map[i + 1][j] != 1) {

							// i + 1���� �� �����ִ��� Ȯ���ؾ��Ѵ�.
							if (city_map[i + 1][j] == 2 && checkRange(i + 2, j)) { // 2�̰� 
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