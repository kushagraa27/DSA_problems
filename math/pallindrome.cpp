// problem: pallindrome number
// difficulty: easy
// topic: math
// approach: first one is brute force where we reverse the whole number and check at last if rev is equal to the number, but one optimal approach is that we dont need to reverse whole number
// just reverse half of the number and then compare it with other half (while rev<x)
// time: O(log n)
// space: O(1)
// link: https://leetcode.com/problems/palindrome-number/description/

class Solution {
public:
    bool isPalindrome(int x) {

        if(x<0 || (x%10 == 0 && x!=0)) return false;
        int rev = 0;

        while(rev<x)
        {   
            rev = rev*10 + (x%10);
            x = x/10;
        }
        return rev==x || rev/10==x;
    }
};
