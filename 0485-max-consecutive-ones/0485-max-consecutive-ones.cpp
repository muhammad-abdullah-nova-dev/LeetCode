class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxStreak=0;
        int currentStreak=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                currentStreak++;
                maxStreak=max(maxStreak,currentStreak);
            }
            else if(nums[i]==0)
            {
                currentStreak=0;
            }
        }
        return maxStreak;
    }
};