/* 2015112119 이현재 */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

bool desc(vector<string> vec1, vector<string> vec2) {
	string temp1 = vec1[0];
	string temp2 = vec2[0];

	transform(temp1.begin(), temp1.end(), temp1.begin(), ::toupper);
	transform(temp2.begin(), temp2.end(), temp2.begin(), ::toupper);

	if (temp1 == temp2) {
		return stoi(vec1[1]) < stoi(vec2[1]);
	}
	else return temp1 < temp2;
}

vector<string> solution(vector<string> files) {
	vector<string> answer;
	vector<vector<string>> vec;

	for (int i = 0; i < files.size(); i++) {
		string temp1 = "";
		string temp2 = "";
		string temp3 = "";
		bool check1 = false;
		int check2 = 0;
		vector<string> temp;
		for (int j = 0; j < files[i].size(); j++) {
			if (!check1 && !(files[i][j] >= 48 && files[i][j] <= 57)) {
				//HEAD 부분이고 숫자가 아닌경우
				temp1 += files[i][j];
			}
			else {
				check1 = true;
				if (files[i][j] >= 48 && files[i][j] <= 57) {
					temp2 += files[i][j];
				}
				else {
					temp3 += files[i].substr(j);
					string tempSrr = "";
					tempSrr += (char)(i + '0');
					temp.push_back(temp1);
					temp.push_back(temp2);
					temp.push_back(temp3);
					temp.push_back(tempSrr);
					break;
				}
			}
		}

		if (temp.empty()) {
			string tempSrr = "";
			tempSrr += (char)(i + '0');
			temp.push_back(temp1);
			temp.push_back(temp2);
			temp.push_back(temp3);
			temp.push_back(tempSrr);
		}

		vec.push_back(temp);
	}

	//sort는 퀵정렬이라 불안정한 정렬
	//stable_sort는 안정한 정렬
	stable_sort(vec.begin(), vec.end(), desc);

	for (auto ele : vec) {
		string temp = "";
		for (int i = 0; i < 3; i++) {
			temp += ele[i];
		}
		answer.push_back(temp);
	}

	return answer;
}

bool Pred(vector<string> a, vector<string> b) {
	string a1;
	string b1;
	for (int i = 0; i < a[0].size(); i++) {
		a1 += toupper(a[0][i]);
	}
	for (int i = 0; i < b[0].size(); i++) {
		b1 += toupper(b[0][i]);
	}
	if (a1.compare(b1) == 0) {
		return stoi(a[1]) < stoi(b[1]);
	}
	if (a1.compare(b1) > 0)
		return false;
	else
		return true;
}

vector<string> solution1(vector<string> files) {
	vector<string> answer;
	vector<vector<string>> data(files.size(), vector<string>(3));

	int temp = 0;
	int j = 0;
	for (int i = 0; i < files.size(); i++) {
		j = 0;
		temp = 0;
		while (j < files[i].size()) {
			if ((files[i][j] < '0' || files[i][j] > '9')) {
				data[i][temp] += files[i][j];
			}
			else {
				temp++;
				break;
			}
			j++;
		}
		while (j < files[i].size()) {
			if (files[i][j] >= '0' && files[i][j] <= '9') {
				data[i][temp] += files[i][j];
			}
			else {
				temp++;
				break;
			}
			j++;
		}
		while (j < files[i].size()) {
			data[i][temp] += files[i][j];
			j++;
		}
	}
	stable_sort(data.begin(), data.end(), Pred);

	for (int i = 0; i < files.size(); i++) {
		answer.push_back(data[i][0] + data[i][1] + data[i][2]);
	}
	return answer;
}

int main() {
	
	//vector<string> files = { "g123124fdsa.sdfa", "G123122aaaa.sdfs", "zz0024zz.zip", "zz001.zip", "aVCd012.sdf", "aVCd00120.sdf", "aVCd0012.sdf"  };
	//vector<string> files = { "g000000700fdsa.sdfa", "g000100fdsa.sdfa","g000000600fdsa.sdfa","g000000600DDDD.sdfa","g00000010fdsa.sdfa","g00000005fdsa.sdfa","g0000001fdsa.sdfa" };
	vector<string> files = { "A1111155", "a2", "A1111132", "a44" };
	vector<string> vrr = solution(files);
	vector<string> vrr2 = solution1(files);

	for (auto ele : vrr) {
		cout << ele << " ";
	}
	cout << endl;
	for (auto ele : vrr2) {
		cout << ele << " ";
	}
}