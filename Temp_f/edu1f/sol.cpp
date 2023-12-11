#include <bits/stdc++.h>

/*** TEMPLATE CODE STARTS HERE ***/

using namespace std;
typedef vector<string> vs;
typedef long long ll;
typedef complex<ll> pnt;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define RA(x) begin(x), end(x)
#define FE(i, x) for (auto i = begin(x); i != end(x); ++i)
#define SZ(x) ((ll)(x).size())

template <typename T>
static inline T dot(const std::complex<T> &a, const std::complex<T> &b) {
    return real(conj(a) * b);
}

template <typename T>
static inline T cross(const std::complex<T> &a, const std::complex<T> &b) {
    return imag(conj(a) * b);
}

template <typename T>
static inline T cross(const std::complex<T> &a, const std::complex<T> &b, const std::complex<T> &c) {
    return cross(b - a, c - a);
}

static ll get_coord() {
    double x;
    cin >> x;
    return ll(round(x * 100.0));
}

static pnt get_pnt() {
    ll x, y;
    x = get_coord();
    y = get_coord();
    return pnt(x, y);
}

struct event {
    double x;
    int d;

    bool operator<(const event &other) const
    {
        return x < other.x;
    }

    event(double x, int d) : x(x), d(d) {}
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<pnt> pnts;
    ll area = 0;
    for (int i = 0; i < N; i++)
        pnts.push_back(get_pnt());
    for (int i = 0; i < N; i++)
        area += cross(pnts[i], pnts[(i + 1) % N]);
    if (area < 0)
        reverse(RA(pnts));

    cout << fixed << setprecision(12);
    for (int i = 0; i < M; i++) {
        pnt a = get_pnt();
        pnt b = get_pnt();
        vector<event> events;
        for (int i = 0; i < N; i++)
        {
            pnt p = pnts[i];
            pnt q = pnts[(i + 1) % N];
            ll cp = cross(a, b, p);
            ll cq = cross(a, b, q);
            bool up_p = cp >= 0;
            bool up_q = cq >= 0;
            if (up_p != up_q)
            {
                double cut = (dot(b - a, p) * double(cq) - dot(b - a, q) * double(cp)) / (cq - cp);
                events.emplace_back(cut, up_p ? 1 : -1);
            }
            else if (cp == 0 && cq == 0)
            {
                double dp = dot(b - a, p);
                double dq = dot(b - a, q);
                if (dp > dq)
                    swap(dp, dq);
                events.emplace_back(dp, 1);
                events.emplace_back(dq, -1);
            }
        }

        sort(RA(events));
        int level = 0;
        double last = 0;
        double ans = 0;
        for (const event &e : events)
        {
            if (level)
                ans += e.x - last;
            last = e.x;
            level += e.d;
        }
        ans /= sqrt(dot(b - a, b - a)) * 100.0;
        cout << ans << '\n';
    }
}
