// problem: 977. Squares of a Sorted Array
// difficulty: easy 
// topics: array, two pointers
// approach: we make a seperate vector to store the values from nums and then use left and right pointers, compare their absolute values and fill the square
// of larger value from the right side of new vector because at both ends we have larger values, now smaller.
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/squares-of-a-sorted-array/description/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int l=0;
        int r = n-1;
        int i=n-1;
        while(l<=r)
        {
            if(abs(nums[l])>abs(nums[r])){
                res[i] = nums[l]*nums[l];
                l++;
                i--;
            }
            else{
                res[i] = nums[r]*nums[r];
                r--;
                i--;
            }

        }
        return res;
    }
};
