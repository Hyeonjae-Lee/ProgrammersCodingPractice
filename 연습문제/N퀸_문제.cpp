///* 2015112119 이현재 */
//
//#include <string>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//
//int solution(int n) {
//	int answer = 0;
//
//	if (n < 4) return 0;
//
//
//	return answer;
//}

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string>

using namespace std;
int n, sum = 0, row;
bool a[15][15];
bool check_col[15];
bool check_dig[40];
bool check_dig2[40];

bool check(int row, int col) {
	//|
	if (check_col[col]) return false;

	//왼쪽 위 대각선
	if (check_dig[row + col]) return false;

	// /
	if (check_dig2[row - col + n]) return false;

	return true;
}

void dfs(int row) {
	if (row == n) {
		sum++;
	}

	for (int col = 0; col < n; col++) {
		a[row][col] = true;
		if (check(row, col)) {
			check_dig[row + col] = true;
			check_dig2[row - col + n] = true;
			check_col[col] = true;
			a[row][col] = true;

			dfs(row + 1);

			check_dig[row + col] = false;
			check_dig2[row - col + n] = false;
			check_col[col] = false;
			a[row][col] = false;
		}
	}

}

int main() {
	cin >> n;
	dfs(0);

	cout << sum;
}