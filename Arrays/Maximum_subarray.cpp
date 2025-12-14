// problem: 53. Maximum Subarray - find a subrarray whos addition of elements is maximum and return the sum
// difficulty: medium
// topic: array, divid and conquer, dynamic programming (kadane's algorithm)
// approach :-
// Brute force - in this we will initialise our max sum as nums[0] then outer loop i from 0 to n and at every i, our sum will start from 0, then in inner loop, j will
// run from 0 to n and keep adding the elements one by one, if that sum is greater than max sum then set max sum as that current sum, keep scanning for all posibilities
// kadane's algo - now in this we remove the outer loop and instead of updating current sum at every i, we write sum = max(nums[i],sum+nums[i]), this automatically,
// drops the old sum if value is less than 0, coz it wont contribute in future summation and consider the old sum if its greater than o, because it can contibute.
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/maximum-subarray/submissions/1855218659/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int Tsum = nums[0];
        int sum = nums[0];
        for (int i =1;i< nums.size(); i++)
        { 
            sum=max(nums[i],sum+nums[i]);
            Tsum = max(sum,Tsum);

            
        }
        return Tsum;
    }
        
};
