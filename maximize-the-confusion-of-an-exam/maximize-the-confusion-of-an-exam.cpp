class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans=0,i=0,j=0,n=answerKey.size(),c=0,ans2=0;
        while(j<n)
        {
            if(answerKey[j]=='F')
                c++;
            while(c>k)
            {
                if(answerKey[i]=='F')
                    c--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        j=0,i=0,c=0;
        while(j<n)
        {
            if(answerKey[j]=='T')
                c++;
            while(c>k)
            {
                if(answerKey[i]=='T')
                    c--;
                i++;
            }
            ans2=max(ans2,j-i+1);
            j++;
        }
        return max(ans,ans2);
    }
};