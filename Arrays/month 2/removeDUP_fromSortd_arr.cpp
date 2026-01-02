// problem: 26. Remove Duplicates from Sorted Array
// difficulty: easy
// topics: array. two pointers
// approach: in the sorted array, i took two pointers, i and j, j was set to zero and i was moving from 1 to nums.size, as the i was increasing, i checked if nums[i]!=
// nums[j] if yes then we replace nums[j+1] with nums[i] and increase j by 1 and keep repeating this, at last we return j+1 which will be size of new array. 
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int j=0;
       int n = nums.size();
       if(n==0) return 0;
       for(int i=1;i<nums.size();i++)
       {
        if(nums[i]!=nums[j])
        {
            nums[j+1]=nums[i];
            j++;
        }
       }
       return j+1;
       
    }
};
