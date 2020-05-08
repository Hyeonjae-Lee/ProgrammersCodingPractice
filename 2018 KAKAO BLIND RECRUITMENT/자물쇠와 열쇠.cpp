/* 2015112119 이현재 */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

vector<vector<int>> dp;
int newKeyWidth;
int lockWidth;
int keyWidth;
// 필요한 함수는 key 배열을 회전시키는 함수

vector<vector<int>> rotate(vector<vector<int>> key) {
	vector<vector<int>> answer;
	for (int i = 0; i < key.size(); i++) {
		vector<int> temp;
		for (int j = key.size()-1; j >= 0; j--) temp.push_back(key[j][i]);
		answer.push_back(temp);
	}
	return answer;
}

// 필요한 함수는 lock안에 1로 채워져 있는지 확인하는 함수
bool checkLock(vector<vector<int>> key) {

	for (int i = keyWidth; i <= keyWidth + lockWidth; i ++) {
		for (int j = keyWidth; j <= keyWidth + lockWidth; j++) {
			if (key[i][j] != 1) return false;
		}
	}
	return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;
	newKeyWidth = lock.size() + (key.size() - 1) * 2;
	lockWidth = lock.size() - 1;
	keyWidth = key.size() - 1;

	for (int i = 0; i < newKeyWidth; i++) {
		vector<int > tempDp;
		for (int j = 0; j < newKeyWidth; j++) tempDp.push_back(0);
		dp.push_back(tempDp);
	}

	for (int i = 0; i < newKeyWidth; i++) {
		for (int j = 0; j < newKeyWidth; j++) {
			if (i >= keyWidth && i <= lockWidth + keyWidth && j >= keyWidth && j <= lockWidth + keyWidth ) {
				dp[i][j] = lock[i - keyWidth][j - keyWidth];
			}
		}
	} // 새로운 lock 확인

	for (int b = 0; b < 4; b++) {
		vector<vector<int>> answerVec = rotate(key);
		key = answerVec;

		for (int i = 0; i < newKeyWidth - keyWidth; i++) {
			for (int j = 0; j < newKeyWidth - keyWidth; j++) {
				vector<vector<int>> tempLock = dp;

				// 다 더한 후 확인을 해야한다.
				for (int k = i; k <= i + keyWidth; k++) {
					for (int h = j; h <= j + keyWidth; h++) {
						tempLock[k][h] += answerVec[k - i][h - j];
					}
				}

				if (checkLock(tempLock)) {
					answer = true;
					return answer;
				}
			}
		} 
	}
	return answer;
}

int main() {
	vector<vector<int>> key = { {1,0},{1,1} };
	vector<vector<int>> lock = { {1,1,1},{1,0,0},{1,1,0} };
	cout << solution( key, lock);
}