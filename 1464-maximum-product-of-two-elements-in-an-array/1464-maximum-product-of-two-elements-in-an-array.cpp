class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int largest=INT_MIN;
       int secondLargest=INT_MIN;
       for(int i=0;i<nums.size();i++)
       {
        if(nums[i]>largest)
        {
            secondLargest=largest;
            largest=nums[i];
        }
        else if(nums[i]>secondLargest)
        {
            secondLargest=nums[i];
        }
       }
       return (largest-1)*(secondLargest-1);
    }
};