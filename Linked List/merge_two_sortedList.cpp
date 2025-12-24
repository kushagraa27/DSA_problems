// problem: 21. Merge Two Sorted Lists
// difficulty: easy
// topic: linked list, recursion
// approach: first of all i made a dummy node and a tail pointing towards that dummy node then we compare both lists one by one and the node which is smaller comes first and the tail starts pointing towards it,
// like this we continue untill we link all the nodes and return dummy->next
// time: O(m+n)
// space: O(1)
// link: https://leetcode.com/problems/merge-two-sorted-lists/description/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val<list2->val)
            {
                tail->next = list1;
                list1=list1->next;
            }
            else 
            {
                tail->next=list2;
                list2=list2->next;
            }
            tail=tail->next;

        }
        if(list1==NULL)
        tail->next=list2;
        if(list2==NULL)
        tail->next=list1;
        return dummy->next;
    }
};

