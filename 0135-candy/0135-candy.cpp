class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size());
        int n=candies.size();
        for(int i=0;i<candies.size();i++)
        {
            candies[i]=1;
        }
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                candies[i]=candies[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(ratings[i]>ratings[i+1])
            {
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=candies[i];
        }
        return sum;
    }
};