// problem: 704. Binary Search
// difficulty: easy
// topic: array, binary search
// approach: from the sorted array we will assign last element index to high and first index to low when while low<= high we will run a loop and keep updating mid to low+(high-low)/2, ig nums at index of mid is 
// target then return mid, if its greater than target them update high to mid-1 and if its smaller than target then update low to mid +1, at last if loop ends then return -1;
// time: O(log n)
// space: O(1)
// link: https://leetcode.com/problems/binary-search/description/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int low=0;
        int high= nums.size()-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid]==target)
            return mid;
            else if(nums[mid]>target)
            high = mid-1;
            else
            low = mid+1;
        }
        return -1;
    }
};
