class dsu{
    int *size, *parent, n;
 
public:
    dsu(int n)
    {
        size = new int[n];
        parent = new int[n];
        this->n = n;
        makeSet();
    }
    void makeSet()
    {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int x)
    {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
 
    void unite(int x, int y)
    {
	//Unites two sets and makes x the parent of y.
        int xset = find(x);
        int yset = find(y);
 
        if (xset == yset){
            return;
        }
 
        if(size[xset]<size[yset])swap(xset,yset);
        parent[yset] = xset;
        size[xset]+=size[yset];
    }
};
int main(){
	int n;
	cin>>n;
	dsu obj(n);
}
