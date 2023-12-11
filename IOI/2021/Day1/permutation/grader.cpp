#include "permutation.h"
#include <iostream>
#include <vector>
#include <cstring>

static const int Nmax = 500;

static int N, p[Nmax], nrq = 0;
static int ap[Nmax];
static bool found = 0;

void WA(std::string msg) {
    std::cout << "WA" << std::endl;
    std::cout << msg << std::endl;
    exit(1);
}

void AC() {
    std::cout << "AC" << std::endl;
    std::cout << "Number of queries: " << nrq << std::endl;
}

int query(std::vector<int> q) {
    ++nrq;

    if(nrq > 100) {
        WA("Too many queries");
    }

    if(q.size() != N) {
        WA("Wrong query format");
    }

    for (int i = 1; i <= N; ++i) {
        ap[i] = 0;
    }

    for (auto it : q) {
        if (!(it >= 1 && it <= N)) {
            WA("Is not a permutation");
        }

        ap[it]++;
    }

    for(int i = 1; i <= N; ++i) {
        if (ap[i] != 1) {
            WA("Is not a permutation");
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        cnt += (q[i] == p[i]);
    }

    if (cnt == N) {
        AC();
        found = 1;
    }

    return cnt;
}

int main() {
    if (!(std::cin >> N)) {
        WA("Error reading input");
    }

    for(int i = 0; i < N; ++i) {
        if (!(std::cin >> p[i])) {
            WA("Error reading input");
        }
    }

    solve(N);

    if (!found) {
        WA("Answer not found");
    }

	return 0;
}
