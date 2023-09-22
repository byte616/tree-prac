#include <iostream>
#include <vector>
using namespace std;
int n, m, a, b, arr[20][200005];
void build(){
    for(int i = 1; i <= 19; i++){
        for(int j = 1; j <= n; j++){
            arr[i][j] = arr[i - 1][arr[i - 1][j]];
        }
    }
}
int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for(int i = 2; i <= n; i++){
        cin >> arr[0][i];
    }
    build();
    while(m--){
        cin >> a >> b;
        for(int i = 0; i <= 19; i++){
            if(b & (1 << i)){
                a = arr[i][a];
            }
        }
        cout << (a == 0 ? -1 : a) << '\n';
    }
}
