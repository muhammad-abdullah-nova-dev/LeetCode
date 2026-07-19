class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ')
            i--;

        int length = 0;

        // Count the last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};