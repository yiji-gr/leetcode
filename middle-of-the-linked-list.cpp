//2019年8月9日 
//leetcode第876题 https://leetcode-cn.com/problems/middle-of-the-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *n1 = head;
        ListNode *n2 = head;
        while(n2){
            if(!n2->next)
                break;
            n2 = n2->next->next;
            n1 = n1->next;
        }
        return n1;
    }
};
