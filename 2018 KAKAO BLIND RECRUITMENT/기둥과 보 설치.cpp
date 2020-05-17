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

int dp[105][105]; // �� 1
int dp2[105][105]; // ��� 0

int N;

// ����� ���

// �ٴڿ� ��ġ �ϰų� || �Ʒ��� ����� �����ϰų� ((y - 1)�̹Ƿ� y >= 1�̾���Ѵ�) || �ؿ� ���������� ���� ���� �ְų� || �ؿ� �������� ����
// ���� ������ true, ������ false


bool checkBo(int x, int y) {
	// ���� ���
	// ���� �𼭸��� ����� ��ġ�� �ְų� || 
	// ������ �Ʒ��� ����� ��ġ�� �ְų� || �� ���� ���� ������ true, ������ false

	/*if ( (x + 1 <= N && (dp2[x + 1][y] == 0 || dp2[x + 1][y + 1] == 0)) || ( y >= 1 && dp[x][y - 1] == 1 && dp[x][y + 1] == 1)) return true;
	return false;*/
	if ((y >= 1 && (dp2[y - 1][x] == 0 || dp2[y - 1][x + 1] == 0)) || (x >= 1 && dp[y][x - 1] == 1 && dp[y][x + 1] == 1)) {
		return true;
	}
	else return false;

}

bool checkGidung(int x, int y) {
	// �ٴڿ� ��ġ �ϰų� || �Ʒ��� ����� �����ϰų� ((y - 1)�̹Ƿ� y >= 1�̾���Ѵ�) 
	// ||�ؿ� ���������� ���� ���� �ְų� || �ؿ� �������� ����
	// ���� ������ true, ������ false

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

		if (building) { // ���ΰ��
			if (doing) { // ��ġ�ϴ� ���
				if (checkBo(x, y)) { // 1 ���ؿ� ������ ���
					dp[y][x] = 1;
				}
			}
			else { //�����ϴ� ���

				// ���� �ϴ� ���� ���� �� �ִٰ� ��������
				dp[y][x] = -1;

				// ���� �𼭸� ���� ����� ���� ���
				if (dp2[y][x] == 0 && !checkGidung(x, y)) {
					dp[y][x] = 1;
				}
				// ������ �𼭸��� ����� ���� ���
				else if (dp2[y][x + 1] == 0 && !checkGidung(x + 1, y)) dp[y][x] = 1;

				// ���ʿ� ���� ���� ���
				else if (x >= 1 && dp[y][x - 1] == 1 && !checkBo(x - 1, y)) {
					dp[y][x] = 1;
				}

				// �����ʿ� ���� ���� ���
				else if (dp[y][x + 1] == 1 && !checkBo(x + 1, y)) { // ���ؿ� �������� ���� ���
					dp[y][x] = 1;
				}
			}
		}
		else { // ����ΰ��
			if (doing) { // ��ġ�ϴ� ���
				if (checkGidung(x, y)) { // 2 ���ؿ� ������ ���
					dp2[y][x] = 0;
				}
			}
			else { // �����ϰ��� �ϴ� ������Ʈ�� ����� ���

				// �ϴ� ����� ���� �� �ִٰ� ��������
				dp2[y][x] = -1;

				// ����� �����µ� ���� �ٷ� ���� �ٸ� ����� ������, �� ����� ������ �� ���� ������,		
				// �ٽ� ����� ���ΰ� ������ ���ϴϱ� �׳� �۾��� �����Ѵ�.
				if (dp2[y + 1][x] == 0 || !checkGidung(x, y + 1)) {
					dp2[y][x] = 0;
				}
				// ���� �������� ���� ���� �ְ� �� ���� ������ �� ���ٸ�,	
				// ���� �ٽ� �ǵ���
				else if (x >= 1 && dp[y + 1][x - 1] == 1 && !checkBo(x - 1, y + 1)) {
					dp2[y][x] = 0;
				}

				// ���� ���������� ���� ���� �ִ� ���
				else if (dp[y + 1][x] == 1 && !checkBo(x, y + 1)) {
					dp2[y][x] = 0;
				}
				// ���� ���̽��� �ش���� ������ ���� �� �ִ�. ����̹Ƿ� -1 ������.

			}
		}
	}

	// answer�� �ִ� ����
	for (int y = 0; y <= n; y++) {
		for (int x = 0; x <= n; x++) {
			//build�� 0�� �ƴ�, �� ���� ����̵� ���� ������ ���
			// ��ո� ���� ��� ���� answer�� ���� ��ǥ�� (x, y, 0)�� �־�����
			if (dp2[y][x] == 0) {
				vector<int> tmp;
				tmp.push_back(x);
				tmp.push_back(y);
				tmp.push_back(0);
				answer.push_back(tmp);
			}

			// ���� ���� ��� ���� answer�� ���� ��ǥ�� (x, y, 1)�� �־�����
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