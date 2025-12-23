// problem: 206. Reverse Linked List
// difficulty: easy 
// topic: linked list, recursion 
// approach: since we need to reverse the list we will take 3 pointers, next, curr and prev, now prev will be NULL and curr will be head and we will traver the LL untill curr is not NULL so the
// current node's next will be saved in next and curr node's next will be set to prev, then perv will become curr and curr will become next and do this untill curr != null and at last return prev
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/reverse-linked-list/description/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL;
        ListNode *curr = head;

        while(curr!=NULL)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};
