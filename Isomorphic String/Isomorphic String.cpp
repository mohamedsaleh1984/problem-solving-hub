
#include <algorithm> // copy
#include <iostream> // cin
#include <iterator> // back_inserter, istream_iterator
#include <sstream> // istringstream
#include <string> // getline, string
#include <vector> // vector
#include <set>
#include <map>
using namespace std;

bool is_isomorphic(std::string str_1, std::string str_2) {
    if (str_1.length() != str_2.length())
        return false;
    bool result = true;
    std::map<char, char> map;
    std::map<char, char>::iterator it;
    std::set<char> duplicationDetector;

    for (int i = 0; i < str_1.length(); i++) {
        char c = str_1[i];
        it = map.find(c);
        if (it == map.end()) {
            //to avoid mapping a character to another-one.
            if (duplicationDetector.find(str_2[i]) != duplicationDetector.end()) {
                result = false;
                break;
            }
            map.insert(pair<char, char>(str_1[i], str_2[i]));
            duplicationDetector.insert(str_2[i]);
        }
        else
        {
            char ref_Charcater = it->second;
            if (ref_Charcater != str_2[i]) {
                result = false;
                break;
            }
        }
    }
    return result;
}

int main()
{
    cout << is_isomorphic("egg", "all") << endl;
    cout << is_isomorphic("wow", "aaa") << endl;
    return 0;
}
