#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    string s; cin >> s;
    ll ans=0, t=0;
    for(ll i=1 ; i<s.size(); i++){
        if(s[i]<='9' && s[i]>='0'){
            t=t*10+(s[i]-'0');
        }
        else{
            ans+=t;
            t=0;
        }
    }
    cout << ans << "\n";

}
