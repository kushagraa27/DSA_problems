// problem:19. Remove Nth Node From End of List
// difficulty: medium
// topic: linked list, two pointers
// aprroach: two pointers will be there, left and right, so first of all we will make a dummy node which will be placed before the head so that in case we have to delete the head node we could do that,
// so first we will iterate the fast pointer by n times so that the gap between the fast pointer and the slow one becomes n times, then when its iterated n times then we will increase both of them one by one
// till the next of fast pointer becomes null or it reaches the last node, then the slow pointer will be one node behind the node which we have to delete, therefore add a link from slow ptr to next of next and 
// remove the link of next node from its next, and return dummy->next.
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next= head;
        ListNode* fast=dummy;
        ListNode* slow = dummy;
        
        for(int i=1;i<=n;i++)
        fast=fast->next;
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* temp = slow->next;
        slow->next=temp->next;
        temp->next=NULL;
        delete temp;
    ListNode* result= dummy->next;
    delete dummy;
    return result;
    }
};

