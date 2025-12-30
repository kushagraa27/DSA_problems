// problem: 70. Climbing Stairs
// difficulty: easy
// topics: maths, DP, memoization 
// approach: DP is all about storing sub problems somewhere and using them in future calculations, so here we are first of all storing ways to climb 1 and 2 steps and then our dp[i] will be dp[i-1]+dp[i-2]
// now at first i tried this by using vector which gives space complexity of n but then i realised we can do it simple using only integer variables, getting overwritten again n again in our loop. 
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/climbing-stairs/description/

class Solution {
public:
    int climbStairs(int n) {
        if(n <=2) return n;
        int prev2 = 1;
        int prev1 = 2;

        for(int i=3;i<=n;i++)
        {
            int curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
