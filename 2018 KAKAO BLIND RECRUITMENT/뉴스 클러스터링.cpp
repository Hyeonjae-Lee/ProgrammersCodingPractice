/* 2015112119 이현재 */

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>

using namespace std;

bool check1[10001];
bool check2[10001];

int solution(string str1, string str2) {
	int answer = 0;

	vector<string> vec1;
	vector<string> vec2;

	for (int i = 0; i < str1.size()-1; i++) {
		//영문자가 아닌경우 패스,
		//영문자를 모두 대소문자로

		if (((str1[i] >= 65 && str1[i] <= 90) || (str1[i] >= 97 && str1[i] <= 122))
			&& ((str1[i + 1] >= 65 && str1[i + 1] <= 90) || (str1[i + 1] >= 97 && str1[i + 1] <= 122))) {
			string temp = "";
			str1[i] = toupper(str1[i]);
			str1[i + 1] = toupper(str1[i + 1]);
			temp += str1[i];
			temp += str1[i + 1];
			vec1.push_back(temp);
		}
	}
	for (int i = 0; i < str2.size() - 1; i++) {
		//영문자 고려
		if (((str2[i] >= 65 && str2[i] <= 90) || (str2[i] >= 97 && str2[i] <= 122))
			&& ((str2[i + 1] >= 65 && str2[i + 1] <= 90) || (str2[i + 1] >= 97 && str2[i + 1] <= 122))) {
			string temp = "";
			str2[i] = toupper(str2[i]);
			str2[i + 1] = toupper(str2[i + 1]);
			temp += str2[i];
			temp += str2[i + 1];
			vec2.push_back(temp );
		}
	}

	vector<string> vec3 = vec2;//교집합

	//교집합만 찾으면 끝나는것
	for (int i = 0; i < vec1.size(); i++) {
		auto itr = find(vec3.begin(), vec3.end(), vec1[i]);
		if (itr != vec3.end())
		{
			vec3.erase(itr);
			answer++;
		}
	}
	if (vec2.empty() && vec1.empty()) return 65536;
	return 65536.0 * ((double)answer / (double)(vec1.size() + vec2.size() - answer));
	//. 집합 A와 집합 B가 모두 공집합일 경우에는 나눗셈이 정의되지 않으니 따로 J(A, B) = 1로 정의한다.
	// 교집합 / 합집합
	// tempAnswer = 합집합
	// vec3 = 교집합
}

int main() {
	string str1 = "abcd+d++de";
	string str2 = "ab+dd++ecd";

	cout << solution( str1,  str2);
}


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctype.h>

using namespace std;
int solution(string str1, string str2);
vector <string> makeArr(string str);

int main() {
	string str1 = "++++++bb";
	string str2 = "------aa";
	
	cout << solution( str1,  str2);
}

int solution(string str1, string str2) {
	int answer = 0;
	vector <string> sv1 = makeArr(str1);
	vector <string> sv2 = makeArr(str2);
	vector <string> sv = sv2;

	if (!sv1.size() && !sv2.size()) return 65536;

	for (int i = 0; i < sv1.size(); i++) {
		auto itr = find(sv.begin(), sv.end(), sv1[i]);
		if (itr != sv.end())
		{
			sv.erase(itr);
			answer++;
		}
	}
	return 65536.0 * ((double)answer / (double)(sv1.size() + sv2.size() - answer));
}

vector <string> makeArr(string str) {
	vector<string> sv;
	string sub;

	for (int i = 0; i < str.length() - 1; i++) {
		if (!isalpha(str[i]) || !isalpha(str[i + 1])) continue;
		sub = str.substr(i, 2);

		transform(sub.begin(), sub.end(), sub.begin(), towlower);
		sv.push_back(sub);
	}
	return sv;
}