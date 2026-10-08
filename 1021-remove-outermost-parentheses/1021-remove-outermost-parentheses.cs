public class Solution {
    public string RemoveOuterParentheses(string s) {
        StringBuilder res = new StringBuilder();
        Stack<char> stack = new Stack<char>();
        foreach (char c in s) {
            if (c == ')') {
                stack.Pop();
            }
            if (stack.Count > 0) {
                res.Append(c);
            }
            if (c == '(') {
                stack.Push(c);
            }
        }
        return res.ToString();
    }
}