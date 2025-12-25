// problem: 2. Add Two Numbers
// difficulty: medium 
// topic: linked list, math, recursion
// approach: first we will make a dummy node and assign its address to our current pointer then while loop will be executed until l1 or l2 are not NULL and c is not 0
// then we will assign 0 to the value of list if it becomes NULL and other is not, or both r NULL but carry is not, sum will be calculated and modded by 10 and carry will
// be sum/10 and here one important thing is we are making new nodes to store the value of sum, their value will be sum mod 10 stored in them and then move current pointer
// l1 and l2 untill loop gets terminated, finally return the new list.
// time:O(max(m,n))
// space:O(max(m,n))
// link: https://leetcode.com/problems/add-two-numbers/description/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry!=0)

        { int x = (l1!=NULL) ? l1->val:0;
          int y = (l2!=NULL) ? l2->val:0;
             int sum = x+y+carry;
             carry=sum/10;
             curr->next = new ListNode(sum%10);
             curr = curr->next;
            if(l1!=NULL) l1=l1->next;
            if(l2!=NULL) l2=l2->next;

        }
        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};
