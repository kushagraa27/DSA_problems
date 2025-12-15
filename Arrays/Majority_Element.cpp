// problem: 169. Majority Element - find majority element in array, repeating more than n/2 times
// difficulty: easy
// topic: array, hash table, counting, sorting, divide n conquer 
// approach:-
// brute foce - simply just initialise counter variable and n (size) at starting, outer loop i, from 0 to n and at each i the counter should be reset, inner loop j will
// run from 0 to n and counter increments if a value is repeated, at the end of inner loop, if c is more than n/2, return nums[i].
// optimized - by using unordered map we can further optimize the code, initialse the map first (m[key]->frequency), the loop will run from 0 to n and we will keep
// upating, m[nums[i]]++, this will increase the frequency of the key in map, or make one, if its not existing, finally if m[nums[i]]>n/2 then return it.
// Boyer–Moore algo - initialise candidate and count at starting, then the concept is, run the loop from 0 to n and if we cancel out non-majority element with 
// majority element, at last we will be left with majority one, so then we return the candidate after cancelling all out.
// time: O(n)
// space:O(1)
// link: https://leetcode.com/problems/majority-element/submissions/1855947269/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int count=0;
       int candidate = 0;
       for(int i: nums)
       {
        if (count == 0)
        {
            candidate=i;
            count = 1;
        }
        else if(i==candidate)
        {count++;
        }
        else{
            count --;
        }
       }
       return candidate;
    }
};
