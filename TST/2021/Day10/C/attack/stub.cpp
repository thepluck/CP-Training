#include "attack.h"

#include <iostream>
#include <string>

using namespace std;

int main() {
	string queryType, message;
	cin >> queryType;
	
	if (queryType == "ENCODE") {
		int dd;
		int hh;
		int mm;
		cin >> dd >> hh >> mm;
		string message = "00 00:00";
		message[0] += dd / 10;
		message[1] += dd % 10;

		message[3] += hh / 10;
		message[4] += hh % 10;

		message[6] += mm / 10;
		message[7] += mm % 10;
		cout << encode(message) << endl;
	}
	if (queryType == "DECODE" ) {
		cin >> message;
		cout << decode(message) << endl;
	}
}
