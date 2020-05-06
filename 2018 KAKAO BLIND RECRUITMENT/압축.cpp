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
	} // ���ĺ��� 65 ~ 90

	for (int i = 0; i < msg.size();) {
		int temp = 0;
		string tempsrr = "";
		map<string, int>::iterator iter;
		
		// �ϳ��� �����ض�
		int j = 1;
		while (true) {

			if (i + j > msg.size()) {
				if (!tempsrr.empty()) {
					// ã���Ŵϱ�
					answer.push_back(temp);
					string trr = "";
					trr += tempsrr;
				}
				i += j;
				break;
			}

			if (myMap.find(msg.substr(i, j)) != myMap.end()) {
				// ���Ҹ� ã�Ҵٴ� �ǹ�
				// ���Ҹ� ã������ ���� ū�� ���ؾ� �ϴ� j�� �� ũ�� �ؼ� ã�´�. 
				if (temp < myMap[msg.substr(i, j)]) {
					temp = myMap[msg.substr(i, j)];
					tempsrr = msg.substr(i, j);
				} j++;
			}
			else {
				// ���Ҹ� ��ã����
				// ���Ҹ� ��ã������ �������� ã�� ������ �ִ��� �־� �־�� �Ѵ�. 
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