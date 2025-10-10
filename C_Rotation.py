"""

THIS ANSWER GIVES TLE 

If you have 100,000 queries each rotating by 100,000 positions, you'd do 10 billion operations! 

import sys
input = sys.stdin.readline  # fast input

# 1. Read N and Q
N, Q = map(int, input().split())

# 2. Read string S
S = input().strip()  # remove newline

# 3. Read all Q queries
queries = [list(map(int, input().split())) for _ in range(Q)]


for query in queries:
    t, x = query
    if t == 1:
        # move last to front x times
        for _ in range(x):
            S = S[-1] + S[:-1]
    else:
        # output x-th character (1-based)
        print(S[x - 1])
"""


# MORE FAST VERSION : 

import sys
input = sys.stdin.readline

# 1. Read input
N, Q = map(int, input().split())
S = input().strip()

# 2. Track how much the string is rotated
offset = 0  # number of right rotations

for _ in range(Q):
    t, x = map(int, input().split())
    if t == 1:
        # type-1: rotate right by x
        offset = (offset + x) % N
    else:
        # type-2: output x-th character
        # adjust for offset
        idx = (x - 1 - offset) % N
        print(S[idx])


"""
when to USE THIS ROTATION LOGIC: 
    1.	You have a sequence/array/string.
	2.	Operations involve cyclic rotations (left/right, last-to-front, etc.).
	3.	Queries ask for positions/elements after multiple rotations.
	4.	Constraints are large, so moving the elements physically is too slow.
"""