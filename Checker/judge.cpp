#include <bits/stdc++.h>
using namespace std;

namespace Judger {
    string taskName;
    int numTest;
    double pointPerTest;
    string inputFile;
    string outputFile;
    string answerFile;

    void registerJudge(const string &taskName, int numTest, double pointPerTest,
    const string &inputFile, const string &outputFile, const string &answerFile) {
        Judger::taskName = taskName; Judger::numTest = numTest;
        Judger::pointPerTest = pointPerTest; Judger::inputFile = inputFile;
        Judger::outputFile = outputFile; Judger::answerFile = answerFile;
    }

    string inputPath(int testIndex) {

    }

    string answerPath(int testIndex) {

    }

    bool checkAnswer() {
        return 1;
    }

    string execute(int testIndex, double &totalPoint) {
        system(("cp " + inputPath(testIndex) + " " + inputFile).data());
        system(("cp " + answerPath(testIndex) + " " + answerFile).data());
        system(("./" + taskName + " < " + inputFile + " > " + outputFile).data());
        return checkAnswer() ? totalPoint += pointPerTest, "Accepted" : "Wrong answer";
    }

    double judge() {
        double totalPoint = 0;
        for (int testIndex = 1; testIndex <= numTest; testIndex++) {
            cout << "Test " << testIndex << ". Status: ";
            auto start = clock();
            cout << execute(testIndex, totalPoint) << "; ";
            auto finish = clock();
            cout << "Time elapsed: " << finish - start << " ms\n";
        }
        return totalPoint;
    }
}

int main() {
}