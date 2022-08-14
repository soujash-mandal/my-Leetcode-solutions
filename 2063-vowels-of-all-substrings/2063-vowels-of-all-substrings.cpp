class Solution {
public:
    bool isVowel(char c)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
        return false;
    }
    long long countVowels(string word) {
        int n=word.size();
        long long res=0;
        
        for(int i=0;i<n;i++)
        {
            if(isVowel(word[i]))
            {
                res+=(i+1)*1LL*(n-i);
            }
        }
        return res;
    }
};