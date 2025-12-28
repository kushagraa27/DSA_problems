// problem: 33. Search in Rotated Sorted Array
// difficulty: medium 
// topic: array, binary search
// approach: first we will assign 0 to low, last index to high, then while low is smaller than or equal to high we will run the loop in which mid will be calculated and then if nums[mid] is target return mid
// if left side is sorted we will check if the target is in left side and high will be mid-1 but if its not in left side then low = mid+1, similarly if right side is sorted, we will check if our target is in right?
// if yes then low=mid+1 else if its in left then high=mid-1. at last return -1 if loop ends.
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/search-in-rotated-sorted-array/description/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high)
        {
            int mid = low+ (high-low)/2;
            if(nums[mid]==target)
            return mid;
            else if(nums[low]<=nums[mid])
            {
                if(target>=nums[low]&&target<nums[mid])
                high = mid-1;
                else
                low = mid+1;
            }
            else{
                 if(target>nums[mid]&&target<=nums[high])
                low = mid+1;
                else
                high = mid-1;
            }
        }
        return -1;
    }
};
