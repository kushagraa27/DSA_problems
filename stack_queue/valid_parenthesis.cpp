// problem: 20. Valid Parentheses
// difficulty: easy 
// topic: stack, string 
// approach: so first we will make an empty stack and then access the characters in string from left to right, if the caracter is an opening bracket then push it to the stack else if its a closing bracket, if
// stack is empty then return false, else if for that closing bracket, appropriate opening bracket is not there at top of stack then return false, at last return st.empty() not true, because it can return true if
// out string is "(((" so return st.empty(); at last.
// time: O(n)
// space: O(n)
// link: https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
       for(char c : s)
       {
        if(c=='['||c=='{'||c=='(')
        st.push(c);
        else
        {
            if(st.empty()) return false;
            if((c==')' && st.top()!='(')||
               (c==']' && st.top()!='[')||
               (c=='}' && st.top()!='{'))
               return false;
               st.pop();
        }
       }
       return st.empty();
    }
};
