// problem: 11. Container With Most Water
// difficulty: medium 
// topics: array, two pointers, greedy
// approach: so in this problem we applied greedy approach, in order to find max area, we took two pointers - left and right, l = 0 and r=n-1, now we will calculate
// area of each container, and if its greater than the current value of area then update it, else iterate the container with lesser height, since the greater height
// can give us more area, thats greedy approach.
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/container-with-most-water/description/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r= n-1;
        int area =0;
        while(l<r)
        {
            area = max(area, min(height[l],height[r])*(r-l));
            if(height[l]<height[r])
            l++;
            else
            r--;
        }
        return area;
    }
};

