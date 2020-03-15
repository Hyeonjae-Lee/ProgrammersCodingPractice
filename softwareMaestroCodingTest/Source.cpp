#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <string.h>
#include <unordered_set>
#include <queue>
#include <string>

using namespace std;

int arr[10] = { 6,2,5,5,4,5,6,3,7,6 };
int brr[6] = { 2,3,5,7 };
int crr[100];

string cmp(string a, string b) {
	if (a.length() > b.length()) return a;
	else if (a.length() < b.length()) return b;
	else return max(a, b);
}

string func(int n) {
	string answer = "";
	string finalAnswer = "";
	long long int answer1 = 0;
	//n이 커져도 획이 가장 작은 것이 살아남는다.
	int temp = 1;
	int tempAnswerA = 0;
	int tempAnswerB = 0;
	
	crr[6] = 111;
	crr[5] = 71;
	crr[4] = 11;
	crr[3] = 7;
	crr[2] = 1;
	crr[1] = 0;

	for (int i = 0; i < 4; i++) {
		string answer = "";
		temp = brr[i];
		if (temp > n) break;

		tempAnswerA = n / temp;//몫
		tempAnswerB = n % temp;//나머지

		for (int j = 0; j < tempAnswerA; j++) {
			answer += to_string(crr[temp]);
		}
		if(crr[tempAnswerB] != 0) answer = cmp(answer + to_string(crr[tempAnswerB]), to_string(crr[tempAnswerB]) + answer);
		finalAnswer = cmp(answer, finalAnswer);
	}

	return finalAnswer;
}

int main() {
	int n;
	cin >> n;
	cout << func(n);
}