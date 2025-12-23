// problem: 5. Longest Palindromic Substring
// difficulty: medium
// topic: two pointers, dynamic programmming, string
// approach: in brute force approach while moving from left to right we check all possible substrings and check if they r pallindrome and store max lenth, this causes
// n^3 of complexity so for better complexity i expanded the centre instead of checking all substrings, there are 2 centres at each i, even and odd, in even, 
// right = left+1, and in odd right == left, we keep expanding the centre by reducing left and incrementing right, until s[left]!=s[right] and record the starting
// index of maximum pallindrome reached and its length, after done till end, we return substring starting from start we stored and of lenth maxL which we also stored
// time: O(n^2)
// space: O(1)
// link: https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution {
public:
    string longestPalindrome(string s) {
       int right=0;
        int left=0;
        int n=s.size();
        int maxL=0;
        int start =0;
        for(int i=0;i<n;i++)
        {
            left=i;
            right=i;
            while(left>-1&&right<n&&s[left]==s[right])
            {
               if(right-left+1>maxL)
               {
                maxL=right-left+1;
                start=left;
               }
                left--;
                right++;
            }
            left=i;
            right=i+1;
            while(left>-1&&right<n&&s[left]==s[right])
            {
               if(right-left+1>maxL)
               {
                maxL=right-left+1;
                start=left;
               }
                left--;
                right++;
            }
        }
        return s.substr(start, maxL);
        
    }
};

