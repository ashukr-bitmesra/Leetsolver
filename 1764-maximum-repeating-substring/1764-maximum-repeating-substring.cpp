class Solution {
public:
    vector<int> pre(string& word)
    {
        vector<int> res(word.size());
        for(int i = 1, j = 0;i<word.size();++i)
        {
            if(word[i] == word[j])
            {
                res[i] = ++j;
            }
            else
            {
                if(j != 0)
                {
                    j = res[j-1];
                    --i;
                }
            }
        }
        return res;
    }
    int find(string& sequence,string& word)
    {
        auto v  = pre(word);
        int j = 0;
        for(int i = 0;i<sequence.size();)
        {
            if(sequence[i] == word[j])
            {
                ++i;
                if(++j == word.size())
                    return i-word.size();
            }
            else
            {
                if(j != 0)
                    j = v[j-1];
                else
                    ++i;
            }
        }
        return -1;
    }
    int maxRepeating(string sequence, string word) {
        int count=0;
        string temp=word;
        while(find(sequence, temp) != -1)
        {
            count++;
            temp+=word;
        }
        return count;
    }
};