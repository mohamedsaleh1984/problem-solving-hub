#include "../common.h"

std::vector<std::vector<std::string>> group_anagrams(std::vector<std::string> strs) {
	std::map<std::string, std::vector<string>> map;
	std::vector<std::vector<std::string>> result;
	std::map<std::string, std::vector<string>>::iterator it;
	for (int i = 0; i < strs.size(); i++) {
		string anagramId = strs[i];
		sort(anagramId.begin(), anagramId.end());
		it = map.find(anagramId);
		if (it == map.end()) {
			map.insert(std::pair<string, vector<string>>(anagramId, {}));
		}
		map.at(anagramId).push_back(strs[i]);
	}

	for (std::map<string, vector<string>>::iterator it = map.begin(); it != map.end(); ++it) {
		result.push_back(it->second);
	}

	return result;
}
int main()
{
	vector<string> vec = { "eat" ,"tea", "tan", "ate", "nat", "bat" };
	group_anagrams(vec);
	
	return 0;
}
