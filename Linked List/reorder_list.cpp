// problem: 143. Reorder List
// difficulty: medium
// topic: linked list, recursion, two pointers
// approach: ok so one approach is that we add last element to next of curr pointer one by one but then we have to iterate two pointers at last again n again which will 
// take much time so other optimal approach is that we first of all find the middle of the list and from there we split our list in two halves, then we reverse the 
// second half and fiinally merge them alternatively, finally the list will be ordered as desired 
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/reorder-list/description/

class Solution {
public:
    void reorderList(ListNode* head) {
        
        ListNode* prev = NULL, *slow=head, *fast = head;
        if(!head || !head->next) return;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* curr = slow->next;
        slow->next=NULL;
        while(curr!=NULL)
        {
            ListNode* next = curr->next;
            curr->next=prev;
            prev=curr;
            curr = next;
        }
        ListNode* first= head;
        ListNode* second= prev;
        while(second!=NULL)
        {   
            ListNode* FN = first->next;
            ListNode* SN = second->next;
            first->next = second;
            second->next= FN;
            first = FN;
            second = SN;
        }
        

    }
};

