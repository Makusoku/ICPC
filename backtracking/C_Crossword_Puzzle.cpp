#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll arr[9][9];
ll row, col;

bool ver_num(ll row, ll col, ll num){
    for(ll i = 0; i < 9; i++){
        if(arr[row][i] == num)
            return false;
    }
    for(ll i = 0; i < 9; i++){
        if(arr[i][col] == num)
            return false;
    }
    ll start_col = 3 * (col / 3);
    ll start_row = 3 * (row / 3);
    for(ll i = 0; i < 3; i++){
        for(ll j = 0; j < 3; j++){
            if(arr[start_row + i][start_col + j] == num)
                return false;
        }
    }
    return true;
}


bool backtracking(ll row, ll col){
    if(row == 8 and col == 9){
        return true;
    }

    if(col == 9){
        col = 0;
        row++;
    }

    if(arr[row][col] > 0){
        return backtracking(row, col + 1);
    }

    for(ll i = 1; i <= 9; i++){
        if(ver_num(row, col, i)){
            arr[row][col] = i;
            if(backtracking(row, col + 1)){
                return true;
            }
        }
        arr[row][col] = 0;
    }
    return false;
}

void solve(){
    
    for(ll i = 0; i < 9; i++){
        for(ll j = 0; j < 9; j++)
            cin >> arr[i][j];
    }    

    if(backtracking(0, 0)){
        for(ll i = 0; i < 9; i++){
            for(ll j = 0; j < 9; j++)
                cout << arr[i][j] << " ";
            cout << endl;
        }
    }
    else{
        cout << "No solution" << endl;
    }
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    ll t;
    cin >> t;
    while(t--)
    solve();
    return 0;
}