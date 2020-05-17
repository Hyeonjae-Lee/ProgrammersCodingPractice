/* 2015112119 이현재 */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>
#include <bitset>
#include <string.h>

using namespace std;

// 기둥은 바닥 위에 있거나 보의 한쪽 끝 부분 위에 있거나, 또는 다른 기둥 위에 있어야 합니다.
// 보는 한쪽 끝 부분이 기둥 위에 있거나, 또는 양쪽 끝 부분이 다른 보와 동시에 연결되어 있어야 합니다.
// 0은 기둥, 1은 보
// 0은 삭제, 1은 설치

int dp[101][101]; // 보
int dp2[101][101]; // 기둥

int N;

bool checkBo(int x, int y) {

	if (x == N) return false;
	
	if (dp2[x + 1][y] == 0 || dp2[x + 1][y + 1] == 0) return true; // 한쪽 끝 부분이 기둥위에있거나
	if (dp[x][y - 1] == 1 && dp[x][y + 1] == 1) return true; // 양쪽 끝 부분이 동시에 연결되어 있어야 한다.

	return false;
}

bool checkGidung(int x, int y) {

	if (x == N || dp[x][y-1] == 1 || dp[x][y] == 1 || dp2[x+1][y] == 0 ) return true;
	return false;

}

bool desc(vector<int> a, vector<int> b) {
	if (a[0] != b[0]) return a[0] < b[0];
	else return a[1] < b[1];
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	N = n;
	for (int i = 0; i < 101; i++) memset(dp[i], -1, sizeof(dp[i]));
	for (int i = 0; i < 101; i++) memset(dp2[i], -1, sizeof(dp2[i]));

	for (int i = 0; i < build_frame.size(); i++) {

		int x = build_frame[i][1];
		int y = build_frame[i][0];
		int building = build_frame[i][2];
		int doing = build_frame[i ][3];

		if (building) { // 보인경우
			if (doing) { // 설치하는 경우
				if ( checkBo(n - x, y) ) { // 2 기준에 부합할 경우
					dp[n - x][y] = 1;
				}
			}
			else { //삭제하는 경우
				dp[n - x][y] = -1;
				if (!checkBo(n - x, y) ) { // 2 기준에 부합할 경우
					dp[n - x][y] = 1;
				}
			}
		}
		else { // 기둥인경우
			if (doing) { // 설치하는 경우
				if (checkGidung(n - x, y)) { // 2 기준에 부합할 경우
					dp2[n - x][y] = 0;
				}
			}
			else {
				dp2[n - x][y] = -1;
				if (!checkGidung(n - x - 1, y) || !checkBo(n -x -1 , y)) { // 2 기준에 부합할 경우
					dp2[n - x][y] = 0;
				}
			}
		}

	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (dp2[i][j] == 0) {
				vector<int> temp;
				temp.push_back(j);
				temp.push_back(n - i);
				temp.push_back(0);
				answer.push_back(temp);
			}
			
			if (dp[i][j] == 1) {
				vector<int> temp;
				temp.push_back(j);
				temp.push_back(n - i);
				temp.push_back(1);
				answer.push_back(temp);
			}
		}
	}

	sort(answer.begin(), answer.end(), desc);

	return answer;
}

int main() {
	int n = 5;
	vector<vector<int>> build_frame = { {0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1 }
};
	solution( n, build_frame);
}