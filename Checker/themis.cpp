#include <bits/stdc++.h>

#define task ""

typedef char NameFile[1000];

using namespace std;

NameFile input, output, answer;
ifstream in, out, ans;
const int N = 4;
int readInput() {
  in.open(input);
}
int readOutput() {
  out.open(output);
}
int readAnswer() {
  ans.open(answer);
}

void check() {

}

main() {
	gets(input);
	gets(output);
	strcpy(answer, input);
	strcat(input,  task".INP");
	strcat(output, task".OUT");
	strcat(answer, task".ANS");
	readInput();
	readOutput();
	readAnswer();
	check();
	in.close();
	out.close();
	ans.close();
}
