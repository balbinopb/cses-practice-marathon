#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(false); cin.tie(nullptr)
#define ceil(n, m) (((n) + (m) - 1) / (m))
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define EPS 1e-9
#define pb push_back
#define pf push_front
#define vi vector<int>
#define vl vector<long long>
#define vvi vector<vector<int>>
#define DIGITS(x) ((int)to_string(x).size())





int main() {
    fast_io;

    ll n; cin>>n;


    // 8 : 1 2 3 4 5 6 7 8 9
    // 3 5 7 8
    // 1 2 4 6 9

    ll total =n*(n+1)/2;

    if(total %2!=0){
        cout<<"NO\n";
        return 0;
    }

    vi set1,set2;

    ll target = total / 2;

    if (n % 4 == 0) {
        for (int i = 1; i <= n; i += 4) {
            set1.push_back(i);
            set1.push_back(i + 3);
            set2.push_back(i + 1);
            set2.push_back(i + 2);
        }
    } else { // n % 4 == 3
        set1.push_back(1);
        set1.push_back(2);
        set2.push_back(3);
        for (int i = 4; i <= n; i += 4) {
            set1.push_back(i);
            set1.push_back(i + 3);
            set2.push_back(i + 1);
            set2.push_back(i + 2);
        }
    }

    cout << set1.size() << "\n";
    for(int elm: set1){
        cout<<elm<<" ";
    }
    cout<<endl;
    cout << set2.size() << "\n";
    for(int elm: set2){
        cout<<elm<<" ";
    }
    cout<<endl;


    
    

    
    return 0;
}
