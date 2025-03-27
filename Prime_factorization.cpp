int precompute_smallest_prime_factor(int n){
    spf.assign(n+1,0);
    for(int i=1 ; i<=n; i++){
        spf[i] = i;
    }
    for(int i=2; i*i<=n;i++){
        if(spf[i]==i){
            for( int j = i; j<=n; j+=i){
                if(spf[j] ==j)
                    spf[j] = i ;
            }
        }
    }
}   
unordered_set<int> factorise(int num){
    unordered_set<int> ans ;
    if(num==1){
        return ans ;
    }
    while(1){
        ans.insert(spf[num]) ;
 
        num = num/spf[num] ;
 
        if(num==1)  break;  
    }
    return ans ;
}
