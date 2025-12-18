// problem: 347. Top K Frequent Elements
// difficulty: Medium
// topic: hash table, bucket sort, array, counting, Quickselect
// approach:-
// first of all what i did is, make a map, store frequencies of all elements in it, then make a pair vector and store map values and frequencies in it and then
// sort the pair vector according to second element and then return the ans containing starting k elements of pair vector complexity of this method is O(n log n)
// for more optimal solution we use bucket sort, in which we first store frequencies of each value in map then make a vector of vectors named bucket and inside it
// we store the values and index is according to their frequency, therefore the size of bucket should be n+1 since n is the max frequency an element can have
// then simply traverse in bucket from left to right to get ending k elemnts with max frequency and return ans.
// time: O(n)
// space: O(n)
// link: https://leetcode.com/problems/top-k-frequent-elements/submissions/1858651687/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i : nums)
        {
            m[i]++;
        }
        int n = nums.size();
        vector<vector<int>> bucket(n+1);
        for(auto a : m)
        {
            int element = a.first;
            int count = a.second;
            bucket[count].push_back(element);
        }
        vector <int> ans;
        for (int i=n; i>=0 && ans.size()<k;i--)
        {
            for(int j : bucket[i])
            {ans.push_back(j);
            if(ans.size()==k) break;
            }
        }
        
        return ans;

    }
};
