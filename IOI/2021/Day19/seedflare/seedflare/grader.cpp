#include "seedflare.h"
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace {

int N, flower_count = 0, query_count = 0;
vector<int> input;
vector<int> cnt;

void WrongAnswer() {
	printf("Wrong Answer\n");
	exit(0);
}

} //namespace

int SeedFlare(vector<int> &v) {
	if ((int) v.size() > 1000000) WrongAnswer();
	int poison = 0;
	flower_count += (int) v.size();
	query_count++;
	for (int i = 0; i < (int) v.size(); i++) {
		if (v[i] <= 0 || v[i] > N) WrongAnswer();
		if (i > 0 && v[i] == v[i-1]) WrongAnswer();
		if (poison == 0) poison = v[i];
		else if (cnt[v[i]] > cnt[poison]) poison = 0;
	}
	return poison;
}

int main() {
	scanf("%d", &N);
	input.resize(N); cnt.resize(N+1);
	for (int i = 0; i < N; i++) {
		scanf("%d", &input[i]);
		cnt[input[i]] = i+1;
	}
	vector<int> res = SortFlowers(N);
	if ((int) res.size() != N) WrongAnswer();
	for (int i = 0; i < res.size(); i++) {
		if (res[i] != input[i]) WrongAnswer();
	}
	printf("Accepted: %d %d\n", query_count, flower_count);
	return 0;
}