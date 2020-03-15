#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int arr[201][201];
bool check[201][201];
int checkb = 0;

bool checkRange(int a, int b) {
	return (a >= 0 && b >= 0 && a < checkb && b < checkb);
}

void dfs(int a, int b) {
	check[a][b] = true;
	for (int i = 0; i < checkb; i++) {
		if (!check[b][i] && arr[b][i]) {
			dfs(b, i);
		}
	}
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;
	checkb = n;

	for (int i = 0; i < computers.size(); i++) 
		for (int j = 0; j < computers[i].size(); j++) 
			if (computers[i][j] == 1) arr[i][j] = 1;

	for (int i = 0; i < computers.size(); i++) {
		for (int j = 0; j < computers[i].size(); j++) {
			if (computers[i][j] == 1 && !check[i][j]) {//이 조건에 들어가면 dfs를 실행하고 answer에 하나를 추가한다.
				dfs(i, j);
				answer++;
			}
		}
	}

	return answer;
}

int main() {
	vector<vector<int>> computers = { {1,0,0,1},{0,1,1,0},{0,1,1,0},{1,1,0,1} };
	solution(4, computers);
}