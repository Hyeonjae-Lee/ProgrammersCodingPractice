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

int dp[105][105]; // 보 1
int dp2[105][105]; // 기둥 0

int N;

// 기둥일 경우

// 바닥에 설치 하거나 || 아래에 기둥이 존재하거나 ((y - 1)이므로 y >= 1이어야한다) || 밑에 오른쪽으로 뻗은 보가 있거나 || 밑에 왼쪽으로 뻗은
// 보가 있으면 true, 없으면 false


bool checkBo(int x, int y) {
	// 보일 경우
	// 왼쪽 모서리에 기둥이 받치고 있거나 || 
	// 오른쪽 아래에 기둥이 받치고 있거나 || 양 옆에 보가 있으면 true, 없으면 false

	/*if ( (x + 1 <= N && (dp2[x + 1][y] == 0 || dp2[x + 1][y + 1] == 0)) || ( y >= 1 && dp[x][y - 1] == 1 && dp[x][y + 1] == 1)) return true;
	return false;*/
	if ((y >= 1 && (dp2[y - 1][x] == 0 || dp2[y - 1][x + 1] == 0)) || (x >= 1 && dp[y][x - 1] == 1 && dp[y][x + 1] == 1)) {
		return true;
	}
	else return false;

}

bool checkGidung(int x, int y) {
	// 바닥에 설치 하거나 || 아래에 기둥이 존재하거나 ((y - 1)이므로 y >= 1이어야한다) 
	// ||밑에 오른쪽으로 뻗은 보가 있거나 || 밑에 왼쪽으로 뻗은
	// 보가 있으면 true, 없으면 false

	/*if (x == N || (x + 1 <= N && dp2[x + 1][y] == 0) || (y >= 1 && dp[x][y - 1] == 1) || dp[x][y] == 1) return true;
	return false;*/
	if (y == 0 || (y >= 1 && dp2[y - 1][x] == 0) || dp2[y][x] == 0 || (x >= 1 && dp[y][x - 1] == 1)) {
		return true;
	}
	else return false;
}

bool desc(vector<int> a, vector<int> b) {

	if (a[0] != b[0]) return a[0] < b[0];
	else if (a[0] == b[0] && a[1] != b[1]) return a[1] < b[1];
	else return a[2] < b[2];
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	N = n;

	for (int i = 0; i < 101; i++) memset(dp[i], -1, sizeof(dp[i]));
	for (int i = 0; i < 101; i++) memset(dp2[i], -1, sizeof(dp2[i]));

	for (int i = 0; i < build_frame.size(); i++) {

		int x = build_frame[i][0];
		int y = build_frame[i][1];
		int building = build_frame[i][2];
		int doing = build_frame[i][3];

		if (building) { // 보인경우
			if (doing) { // 설치하는 경우
				if (checkBo(x, y)) { // 1 기준에 부합할 경우
					dp[y][x] = 1;
				}
			}
			else { //삭제하는 경우

				// 역시 일단 보를 지울 수 있다고 가정하자
				dp[y][x] = -1;

				// 왼쪽 모서리 위에 기둥이 있을 경우
				if (dp2[y][x] == 0 && !checkGidung(x, y)) {
					dp[y][x] = 1;
				}
				// 오른쪽 모서리에 기둥이 있을 경우
				else if (dp2[y][x + 1] == 0 && !checkGidung(x + 1, y)) dp[y][x] = 1;

				// 왼쪽에 보가 있을 경우
				else if (x >= 1 && dp[y][x - 1] == 1 && !checkBo(x - 1, y)) {
					dp[y][x] = 1;
				}

				// 오른쪽에 보가 있을 경우
				else if (dp[y][x + 1] == 1 && !checkBo(x + 1, y)) { // 기준에 부합하지 않을 경우
					dp[y][x] = 1;
				}
			}
		}
		else { // 기둥인경우
			if (doing) { // 설치하는 경우
				if (checkGidung(x, y)) { // 2 기준에 부합할 경우
					dp2[y][x] = 0;
				}
			}
			else { // 삭제하고자 하는 오브젝트가 기둥일 경우

				// 일단 기둥을 지울 수 있다고 가정하자
				dp2[y][x] = -1;

				// 기둥을 지웠는데 만약 바로 위에 다른 기둥이 있으며, 이 기둥이 존재할 수 있지 않으면,		
				// 다시 기둥을 냅두고 삭제를 못하니까 그냥 작업을 무시한다.
				if (dp2[y + 1][x] == 0 || !checkGidung(x, y + 1)) {
					dp2[y][x] = 0;
				}
				// 위에 왼쪽으로 뻗은 보가 있고 이 보가 존재할 수 없다면,	
				// 역시 다시 되돌림
				else if (x >= 1 && dp[y + 1][x - 1] == 1 && !checkBo(x - 1, y + 1)) {
					dp2[y][x] = 0;
				}

				// 위에 오른쪽으로 뻗은 보가 있는 경우
				else if (dp[y + 1][x] == 1 && !checkBo(x, y + 1)) {
					dp2[y][x] = 0;
				}
				// 위의 케이스에 해당되지 않으면 지울 수 있다. 기둥이므로 -1 해주자.

			}
		}
	}

	// answer에 넣는 과정
	for (int y = 0; y <= n; y++) {
		for (int x = 0; x <= n; x++) {
			//build가 0이 아닌, 즉 보든 기둥이든 뭐가 존재할 경우
			// 기둥만 있을 경우 현재 answer의 현재 좌표에 (x, y, 0)을 넣어주자
			if (dp2[y][x] == 0) {
				vector<int> tmp;
				tmp.push_back(x);
				tmp.push_back(y);
				tmp.push_back(0);
				answer.push_back(tmp);
			}

			// 보만 있을 경우 현재 answer의 현재 좌표에 (x, y, 1)을 넣어주자
			if (dp[y][x] == 1) {
				vector<int> tmp;
				tmp.push_back(x);
				tmp.push_back(y);
				tmp.push_back(1);
				answer.push_back(tmp);
			}

		}
	}

	/*for (int i = 0; i <= n; i++) {
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
	}*/

	sort(answer.begin(), answer.end(), desc);

	return answer;
}

int main() {
	int n = 5;
	vector<vector<int>> build_frame = { {0,0,0,1},{2,0,0,1},{4,0,0,1},{0,1,1,1},{1,1,1,1},{2,1,1,1},{3,1,1,1},{2,0,0,0},{1,1,1,0},{2,2,0,1 } };
	solution(n, build_frame);
}