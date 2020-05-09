/* 2015112119 ������ */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> operations) {
	vector<int> answer;

	vector<vector<string>> vec;
	for (int i = 0; i < operations.size(); i++) {
		vector<string> temp;
		stringstream ss;
		string srr;

		ss.str(operations[i]);

		while (ss >> srr) temp.push_back(srr);
		
		vec.push_back(temp);
	}
	
	priority_queue<int> qu;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i][0] == "I") {//����
			qu.push( atoi(vec[i][1].c_str()) );
		}
		else {// ����
			if (!qu.empty()) {
				if (vec[i][1] == "1") {
					//ť���� �ִ��� �����Ѵ�.
					qu.pop();
				}else if (vec[i][1] == "-1") {
					//ť���� �ּҰ��� �����Ѵ�.
					deque<int> tempdeq;
					while (!qu.empty()) {
						tempdeq.push_back(qu.top());
						qu.pop();
					}

					tempdeq.pop_back();
					while (!tempdeq.empty()) {
						qu.push(tempdeq.front());
						tempdeq.pop_front();
					}
				}
			}
		}
	}

	if (qu.empty()) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		answer.push_back(qu.top());
		vector<int> tempdeq;
		while (!qu.empty()) {
			tempdeq.push_back(qu.top());
			qu.pop();
		}
		answer.push_back(tempdeq.back());
	}

	return answer;
}