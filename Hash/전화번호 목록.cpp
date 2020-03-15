#include <string>
#include <vector>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool desc(string a, string b) {

	return a > b;
}

//bool solution(vector<string> phone_book) {
//	bool answer = true;
//	sort(phone_book.begin(), phone_book.end());
//
//	for (int i = 0; i < phone_book.size(); i++) {
//		if (phone_book[i] == phone_book[i + 1].substr(0, phone_book[i].size()) ) {
//			answer = false;
//			return answer;
//		}
//	}
//	return answer;
//}

int main() {

	/*[leo, kiki, eden] [eden, kiki] leo
		[marina, josipa, nikola, vinko, filipa][josipa, filipa, marina, nikola]	vinko
		[mislav, stanko, mislav, ana][stanko, ana, mislav]*/

	vector<string> a = { "leo", "kiki", "eden" };
	vector<string> b = { "eden", "kiki" };

	//bool temp = solution(a);
}