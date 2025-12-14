// problem: 238. Product of Array Except Self
// difficulty: Medium
// topics: array, prefix sum
// approach:-
// brute force - first i initialised the vector named arr to store then products, pro and s to store prodoct of right side and left side respectively, the outer loop 
// i, runs from 0 to n and at starting of each i, pro becomes 1, inner loop j, runs from i+1 to n and computes right side sum in pro, it is then store in arr after,
// multiplying with left product s, and s value is updated to s=s*nums[i]. Same steps repeat from next i and at last arr is returned.
// optimized soln - in optimized solution, instead of using nested for loop we used 2 seperate loops for calculating left product and right product, and in 2nd loop
// of right product we just altered the array formed by left product in first loop and got our result,
// first lopp runs from left to right and second loop runs from right to left
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/product-of-array-except-self/submissions/1855293161/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int s=1;
       int n= nums.size();
       int pro=1;
        vector<int> arr(n);
        arr[0]=1;
        for (int i=1;i<n;i++)
        {
            
            s=s*nums[i-1];
            arr[i]=s;
        }
        for (int j=n-2;j>-1;j--){
            
            pro=pro*nums[j+1];
         arr[j]*=pro;
        }   
        return arr;
        
    }
};
