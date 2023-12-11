#include "stagegames.h"
#include <bits/stdc++.h>
using namespace std;

int Q, T, N, C[500], B[500], calls = 0;
bool seen[505];

void check_permutation(int *A) {
	for (int i = 1; i <= N; i++) {
		seen[i] = false;
	}
	for (int i = 0; i < N; i++) {
		if (A[i] < 1 || A[i] > N || seen[A[i]]) {
			printf("Not a permutation!\n");
			exit(0);
		}
		seen[A[i]] = true;
	}
}

int ask1(int *A) {
	calls++;
	check_permutation(A);
	
	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (A[i] == C[j]) {
				B[i] = j+1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (B[i] > B[j]) {
				count++;
			}
		}
	}
	
	return count;
}

int ask2(int *A) {
	calls++;
	check_permutation(A);
	int total = 0;
	for (int i = 0; i < N; i++) {
		total += abs(A[i] - C[i]);
	}
	return total;
}

void answer(int *A) {
	bool correct = true;
	for (int i = 0; i < N; i++)
		if (A[i] != C[i])
			correct = false;
	if (!correct) {
		for (int i = 0; i < N; i++)
			cout << A[i] << ' '<< C[i] << '\n';
		exit(0);
	}
	// printf("Calls: %d\n", calls);
}

int main() {

	// scanf("%d%d", &Q, &T);
	// for (int i = 0; i < Q; i++) {
	// 	scanf("%d", &N);
	// 	for (int j = 0; j < N; j++) {
	// 		scanf("%d", &C[j]);
	// 	}

	// 	check_permutation(C);

	// 	calls = 0;
	// 	if (T == 1) {
	// 		play1(N);
	// 	}
	// 	else {
	// 		play2(N);
	// 	}
	// }
	cin >> N;
	iota(C, C + N, 1);
	do {
		play2(N);
	} while (next_permutation(C, C + N));

	return 0;
}

