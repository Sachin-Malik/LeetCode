class NumArray {
public:
vector<int> BITree;
vector<int> arr;
NumArray(vector<int>& nums) {
        int n=nums.size();
        BITree.resize(n+1,0);
        arr.resize(n,0);
        arr=nums;
        for(int i=0; i<n; i++)
                updateBITree(i,nums[i],BITree);
}

void update(int index, int val) {
        int diff=val-arr[index];
        arr[index]=val;
        updateBITree(index,diff,BITree);
}

int sumRange(int left, int right) {
        int r=getSum(right,BITree);
        int l=getSum(left-1,BITree);
        return r-l;
}

void updateBITree(int index,int val,vector<int>&BITree){
        index=index+1;
        int n=BITree.size();
        while(index<n) {
                BITree[index]+=val;
                index+=index&(-index);
        }
}

int getSum(int index,vector<int>&BITree){
        index=index+1;
        int n=BITree.size(),sum=0;
        while(index>0) {
                sum+=BITree[index];
                index-=index&(-index);
        }
        return sum;
}
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
