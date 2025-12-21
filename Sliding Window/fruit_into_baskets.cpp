// problem: 904. Fruit Into Baskets
// difficulty: medium
// topics: array, sliding window, hash table
// approach: first we make an unordered map to store the frequency, now one imp thing to understand is that, we use map to identify the types of fruit in window
// (size of map) and to identify the number of fruits we use length of window, now we more right pointer from left to right, and if size of map becomes more than
// 2 then we should decrese frequency of left by 1 intil map size is less than 2, if frequency of any type becomes zero then erase that type from map, not before
// then store lax muber of fruits in a variable and return it at last.
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/fruit-into-baskets/description/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> m;
        int left=0;
        int maxF=0;
        for(int right=0;right<fruits.size();right++)
        {
            m[fruits[right]]++;
            while(m.size()>2)
            {
                m[fruits[left]]--;
                if(m[fruits[left]]==0)
                m.erase(fruits[left]);
                left++;
            }
            maxF= max(maxF, right-left+1);
        }
        return maxF;
    }
};
