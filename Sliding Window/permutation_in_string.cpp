// problem: 567. Permutation in String
// difficulty: medium
// topic: hash table, two pointer, strings, sliding window
// approach:since in this problem they mentioned that leterrs are lowercase, we can use array of size 26 to store the frequency of characters
// so first store frequency of all characters in first string, freq1
// then store the frequqncy of characters in a window of second string, freq2, window size is fixed (K)
// now at each window check if freq1==freq2, if yes then return true if not then false at last
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/permutation-in-string/description/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26,0), freq2(26,0);
        for(char c: s1)
        freq1[c - 'a']++;
        int left = 0;
        int k = s1.size();
        for(int right=0;right<s2.size();right++)
        {
            freq2[s2[right] - 'a']++;
            if((right-left+1)>k)
            {
                freq2[s2[left]-'a']--;
                left++;
            }
            
            if((right-left+1)==k)
            {
                if(freq1==freq2)
                return true;
            }
        }
        return false;
    }
};

