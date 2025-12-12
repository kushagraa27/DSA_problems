// problem: 121. Best Time to Buy and Sell Stock
// difficulty: easy
// topic: array, dynamic programming 
// approach:- 
//Brute Force:first i solved it using brute foce in which outer loop was from 0 to last element and inner loop was from i+1 to last element, then stored prices of j-i 
// (selling price - buying price) and stored in temp, if temp is > maxProfit then change the value of maxProfit and return maxProfit at last
// now for more optimal solution: we initialised minPrice = prices[0] and maxPrice=0 and the loop goes from 0 to last element, at each step it checks if profit,
// (which is prices[i]- minPrice), is greater than maxPrifit and if prices[i] is smaller than minPrice, if yes then update them respectively 
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/1853738151/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        for (int i=1; i<prices.size(); i++)
        {
            int profit = prices[i] - minPrice;
            if (profit > maxProfit)
                maxProfit = profit;
            if (prices[i]<minPrice)
                minPrice = prices[i];
            
        }
       
        return maxProfit;
    }
};
