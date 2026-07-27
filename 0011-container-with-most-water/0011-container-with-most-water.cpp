class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int n=height.size();
        int r=n-1;
        int area=0;
        int maxArea=0;
        while(l<r)
        {
            area = min(height[l], height[r]) * (r - l);
            maxArea = max(maxArea, area);
            if(height[l]<height[r])
            {
                l++;
            }
            else 
            {
                r--;
            }
        }
        return maxArea;
    }
};