#include <iostream>
#include <map>
using namespace std;

int main()
{
	map<int, string> zmap;
	zmap.insert(pair<int, string>( 2, "Two"));
	zmap.insert(pair<int,string>(1, "One"));
	zmap.insert(pair<int,string>(3, "Three"));

	map<int, string>::iterator itr;
	itr = zmap.begin();
	while (itr != zmap.end()) {
		cout << itr->first << " " << itr->second << endl;
		itr++;
	}

	return 0;
}
