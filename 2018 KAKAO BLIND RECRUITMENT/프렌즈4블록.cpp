#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

char block[31][31];
bool check[31][31];

int x, y;

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	x = m;
	y = n;

	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			block[i][j] = board[i][j];
		}
	}

	int sum = 1;

	while (sum > 0) {
		sum = 0;
		
		for (int i = 0; i < m - 1; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (block[i][j] == block[i][j + 1] && block[i][j] == block[i + 1][j] &&
					block[i][j] == block[i + 1][j + 1] && block[i][j] != 'x') {
					check[i][j] = check[i + 1][j] = check[i + 1][j + 1] = check[i][j + 1] = true;
					sum++;
				}
			}
		}

		if (sum == 0) break;

		for (int i = 0; i < n; i++) {
			vector<char> vec;
			for (int j = 0; j < m; j++) {
				if (!check[j][i] && block[j][i] != 'x') {//trueÀÎ °÷
					vec.push_back(block[j][i]);
				}
			}
			int k = 0;
			for (int j = 0; j < m - vec.size(); j++) {
				block[j][i] = 'x';
				check[j][i] = false;
			}
			for (int j = m - vec.size(); j < m; j++) {
				block[j][i] = vec[k++];
				check[j][i] = false;
			}
		}
	}

	for (int i = 0; i < m ; i++) {
		for (int j = 0; j < n; j++) {
			if (block[i][j] == 'x') answer++;
		}
	}

	return answer;
}

int main() {
	vector<string> board = { "CCBDE", "AAADE", "AAABF", "CCBBF" };

	cout << solution(4, 5 , board);
}