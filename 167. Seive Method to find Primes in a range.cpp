int seivePrimes(int n){
    int primeCount=0;
    vector<bool> arr(n+1,false);

    //marked all non prime numbers
    for(int i=2;i<=n;i++){
        if(!arr[i]){
            for(int j=i*i;j<=n;j+=i){
                arr[i]=true;
            }
        }
    }

    //count the number that are not visited.
    for(int j=2;j<=n;j++){
        if(!arr[i])
        primeCount++;
    }

    return primeCount;
}