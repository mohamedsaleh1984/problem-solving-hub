#include "../common.h"

class Solution {
private:
	vector<int> nums;
	vector<vector<int>> resultSet;
	vector<bool> used;
	vector<int> currentEntry;
public:
	Solution(vector<int> nums) {
		this->nums = nums;
		this->used.resize(nums.size(), false);
	}

	vector<vector<int>> findPermutation() {
		Solve();
		return resultSet;
	}
private:
	void Solve() {
		if (currentEntry.size() == nums.size()) {
			resultSet.push_back(currentEntry);
			return;
		}

		for (int i = 0; i < nums.size(); i++)
		{
			if (!used[i]) {

				used[i] = true;
				currentEntry.push_back(nums[i]);
				Solve();
				used[i] = false;
				currentEntry.pop_back();
			}
		}
	}
};

int main()
{
	
	vector<int> nums{ 1,2,3,4 };
	Solution s(nums);
	vector<vector<int>> result = s.findPermutation();
	

	return 0;

}

class SolutionEx {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> vec;
		int n = nums.size();
		vector<int> arr(n);

		for (int i = 0; i < n; i++)
			arr[i] = nums[i];

		std::sort(arr.begin(), arr.end());

		do {
			vector<int> t;
			for (int i = 0; i < n; i++)
				t.push_back(arr[i]);
			vec.push_back(t);
		} while (std::next_permutation(arr.begin(), arr.end()));

		return vec;
	}
};

class Solution3 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> p;
        permuteHelper(p, nums, result);
        return result;
    }


    void permuteHelper(vector<int>& p, vector<int>& nums, vector<vector<int>>& result) 
    {
        if(nums.size() == 0){
            result.push_back(p);
            return;
        }
        
        int v = nums[0];

        for(int i = 0 ; i <= p.size(); i++)
        {
            // construction of the string
            vector<int> first;
            copy(p.begin(),p.begin()+i,back_inserter(first));

            vector<int> second;
            copy(p.begin()+i,p.end(),back_inserter(second));

            vector<int> newp;
            copy(first.begin(),first.end(),back_inserter(newp));
            

            newp.push_back(v);
            
            copy(second.begin(),second.end(),back_inserter(newp));

            vector<int> newup;

            copy(nums.begin()+1,nums.end(),back_inserter(newup));

            permuteHelper(newp,newup,result);
        }


    }

    vector<vector<int>> permute2(vector<int>& nums) {
        vector<vector<int>> resultSet;
        vector<int> entry;
        perform_permutation(nums, entry, resultSet);
        return resultSet;
    }

    void perform_permutation(vector<int> nums, vector<int>& entry,
                             vector<vector<int>>& resultSet) {
        if (!nums.size())
            resultSet.push_back(entry);

        for (int i = 0; i < nums.size(); i++) {
            // Copy
            vector<int> newSet(nums.begin(), nums.end());
            // Remove Element
            newSet.erase(newSet.begin() + i);
            // Push to entry
            entry.push_back(nums[i]);

            perform_permutation(newSet, entry, resultSet);

            entry.pop_back();
        }
    }
};
