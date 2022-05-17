#include <iostream>
#include <bitset>
using namespace std;

uint32_t reverseBits(uint32_t n) {
	std::bitset<32> myset(n);
	for (int i = 0, j = 31; i < (32 / 2); i++, j--) {
		bool tmp = myset[i];
		myset[i] = myset[j];
		myset[j] = tmp;
	}
	return myset.to_ulong();
}

int main()
{
	std::bitset<32> myset(100);
	for (int i = 0, j = 31; i < (32 / 2); i++, j--) {
		bool tmp = myset[i];
		myset[i] = myset[j];
		myset[j] = tmp;
	}
	cout << myset.to_ulong() << endl;

}
