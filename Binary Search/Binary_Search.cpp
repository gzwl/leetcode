class Solution {
public:
    int binsearch(int l,int h, vector<int>& nums, int target)
    {
        if(nums[l]==target)
            return l;
        if(nums[h]==target)
            return h;
        if(l==h)
            return -1;
        
        //cout<<l<<h<<endl;
        
        int m=(l+h)/2;
        if(target <nums[m+1])
            return binsearch(l,m,nums,target);
        else
            return binsearch(m+1,h,nums,target);
        
        
    }
    int search(vector<int>& nums, int target) {
        return binsearch(0,nums.size()-1,nums,target);
        
    }
};
