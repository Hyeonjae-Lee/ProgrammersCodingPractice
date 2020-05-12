/* 2015112119 ������ */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <queue>

using namespace std;

int dx[4] = { 0, 0, 1, -1 };// ������, ���� , �Ʒ���, ����
int dy[4] = { 1, -1, 0, 0 };
int M, N;

struct Ditec {
	int x;
	int y;
	int go;
	int drift;
	int direc;
};

bool check[30][30];
Ditec visited[30][30];

bool checkRange(int a, int b) {
	return (a < M && b < M && a >= 0 && b >= 0);
}

int solution(vector<vector<int>> board) {
	int answer = 99999999;
	M = board.size();

	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			Ditec c = { 0, 0, 0, 0, -1 };
			visited[i][j] = c;
		}
	}

	queue<Ditec> qu;
	Ditec c = { 0, 0, 0, 0, -1 }; // 0�� ���� 1�� ������ 2�� ���� 3�� �Ʒ���
	qu.push(c);

	visited[0][0] = c;

	while (!qu.empty()) {
		Ditec temp = qu.front();
		qu.pop();

		if (temp.x == M - 1 && temp.y == M - 1) {
			answer = min(answer, (temp.go) * 100 + temp.drift * 500);
		}

		for (int i = 0; i < 4; i++) {// ������, ���� , �Ʒ���, ����
			int tx = dx[i] + temp.x;
			int ty = dy[i] + temp.y;

			if (checkRange(tx, ty) && board[tx][ty] == 0 && !check[tx][ty]) { // ���� ���� ���� ���� �ִ°��
				//������ ���� ����ִ� ���϶�

				if (temp.direc == -1) {//�ʱ�����ϰ��
					Ditec d = { tx, ty, temp.go + 1, temp.drift, i };
					visited[tx][ty] = d;
					qu.push(d);
				}
				else { // �ʱ���°� �ƴѰ��
					if (i == 1 || i == 2) {//������ Ȥ�� �������� �̵���
						if (temp.direc == 1 || temp.direc == 2) {
							Ditec d = { tx, ty, temp.go + 1, temp.drift, i };

							if (!check[tx][ty]) {
								visited[tx][ty] = d;
								qu.push(d);
							}
							else {
								if (visited[tx][ty].go * 100 + visited[tx][ty].drift * 500 > (temp.go + 1)*100 + temp.drift * 500 ) {
									//���� ���� �� ū���
									visited[tx][ty] = d;
									qu.push(d);
								}
							}
						}
						else {//�Ʒ� Ȥ�� �������� �̵����� ��
							Ditec d = { tx, ty, temp.go + 1, temp.drift + 1, i };

							if (!check[tx][ty]) {
								visited[tx][ty] = d;
								qu.push(d);
							}
							else {
								if (visited[tx][ty].go * 100 + visited[tx][ty].drift * 500 > (temp.go + 1) * 100 + (temp.drift + 1) * 500) {
									//���� ���� �� ū���
									visited[tx][ty] = d;
									qu.push(d);
								}
							}
							qu.push(d);
						}
					}
					else {//���� Ȥ�� �Ʒ������� �̵���
						if (temp.direc == 1 || temp.direc == 2) {
							Ditec d = { tx, ty, temp.go + 1, temp.drift + 1, i };

							if (!check[tx][ty]) {
								visited[tx][ty] = d;
								qu.push(d);
								
							}
							else {
								if (visited[tx][ty].go * 100 + visited[tx][ty].drift * 500 > (temp.go + 1) * 100 + (temp.drift +1) * 500) {
									//���� ���� �� ū���
									visited[tx][ty] = d;
									qu.push(d);
								}
							}
						}
						else {
							Ditec d = { tx, ty, temp.go + 1, temp.drift, i };

							if (!check[tx][ty]) {
								visited[tx][ty] = d;
								qu.push(d);
							}
							else {
								if (visited[tx][ty].go * 100 + visited[tx][ty].drift * 500 > (temp.go + 1) * 100 + temp.drift * 500) {
									//���� ���� �� ū���
									visited[tx][ty] = d;
									qu.push(d);
								}
							}
						}
					}
				}

			}
		}
		check[temp.x][temp.y] = true;

	}

	return answer;
}

int main() {
	//vector<vector<int>> board = { {0,0,0,0,0,0},{0,1,1,1,1,0},{0,0,1,0,0,0},{1,0,0,1,0,0},{0,1,0,0,0,1},{0,0,0,0,0,0} };
	vector<vector<int>> board = { {0,0,0,0,0,0,0,1},{0,0,0,0,0,0,0,0},{0,0,0,0,0,1,0,0},
{0,0,0,0,1,0,0,0},{0,0,0,1,0,0,0,1},{0,0,1,0,0,0,1,0},{0,1,0,0,0,1,0,0}};
	solution( board);
}