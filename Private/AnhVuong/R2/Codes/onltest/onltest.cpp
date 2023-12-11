#include <bits/stdc++.h>
#include "onltest.h"

using namespace std;

int color[105], cnt[3];

string online_test(int A, int B, int C) {
    int N = A + B + C;
    string sampleAnswer;
    for (int i = 0; i < A; i++)
        sampleAnswer.push_back('A');
    for (int i = 0; i < B; i++)
        sampleAnswer.push_back('B');
    for (int i = 0; i < C; i++)
        sampleAnswer.push_back('C');
    int initCorrect = submit(sampleAnswer);
    for (int i = 1; i < N; i++)
        if (sampleAnswer[i] != sampleAnswer[0]) {
            swap(sampleAnswer[i], sampleAnswer[0]);
            int currentCorrect = submit(sampleAnswer);
            swap(sampleAnswer[i], sampleAnswer[0]);
            if (currentCorrect == initCorrect + 2
            || currentCorrect == initCorrect - 1)
                color[i] = sampleAnswer[0] - sampleAnswer[i];
            if (currentCorrect == initCorrect - 2
            || currentCorrect == initCorrect + 1)
                color[i] = sampleAnswer[i] - sampleAnswer[0];
        }
    for (int i = 1; i < N; i++)
        if (sampleAnswer[i] == sampleAnswer[0]
        && sampleAnswer[i] != sampleAnswer[N - 1]) {
            swap(sampleAnswer[i], sampleAnswer[N - 1]);
            int currentCorrect = submit(sampleAnswer);
            swap(sampleAnswer[i], sampleAnswer[N - 1]);
            if (currentCorrect == initCorrect + 2
            || currentCorrect == initCorrect - 1)
                color[i] = color[N - 1] +
                sampleAnswer[N - 1] - sampleAnswer[i];
            if (currentCorrect == initCorrect - 2
            || currentCorrect == initCorrect + 1)
                color[i] = color[N - 1] +
                sampleAnswer[i] - sampleAnswer[N - 1];
            if (currentCorrect == initCorrect)
                color[i] = color[N - 1];
        }
    
    for (int i = 0; i < N; i++)
        cnt[color[i] = (color[i] % 3 + 3) % 3]++;
    string correctAnswer;
    for (int col = 0; col < 3; col++)
        if (cnt[col] == A &&
        cnt[(col + 1) % 3] == B &&
        cnt[(col + 2) % 3] == C) {
            for (int i = 0; i < N; i++)
                correctAnswer.push_back
                ((color[i] - col + 3) % 3 + 'A');
        }
    return correctAnswer;
}