#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<int> v[200005];
ll n, q, a, b, op, s, x, arr[200005], tree[200005];
int in[200005], out[200005], idx;
ll sum(int k){
    ll ret = 0;
    while(k >= 1){
        ret += tree[k];
        k -= k & -k;
    }
    return ret;
}
void update(int k, ll x){
    while(k <= n){
        tree[k] += x;
        k += k & -k;
    }
}
void dfs(int x, int pre){
    in[x] = ++idx;
    for(auto i : v[x]){
        if(i == pre) continue;
        dfs(i, x);
    }
    out[x] = idx;
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q;
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
        update(in[i], arr[i]);
    }
    while(q--){
        cin >> op >> s;
        if(op & 1){
            cin >> x;
            ll dif = x - arr[s];
            update(in[s], dif);
            arr[s] = x;
        }
        else{
            cout << sum(out[s]) - sum(in[s] - 1) << '\n';
        }
    }
}
