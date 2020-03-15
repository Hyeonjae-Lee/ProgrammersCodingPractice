#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 0;

	unordered_multimap<string, string> mymap;
	unordered_map<string, string> mymap2;
	//for (int i = 0; i < clothes.size(); i++) {
	//	//clothes[i][1];
	//	mymap.insert({ clothes[i][1], clothes[i][0] });
	//}

	int j = 0;
	for (vector<string> temp : clothes) {
		mymap.insert({ temp[1], temp[0] });
		mymap2.insert({ temp[1], temp[1] });
	}

	vector<int> vec;
	for (auto temp: mymap2) {
		auto range = mymap.equal_range(temp.first);
		int sum = 0;
		for (auto ele = range.first; ele != range.second; ele++) {
			sum++;
		}
		vec.push_back(sum);
	}

	answer = 1;

	for (int i : vec) {
		answer *= (i + 1);
	}

	return answer - 1;
}

int main() {

	vector<vector<string>> clothes = { {"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"} };

	cout << solution(clothes);
}