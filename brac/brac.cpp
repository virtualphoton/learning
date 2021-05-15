#include <iostream>
#include <string>
#include <stack>
#include <map>

using std::string;
bool is_valid(string s) {
	if (s.size() == 0)
		return true;
	std::map<char, char> pairs {{'(', ')'}, {'{', '}'}, {'[', ']'}};
	int start = 0;
	bool res = true;
	while (start != s.size()) {
		char st = s[start];
		if (pairs.find(st) == pairs.end())
			return false;

		int counter = 0;
		int i;
		for (i = 0; i < s.size(); i += 1) {
			if (s[i] == pairs[st])
				counter -= 1;
			if (s[i] == st)
				counter += 1;
			if (counter == 0)
				break;
		}
		if (counter)
			return false;
		res = res and is_valid(s.substr(start+1, i-start-1));
		start = i + 1;
	}
	return res;
}

void main() {
	is_valid("([{]})");
}