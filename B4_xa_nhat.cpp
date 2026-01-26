#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn = 1e6+7;
vector <ll> a(maxn),b(maxn);
ll find(ll l,ll r,ll t){
    ll s=0, mid;
    while(l<=r){
        mid=(l+r)/2;
        if(b[mid]<=t){
            s=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return s;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n,p;

    cin >> n >> p;
    ll ans=0;
    for(ll i=1 ; i<=n ; i++){
        cin >> a[i];
        if(i==1) b[1]=a[1];
        else{
            b[i]=min(b[i-1],a[i]);
        }
    }
    for(ll i=1 ; i<=n ; i++){
        if(a[i]-p>0){
            ll k=find(1,i,a[i]-p);
            if(k!=0) ans=max(ans,i-k);
        }
    }
    cout << ans << "\n";
}
