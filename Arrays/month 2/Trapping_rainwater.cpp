// problem: 42. Trapping Rain Water
// difficulty: hard
// topic: array, dp, two pointers, stack, monotonic stack.
// approach: to solve this problem in an optimized approach, we will use two pointer approach, l will be 0 and right will be n-1, now the stored water formula will be
// water[i] = min(max height at left,max height at right) - height[i], which means the water stored above a height will be minimum of height among leftMax and rightMax
// because the volume of water depends on the smaller height, and we subtract the current height with that max and keep on adding such values to get final result.
// if height[l] is smaller than height[r] we see the left side because the less height side contributes the volume of water.
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,leftMax=0,rightMax=0;
        int r = height.size()-1;
        int water=0;

        while(l<r)
        {
            if(height[l]<height[r])
            {
                if(leftMax<=height[l])
                leftMax=height[l];
                else
                water = water + leftMax-height[l];
                l++;
            }
            else{
                if(rightMax<=height[r])
                rightMax = height[r];
                else
                water = water + rightMax-height[r];
                r--;
            }
        }
        return water;
        
    }
};
