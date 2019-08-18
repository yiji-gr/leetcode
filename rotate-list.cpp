//  2019年8月18日 
//  leetcode第61题  https://leetcode-cn.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || k == 0)
            return head;
        ListNode *node1 = head;
        int len = 0;
        while(node1){   //计算长度
            len++;
            node1 = node1->next;
        }
        k %= len;
        if(k == 0)
            return head;
        
        ListNode *node2 = head, *node3;
        int i = 0;
        while(node2){
            if(i == len - k - 1){     //在断点处截断链表
                node3 = node2->next;
                node2->next = nullptr;
                break;
            }
            i++;
            node2 = node2->next;
        }
        ListNode *cur = node3;
        for(int i = len - k; i < len - 1; ++i){
            cur = cur->next;
        }
        cur->next = head;     //后面连上前面
        return node3;
    }
};
