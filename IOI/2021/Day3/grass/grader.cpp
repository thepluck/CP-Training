#include "grass.h"
#include <iostream>
#include <vector>

int main() {
    int N, H, M;
    std::cin >> N >> H >> M;

    std::vector<char> events;
    std::vector<int> X;
    for (int i = 0; i < M; ++i) {
        char event; int x = 0;
        std::cin >> event;
        if (event != 'Z') {
            std::cin >> x;
        }

        events.push_back(event);
        X.push_back(x);
    }

    std::vector<long long> fertilizers = simulate(N, H, M, events, X);
    for (long long fertilizer: fertilizers) {
        std::cout << fertilizer << std::endl;
    }
}
