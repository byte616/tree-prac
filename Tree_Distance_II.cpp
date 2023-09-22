#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll n, a, b, sz[200005], dep[200005];
vector<int> v[200005];
void dfs1(int x, int pre, int depth){
    sz[x] = 1;
    dep[1] += depth;
    for(auto i : v[x]){
        if(i == pre) continue;
        dfs1(i, x, depth + 1);
        sz[x] += sz[i];
    }
}
void dfs2(int x, int pre){
    for(auto i : v[x]){
        if(i == pre) continue;
        dep[i] = dep[x] - sz[i] + (n - sz[i]) ;
        dfs2(i, x);
    }
}
int main(){
    ios::sync_with_stdio(0) ,cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs1(1, 0, 0);
    dfs2(1, 0);
    for(int i = 1; i <= n; i++){
        cout << dep[i] << " ";
    }
}
