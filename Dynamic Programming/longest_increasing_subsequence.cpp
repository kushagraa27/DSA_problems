// problem: 300. Longest Increasing Subsequence
// difficulty: medium
// topics: array, DP, binary search 
// approach: so here either we can do by brute force, but it will be complex so other approach will be through dynamic programming, where we dont care about 
// the subsequence, we only need max length, so for that we will first make a vector named tail in which we will store the values of nums, according to the value, 
// if the value of nums[i] is smaller than any elemnt in our tail then we will replace it and if not then we will just push it to our tail, at last we will reuturn
// the size of tail.
// time: O(n log n)
// space:O(n)
// link: https://leetcode.com/problems/longest-increasing-subsequence/description/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tail;

        for(int x : nums)
        {
            auto it = lower_bound(tail.begin(),tail.end(),x);
            if(it==tail.end())
            tail.push_back(x);
            else
            *it = x;
        }
        return tail.size();
    }
};
