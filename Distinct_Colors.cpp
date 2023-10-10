#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n, a, b, arr[200005], idx;
int in[200005], out[200005], tree[200005], ans[200005], Index[200005];
pair<int,int> q[200005];
vector<int> v[200005];
map<int,int> mp; // color : last idx 
void dfs(int x, int pre){
    in[x] = ++idx;
    Index[idx] = x;
    for(auto i : v[x]){
        if(i == pre) continue;
        dfs(i, x);
    }
    out[x] = idx;
}
int sum(int k){
    int res = 0;
    while(k >= 1){
        res += tree[k];
        k -= k & -k;
    }
    return res;
}
void update(int k, int x){
    while(k <= n){
        tree[k] += x;
        k += k & -k;
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }   
   for(int i = 1; i < n; i++){
       cin >> a >> b;
       v[a].push_back(b);
       v[b].push_back(a);
   }
   dfs(1, 0);
   for(int i = 1; i <= n; i++){
       q[in[i]] = {out[i], i};
   }
   for(int i = n; i >= 1; i--){
        int color = arr[Index[i]];
        if(mp[color]) update(mp[color], -1);
        update(i, 1);
        mp[color] = i;
        pair<int,int> j = q[i];
        ans[j.second] = sum(j.first);
   }
   for(int i = 1; i <= n; i++){
       cout << ans[i] << " ";
   }
}
