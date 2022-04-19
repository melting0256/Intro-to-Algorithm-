#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
  
long long int n, m, a, b, dfn[200005], stk[200005], low[200005], pa[200005], in[200005], k[200005], scc, idx;
long long coins[200005], dp[200005], ans;
vector <long long int> v[400005];
vector <long long int> v2[400005];
stack <long long int> st;
  
void tarjan(long long int x){
    idx++;
    dfn[x] = low[x] = idx;
    st.push(x);
    stk[x] = 1;
    for (auto i:v[x]){
        if (!dfn[i]){
            tarjan(i);
            low[x] = min(low[x], low[i]);
        }
        else if (stk[i]){
            low[x] = min(low[x], dfn[i]);
        }
    }
    if (dfn[x] == low[x]){
        scc++;
        pa[x] = scc;
        long long int nxt = -1;
        while (nxt != x){
            nxt = st.top();
            st.pop();
            pa[nxt] = scc;
            stk[nxt] = 0;
        }
    }
}
void build(){
    for (long long int i = 0; i < n; i++){
        coins[pa[i]] += k[i];
        for (long long int j:v[i]){
            if (pa[i] != pa[j]){
                v2[pa[i]].push_back(pa[j]);
                in[pa[j]]++;
            }
        }
    }
}
void topo(){
    queue <int> q;
    for (long long int i = 1; i <= scc; i++){
        if (in[i] == 0) q.push(i);
    }
    while (!q.empty()){
        long long int now = q.front();
        q.pop();
        dp[now] += coins[now];
        ans = max(ans, dp[now]);
        for (auto i:v2[now]){
            in[i]--;
            dp[i] = max(dp[i], dp[now]);
            if (!in[i]) q.push(i);
        }
    }
}
  
int main() {
    cin >> n >> m;
    for (long long int i = 0; i < n; i++){
        k[i]=1;
    }
    for (long long int i = 0; i < m; i++){
        cin >> a >> b;
        v[a].push_back(b);
    }
    for (long long int i = 0; i < n; i++){
        if (!dfn[i]) tarjan(i);
    }
    build();
    topo();
    cout << ans ;
}
