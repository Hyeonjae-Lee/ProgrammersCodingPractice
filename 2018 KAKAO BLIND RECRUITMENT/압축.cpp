#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(string msg) {
	vector<int> answer;
	vector<char> vec;

	map<string, int> myMap;
	string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string srr = "";

	for (int i = 0; i < 26; i++) {
		srr = alph[i];
		myMap.insert({ srr , i + 1 });
		srr = "";
	} // 알파벳은 65 ~ 90

	for (int i = 0; i < msg.size();) {
		int temp = 0;
		string tempsrr = "";
		map<string, int>::iterator iter;
		
		// 하나씩 실행해라
		int j = 1;
		while (true) {

			if (i + j > msg.size()) {
				if (!tempsrr.empty()) {
					// 찾은거니까
					answer.push_back(temp);
					string trr = "";
					trr += tempsrr;
				}
				i += j;
				break;
			}

			if (myMap.find(msg.substr(i, j)) != myMap.end()) {
				// 원소를 찾았다는 의미
				// 원소를 찾았으면 가장 큰걸 구해야 하니 j를 더 크게 해서 찾는다. 
				if (temp < myMap[msg.substr(i, j)]) {
					temp = myMap[msg.substr(i, j)];
					tempsrr = msg.substr(i, j);
				} j++;
			}
			else {
				// 원소를 못찾은것
				// 원소를 못찾았으니 이전까지 찾은 원소의 최댓값을 넣어 주어야 한다. 
				answer.push_back(temp);
				string trr = "";
				trr += tempsrr;
				if (j != 1) {
					trr += msg[i + j - 1];
					i += j - 1;
				}
				else {
					trr += msg[i + j];
					i += j;
				}
				myMap.insert({ trr , myMap.size() + 1 });
				
				break;
			}
			
		}
	}

	return answer;
}

int main() {

	string srr = "TOBEORNOTTOBEORTOBEORNOT";

	cout << srr.substr(1, 1);

	vector<int> answer = solution(srr);

	for (auto ele : answer) {
		cout << ele << endl;
	}
}