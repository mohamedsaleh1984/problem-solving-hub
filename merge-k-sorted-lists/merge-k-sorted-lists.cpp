#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://leetcode.com/problems/merge-k-sorted-lists/
// 0ms Beats 100.00%

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<int> vec;
        while (!eofOfLists(lists))
        {
            for (int l = 0; l < lists.size(); l++)
            {
                if (lists[l] != nullptr)
                {
                    vec.push_back(lists[l]->val);
                    lists[l] = lists[l]->next;
                }
            }
        }
        sort(vec.begin(), vec.end());
        ListNode* res = createList(vec);
        return res;
    }

    bool eofOfLists(vector<ListNode *> &nodes)
    {
        bool result = true;
        for (int i = 0; i < nodes.size(); i++)
        {
            if (nodes[i] != nullptr)
            {
                result = false;
                break;
            }
        }
        return result;
    }

    ListNode *createList(vector<int> values)
    {
        ListNode *head = new ListNode(0);
        ListNode *tmp = head;

        for (int i = 0; i < values.size(); i++)
        {
            head->next = new ListNode(values[i]);
            head = head->next;
        }

        return tmp->next;
    }

    void traverseList(ListNode *node)
    {
        while (node != nullptr)
        {
            cout << node->val << " ";
            node = node->next;
        }
        cout << endl;
    }
};

int main()
{
    Solution s;
    ListNode *l1 = s.createList({1, 4, 5});
    ListNode *l2 = s.createList({1, 3, 4});
    ListNode *l3 = s.createList({2, 6});

    // s.traverseList(l1);
    // cout << "*********************" << endl;
    // s.traverseList(l2);
    // cout << "*********************" << endl;
    // s.traverseList(l3);
    // cout << "*********************" << endl;


    vector<ListNode*> lists = {l1,l2,l3};
    
    ListNode* All = s.mergeKLists(lists);
    
    s.traverseList(All);


    return 0;
}
