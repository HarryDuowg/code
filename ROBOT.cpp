#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n, q; cin >> n >> q;
    vector <ll> a(n+1, 0), pre(n+1, 0);
    for(ll i=1 ; i<=n ; i++){
        cin >> a[i];
        pre[i]=pre[i-1]+a[i];
    }
    while(q--){
        ll l, s; cin >> l >> s;
        auto it = upper_bound(pre.begin()+l, pre.end(), s+pre[l-1]);
        if(it!=pre.begin()){
            it--;
            ll ans=it-pre.begin()-l+1;
            //cout  << l << " " << it-pre.begin()+l << "\n";
            if(ans<=0) cout << "0\n";
            else cout << ans << "\n";
        }
    }
}
