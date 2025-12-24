// problem: 141. Linked List Cycle
// difficulty: easy
// topic: linked list, two pointers 
// approach: first we will initialise two pointers, fast and slow, now if there is a cycle in the list, then if we run the loop until fast or fast->next!=NULL then loop will never terminate
// because of cyle and since we are incrementing fast by 2 and slow by 1 then they will overlap at some time, if that happened then return true, and if loop terminated then return false 
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/linked-list-cycle/description/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            if (fast==slow)
            return true;
        }
        return false;
        
    }
};
