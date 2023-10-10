#include <iostream>
#include <vector>
using namespace std;
vector<int> v[200005];
int n, a, b, sub[200005], par[200005];
void dfs(int x, int pre){
    sub[x] = 1;
    par[x] = pre;
    for(auto i : v[x]){
        if(i == pre) continue;
        dfs(i, x);
        sub[x] += sub[i];
    }
}
int main(){
    cin >> n;
    for(int i = 1; i < n; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++){
        bool flag = 0;
        for(auto j : v[i]){
            if(j != par[i]){
                if(sub[j] > n / 2) flag = 1;
            }
            else{
                if(n - sub[i] > n / 2) flag = 1;
            }
        }
        if(!flag){
            cout << i << '\n';
            return 0;
        }
    }
}
