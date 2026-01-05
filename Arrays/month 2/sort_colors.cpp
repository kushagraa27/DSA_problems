// problem: 75. Sort Colors
// difficulty: medium 
// topics: array, two pointers, sorting 
// approach: here we have 3 pointers, low, mid and high, low and mid are 0 and high is last element, now in order to sort this array in one pass, we will have 3 
// base conditions, if nums[mid] is zero then swap it with nums[low] since zero must be at left and then increase low and mid, if nums[mid] is one the simply increase 
// the mid, since one is supposed to be in middle, and if nums[mid] is 2 then swap it with the nums[high] since 2 should be at right, and decrease high but dont increase
// mid since we dont know what value came from nums[high], then repeat these steps till mid<=high, and at last the array will be sorted as desired.
// time: O(n)
// space: O(1)
// link:  https://leetcode.com/problems/sort-colors/description/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        int mid = 0;
        while(mid<=high)
        {
            if(nums[mid]==0)
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
            mid++;
            else
            {swap(nums[high],nums[mid]);
            high--;
            }
        }
            
        
    }
};
