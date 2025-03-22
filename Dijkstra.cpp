#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    priority_queue<pi, vector<pi>, greater<pi>>pq;
    pq.push({0,1});
    vl dist(n+1,inf);
    //Single source dijsktra:
    while(!pq.empty()){
        int u = pq.top().second;
        //This condition is to make sure that the current node has the most recent distance
        // This makes sure that we dont process duplicate nodes when we dont need to
        if(pq.top().first!=dist[u]){
            pq.pop();
            continue;
        }
        pq.pop();
        for(auto e : adj[u]){
            int v = e.first;
            deb(v);
            int weight = e.second;
            if(dist[v]>dist[u]+weight){
                dist[v] = dist[u]+weight;
                pq.push({dist[v],v});
            }
        }
    }
    return 0;
}
