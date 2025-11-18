/*
few observations ->
- x should be the largest because it will not increase again, you have to choose these greedily
- sort the array
- tell if the destruction of array is possible within n operations (
“Determine if it is possible to destroy the array.”

Destroying the array = removing all 2n elements.
Since each step removes 2 elements, the total number of steps must be exactly n)

- use multiset -> keeps the elements sorted and O(logn) removal(vector removal is O(n))
*/

#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

// C++ Standard Library Headers
#include <algorithm>
#include <deque>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

// C++11 Headers
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

// Useful typedefs for competitive programming
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

// Commonly used defines
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define REPR(i, a, b) for (int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define present(c, x) ((c).find(x) != (c).end())

// Constants
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

void solve()
{
    int n;
    if (!(cin >> n))
        return;
    int m = 2 * n;
    vector<long long> a(m);
    for (int i = 0; i < m; ++i)
        cin >> a[i];

    sort(all(a));

    for (int i = 0; i < m - 1; ++i)
    {
        long long S = a[i] + a[m - 1];
        multiset<long long> ms(a.begin(), a.end());
        vector<pair<long long, long long>> res;
        long long current = S;
        bool ok = true;

        while (!ms.empty())
        {
            long long x = *prev(ms.end()); // largest remaining
            ms.erase(prev(ms.end()));
            long long y = current - x;
            auto it = ms.find(y);
            if (it == ms.end())
            {
                ok = false;
                break;
            }
            ms.erase(it);
            res.emplace_back(x, y);
            current = x;
        }

        if (ok && (int)res.size() == n)
        {
            cout << "YES\n";
            cout << S << "\n";
            for (auto &p : res)
            {
                long long x = p.first, y = p.second;
                if (x > y)
                    swap(x, y); // print smaller first for consistency with expected
                cout << x << ' ' << y << "\n";
            }
            return;
        }
    }

    cout << "NO\n";
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false); // -> makes almost 2x-5x faster
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T = 1;
    if (!(cin >> T))
        return 0;
    while (T--)
        solve();
    return 0;
}
/*
solution from editorial(random yt person sol)->
    #include <bits/stdc++.h>
    using namespace std;
    #define mod 998244353
    #define inf 1e16
    #define pb push_back
    #define ins insert
    #define vc vector
    #define umap unordered_map
    #define uset unordered_set
    #define int long long int
    #define pi pair<int, int>
    #define ld long double
    #define ff first
    #define ss second
    #define all(x) x.begin(), x.end()
    #define fr(i, a, n) for (int i = a; i < n; i++)
    #define frr(i, a, n) for (int i = n - 1; i >= a; i--)
    #define file_in freopen("a.txt", "r", stdin);
    const int mxn=2e6+7;
    int arr[mxn];
    multiset<int> st;
    vc<pi> ans;
    int n;

    bool solve(multiset<int> &cpy, int mx) {
        while(!cpy.empty()) {
            int sum = mx;
            //take the maximum element
            multiset<int>::reverse_iterator itr = cpy.rbegin();
            mx = *itr;
            cpy.erase(cpy.find(mx));
            if(cpy.find(sum - mx) == cpy.end()) {
                break;
            } else {
                cpy.erase(cpy.find(sum-mx));
                ans.pb({mx,sum-mx});
            }
        }
        if(ans.size() == n/2) {
            cout<<"YES\n";
            cout<<ans.front().first + ans.front().second<<"\n";
            for(auto el : ans )
                cout<<el.first<<" "<<el.second<<"\n";
            return true;
        }
        return false;
    }

    void tc() {
        cin>>n;
        n*=2;
        st.clear();
        fr(i,1,n+1) {
            cin>>arr[i];
            st.ins(arr[i]);
        }
        sort(arr+1,arr+1+n);
        ans.clear();
        for(int i=1; i<n; i++) {
            ans.pb({arr[i],arr[n]});
            multiset<int> cpy(st);
            cpy.erase(cpy.find(arr[n]));
            cpy.erase(cpy.find(arr[i]));
            if(solve(cpy,arr[n]))
                return;
            ans.clear();
        }
        cout<<"NO\n";
    }
    int32_t main() {
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int t; t=1;
        cin>>t;
        while(t--)  tc();
    }
*/