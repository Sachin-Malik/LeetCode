// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
//
// The number of elements initialized in nums1 and nums2 are m and n respectively.
// You may assume that nums1 has a size equal to m + n such that it has enough space
// to hold additional elements from nums2.

class Solution {
public:
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        int j=0;
        while(m>0&&n>0)
        {
                if(nums1[i]>nums2[j])
                {
                        swap(nums1[i],nums2[j]);
                        sort(nums2.begin(),nums2.end());
                }
                i++;
                m--;
        }
        for(int s=0; s<nums2.size(); s++)
        {
                nums1[i]=nums2[s];
                i++;
        }

}
};
