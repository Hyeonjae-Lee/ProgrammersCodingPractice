#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>

//#define p pair<string, vector<vector<string>>>
//#define m(a,b) make_pair(a, b)

using namespace std;

struct mytype {
	string start1;
	vector<vector<string>> ticket;
	vector<string> route;
	/*bool operator()(mytype a, mytype b) {
		if (a.route.size() == b.route.size()) {
			return a.start1 > b.start1;
		}
		else return a.route.size() < b.route.size();
	}*/
};

//bool operator<(mytype a, mytype b) {
//	if (a.route.size() == b.route.size()) {
//		return a.start1 > b.start1;
//	}
//	else return a.route.size() < b.route.size();
//};

struct cmp {
	bool operator()(mytype a, mytype b) {
		if (a.route.size() == b.route.size()) {
			return a.start1 > b.start1;
		}
		else return a.route.size() < b.route.size();
	}
};

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	priority_queue<mytype, vector<mytype>, cmp> qu;
	vector<string> answer1;

	answer1.push_back("ICN");
	qu.push({ "ICN", tickets, answer1 });
	while (!qu.empty()) {
		mytype vec = qu.top();
		qu.pop();

		if (vec.ticket.size() == 0) {
			answer = vec.route;
			break;
		}

		for (int i = 0; i < vec.ticket.size(); i++) {
			if (vec.start1 == vec.ticket[i][0]) {
				vector<vector<string>> temp = vec.ticket;
				temp.erase(temp.begin() + i);
				vector<string> aa;
				aa = vec.route;
				string tempa = vec.ticket[i][1];
				aa.push_back(tempa);
				mytype a;
				a.start1 = tempa;
				a.ticket = temp;
				a.route = aa;
				qu.push(a);
			}
		}

	}

	return answer;
}

int main() {

	vector<vector<string>> tickets = { {"ICN","SFO"},{"ICN","ATL"},{"SFO","ATL"},  {"ATL","ICN"},{"ATL","SFO"} };
	
	vector<string> aa = solution(tickets);
	for (auto ele : aa) {
		cout << ele << " ";
	}

}