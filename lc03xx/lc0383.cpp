//--- Q: 383. Ransom Note

//--- method 1: array operation
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> ch(26, 0);
        for (int i = 0; i < magazine.size(); ++i)
        	++ch[magazine[i]-'a'];
        for (int i = 0; i < ransomNote.size(); ++i)
        {
        	if (--ch[ransomNote[i]-'a'] < 0)
                return false;
        }
        return true;
    }
};