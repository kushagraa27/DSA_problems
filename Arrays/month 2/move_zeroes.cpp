// problem: 283. Move Zeroes
// difficulty: easy
// topic: array, two pointers
// approach: so first of all i was thinking how to transfer all zeroes to the last of array and keep the order of non zero numbers same, i though many things like
// swapping each zero with non zero numbers one by one but that would make complexity n^2 later i took help and figured that it we set j=0 and iterate it through the 
// array and each time we get a non zero number we swap it with jth position and then increase j by 1, our array will be changed in one pass only, thats the solution
// time: O(n)
// space: O(1)
// link:  https://leetcode.com/problems/move-zeroes/description/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] != 0)
            {
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};

