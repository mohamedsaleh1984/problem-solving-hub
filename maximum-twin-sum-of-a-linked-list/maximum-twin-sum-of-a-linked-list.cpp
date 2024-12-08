/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 // https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/submissions/?envType=study-plan-v2&envId=leetcode-75
 // 4ms Beats 62.88%
 // 12/08/2024
 
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> nodes;
        while(head != nullptr){
            nodes.push_back(head->val);
            head= head->next;
        }

        int l=0,r=nodes.size()-1,sum = 0;

        while(l < r){
            sum = max(sum, nodes[l]+ nodes[r]);
            l++;
            r--;
        }

        return sum;
    }

    
};
