/* 2015112119 ������ */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;

	for (int i = 0; i < skill_trees.size(); i++) {

		deque<char> temp;
		bool flag = false;
		for (auto ele : skill) temp.push_back(ele);

		for (int j = 0; j < skill_trees[i].size(); j++) {
			if (find(temp.begin(), temp.end(), skill_trees[i][j]) != temp.end()) {
				//���Ҹ� ã�� ���̴�.
				//���Ҹ� ã�Ұ� �� ���Ұ� temp�� �տ� ���� ������ TEMP�� ���� ���ֹ�����
				if (temp.front() == skill_trees[i][j]) temp.pop_front();
				else {
					//���� �ٸ��� ������ �̰��� �Ұ����� ��ųƮ��
					flag = true;
					break;
				}
			}
		}

		if (!flag) answer++;
	}

	return answer;
}

int main() {
	string skill = "REA";
	vector<string> skill_trees = { "REA", "POA", "CDAE" };

	cout << solution(skill, skill_trees);
}