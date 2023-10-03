#include <iostream>
#include <vector>
using namespace std;
vector<int> v[200005];
int n, q, a, b, dep[200005], arr[20][200005];
void dfs(int x, int pre){
    for(auto i : v[x]){
        if(i == pre) continue;
        dep[i] = dep[x] + 1;
        arr[0][i] = x;
        dfs(i, x);
    }
}
void build(){
    for(int i = 1; i <= 19; i++){
        for(int j = 1; j <= n; j++){
            arr[i][j] = arr[i - 1][arr[i - 1][j]];
        }
    }
}
int lca(int a, int b){
    if(dep[a] > dep[b]) return lca(b, a);
    int dif = dep[b] - dep[a];
    for(int i = 0; i <= 19; i++){
        if(dif & (1 << i)){
            b = arr[i][b];
        }
    }
    if(a == b) return a;
    for(int i = 19; i >= 0; i--){
        if(arr[i][a] != arr[i][b]){
            a = arr[i][a];
            b = arr[i][b];
        }
    }
    return arr[0][b];
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i < n; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0);
    build();
    while(q--){
        cin >> a >> b;
        cout << dep[a] + dep[b] - dep[lca(a, b)] * 2 << '\n';
    }
}
