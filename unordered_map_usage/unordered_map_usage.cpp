#include "../common.h"

typedef unordered_map<int, string>::iterator uomIter;
typedef unordered_map<int, string> isunom;

int main()
{
	unordered_map<int, string> zmap;
	zmap.insert(pair<int, string>(2, "Two"));
	zmap.insert(pair<int, string>(1, "One"));
	zmap.insert(pair<int, string>(3, "Three"));
	//Iterator
	uomIter itr;
	itr = zmap.begin();
	while (itr != zmap.end()) {
		cout << itr->first << " " << itr->second << endl;
		itr++;
	}
	//ForLoop
	int sizeMap = zmap.size();

	auto it = zmap.begin();
	for (int i = 0; i < sizeMap; i++) {
		std::cout << "Key: " << it->first << " Value: " << it->second << std::endl;
		it++;
	}


	return 0;
}
 
