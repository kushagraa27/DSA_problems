// problem: 15. 3Sum- Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// difficulty: Medium
// topics: sorting, two pointers, array
// approach: i first started confused, tried unordered maps etc but it cant work, later i took hints n help and then first did sorting of array, then a for loop from 0 to n,
// if there is a duplicate element behind i then i++ and select nums[i] as first number of triplet, now set left as i+1 and right as n-1 and again loop until left<right
// do the sum of nums[i], nums[left] and nums [right], if its equal to zero then store the indices in ans and skip the duplicates of both left and right until right side of left n right is not a 
// different number, and do increment, if sum is greater than zero then decrease right and if sum is less than zero then increase the left index. then return ans
// time: O(n^2)
// space:O(1)
// link: https://leetcode.com/problems/3sum/submissions/1857039075/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++)
        {
            if(i>0&&nums[i]==nums[i-1]) continue;
            int left = i+1;
            int right = n-1;
            while(left<right)
            {
                int sum = nums[i]+nums[left]+nums[right];
                if (sum==0){
                ans.push_back({nums[i],nums[left],nums[right]});

                while(left<right&&nums[left]==nums[left+1]) left++;
                while(left<right&&nums[right]==nums[right-1]) right--;

                left++;
                right--;
                }
                else if(sum<0)
                left++;
                else
                right--;

            }
        }
        return ans;
        
    }
};


