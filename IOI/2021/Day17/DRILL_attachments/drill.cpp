#include "drill.h"
#include <string>
#include <map>

namespace {
    std::map<std::string, std::string> match;
}

void drill(std::string question, std::string answer) {
    match[question] = answer;
}

std::string query(std::string question) {
	return match[question];
}
