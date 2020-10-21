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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carryOut;
        int res = l1->val + l2->val;
        if (res >= 10) {
            carryOut = 1;
            res -= 10;
        } else {
            carryOut = 0;
        }
        ListNode *head = new ListNode{res, nullptr};
        ListNode *res_llist = head;
        ListNode *curr1 = l1->next;
        ListNode *curr2 = l2->next;
        while (true) {
            // cout << "debug" << endl;
            if (curr1 == nullptr && curr2 == nullptr) {
                if (carryOut == 1) {
                    res_llist->next = new ListNode{1, nullptr};
                    res_llist = res_llist->next;
                }
                break;
            } else if (curr1 != nullptr && curr2 == nullptr) {
                res = curr1->val + carryOut;
                if (res >= 10) {
                    carryOut = 1;
                    res -= 10;
                } else {
                    carryOut = 0;
                }
                // cout << res << endl;
                res_llist->next = new ListNode{res, nullptr};
                res_llist = res_llist->next;
                curr1 = curr1->next;
            } else if (curr1 == nullptr && curr2 != nullptr) {
                res = curr2->val + carryOut;
                if (res >= 10) {
                    carryOut = 1;
                    res -= 10;
                } else {
                    carryOut = 0;
                }
                // cout << res << endl;
                res_llist->next = new ListNode{res, nullptr};
                res_llist = res_llist->next;
                curr2 = curr2->next;
            } else {
                res = curr1->val + curr2->val + carryOut;
                if (res >= 10) {
                    carryOut = 1;
                    res -= 10;
                } else {
                    carryOut = 0;
                }
                // cout << res << endl;
                res_llist->next = new ListNode{res, nullptr};
                res_llist = res_llist->next;
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
        }
        return head;
    }
};
