/*
   Lauren has a chart of distinct projected prices for a house over the next several years.
   She must buy the house in one year and sell it in another, and she must do so at a loss.
   She wants to minimize her financial loss.
 */
long minimumLoss(vector<long> price) {
        unordered_map<long,long> hashTable;
        for(long i=0; i<price.size(); i++) {
                hashTable[price[i]]=i;
        }

        sort(price.begin(),price.end());
        long minDiff=INT_MAX;
        for(long i=1; i<price.size(); i++) {
                if(hashTable[price[i]]<hashTable[price[i-1]]) {
                        long d=price[i]-price[i-1];
                        minDiff=min(minDiff,d);
                }
        }
        return minDiff;
}
