/* 2015112119 ÀÌÇöÀç */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

int solution(string str1, string str2) {
	int answer = 0;

	vector<string> vec1;
	vector<string> vec2;

	for (int i = 0; i < str1.size()-1; i++) {
		vec1.push_back("" + str1[i] + str1[i + 1]);
	}
	for (int i = 0; i < str2.size() - 1; i++) {
		vec2.push_back("" + str2[i] + str2[i + 1]);
	}



	return answer;
}

int main() {

}