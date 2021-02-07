class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        int ans =0;
        if(size==0) return 0;
        vector<int> left(size),right(size);
        
        left[0] = height[0];
        for(int i=1;i<size;i++)
            left[i] = max(left[i-1],height[i]);
        right[size-1]= height[size-1];
        for(int i=size-2;i>=0;i--)
            right[i] = max(right[i+1],height[i]);
        
        for(int i=1;i<size-1;i++)
            ans += min(left[i],right[i]) - height[i];
        
        return ans;
    }
};