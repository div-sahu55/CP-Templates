class SparseTable{
    int maxNums = 0;
    vector<vector<int>> table;
    public:
        SparseTable(vector<int>& dataVector){
            maxNums = (int)dataVector.size();
            //  State: table[i][j] -> min of the range starting from i and of width j
            // That is, table(i,j) => min(range(i,i+2^j-1))
            table.assign(maxNums,vector<int>(25,INT_MAX));
            build(dataVector);
        }
        void build(vector<int>& dataVector){
            for(int l=maxNums-1;l>=0;l--){
                for(int w=0;w<25;w++){
                    // for width of size 0, the min would be the number itself
                    if(w==0){
                        table[l][w] = dataVector[l];
                        continue;
                    }
                    int r = l+(1<<w)-1;
                    if(r>=maxNums)break;
                    else{
                        //DP transition: dp[i][j] = min(dp(first half of width w-1),dp(second half of width w-1))
                        // j is always a power of 2
                        //Can be modified to find the max, gcd or sum in the range
                        table[l][w] = min(table[l][w-1], table[l+(1<<(w-1))][w-1]);
                    }
                }
            }
        }
        int query(int l, int r){
            if (l < 0 || r >= maxNums || l > r) {
                throw std::out_of_range("Query range is out of bounds.");
            }
            int w = r-l+1;
            int pwr = (int)log2(w);
            return min(table[l][pwr],table[r-(1<<pwr)+1][pwr]);
        }
};
int main(){
    vector<int> arr = {1,2,3,4,5};
    SparseTable table(arr);
    cout<<table.query(5,5);
} 