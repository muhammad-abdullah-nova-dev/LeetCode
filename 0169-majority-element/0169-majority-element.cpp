class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int element;
       int count;
       for(int value : nums)
       {
        if(count==0){
            element=value;
        }
        if(value==element){
            count++;
        }
        else{
            count--;
        }
       }
       int cnt=0;
       for(int values : nums)
       {
        if(values==element)
        cnt++;
       }
       if(cnt>(nums.size()/2))
       {
        return element;
       }
       return -1;
    }
};