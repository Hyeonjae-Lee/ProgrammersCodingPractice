/* 2015112119 ÀÌÇöÀç */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

string solution(string s) {
	string answer = "";

	stringstream ss;
	ss.str(s);

	int a;
	vector<int> vec;
	while (ss >> a) {
		vec.push_back(a);
	}

	sort(vec.begin(), vec.end());
	int firsta = vec.front();
	int enda = vec.back();

	answer += to_string(firsta);
	answer += " ";
	answer += to_string(enda);

	return answer;
}

int main() {

}