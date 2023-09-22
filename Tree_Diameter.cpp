#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n, a, b, len[200005];
vector<int> v[200005];
void dfs(int x, int pre, int &max_len, int &max_id){
    if(len[x] > max_len){
        max_len = len[x];
        max_id = x;
    }
    for(auto i : v[x]){
        if(i == pre) continue;
        len[i] = len[x] + 1;
        dfs(i, x, max_len, max_id);
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
    int max_len = 0, max_id = 0;
    dfs(1, 0, max_len, max_id);
    memset(len, 0, sizeof(len));
    max_len = 0;
    dfs(max_id, 0, max_len, max_id);
    cout << max_len << '\n';
}
