class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        for(int i = m - 1;i >= 0;i--){
            nums1[i+n] = nums1[i];      //因为nums1空间大，所以我们把元素都后移n位来存nums2
        }
        int cnta = 0,cntb = 0,cnt = 0;
        while(cnta < m && cntb < n){
            if(nums1[cnta+n] <= nums2[cntb]){
                nums1[cnt++] = nums1[cnta+n];
                cnta++;
            }
            else{
                nums1[cnt++] = nums2[cntb];
                cntb++;
            }
        }
        while(cnta < m){
                nums1[cnt++] = nums1[cnta+n];
                cnta++;
        }
        while(cntb < n){
                nums1[cnt++] = nums2[cntb];
                cntb++;
        }
    }
};
