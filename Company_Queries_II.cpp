#include <iostream>
#include <vector>
using namespace std;
int n, m, a, b, dep[200005], arr[20][200005];
vector<int> v[200005];
void dfs(int x){
    for(auto i : v[x]){
        dep[i] = dep[x] + 1;
        dfs(i);
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
    if(dep[b] > dep[a]) return lca(b, a);
    int dif = dep[a] - dep[b];
    for(int i = 0; i <= 19; i++){
        if(dif & (1 << i)){
            a = arr[i][a];
        }
    }
    if(a == b) return a;
    for(int i = 19; i >= 0; i--){
        if(arr[i][a] != arr[i][b]){
            a = arr[i][a];
            b = arr[i][b];
        }
    }
    return arr[0][a];
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 2; i <= n; i++){
        cin >> arr[0][i];
        v[arr[0][i]].push_back(i);
    }
    dfs(1);
    build();
    while(m--){
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
}
