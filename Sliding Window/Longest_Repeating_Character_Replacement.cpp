// problem: 424. Longest Repeating Character Replacement
// difficulty: medium
// topic: hash table, string, sliding window
// approach: so here i used unordered map to store frequencies of character, the right moves from left to right and we will keep increasing the frequency of s[right]
// in map and store it to evaluate max frequency of elements in window, our condition to shrink window will be 
// L-maxFrequency>k, because we can only keep the characters inside window which can be replaced, and then we evaluate max length of stored window and return it
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> m;
        int left=0;
        int maxL = 0;
        int maxF = 0;
        for(int right=0;right<s.size();right++)
        {
            m[s[right]]++;
            maxF = max(maxF, m[s[right]]);
            while((right-left+1)-maxF>k)
            {
                m[s[left]]--;
                left++;
            }
            maxL = max(maxL, right-left+1);
        }
        return maxL;
    }
};

