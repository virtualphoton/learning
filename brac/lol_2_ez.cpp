#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <utility>

using std::string;

bool is_valid(string const & s) {
	std::map<char, int> gl_br{ {'(', 0}, {'{', 0}, {'[', 0} };
	// maps each bracket to pair (which counter should change, how to change it)
	std::map<char, std::pair<char, int>> brac_map{ {'(',{'(',+1}}, {'{',{'{',+1}}, {'[',{'[',+1}}, {')',{'(',-1}}, {'}',{'{',-1}}, {']',{'[',-1}} };
	for (int start = 0; start < s.size(); start += 1) {
		std::map<char, int> loc_br{ {'(', 0}, {'{', 0}, {'[', 0} };
		if (brac_map.find(s[start]) == brac_map.end() or (gl_br[brac_map[s[start]].first] += brac_map[s[start]].second) < 0)
			return false;
		if (brac_map[s[start]].second == 1) {
			for (int i = start; i < s.size(); i += 1)
				if ((loc_br[brac_map[s[i]].first] += brac_map[s[i]].second) < 0 or not loc_br[s[start]])
					break;
			if (loc_br['{'] or loc_br['('] or loc_br['['])
				return false;
		}
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
	std::cout << is_valid("{[)(]}");
}