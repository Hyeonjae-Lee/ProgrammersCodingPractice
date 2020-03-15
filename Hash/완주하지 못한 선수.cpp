#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//string solution(vector<string> participant, vector<string> completion) {
//	string answer = "";
//	
//	sort(participant.begin(), participant.end());
//	sort(completion.begin(), completion.end());
//
//	for (int i = 0; i < participant.size() - 1; i++) {
//		if (participant[i] != completion[i]) {
//			answer = participant[i];
//			break;
//		}
//	}
//
//	if (answer == "") {
//		answer = participant[participant.size() - 1];
//	}
//
//	return answer;
//}

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";

	unordered_map<string, int> mymap;
	unordered_multiset<string> mysey;

	for (string name : participant) {
		mysey.insert(name);
	}

	for (string name : participant) {
		mymap[name]++;
	}

	for (string name : completion) {
		mymap[name]--;
	}

	for (auto name : mymap) {
		if (name.second > 0) {
			return name.first;
		}
	}

	return answer;
}

int main() {

	/*[leo, kiki, eden] [eden, kiki] leo
		[marina, josipa, nikola, vinko, filipa][josipa, filipa, marina, nikola]	vinko
		[mislav, stanko, mislav, ana][stanko, ana, mislav]*/

	vector<string> a = { "leo", "kiki", "eden" };
	vector<string> b = { "eden", "kiki" };
	
	string temp = solution(a, b);
	cout << temp;
}