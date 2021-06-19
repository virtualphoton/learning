#include <iostream>
#include <string>
#include <stack>
#include <map>

using std::string;
bool is_valid(string s) {
	std::map<char, char> pairs{ {'(', ')'}, {'{', '}'}, {'[', ']'} };
	for (int i = 0; i < s.size(); i += 1)
		if (s[i] != 'ø') {
			if (pairs.find(s[i]) == pairs.end())
				return false;
			int counter = 0, j;
			for (j = i; j < s.size(); j += 1) {
				if (s[j] == pairs[s[i]])
					counter -= 1;
				if (s[j] == s[i])
					counter += 1;
				if (not counter or s[j] == 'ø')
					break;
			}
			if (counter)
				return false;
			s[i] = s[j] = 'ø';
		}
	return true;
}

void main() {
	std::cout << is_valid("[()]");
	std::cout << is_valid("{[()]}");
	std::cout << is_valid("([{{[(())]}}])");
	std::cout << '\n';
	std::cout << is_valid("abc[](){}");
	std::cout << is_valid("{{[]()}}}}");
	std::cout << is_valid("{[())}");
}