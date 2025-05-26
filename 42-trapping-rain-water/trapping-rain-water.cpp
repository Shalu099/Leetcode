class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>lb(n);
        vector<int>rb(n);

        //left heightest

        for(int i=0;i<n;i++){
            if(i==0){
                lb[i]=height[i];continue;
            }
            lb[i]=max(height[i],lb[i-1]);

        }
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                rb[i]=height[i];continue;
            }
            rb[i]=max(height[i],rb[i+1]);
        }
        int area=0;
        for(int i=0;i<n;i++){
            area+=min(lb[i],rb[i])-height[i];
        }
        return area;
    }
};