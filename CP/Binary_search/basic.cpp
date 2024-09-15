#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int arr[1000000];
int n;
bool check(int x){
    // write acc to question
}
void solve() {
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    int lo=0,hi=n-1, ans =0 ;// change acc to question
    while(lo<=hi){
        int mid =(lo+hi)/2;
        if(check(mid)){
            ans=mid;
            hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }
    cout<<ans<<endl;
    
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}