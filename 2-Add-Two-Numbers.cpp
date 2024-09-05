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

        ListNode* Temp = new ListNode();  // Allocate memory for Sum
        ListNode* Sum=Temp;
                int carry = 0;
while(l1!=nullptr || l2!=nullptr){
  int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
  int sum = val1 + val2 + carry;

            carry = sum / 10;
            Sum->next = new ListNode(sum % 10);
            Sum = Sum->next;
 if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
}
 if (carry > 0) {
            Sum->next = new ListNode(carry);
        }
return Temp->next;

    }
};