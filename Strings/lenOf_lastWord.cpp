// problem: 58. Length of Last Word
// difficulty: easy 
// topic: string 
// approach: we will start scanning from right since we need last word, first we will check if there are any spaces at last, and remove them, then when its done
// we will keep running while loop until we get one more blank space or the value of n reaches less than zero (end of the string), at each iteration we will increase
// the counter which will track the length of last word and we will return it at last.
// time: O(n)
// space: O(1)
// link: https://leetcode.com/problems/length-of-last-word/description/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size()-1;
        while(s[n] == ' ' && n>=0)
        {
            n--;
        }
        int c=0;
            while(n >= 0 && s[n]!=' ')
            {
                c++;
                n--;
            }

        return c;
    }
};
