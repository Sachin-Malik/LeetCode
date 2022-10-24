class Solution {
public:
    int maxLen=INT_MIN;
    void backtrack(int index,int currentLen,vector<string>&arr,vector<int>&freq){
        if(index==arr.size()){
            maxLen=max(maxLen,currentLen);
            return;
        }

        //include this string
        bool canInlucdeThisString=true;
        for(int i=0;i<arr[index].size();i++){
              freq[arr[index][i]-'a']++;
              if(freq[arr[index][i]-'a']>1) canInlucdeThisString = false;
        }

        if(canInlucdeThisString)
        backtrack(index+1,currentLen+arr[index].size(),arr,freq);
        
        //undo the changes for the backtracking
        for(int i=0;i<arr[index].size();i++){
              freq[arr[index][i]-'a']--;
        }


        //don't include this string
        backtrack(index+1,currentLen,arr,freq);

    }
    int maxLength(vector<string>& arr) {
        vector<int> freq(26,0);
        backtrack(0,0,arr,freq);
        return maxLen;
    }
};