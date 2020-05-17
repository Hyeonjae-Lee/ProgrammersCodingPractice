/* 2015112119 이현재 */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

//크루스컬 알고리즘, 최소비용신장트리를 만들기 위한 대표적인 알고리즘이다.
//이때 사이클 테이블을 만들어서 사이클을 도는지 확인해야한다.

bool desc(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}

int parent[105];

int Find(int x) {
	// Root인 경우 x를 반환
	if (x == parent[x]) {
		return x;
	}
	else {
		// 아니면 Root를 찾아감
		int p = Find(parent[x]);
		parent[x] = p;
		return p;
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x != y) {
		parent[y] = x;
	}
}

int solution(int n, vector<vector<int>> costs) {
	int answer = 0;

	for (int i = 0; i < n; i++) parent[i] = i;
	sort(costs.begin(), costs.end(), desc);

	for (int i = 0; i < costs.size(); i++) {
		if (Find(costs[i][1]) != Find(costs[i][0])) {
			//부모가 같지않을경우
			Union(costs[i][0], costs[i][1]);
			answer += costs[i][2];
		}
	}

	return answer;
}

int main() {
	int n = 5;
	vector<vector<int>> costs = { {0, 1, 1},{2, 3, 1},{3, 4, 2},{1, 2, 2},{0, 4, 100} };

	cout << solution(n, costs);
}