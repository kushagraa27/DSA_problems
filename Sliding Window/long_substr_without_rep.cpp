// problem: 3. Longest Substring Without Repeating Characters
// difficulty: Medium
// topics: hash table, string, sliding window
// approach: so i first assigned left=0 and maxL=0 and made an unordered set to store window, now we will start for loop for right pointer from 0 to its length and
//first check if s[right] is already in set, if yes then keep removing s[left] from set and increase left by 1 until s[right'] is no more in set, then after coming out,
// inser s[right] in set and maxL = max(maxL, right-left+1)
// at last return maxL
// time: O(n)
// space: O(min(n, charset))
// link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int left=0;
        int maxL=0;

        for (int right=0;right<s.size();right++)
        {
             while(st.find(s[right])!=st.end())
                {
                    st.erase(s[left]);
                    left++;
                }
            st.insert(s[right]);
            maxL = max(maxL,right-left+1);
        }
        return maxL;
    }
};

