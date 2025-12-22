// problem: 344. Reverse String
// difficulty: easy
// topic: two pointers, string
// approach: just simple initialise right pointer with last element and left pointer with starting element and swap left and right until left=right.
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/reverse-string/description/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left=0;
        int right=s.size()-1;
        while(left<right)
        {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

