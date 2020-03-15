#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#define pairing pair<string, int>
#define m(a,b); make_pair(a, b) 

using namespace std;

template<template <typename> class P = std::less >
struct compare_pair_second {
	template<class T1, class T2> bool operator()(const std::pair<T1, T2>& left, const std::pair<T1, T2>& right) {
		return P<T2>()(left.second, right.second);
	}
};

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	multimap<string, int> mymap;
	map<string, int> tempMap;
	for (int i = 0; i < genres.size(); i++) {
		mymap.insert({ genres[i], plays[i] });
		tempMap.insert({ genres[i], 0 });
	}
	int j = 0;
	for (auto ele : tempMap) {
		int sum = 0;
		auto range = mymap.equal_range(ele.first);
		for (auto tempele = range.first; tempele != range.second; tempele++ ) {
			sum += tempele->second;
		}
		tempMap[ele.first]=sum;
	}

	vector<pair<string, int> > vec(tempMap.begin(), tempMap.end());
	sort(vec.begin(), vec.end(), compare_pair_second<std::greater>());

	for (int i = 0; i < vec.size(); i++) {
		vector<pair<int, int>> tempvec;
		for (int j = 0; j < genres.size(); j++) {
			if (vec[i].first == genres[j]) {
				tempvec.push_back({ -plays[j], j });
			}
		}
		sort(tempvec.begin(), tempvec.end());
		
		if (tempvec.size() > 1) {
			answer.push_back( tempvec[0].second);
			answer.push_back(tempvec[1].second);
		}
		else {
			answer.push_back(tempvec[0].second);
		}
	}

	return answer;
}


int main() {
	vector<string> arr = { "classic", "pop", "classic", "classic", "pop" };
	vector<int> srr = { 500,600,150,800,2500 };
	solution(arr, srr);

}