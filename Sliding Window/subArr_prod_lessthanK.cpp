// problem: 713. Subarray Product Less Than K
// difficulty: medium
// topic: array, binary sum, sliding window, prefix sum
// approach: code if very simple if understood how to work, so what we should do is, right pointer from left to right and if prod becomes equal to or less than k then
// divide the product with left pointer and increase it by one, now store the number of subarray in a variable, and thats the main logic, the length of current window
// should be added to the variable thats how we will get total number.
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/subarray-product-less-than-k/description/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left=0,number=0;
        double prod=1;
        if(k<=1) return 0;
        for(int right=0; right<nums.size();right++)
        {
            prod*=nums[right];
            while(prod>=k)
            {
                prod/=nums[left];
                left++;
            }
            number+=right-left+1;
        }
        
        return number;
    }
};
