/* 2015112119 ������ */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

//ũ�罺�� �˰���, �ּҺ�����Ʈ���� ����� ���� ��ǥ���� �˰����̴�.
//�̶� ����Ŭ ���̺��� ���� ����Ŭ�� ������ Ȯ���ؾ��Ѵ�.

bool desc(vector<int> a, vector<int> b) {
	return a[2] < b[2];
}

int parent[105];

int Find(int x) {
	// Root�� ��� x�� ��ȯ
	if (x == parent[x]) {
		return x;
	}
	else {
		// �ƴϸ� Root�� ã�ư�
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
			//�θ� �����������
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