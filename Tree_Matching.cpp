#include <iostream>
#include <vector>
using namespace std;
int n, a, b, cnt = 0;
vector<int> v[200005];
bool dfs(int x, int pre){
    bool use = 0;
    for(auto i : v[x]){
        if(i == pre) continue;
        if(dfs(i, x)) use = 1;
    }
    if(use){
        cnt += 1;
        return 0;
    }
    return 1;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 1);
    cout << cnt << '\n';
}
