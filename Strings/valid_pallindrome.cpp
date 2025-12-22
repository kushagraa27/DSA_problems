// problem: 125. Valid Palindrome
// difficulty: easy
// topic: two pointers, string
// approach: so we use two pointers, left starts from zero and right starts from last element, now we check if right or left is alphanumeric, if not then skip it
// and move to next, if lowercase of left and lowecase of right are not equal at any point then return false, loop will run till left<right and return true at last.
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/valid-palindrome/description/

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        while(left<right)
        {
            while(left<right&& !isalnum(s[left]))
             left++;
            while(left<right&& !isalnum(s[right]))
             right--;
            if(tolower(s[left])!=tolower(s[right]))
            return false;

            left++;
            right--;
        }
        return true;
    }
};
