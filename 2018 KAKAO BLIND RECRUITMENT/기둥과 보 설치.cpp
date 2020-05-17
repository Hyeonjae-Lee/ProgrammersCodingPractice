/* 2015112119 ������ */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>
#include <bitset>
#include <string.h>

using namespace std;

// ����� �ٴ� ���� �ְų� ���� ���� �� �κ� ���� �ְų�, �Ǵ� �ٸ� ��� ���� �־�� �մϴ�.
// ���� ���� �� �κ��� ��� ���� �ְų�, �Ǵ� ���� �� �κ��� �ٸ� ���� ���ÿ� ����Ǿ� �־�� �մϴ�.
// 0�� ���, 1�� ��
// 0�� ����, 1�� ��ġ

int dp[101][101]; // ��
int dp2[101][101]; // ���

int N;

bool checkBo(int x, int y) {

	if (x == N) return false;
	
	if (dp2[x + 1][y] == 0 || dp2[x + 1][y + 1] == 0) return true; // ���� �� �κ��� ��������ְų�
	if (dp[x][y - 1] == 1 && dp[x][y + 1] == 1) return true; // ���� �� �κ��� ���ÿ� ����Ǿ� �־�� �Ѵ�.

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

		if (building) { // ���ΰ��
			if (doing) { // ��ġ�ϴ� ���
				if ( checkBo(n - x, y) ) { // 2 ���ؿ� ������ ���
					dp[n - x][y] = 1;
				}
			}
			else { //�����ϴ� ���
				dp[n - x][y] = -1;
				if (!checkBo(n - x, y) ) { // 2 ���ؿ� ������ ���
					dp[n - x][y] = 1;
				}
			}
		}
		else { // ����ΰ��
			if (doing) { // ��ġ�ϴ� ���
				if (checkGidung(n - x, y)) { // 2 ���ؿ� ������ ���
					dp2[n - x][y] = 0;
				}
			}
			else {
				dp2[n - x][y] = -1;
				if (!checkGidung(n - x - 1, y) || !checkBo(n -x -1 , y)) { // 2 ���ؿ� ������ ���
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