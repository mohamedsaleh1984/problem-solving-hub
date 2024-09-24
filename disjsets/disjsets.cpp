#include <iostream>
#include <vector>
using namespace std;
/*
Two sets has nothing in common.
*/
class DisjSets {
public:
	DisjSets(int numOfElements);
	int find(int x) const;
	int find(int x);
	void unionSets(int root1, int root2);
	void unionSetsSmart(int root1, int root2);
private:
	vector<int> s;
};
DisjSets::DisjSets(int numOfElements) :s{ numOfElements , -1 } {}

void DisjSets::unionSets(int root1, int root2) {
	s[root2] = root1;
}

int DisjSets::find(int x) const {
	if (s[x] < 0)
		return x;
	else
		return find(s[x]);
}

void DisjSets::unionSetsSmart(int root1, int root2) {
	if (s[root2] < s[root1])//root2 is deeper
		s[root1] = root2;
	else
	{
		if (s[root1] == s[root2])
			--s[root1];//update heigh if same 
		s[root2] = root1;
	}
}

int main()
{


	return 0;
}
