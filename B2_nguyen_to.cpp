#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 1e7+7;
//const inf = 1e18;
ll n,m;
vector <bool> nt(maxn+1,true);
bool kt (ll n){
    ll s=0;
    while(n>0){
        s=s*10+(n%10);
        n/=10;
    }
    return (nt[s]==0);
}

void sang(){
    nt[0]=nt[1]=false;
    for(ll i=2 ; i*i<=maxn ; i++){
        if(nt[i]){
            for(ll j=i*i ; j<=maxn ; j+=i) nt[j]=false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    sang();
    cin >> n >> m;
    vector<ll> b(n+1);
    for(ll i=1 ; i<=n ; i++){
        ll x; cin >> x;
        b[i]=b[i-1];
        if(x>0 && nt[x]==0 && kt(x)) b[i]++;
    }
    /*
    for(ll i=1 ; i<=n ; i++) cout << b[i] << " ";
    cout << "\n";
    */
    while(m--){
        ll l,r; cin >> l >> r;
        cout << b[r]-b[l-1] << "\n";
    }

}
