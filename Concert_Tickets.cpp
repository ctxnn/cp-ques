/* 

INITIAL THINKING -> 

h[] - n length 
t[] - m length 

for t if in h there is something h[i]<= t[i] that is the answer and pop h[i] then 
but the problem is it will be O(nXm) and the output size is very big so it wont work 

OPTIMIZED SOLUTION -> 

use multiset and then upper bound then move the iterator one less 


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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;

// Commonly used defines
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define REPR(i,a,b) for (int i = a; i >= b; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define present(c,x) ((c).find(x) != (c).end())

// Constants
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};


void solve(int n, int m, multiset<int>& tickets, const vector<int>& offers) {
    for(int offer: offers){
        auto it = tickets.upper_bound(offer); // first ticket > offer
        if(it == tickets.begin()){
            cout << -1 << "\n";
        }
        else{
            --it; 
            cout << *it << "\n";
            tickets.erase(it);
        }
    }
}

int main() {

    int n, m;
    cin >> n >> m;

    multiset<int> tickets;
    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        tickets.insert(price);
    }

    vector<int> offers(m);
    for (int i = 0; i < m; i++) {
        cin >> offers[i];
    }

    solve(n, m, tickets, offers);
    return 0;
}