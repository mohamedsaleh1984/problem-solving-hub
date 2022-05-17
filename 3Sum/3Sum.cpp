#include <algorithm> // copy
#include <iostream> // cin, cout
#include <iterator> // back_inserter, istream_iterator, ostream_iterator, prev
#include <string> // getline, string
#include <vector> // vector
#include <map> // map
using namespace std;


std::vector<std::vector<int>> triplets_with_sum_0(std::vector<int> nums) {
	if (nums.size() < 3)
		return {};
	std::vector<std::vector<int>> resultSet;
	std::map<std::string, vector<int>> map;
	for (int i = 0; i < nums.size() - 2; i++) {
		for (int j = i + 1; j < nums.size() - 1; j++)
			for (int k = j + 1; k < nums.size(); k++) {
				if (nums[i] + nums[j] + nums[k] == 0) {
					vector<int> result;
					result.push_back(nums[i]);
					result.push_back(nums[j]);
					result.push_back(nums[k]);
					sort(result.begin(), result.end());

					std::string key = to_string(result[0]) + to_string(result[1]) + to_string(result[2]);
					if (map.find(key) == map.end()) {
						map.insert(pair< std::string, vector<int>>{key, result });
						resultSet.push_back(result);
					}
				}
			}
	}
	sort(resultSet.begin(), resultSet.end());
	return resultSet;
}

std::vector<int> triplet_with_sum_0(std::vector<int> nums) {
	vector<int> result;
	for (int i = 0; i < nums.size() - 2; i++) {
		for (int j = i + 1; j < nums.size() - 1; j++)
			for (int k = j + 1; k < nums.size(); k++) {
				if (nums[i] + nums[j] + nums[k] == 0) {
					result.push_back(nums[i]);
					result.push_back(nums[j]);
					result.push_back(nums[k]);
					return result;
				}
			}
	}
	return result;
}


int main()
{
	vector<int> vec = { -1, 0, 1, 2, -1, -4 };
	/*cout << "First triplet with sum 0" << endl;
	vector<int> result = triplet_with_sum_0(vec);
	for (int x : result) {
		cout << x << " ";
	}*/
	//cout << "=====================================================" << endl;
	cout << "Find all triplets with sum 0" << endl;
	std::vector<std::vector<int>> res = triplets_with_sum_0(vec);
	for (vector<int> v : res) {
		for (int x : v) {
			cout << x << " ";
		}
		cout << "\n";
	}
	cout << "=====================================================\n" << endl;
	return 0;
}