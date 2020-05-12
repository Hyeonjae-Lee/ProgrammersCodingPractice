/* 2015112119 ÀÌÇöÀç */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <deque>

using namespace std;

vector<vector<int>> sortVec = { {1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1} };

long long solution(string expression) {
	long long answer = 0;

	vector<char> addvec;
	vector<long long> numvec;
	vector<char> addvec2 = addvec;

	for (int i = 0; i < expression.size(); i++) {
		if (expression[i] == '*' || expression[i] == '-' || expression[i] == '+') {
			addvec.push_back(expression[i]);
			expression[i] = ' ';
		}
	}

	sort(addvec2.begin(), addvec2.end());
	addvec2.erase(unique(addvec2.begin(), addvec2.end()), addvec2.end());

	stringstream ss;
	int irr;
	ss.str(expression);

	while (ss >> irr) numvec.push_back(irr);


	for (int i = 0; i < 6; i++) {

		vector<char> addtemp = addvec;
		vector<long long> numtemp = numvec;

		if (i == 0) {
			// *
			for (int i = 0; i < addtemp.size(); i++) {
				if (addtemp[i] == '*') {
					numtemp[i] *= numtemp[i + 1];
					numtemp[i + 1] = 0;
				}
			}

			vector<long long> numtemp2;
			vector<char> addtemp2;

			for (auto ele : numtemp) {
				if (ele != 0) numtemp2.push_back(ele);
			}for (auto ele : addtemp) {
				if (ele != '*') addtemp2.push_back(ele);
			}

			numtemp = numtemp2;
			addtemp = addtemp2;

			// + 
			for (int i = 0; i < addtemp.size(); i++) {
				if (addtemp[i] == '+') {
					numtemp[i] += numtemp[i + 1];
					numtemp[i + 1] = 0;
				}
			}

			numtemp2.clear();
			addtemp2.clear();

			for (auto ele : numtemp) {
				if (ele != 0) numtemp2.push_back(ele);
			}for (auto ele : addtemp) {
				if (ele != '+') addtemp2.push_back(ele);
			}
			numtemp = numtemp2;
			addtemp = addtemp2;

			// - 
			for (int i = 0; i < addtemp.size(); i++) {
				if (addtemp[i] == '-') {
					numtemp[i] -= numtemp[i + 1];
					numtemp[i + 1] = 0;
				}
			}

			numtemp2.clear();
			addtemp2.clear();

			for (auto ele : numtemp) {
				if (ele != 0) numtemp2.push_back(ele);
			}for (auto ele : addtemp) {
				if (ele != '-') addtemp2.push_back(ele);
			}
			numtemp = numtemp2;
			addtemp = addtemp2;

			long long valeu = 0;
			for (auto ele : numtemp) valeu += ele;

			answer = max(abs(answer), abs(valeu) );
		}
		else if (i == 1) {
			// *
			for (int i = 0; i < addtemp.size(); i++) {
				if (addtemp[i] == '*') {
					numtemp[i] *= numtemp[i + 1];
					numtemp[i + 1] = 0;
				}
			}

			vector<long long> numtemp2;
			vector<char> addtemp2;

			for (auto ele : numtemp) {
				if (ele != 0) numtemp2.push_back(ele);
			}for (auto ele : addtemp) {
				if (ele != '*') addtemp2.push_back(ele);
			}

			numtemp = numtemp2;
			addtemp = addtemp2;

			// + 
			for (int i = 0; i < addtemp.size(); i++) {
				if (addtemp[i] == '-') {
					numtemp[i] -= numtemp[i + 1];
					numtemp[i + 1] = 0;
				}
			}

			numtemp2.clear();
			addtemp2.clear();

			for (auto ele : numtemp) {
				if (ele != 0) numtemp2.push_back(ele);
			}for (auto ele : addtemp) {
				if (ele != '-') addtemp2.push_back(ele);
			}
			numtemp = numtemp2;
			addtemp = addtemp2;

			// - 
			for (int i = 0; i < addtemp.size(); i++) {
				if (addtemp[i] == '+') {
					numtemp[i] += numtemp[i + 1];
					numtemp[i + 1] = 0;
				}
			}

			numtemp2.clear();
			addtemp2.clear();

			for (auto ele : numtemp) {
				if (ele != 0) numtemp2.push_back(ele);
			}for (auto ele : addtemp) {
				if (ele != '+') addtemp2.push_back(ele);
			}
			numtemp = numtemp2;
			addtemp = addtemp2;

			long long valeu = 0;
			for (auto ele : numtemp) valeu += ele;

			answer = max(abs(answer), abs(valeu));
		}
		else if (i == 2) {
			// *
			for (int i = 0; i < addtemp.size(); i++) {
				if (addtemp[i] == '+') {
					numtemp[i] += numtemp[i + 1];
					numtemp[i + 1] = 0;
				}
			}

			vector<long long> numtemp2;
			vector<char> addtemp2;

			for (auto ele : numtemp) {
				if (ele != 0) numtemp2.push_back(ele);
			}for (auto ele : addtemp) {
				if (ele != '+') addtemp2.push_back(ele);
			}

			numtemp = numtemp2;
			addtemp = addtemp2;

			// + 
			for (int i = 0; i < addtemp.size(); i++) {
				if (addtemp[i] == '*') {
					numtemp[i] *= numtemp[i + 1];
					numtemp[i + 1] = 0;
				}
			}

			numtemp2.clear();
			addtemp2.clear();

			for (auto ele : numtemp) {
				if (ele != 0) numtemp2.push_back(ele);
			}for (auto ele : addtemp) {
				if (ele != '*') addtemp2.push_back(ele);
			}
			numtemp = numtemp2;
			addtemp = addtemp2;

			// - 
			for (int i = 0; i < addtemp.size(); i++) {
				if (addtemp[i] == '-') {
					numtemp[i] -= numtemp[i + 1];
					numtemp[i + 1] = 0;
				}
			}

			numtemp2.clear();
			addtemp2.clear();

			for (auto ele : numtemp) {
				if (ele != 0) numtemp2.push_back(ele);
			}for (auto ele : addtemp) {
				if (ele != '-') addtemp2.push_back(ele);
			}
			numtemp = numtemp2;
			addtemp = addtemp2;

			long long valeu = 0;
			for (auto ele : numtemp) valeu += ele;

			answer = max(abs(answer), abs(valeu));
		}
		else if (i == 3) {

			// *
			for (int i = 0; i < addtemp.size(); i++) {
				if (addtemp[i] == '+') {
					numtemp[i] += numtemp[i + 1];
					numtemp[i + 1] = 0;
				}
			}

			vector<long long> numtemp2;
			vector<char> addtemp2;

			for (auto ele : numtemp) {
				if (ele != 0) numtemp2.push_back(ele);
			}for (auto ele : addtemp) {
				if (ele != '+') addtemp2.push_back(ele);
			}

			numtemp = numtemp2;
			addtemp = addtemp2;

			// + 
			for (int i = 0; i < addtemp.size(); i++) {
				if (addtemp[i] == '-') {
					numtemp[i] -= numtemp[i + 1];
					numtemp[i + 1] = 0;
				}
			}

			numtemp2.clear();
			addtemp2.clear();
			for (auto ele : numtemp) {
				if (ele != 0) numtemp2.push_back(ele);
			}for (auto ele : addtemp) {
				if (ele != '-') addtemp2.push_back(ele);
			}
			numtemp = numtemp2;
			addtemp = addtemp2;

			// - 
			for (int i = 0; i < addtemp.size(); i++) {
				if (addtemp[i] == '*') {
					numtemp[i] *= numtemp[i + 1];
					numtemp[i + 1] = 0;
				}
			}

			numtemp2.clear();
			addtemp2.clear();

			for (auto ele : numtemp) {
				if (ele != 0) numtemp2.push_back(ele);
			}for (auto ele : addtemp) {
				if (ele != '*') addtemp2.push_back(ele);
			}
			numtemp = numtemp2;
			addtemp = addtemp2;

			long long valeu = 0;
			for (auto ele : numtemp) valeu += ele;

			answer = max(abs(answer), abs(valeu));
		}
		else if (i == 4) {
			// *
			for (int i = 0; i < addtemp.size(); i++) {
				if (addtemp[i] == '-') {
					numtemp[i] -= numtemp[i + 1];
					numtemp[i + 1] = 0;
				}
			}

			vector<long long> numtemp2;
			vector<char> addtemp2;

			for (auto ele : numtemp) {
				if (ele != 0) numtemp2.push_back(ele);
			}for (auto ele : addtemp) {
				if (ele != '-') addtemp2.push_back(ele);
			}

			numtemp = numtemp2;
			addtemp = addtemp2;

			// + 
			for (int i = 0; i < addtemp.size(); i++) {
				if (addtemp[i] == '*') {
					numtemp[i] *= numtemp[i + 1];
					numtemp[i + 1] = 0;
				}
			}

			numtemp2.clear();
			addtemp2.clear();

			for (auto ele : numtemp) {
				if (ele != 0) numtemp2.push_back(ele);
			}for (auto ele : addtemp) {
				if (ele != '*') addtemp2.push_back(ele);
			}
			numtemp = numtemp2;
			addtemp = addtemp2;

			// - 
			for (int i = 0; i < addtemp.size(); i++) {
				if (addtemp[i] == '+') {
					numtemp[i] += numtemp[i + 1];
					numtemp[i + 1] = 0;
				}
			}

			numtemp2.clear();
			addtemp2.clear();

			for (auto ele : numtemp) {
				if (ele != 0) numtemp2.push_back(ele);
			}for (auto ele : addtemp) {
				if (ele != '+') addtemp2.push_back(ele);
			}
			numtemp = numtemp2;
			addtemp = addtemp2;

			long long valeu = 0;
			for (auto ele : numtemp) valeu += ele;

			answer = max(abs(answer), abs(valeu));
		}
		else if (i == 5) {
			// *
			for (int i = 0; i < addtemp.size(); i++) {
				if (addtemp[i] == '-') {
					numtemp[i] -= numtemp[i + 1];
					numtemp[i + 1] = 0;
				}
			}

			vector<long long> numtemp2;
			vector<char> addtemp2;

			for (auto ele : numtemp) {
				if (ele != 0) numtemp2.push_back(ele);
			}for (auto ele : addtemp) {
				if (ele != '-') addtemp2.push_back(ele);
			}

			numtemp = numtemp2;
			addtemp = addtemp2;

			// + 
			for (int i = 0; i < addtemp.size(); i++) {
				if (addtemp[i] == '+') {
					numtemp[i] += numtemp[i + 1];
					numtemp[i + 1] = 0;
				}
			}

			numtemp2.clear();
			addtemp2.clear();

			for (auto ele : numtemp) {
				if (ele != 0) numtemp2.push_back(ele);
			}for (auto ele : addtemp) {
				if (ele != '+') addtemp2.push_back(ele);
			}
			numtemp = numtemp2;
			addtemp = addtemp2;

			// - 
			for (int i = 0; i < addtemp.size(); i++) {
				if (addtemp[i] == '*') {
					numtemp[i] *= numtemp[i + 1];
					numtemp[i + 1] = 0;
				}
			}

			numtemp2.clear();
			addtemp2.clear();

			for (auto ele : numtemp) {
				if (ele != 0) numtemp2.push_back(ele);
			}for (auto ele : addtemp) {
				if (ele != '*') addtemp2.push_back(ele);
			}
			numtemp = numtemp2;
			addtemp = addtemp2;

			long long valeu = 0;
			for (auto ele : numtemp) valeu += ele;

			answer = max(abs(answer), abs(valeu));
		}
	}
	return answer;
}

int main() {
	

	solution("100 - 200 * 300 - 500 + 20");
}