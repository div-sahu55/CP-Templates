//Author: divyansh_sahu
//2D prefix sums, Problem Link: https://codeforces.com/contest/1722/problem/E
/* 
If we have a grid and we want to find the sum of a rectangle represented by
two cells, (a,b) as the top left corner and (c,d) as the bottom right corner.
We need to find the sum of this sub-rectangle in constant time with some precomputations. 
*/
// Time Complexity: O(N*M), Where N and M are the number of rows and columns in the grid.
#include<iostream>
#include<vector>
const int inf = 1000000000;
using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> arr(n+1,vector<int>(m+1,0)),dp(n+1,vector<int>(m+1,0));
    // Take the grid input as 1-indexed, so that we can access (i-1)th positions without needing to check for seg. faults.
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>arr[i][j];
        }
    }
    //2D precomputation:
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // We sum the values of the penultimate prefix rows and columns and then subtract the common cells as they get added twice.
            dp[i][j] = arr[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
        }
    }
// Now in order to access the sum of a rectangle represented by (a,b) as top-left and (c,d) as bottom right corners:
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int sum = dp[c][d]-dp[c][b-1]-dp[a-1][d]+dp[a-1][b-1];
    cout<<sum;
}   
int main(void){
    solve();
}
