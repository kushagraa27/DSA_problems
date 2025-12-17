// problem: 49. Group Anagrams
// difficulty: Medium
// topic: string, array, hash table, sorting
// approach: first start a loop from 0th to n-1th string, then sort the selected string and store it in a variable, then use that sorted string as the signature key 
// the map and store it in map as m[key].push_back(c); then all strings will be stored in map according to the signature key, now just run a loop to display all 
// elements of map
// time: O(N · K log K)
// space: O(N.K)
// link: https://leetcode.com/problems/group-anagrams/submissions/1857148751/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (string c : strs)
        {
            string key = c;
            sort(key.begin(),key.end());
            m[key].push_back(c);
        }
        vector<vector<string>> ans;
        for(auto it : m)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
