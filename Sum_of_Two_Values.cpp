// i think i can solve this question by two methods ->
// 1. greedy - sort the array and then keep iterating and adding if the solution comes 
// 2. two pointers 
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


void solve(int N, int x, const vector<int>& nums) {
        // IF THIS WAS A SORTED ARRAY WE DIDNT NEED TO TAKE CARE OF THE ORIGINAL INDICES 
    // BUT WE NEED TO RETURN THE ORIGINAL INDICES AS OUTPUT SO WE HAVE TO SORT IT WITH KEEPING THE ORIGINAL SYNTAX IN CONTEXT
    vector<pair<int,int>> arr;
    for (int i = 0; i < N; ++i) arr.push_back({nums[i], i});
    
    // Sort by value
    sort(arr.begin(), arr.end());

    int left = 0, right = N - 1;
    while (left < right) {
        long long sum = (long long)arr[left].first + arr[right].first;
        if (sum == x) {
            // print 1-based indices with a space and newline, then return original indices
            cout <<  (arr[right].second + 1) << ' ' << (arr[left].second + 1) << '\n';
            return;             // IMPORTANT: stop here
        } else if (sum < x) {
            left++;
        } else {
            right--;
        }
    }
    cout << "IMPOSSIBLE\n";   // only reaches here if no pair found
}

int main() {
    int N, X;
    cin >> N >> X;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    solve(N, X, A);

}