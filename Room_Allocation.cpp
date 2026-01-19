
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

using namespace std; 
#define nl '\n'
#define sp ' '
#define ll long long

/*
logic of the code - 
- if the arrival time is greater than any departure time then we will assign the old room other wise new room
- we will use greedy sorting approach 
- we want the minimum no of rooms
*/

#define triplet tuple<int, int, int> // {a, b, c}
#define pii pair<int, int> // {a, b}
#define vi vector<int>
#define len(x) int(x.size()) // integer size of array

void solve(){
    int n; 
    cin >> n;
    vector<triplet> intervals;
    for (int i = 0; i < n; i++) {
        int st, et;
        cin >> st >> et;
        intervals.push_back({st, et, i}); // st -> arrival day, et -> departure time, i -> customer index(0,1,....)
    }
    sort(intervals.begin(), intervals.end()); // sorting the vector based on arrival time - earliest arrival will get the room first
    auto [st, et, idx] = intervals[0];
    vi assigned_room_no(n);
    multiset<pii> et_rid;
    assigned_room_no[idx] = 1;//assign a room no. 1 to earliest arriving customer
    et_rid.emplace(et, 1);//insert({et,1})

    for (int i = 1; i < n; i++) {
        auto [st, et, idx] = intervals[i];

        //> find the smallest end_time among allocated rooms
        auto [smallest_et, rid] = *begin(et_rid);//gives us the smallest end time - * deferences the iterator because begin only returns a iterator 
        if (smallest_et < st) {
            et_rid.erase(et_rid.begin());
            assigned_room_no[idx] = rid;
            et_rid.emplace(et, rid);

        } else {
            // all end_times are greater than equal to current_start
            // allocate new room
            assigned_room_no[idx] = len(et_rid) + 1;
            et_rid.emplace(et, assigned_room_no[idx]);
        }
    }
    cout << *max_element(assigned_room_no.begin(), assigned_room_no.end()) << nl;
    for (auto room : assigned_room_no)
        cout << room << sp;
}  //* T:O(n*logn), S:O(n)

int main() {
    int t = 1;
    // cin>>t;

    while (t--)
        solve();
}



/* GFG SOLUTION
// Function to find the minimum number of rooms and the
// rooms allocated to each customer
function solve(timings) {
    
    // Sort the timings array based on arrival times
    timings.sort((a, b) => a[0] - b[0]);

    // Min heap to store {departure, room number} to fetch
    // the room which gets vacant the earliest
    let occupiedRooms = new MinHeap();

    // Variable to store the total number of rooms needed
    let roomCnt = 0;

    // Array to store the room allocated to each customer
    let ans = [];

    for (let i = 0; i < timings.length; i++) {
        let arrivalTime = timings[i][0];
        let departureTime = timings[i][1];

        // Check if there are no rooms available or all the
        // rooms are occupied
        if (occupiedRooms.isEmpty() || occupiedRooms.top().departure >= arrivalTime) {
            // If there are no rooms or all the rooms are
            // occupied, then increment the total number of
            // rooms needed and allocate the room to the
            // current customer
            roomCnt++;
            occupiedRooms.push({ departure: departureTime, room: roomCnt });
            ans.push(roomCnt);
        } else {
            // If there is a vacant room, then assign that
            // vacant room to the current customer
            let vacantRoom = occupiedRooms.pop().room;
            occupiedRooms.push({ departure: departureTime, room: vacantRoom });
            ans.push(vacantRoom);
        }
    }

    // Print the total rooms needed along with the room
    // allocated to each customer
    console.log(roomCnt);
    console.log(ans.join(" "));
}

// Priority queue implementation for the min heap
class MinHeap {
    constructor() {
        this.heap = [];
    }

    push(value) {
        this.heap.push(value);
        this.heapifyUp();
    }

    pop() {
        if (this.isEmpty()) return null;
        this.swap(0, this.heap.length - 1);
        const poppedValue = this.heap.pop();
        this.heapifyDown();
        return poppedValue;
    }

    top() {
        return this.heap[0];
    }

    isEmpty() {
        return this.heap.length === 0;
    }

    heapifyUp() {
        let currentIdx = this.heap.length - 1;
        let parentIdx = Math.floor((currentIdx - 1) / 2);
        while (currentIdx > 0 && this.heap[currentIdx].departure < this.heap[parentIdx].departure) {
            this.swap(currentIdx, parentIdx);
            currentIdx = parentIdx;
            parentIdx = Math.floor((currentIdx - 1) / 2);
        }
    }

    heapifyDown() {
        let currentIdx = 0;
        let leftChildIdx = 2 * currentIdx + 1;
        while (leftChildIdx < this.heap.length) {
            let rightChildIdx = 2 * currentIdx + 2 < this.heap.length ? 2 * currentIdx + 2 : -1;
            let idxToSwap;
            if (rightChildIdx !== -1 && this.heap[rightChildIdx].departure < this.heap[leftChildIdx].departure) {
                idxToSwap = rightChildIdx;
            } else {
                idxToSwap = leftChildIdx;
            }
            if (this.heap[idxToSwap].departure < this.heap[currentIdx].departure) {
                this.swap(currentIdx, idxToSwap);
                currentIdx = idxToSwap;
                leftChildIdx = 2 * currentIdx + 1;
            } else {
                break;
            }
        }
    }

    swap(i, j) {
        [this.heap[i], this.heap[j]] = [this.heap[j], this.heap[i]];
    }
}

let timings = [
    [1, 2],
    [2, 4],
    [4, 4]
];

solve(timings);
*/