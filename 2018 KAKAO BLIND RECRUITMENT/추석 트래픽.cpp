/* 2015112119 ÀÌÇöÀç */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

int solution(vector<string> lines) {
	int answer = 0;

	vector<vector<string>> vec;

	for (int i = 0; i < lines.size(); i++) {		
		vector<string> temp;
		string trr;
		stringstream ss;
		ss.str(lines[i]);
		while ( ss >> trr ) {
			temp.push_back(trr);
		}
		vec.push_back(temp);
	}

	for (int i = 0; i < vec.size(); i++) {
		string temp = vec[i][1].substr(6);
		double tempa = stod(temp);

		temp = vec[i][2].substr(0, vec[i][2].size() - 1);
		double tempb = stod(temp);


	}

	return answer;
}

int main() {
	vector<string> lines= {"2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"};

	solution(lines);
}