#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#define p pair<int, pair<int, string>>
#define mp(a, b) make_pair(a, b)
using namespace std;

bool check[51];
int length = 0;
string target1 = "";
vector<string> vec;
int aaa = 9999999;

int finalitem = 9999999;

void dfs(string begin, int answer) {
	
	if (begin == target1) {
		finalitem = min(finalitem, answer + 1);
		return;
	}

	for (int i = 0; i < vec.size(); i++) {
		if (!check[i]) {
			int a = 0;
			for (int j = 0; j < vec[i].size(); j++) {
				if (vec[i][j] == begin[j]) a++;
			}

			if (begin.length() - a == 1 ) {
				check[i] = true;
				dfs(vec[i], answer + 1);
				check[i] = false;
			}
		}
	}
	return;
}

int solution(string begin, string target, vector<string> words) {
	int answer = 0;
	target1 = target;
	length = words.size();
	for (string name : words) vec.push_back(name);

	int i = 0;
	for (string name : words) {
		int a = 0;
		finalitem = 9999999;
		memset(check, false, sizeof(check));
		for (int j = 0; j < name.size(); j++) {
			if (name[j] == begin[j]) a++;
		}

		if (begin.length() - a == 1) {
			check[i] = true;
			dfs(vec[i], 0);
			aaa = min(finalitem, aaa);
			check[i] = false;
		}i++;
	}

	answer = aaa;
	if (answer == 9999999) return 0;
	return answer;
}

int main() {
	string target = "cog", begin = "hit";
	vector<string> words = { "hot","dot","dog","lot","log","cog"};

	solution(begin, target, words);
}