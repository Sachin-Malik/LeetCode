class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> firstColumn;
        for(int i=0;i<matrix.size();i++){
            firstColumn.push_back(matrix[i][0]);
        }
        int rowNumber = myBinary(firstColumn,target);
        int colNumber = myBinary(matrix[rowNumber],target);
        return matrix[rowNumber][colNumber]==target;


    }

    int myBinary(vector<int>&nums,int target){
        int result=0;
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]<target){
                result=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return result;
    }
};