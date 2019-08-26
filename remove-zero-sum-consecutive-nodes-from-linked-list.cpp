//    2019年8月26日 
//    leetcode第151周赛第3题   https://leetcode-cn.com/contest/weekly-contest-151/problems/remove-zero-sum-consecutive-nodes-from-linked-list/ 

给你一个链表的头节点 head，请你编写代码，反复删去链表中由 总和 值为 0 的连续节点组成的序列，直到不存在这样的序列为止。
删除完毕后，请你返回最终结果链表的头节点。

示例 1：
输入：head = [1,2,-3,3,1]
输出：[3,1]
提示：答案 [1,2,1] 也是正确的。

示例 2：
输入：head = [1,2,3,-3,4]
输出：[1,2,4]

示例 3：
输入：head = [1,2,3,-3,-2]
输出：[1]

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
    ListNode* removeZeroSumSublists(ListNode* head) {
		vector<int> arrs;
		ListNode *tm = head;
		while (tm != nullptr) {
			arrs.push_back(tm->val);
			tm = tm->next;
		}

        int del[1002];
        memset(del, 0, sizeof(del));
        for(int i = 0; i < arrs.size(); ++i){
            int sum = 0, flag = 0;
            for(int j = i; j < arrs.size(); ++j){
                if(del[j])
                    continue;
                sum += arrs[j];
                if(sum == 0){
                    for(int k = i; k <= j; ++k)
                        del[k] = 1;
                }
            }
        }

        ListNode* tmp = new ListNode(-1);
        ListNode* t = tmp;
        for(int i = 0; i < arrs.size(); ++i){
            if(del[i])
                continue;
            ListNode *cur = new ListNode(arrs[i]);
            t->next = cur;
            t = t->next;
        }
        return tmp->next;
    }
};
