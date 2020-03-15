#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <string.h>
#include <unordered_set>
#include <queue>

using namespace std;

int arr[51][51];
bool check[51][51];

int m, n;
int testCase;

void func(int a, int b) {
	if (a - 1 >= 0 && b - 1 >= 0) {
		//왼쪽 위
		if (arr[a - 1][b] == 1 && arr[a - 1][b - 1] == 1 && arr[a][b - 1] == 1) {
			check[a - 1][b] = true;
			check[a - 1][b - 1] = true;
			check[a][b - 1] = true;
			check[a][b] = true;
		}
	}
	if (a - 1 >= 0 && b + 1 < n) {
		//오른쪽 위
		if (arr[a - 1][b] == 1 && arr[a - 1][b + 1] == 1 && arr[a][b + 1] == 1) {
			check[a - 1][b] = true;
			check[a - 1][b + 1] = true;
			check[a][b - 1] = true;
			check[a][b] = true;
		}
	}
	if (a + 1 < m && b - 1 >= 0) {
		//왼쪽 아래
		if (arr[a + 1][b] == 1 && arr[a + 1][b - 1] == 1 && arr[a][b - 1] == 1) {
			check[a + 1][b] = true;
			check[a + 1][b - 1] = true;
			check[a][b - 1] = true;
			check[a][b] = true;
		}
	}
	if (a + 1 < 0 && b + 1 < n) {
		//오르,ㄴ쪽 아래
		if (arr[a + 1][b] == 1 && arr[a + 1][b + 1] == 1 && arr[a][b + 1] == 1) {
			check[a + 1][b] = true;
			check[a + 1][b + 1] = true;
			check[a][b + 1] = true;
			check[a][b] = true;
		}
	}
}

int main() {
	cin >> testCase;

	while (testCase--) {
		bool flag = false;
		cin >> m >> n;

		for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			check[i][j] = false;
		}

		for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
			if (!check[i][j] && arr[i][j] == 1) {
				func(i, j);
			}
		}

		for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && !check[i][j]) {
				//1인데 종이를 붙이지 못했을 경우
				flag = true;
			}
		}

		if (flag) cout << "NO\n";
		else cout << "YES\n";
	}

	return 0;
}