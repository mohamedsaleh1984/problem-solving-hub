#include <iostream>
#include <string>
using namespace std;
//https://leetcode.com/problems/defanging-an-ip-address
class Solution {
public:
    string defangIPaddr(string address) {
        string strAddress = "";
        string strOcta = "";
        int iIndex = 0;

        while (iIndex < address.size()) {
            strOcta = "";
            while (address[iIndex] != '.') {
                strOcta += address[iIndex];
                iIndex++;
                if (iIndex == address.size())
                    break;
            }
           

            if (iIndex == address.size())
                strAddress += strOcta;
            else
                strAddress += strOcta + "[.]";

            iIndex++;
        }

        return strAddress;
    }
};

int main()
{
    string  address = "1.1.1.1";
    Solution s = Solution();
    cout << s.defangIPaddr(address) << endl;


	return 0;
}
 