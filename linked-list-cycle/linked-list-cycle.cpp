#include "../common.h"
  //https://leetcode.com/problems/linked-list-cycle/
  // 12/15/2024
  // 15ms Beats 12.25%
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr)
            return false;
        set<ListNode*> nodes;
        ListNode* tmp = head;
        while(tmp){
            if(nodes.count(tmp)){
                return true;
            }else{
                nodes.insert(tmp);
            }
            
            tmp = tmp->next;
        }

        return false;
    }
};

int main()
{
    
    return 0;
}
