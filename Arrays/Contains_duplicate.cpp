// problem: 217. Contains Duplicate - fine if there is a duplicate of an element in an array, if yes then return true else false
// Difficulty: easy
// Topic: array, hashing, sorting
// approach:
// a) brute force: outer loop from 0 to last index, inner loop from i+1 to last, and return true as soon as nums[i]==nums[j]
// b) hashing: we use unordered set instead of unordered map because we need only value not index, so after creating unordered set, we will run loop from i=0 to last 
// element, if nums[i] is found in unordered set then return true else false and store then value in set 
// time: O(n)
// Space: O(1)
// Link: https://leetcode.com/problems/contains-duplicate/submissions/1854428020/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0; i< nums.size(); i++)
        {
            if(s.find(nums[i])!=s.end())
            {
                return true;
            }
            s.insert(nums[i]);    
            
        }
        return false;
    }
};
