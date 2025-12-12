// problem : Two Sum, in the array - sum of which two indices is equal to target? print only one result 
// Difficulty : easy
// Topic : Araays, hashing 
// approach: first we try brute force, in which outer loop runs from 0 to arr length and inner loop runs from i+1 to arr length, so complexity becomes n^2
//then to reduce complexity we can implement hashing, in which we will store all values and their indices in the form of values-> index, then what we will do is 
// we will subtract each value of array from target, one by one, and store it in "need" and we will find this "need" in out map, if found, print the result, 
//else store the value of need to map
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/two-sum/submissions/1853682287/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> m; // this creates an empty unordered map
      
        for (int i=0;i<=nums.size();i++)
        {
            int need = target - nums[i]; 
                if (m.find(need)!=m.end()) // checking if the need is present in our map
                {
                    return {m[need],i}; // if found return the result
                }

            m[nums[i]] = i; // if not found then store it to the map and move forward 
            
        }
        return {}; // if no result 
    }
};
