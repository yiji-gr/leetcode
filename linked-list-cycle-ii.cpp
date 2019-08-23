//  2019年8月23日 
//  leetcode第142题	https://leetcode-cn.com/problems/linked-list-cycle-ii/

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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        if(fast == nullptr || fast->next == nullptr)
            return nullptr;

        ListNode *tmp = head;
        while(tmp != slow){
            tmp = tmp->next;
            slow = slow->next;
        }
        return slow;
    }
};
