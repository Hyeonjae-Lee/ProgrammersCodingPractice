/* 2015112119 이현재 */

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
				//원소를 찾은 것이다.
				//원소를 찾았고 이 원소가 temp의 앞에 값이 같으면 TEMP의 앞을 없애버리자
				if (temp.front() == skill_trees[i][j]) temp.pop_front();
				else {
					//값이 다르기 때문에 이것은 불가능한 스킬트리
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