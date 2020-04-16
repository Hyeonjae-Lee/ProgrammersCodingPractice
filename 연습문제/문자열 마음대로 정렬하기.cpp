#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int point = 0;

bool desc(string arr, string brr) {
	if (arr[point] == brr[point]) {
		//같은경우
		return arr < brr;
	}
	else {
		return arr[point] < brr[point];
	}
}

vector<string> solution(vector<string> strings, int n) {
	vector<string> answer;

	point = n;

	sort(strings.begin(), strings.end(), desc);
	answer = strings;

	return answer;
}