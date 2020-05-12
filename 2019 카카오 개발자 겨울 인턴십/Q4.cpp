/* 2015112119 이현재 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <queue>

using namespace std;

int dx[4] = { 0, 0, 1, -1 };// 오른쪽, 왼쪽 , 아래쪽, 위쪽
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
	Ditec c = { 0, 0, 0, 0, -1 }; // 0은 왼쪽 1는 오른쪽 2은 위쪽 3는 아래쪽
	qu.push(c);

	visited[0][0] = c;

	while (!qu.empty()) {
		Ditec temp = qu.front();
		qu.pop();

		if (temp.x == M - 1 && temp.y == M - 1) {
			answer = min(answer, (temp.go) * 100 + temp.drift * 500);
		}

		for (int i = 0; i < 4; i++) {// 오른쪽, 왼쪽 , 아래쪽, 위쪽
			int tx = dx[i] + temp.x;
			int ty = dy[i] + temp.y;

			if (checkRange(tx, ty) && board[tx][ty] == 0 && !check[tx][ty]) { // 벽이 없고 범위 내에 있는경우
				//범위에 들어가고 비어있는 곳일때

				if (temp.direc == -1) {//초기상태일경우
					Ditec d = { tx, ty, temp.go + 1, temp.drift, i };
					visited[tx][ty] = d;
					qu.push(d);
				}
				else { // 초기상태가 아닌경우
					if (i == 1 || i == 2) {//오른쪽 혹은 왼쪽으로 이동시
						if (temp.direc == 1 || temp.direc == 2) {
							Ditec d = { tx, ty, temp.go + 1, temp.drift, i };

							if (!check[tx][ty]) {
								visited[tx][ty] = d;
								qu.push(d);
							}
							else {
								if (visited[tx][ty].go * 100 + visited[tx][ty].drift * 500 > (temp.go + 1)*100 + temp.drift * 500 ) {
									//기존 것이 더 큰경우
									visited[tx][ty] = d;
									qu.push(d);
								}
							}
						}
						else {//아래 혹운 위쪽으로 이동했을 때
							Ditec d = { tx, ty, temp.go + 1, temp.drift + 1, i };

							if (!check[tx][ty]) {
								visited[tx][ty] = d;
								qu.push(d);
							}
							else {
								if (visited[tx][ty].go * 100 + visited[tx][ty].drift * 500 > (temp.go + 1) * 100 + (temp.drift + 1) * 500) {
									//기존 것이 더 큰경우
									visited[tx][ty] = d;
									qu.push(d);
								}
							}
							qu.push(d);
						}
					}
					else {//위쪽 혹은 아래쪽으로 이동시
						if (temp.direc == 1 || temp.direc == 2) {
							Ditec d = { tx, ty, temp.go + 1, temp.drift + 1, i };

							if (!check[tx][ty]) {
								visited[tx][ty] = d;
								qu.push(d);
								
							}
							else {
								if (visited[tx][ty].go * 100 + visited[tx][ty].drift * 500 > (temp.go + 1) * 100 + (temp.drift +1) * 500) {
									//기존 것이 더 큰경우
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
									//기존 것이 더 큰경우
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