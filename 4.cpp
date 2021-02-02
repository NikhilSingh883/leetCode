class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(),m=nums2.size();
        
        double ans;
        

        int idx = (n+m)/2;
        int idx2 = idx - 1;
        
        double a=-1,b=-1;
        
        int i=0,j=0,k=0;

        while(i<n && j<m){

            if(nums1[i] <= nums2[j]){
                
                if(idx == k) a = nums1[i];
                if(idx2 == k) b = nums1[i];
                k++;
                i++;

            }
            else {
                if(idx == k) a= nums2[j];
                if(idx2 == k) b= nums2[j];
                k++;
                j++;

            }
        }

        while(i<n){
                if(idx == k) a = nums1[i];
                if(idx2 == k) b = nums1[i];
                k++;
                i++;

        }
        
        while(j<m){
                if(idx == k) a= nums2[j];
                if(idx2 == k) b= nums2[j];
                k++;
                j++;
        }
        
        cout <<a <<b<<endl;
        
        if((n+m)%2) return a;
         return (a+b)/2;
        
        
    }
};