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
    int pairSum(ListNode* head) {
      ListNode*current = head;
      ListNode*next = head;
      ListNode*prev = nullptr;
      ListNode*fast = head;
      int maxSum = 0;

      while(current){
          if(fast){
          fast = fast->next;
          if(fast) fast = fast->next;
          next = current->next;
          current->next = prev;
          prev = current;
          current = next;
          }else{
            maxSum  = max(maxSum,current->val+prev->val);
            current = current->next;
            prev = prev->next;
          }

      }
      return maxSum;
    }
};