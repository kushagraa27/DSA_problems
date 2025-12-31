// problem: 322. Coin Change
// difficulty: medium 
// topics: array, DP, bfs
// approach: first of all we decided what do we need, we need a dp[amount] which stored the minimum number of coins to keep that amount, then store dp[0] = 0 since we 
// need zero coins to store that amount then we will start a loop from 1 to the required amount, inside that loop at each amount we will check coins requied to rech that
// amount by each coing given, if x-coin is less than zero means coin value is greater than requied amount at that time, also if the required coins for the amount equal to
// x-current coin is INF (or not known yet) we cant know the number of coins requied for this coin, therefore we will only update wehn both conditions are right, 
// dp[x] will become minimum number of coins required out of all the possibilites made with each coin we have.
// at last we will return the dp[amount] if its not INF otherwise return -1.
// time: O(amount x number of coins)
// space: O(amount)
// link :  https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int INF = 1e9;
        vector<int> dp(amount+1, INF);
        dp[0] = 0;
        for(int i =1;i<=amount;i++)
        {
            for(int coin : coins)
            {
                if(i-coin >= 0 && dp[i-coin] != INF)
                dp[i]=min(dp[i], 1+dp[i-coin]);
            }
        }
        return dp[amount] == INF? -1:dp[amount];
    }
};
