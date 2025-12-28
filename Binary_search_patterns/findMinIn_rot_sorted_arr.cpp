// problem: 153. Find Minimum in Rotated Sorted Array
// difficulty: medium
// topic: array, binary search
// approach: first of all initialise low and high then while low is smaller than high, the loop will run while low is smaller than high, if the nums[min] is less 
// than nums[high] then the min will lie on left half and high will be mid and if the nums[mid] is greater than nums[high] then the min will lie on right half and low
// will be mid+1, this will keep going on until low==high and return nums[low] at last
// time: O(log n)
// space: O(1)
// link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high = nums.size()-1;
      
            while(low<high)
            {
               int mid = low + (high-low)/2;
               if(nums[mid]>nums[high])
               low = mid+1;
               else
               high = mid;
            }
            return nums[low];
        
    }
};
