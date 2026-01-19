// changed the input output method using ai for usaco input
#include <iostream>
#include <string>
using namespace std;

int main() {
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int n;
    cin >> n;

    string A, B;
    cin >> A >> B;

    int flips = 0;

    for (int i = 0; i < n; i++) {
        if (A[i] != B[i] && (i == 0 || A[i-1] == B[i-1])) {
            flips++;
        }
    }

    cout << flips << endl;
    return 0;
}