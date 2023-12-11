#include "balls.cpp"
#define MAX_QUERIES 12000

#include <cstdio>
#include <cstdlib>
#include <cassert>

const int MAXN = 160;

int _n, _m, _balls[MAXN];
int _a[MAXN], _b[MAXN];
int _query_number = 0;

int count_distinct(const std::vector<int>& v)
{
    _query_number++;
    for (int i = 0; i <= _n; ++ i) _a[i] = _b[i] = 0;

    printf("count_distinct: %d", v.size());
    for (int i = 0; i < v.size(); ++ i) printf(" %d", v[i]);
    printf("\n");

    if (_query_number > MAX_QUERIES)
    {
        printf("Too many questions\n");
        exit(0);
    }
    if (v.size() == 0 or v.size() > _n)
    {
        printf("Question is not valid\n");
        exit(0);
    }
    for (int i = 0; i < v.size(); ++ i)
    {
        if (v[i] < 0 or v[i] >= _n or _a[v[i]] == 1)
        {
            printf("Question is not valid\n");
            exit(0);
        }
        _a[v[i]] = 1;
    }

    int ans = 0;
    for (int i = 0; i < v.size(); ++ i)
    {
        if (_b[_balls[v[i]]] == 0)
        {
            _b[_balls[v[i]]] = 1;
            ans++;
        }
    }

    printf("answer: %d\n", ans);
    return ans;
}

void answer(const std::vector<int>& v)
{
    printf("answer:");
    for (int i = 0; i < v.size(); ++ i) printf(" %d", v[i]);
    printf("\n");

    if (v.size() != _n)
    {
        printf("Contestant's answer is not valid\n");
        exit(0);
    }
    for (int i = 0; i < _n; ++ i)
    {
        if (v[i] < 1 or v[i] > _m)
        {
            printf("Contestant's answer is not valid\n");
            exit(0);
        }
    }

    for (int i = 0; i < _n; ++ i)
    {
        for (int j = i + 1; j < _n; ++ j)
        {
            if ((v[i] == v[j] and _balls[i] != _balls[j]) or (v[i] != v[j] and _balls[i] == _balls[j]))
            {
                printf("Colours of balls are not correctly assigned\n");
                exit(0);
            }
        }
    }

    printf("Correct with total questions used: %d\n", _query_number);

    exit(0);
}

int main()
{
    scanf("%d", &_n);
    for (int i = 0; i < _n; ++ i)
    {
        scanf("%d", &_balls[i]);
        if (_a[_balls[i]] == 0)
        {
            _a[_balls[i]] = 1;
            _m++;
        }
    }

    play(_n);

    return 0;
}
