/**
 *
 * Sort a linked list using insertion sort.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        if (head == NULL)
            return NULL;
         
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *loopSlowIter = head, *loopFastIter = head->next;
         
        while(loopFastIter != NULL)
        {
            if (loopFastIter->val < loopSlowIter->val)
            {
                ListNode *insertNode = loopFastIter;
                loopFastIter = loopFastIter->next;
                loopSlowIter->next = loopFastIter;
                 
                ListNode *slowIter = newHead, *fastIter = slowIter->next;
                while (fastIter != loopFastIter)
                {
                    if (insertNode->val < fastIter->val)
                    {
                        slowIter->next = insertNode;
                        insertNode->next = fastIter;
                        break;
                    }
                     
                    fastIter = fastIter->next;
                    slowIter = slowIter->next;
                }
                continue;
            }
             
            loopFastIter = loopFastIter->next;
            loopSlowIter = loopSlowIter->next;
        }
         
        head = newHead->next;
        delete newHead;
        return head;
    }
};
