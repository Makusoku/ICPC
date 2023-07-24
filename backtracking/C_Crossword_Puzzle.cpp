#include <bits/stdc++.h>
using namespace std;
#define ll long long
char arr[10][10];

void solve(){
    for(ll i = 0; i < 10; i++){
        for(ll j = 0; j < 10; j++)
            cin >> arr[i][j];
    }
    string name;
    getline(cin, name, ';');

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    ll t;

    solve();
    return 0;
}