// problem: 739. Daily Temperatures
// difficulty: medium
// topic: stack, array, monotonic stack, weekly contest 61
// approach: first we will make an answer vectore of size n and 0 stored at each index by default which will help us to store zero where there is no greater temp
// then we will make a stack to store the index of temp which dont have any greater temp yet, we move temp from left to right and while our stack is not empty and 
// ith temp of vector is greater than the top of our stack then store the top in prev variable, annd pop it from stack then ans[prev] will be i-prev by which we will
// get difference of larger temp day and previous temp day/days. and at last return the ans.
// time: O(n)
// space: O(n)
// link: https://leetcode.com/problems/daily-temperatures/description/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<int> st;
        int n=temperatures.size();
        vector<int> ans(n, 0);
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && temperatures[i]>temperatures[st.top()])
            {
                int prev = st.top();
                st.pop();
                ans[prev] = i-prev;
            }
            st.push(i);
        }
        return ans;
    }
};
