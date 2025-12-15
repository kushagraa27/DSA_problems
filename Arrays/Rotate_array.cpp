// problem: 189. Rotate Array
// difficulty: medium
// topics: array, math, 2 pointers
// approach:-
// Brute force - in this we will save the last element of the array then then shift positions of all elements by 1 and then put last element at first position,
// repeat it k times to get the answer.
// optimization - it can further be optimized if we remove the outer loop repeating k times and put the elements directly to i+kth position, and do necessary 
// formulation if i+k>n-1 but we need to make one vector which consumes space
// once again we can optimise the code to remove extra space, we can just first reverse the array, then reverse it from 0 to kth element, then remaining k to nth element 
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/rotate-array/submissions/1856188284/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         int n=nums.size();
        
         k=k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
        
        
    }
    
};
