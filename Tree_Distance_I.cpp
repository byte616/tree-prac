#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, a, b, max_len, dep1[200005], dep2[200005];
vector<int> v[200005];
void dfs(int x, int pre, int &max_id, int dep[200005]){
    if(dep[x] > max_len){
        max_len = dep[x];
        max_id = x;
    }
    for(auto i : v[x]){
        if(i == pre) continue;
        dep[i] = dep[x] + 1;
        dfs(i, x, max_id, dep);
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int max_id1 = 1, max_id2 = 1, tmp;
    dfs(1, 0, max_id1, dep1);
    memset(dep1, 0, sizeof(dep1));
    max_len = 0;
    dfs(max_id1, 0, max_id2, dep1);
    max_len = 0;
    dfs(max_id2, 0, tmp, dep2);
    for(int i = 1; i <= n; i++){
        cout << max(abs(dep1[i] - dep1[max_id1]), abs(dep2[i] - dep2[max_id2])) << " ";
    }
}
