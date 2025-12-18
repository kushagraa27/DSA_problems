// problem: 128. Longest Consecutive Sequence
// difficulty: Medium
// topic: array, hash table, union find
// approach: first of all i stored all values of array in an unordered set so that no value is repeated then i ran a loop to iterate all elements of set
// if a number n has no n-1 in set then we set current number as n and then run while loop until curr+1!=end of the set, and keep increasing the counter
// if at last value of counter is more than global counter then update it and return global counter at last, if n-1 exists in the set then we dont conpare it since
// we have to start only from the starting element of sequence
// time: O(n)
// space: O(n)
// link: https://leetcode.com/problems/longest-consecutive-sequence/submissions/1858846297/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int x : nums)
        {
            s.insert(x);
        }
        int maxL=0;
        for(int n : s)
        {   
         int c=0;
            if (s.find(n-1)==s.end())
        {   
            int curr = n;
            c=1;
            while(s.find(curr+1)!=s.end())
            {c++;
            curr++;
            }
            if (c>maxL)
            maxL=c;
        }            
        }
        return maxL;
    }
};
