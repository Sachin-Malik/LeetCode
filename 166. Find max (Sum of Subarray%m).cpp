//Given an array a and a modulo m, find the maximum sum of a subset modulo m.

//1.First we need to find the sum of all the elements in the array%m.
//2.Then in order to get max we only need to look number greater than current val in prefix sum array.

long maximumSum(vector<long> a, long m) {
  set<long> s;
  vector<long> prefix(a.size());
  long sum=0,maxVal=INT_MIN;
  for(int long i=0;i<a.size();i++){
    sum+=a[i];
    prefix[i]=sum%m;
    maxVal=max(maxVal,prefix[i]);
    sum=prefix[i];
  }
  
  for(long i=0;i<prefix.size();i++){
      auto it=s.upper_bound(prefix[i]);
      if(it!=s.end()){
          long val=*it;
          val=prefix[i]-val+m;
          maxVal=max(maxVal,val);
      }
      s.insert(prefix[i]);
  }
  return maxVal;
}
