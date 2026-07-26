class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        int j=0;
        for(char ch : t)
        {
             if (i < s.size() && t[j] == s[i])
             {
                 i++;
             }
             j++;
        }
        return i == s.size();
    }
};