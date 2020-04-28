/* 2015112119 이현재 */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

bool check[1001];

int solution(string str1, string str2) {
	int answer = 0;

	vector<string> vec1;
	vector<string> vec2;

	for (int i = 0; i < str1.size()-1; i++) {
		vec1.push_back("" + str1[i] + str1[i + 1]);
	}
	for (int i = 0; i < str2.size() - 1; i++) {

		//영문자 고려
		vec2.push_back("" + str2[i] + str2[i + 1]);
	}

	//교집합만 찾으면 끝나는것

	for (int i = 0; i < str1.size() - 1; i++) {
		vec1.push_back("" + str1[i] + str1[i + 1]);
	}


	return answer;
}

int main() {

}