#include <iostream>
#include <vector>
using namespace std;
int n, x, ans[200005];
vector<int> v[200005];
void dfs(int x){
    ans[x] = 1;
    for(auto i : v[x]){
        dfs(i);
        ans[x] += ans[i];
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 2; i <= n; i++){
        cin >> x;
        v[x].push_back(i);
    }
    dfs(1);
    for(int i = 1; i <= n; i++){
        cout << ans[i] - 1 << " ";
    }
}
