#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int N, long long W, vector<pair<int, int>> &cheese)
{
    // Step 1: Sort cheeses by tastiness (A[i]) in DESCENDING order
    // We want the tastiest cheese first!
    sort(cheese.begin(), cheese.end(), greater<pair<int, int>>());

    long long total_tastiness = 0;
    long long weight_so_far = 0;

    // Step 2: Go through each cheese from tastiest to least tasty
    for (int i = 0; i < N; i++)
    {
        int tastiness_per_gram = cheese[i].first; // A[i]
        int available_weight = cheese[i].second;  // B[i]

        // Step 3: Decide how much of this cheese to use
        long long weight_used;

        if (weight_so_far + available_weight <= W)
        {
            // We have space for ALL of this cheese
            weight_used = available_weight;
        }
        else
        {
            // We can only fit SOME - use remaining space
            weight_used = W - weight_so_far;
        }

        // Step 4: Add to total tastiness
        total_tastiness += (long long)weight_used * tastiness_per_gram;
        weight_so_far += weight_used;

        // Step 5: If pizza is full, stop
        if (weight_so_far >= W)
            break;
    }

    cout << total_tastiness << endl;
}

int main()
{
    int N;
    long long W;
    cin >> N >> W;

    // Store cheese as pairs: (tastiness, weight) = (A[i], B[i])
    vector<pair<int, int>> cheese(N);

    for (int i = 0; i < N; i++)
    {
        cin >> cheese[i].first >> cheese[i].second; // A[i], B[i]
    }

    solve(N, W, cheese);

    return 0;
}

// Compare with 0/1 Knapsack: -> DP 

// In 0/1 Knapsack: You must take the WHOLE item or nothing
// Sometimes you skip a high-value item because it's too heavy
// This requires DP (no greedy solution)

// Fractional Knapsack: -> it is a fractional knapsack problem -> GREEDY 

// You can take ANY amount of an item
// There's NEVER a reason to skip high-value cheese!
// If the best cheese doesn't fit completely, just take a partial amount
// Greedy always works!