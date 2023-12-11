#include "balls.h"

void play(int n)
{
    std::vector<int> v(n);
    for(int i = 0; i < n; ++i) v[i] = i;
    int x = count_distinct(v);
    answer(v);
}
