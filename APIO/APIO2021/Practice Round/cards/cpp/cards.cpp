#include "cards.h"
#include <bits/stdc++.h>

using namespace std;

template <class X, class Y>
bool cmax(X &a, const Y &b) {
    return a < b ? a = b, 1 : 0;
}

const int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040};

int N, K;

void init_magician(int N, int K) {
    ::N = N; ::K = K;
}

void init_assistant(int N, int K) {
    ::N = N; ::K = K;
}

int order_of_per(vector <int> per) {
    int ord = 0;
    for (int i = 1; i < K; i++) {
        int cnt = 0;
        for (int j = i; j < K - 1; j++)
            cnt += per[j] < per[i - 1];
        ord += cnt * fac[K - 1 - i];
    }
    return ord + 1;
}

vector <int> per_of_order
(int ord, vector <int> num) {
    vector <int> per; ord--;
    for (int i = 1; i < K; i++) {
        per.push_back(num[ord / fac[K - 1 - i]]);
        num.erase(num.begin() + ord / fac[K - 1 - i]);
        ord %= fac[K - 1 - i];
    }
    return per;
}

vector <int> choose_cards(vector <int> cards) {
    if (cards[K - 1] - cards[K - 2] <= fac[K - 1]) {
        int ord = cards[K - 1] - cards[K - 2];
        cards.pop_back();
        return per_of_order(ord, cards);
    }
    int ord = N - cards[K - 1] + cards[0];
    cards.erase(cards.begin());
    return per_of_order(ord, cards);
}

int find_discarded_card(vector <int> cards) {
    int ord = order_of_per(cards);
    return (*max_element(cards.begin(), cards.end()) + ord - 1) % N + 1;
}
