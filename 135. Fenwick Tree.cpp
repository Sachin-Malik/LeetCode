#include <bits/stdc++.h>
using namespace std;

void updateBITree(int index,int val,vector<int>&BITree){
        int n=BITree.size();
        index=index+1;
        while(index<n) {
                BITree[index]+=val;
                index+=index&(-index);
        }
}

int getSum(int index,vector<int>&BITree){
        int n=BITree.size(),sum=0;
        index=index+1;
        while(index>0) {
                sum+=BITree[index];
                index-=index&(-index);
        }
        return sum;
}

int main(){

        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
                cin>>arr[i];
        }

        vector<int> BITree(n+1);
        for(int i=0; i<n; i++) {
                updateBITree(i,arr[i],BITree);
        }

        cout<<getSum(4,BITree);
        cout<<endl<<"Add 6 to index 3"<<endl;
        updateBITree(3,6,BITree);//add 6 to index 3
        cout<<getSum(4,BITree);

}
