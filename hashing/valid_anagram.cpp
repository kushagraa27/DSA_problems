// problem: 242. Valid Anagram - Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// difficulty: easy
// topics: hash table, string, sorting 
// approach: we use unordered map here, and first of all i tried to add elements of first string in map then compare it with second string and erase elements of map
// which r there in other string and etc, but its wrong since i learned that map can store only unique values, and in case of duplicate it just overwrites, so then
// i used frequency method, store a frequency for each valued in map and if it reaches negative for any value which comparing with second string, return false
// else true, and also at starting chack the length of both string if its different then no need to go ahead just return false.
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/valid-anagram/submissions/1857087650/

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> st;
        if (s.size()!=t.size()) return false;
        for(char c : s)
        {
            st[c]++;
        }
        for(char c : t)
        {
            st[c]--;
            if(st[c]<0)
            return false;
        }
        return true;
    }
};
