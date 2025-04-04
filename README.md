# CP-Question-Record

### 【AtCoder】 Beginner Contest 397 - F. Variety Split Hard

**Solved**

。Segment Tree + Sliding Window – O($NlogN$)

* Core Concepts
    * Approach
        * Sliding Window to Maintain Prefix and Suffix Distinct Counts
            * Precompute `pre[i]` as the number of distinct integers in the subarray $[1, i]$
            * Precompute `suf[i]` as the number of distinct integers in the subarray $[i, N]$
            * These arrays capture the contribution of the first and third segments respectively
        * Next Occurrence Array
            * Construct an array `nxt[i]` which stores the index of the next occurrence of A[i] (or -1 if none exists)
            * This helps determine where a number's extra contribution might switch between segments
    * Middle Segment Contribution
        * For a fixed first split position `i`, the middle segment $[i+1, j]$ can gain an extra contribution from numbers appearing more than once
        * The extra contribution is optimized by choosing an ideal second split position based on the positions of repeated elements
    * Segment Tree Application
        * The segment tree is used to maintain the extra contribution available for the middle segment
        * It supports adding or subtracting contributions over intervals and range maximum queries
        * Initially, for each index i with a valid next occurrence, the tree is updated over the interval $[i, nxt[i]-1]$ by +1
        * As the first segment increasing i, the tree is updated to remove the influence of numbers that have already been included in the first segment
        * A query on the segment tree then yields the maximum extra contribution for the middle segment
* Detailed Strategy
    1. Preprocessing
        * Use a boolean array to compute the prefix array `pre` by marking which numbers have already been seen
        * Process the array in reverse to build the suffix array `suf` and determine `nxt[i]` for each index
    2. Segment Tree Setup
        * Build a segment tree supporting range updates and maximum queries
        * For every index i with `nxt[i] ≠ -1`, update the tree in the interval $[i, nxt[i]-1]$ with +1, representing the potential extra contribution if that number appears in the middle segment
    3. Iterative Evaluation
        * Iterate over potential first split positions `i`, $\forall i \in [1, n]$
        * For each `i`, when `nxt[i]` exists, decrement the segment tree over the range $[i, nxt[i]-1]$ to remove the contribution from the number that now belongs to the first segment
        * Query the segment tree over the interval $[i+1, n]$ to find the best possible extra contribution for the middle segment
        * Update the final answer as </br>
            `res = max(res, pre[i] + suf[i+1] + maximum extra contribution)`
* Additional Notes
    * The crucial insight is that each integer contributes at least once to the count in any segment it appears in, and may provide additional benefit if it spans across the split boundaries
    * Using a segment tree is essential for efficiently managing interval updates and queries, making it feasible to solve the problem within the given constraints

### 【AtCoder】 Beginner Contest 395 - E. Flip Edge

**Solved**

。Dijkstra - O($(N+M)logN$)

* Core Idea
    * The problem can be solved using Dijkstra that considers two states for each node
        1. Normal Graph `A` ⮕ Move along the edges as given
        2. Flipped Graph `B` ⮕ Move along the reversed edges
* Algorithm Strategy
    * Dijkstra
        * At each step, extract the node with the lowest cost
        * If we reach node `N`, output the cost
        * If visiting from mode `A`
            * Move to all connected nodes in mode `A` with cost `+1`
            * Switch to mode `B` at the same node with cost `+X`
        * If visiting from mode `B`
            * Move to all connected nodes in mode `B` with cost `+1`
            * Switch to mode `A` at the same node with cost `+X`
    * Avoid Reprocessing
        * Use a map to store the best cost for `(node, graph)`
        * Skip nodes if a cheaper path has already been found

### 【AtCoder】 Beginner Contest 395 - D. Pigeon Swap

**Solved**

。Data Structures + Simulation - O($N$)

* Approach & Data Structures
    * To efficiently track and process these operations, we use three arrays
        * `pigeon[i]` ⮕ This stores the **current nest** where pigeon `i` is located
        * `nest[i]` ⮕ This keeps track of which pigeon is currently in **nest `i`**
        * `id[i]` ⮕ This maps a **nest** back to the **original pigeon** assigned to it at the start
    * Initialization
        * Initially, each pigeon `i` is placed in nest `i`. Hence, the arrays are initialized as follows </br>
            ```cpp
            for( int i = 1 ; i <= n ; ++i ) pigeon[i] = nest[i] = id[i] = i;
            ```
        * Handling Operations
            1. Move Operation
                * When we move pigeon `a` to nest `b`, it means pigeon `a` is now in the same place as pigeon `nest[b]`
                    ```cpp
                    pigeon[a] = nest[b];
                    ```
                * This ensures that `pigeon[a]` correctly reflects that pigeon `a` has moved to nest `b`
            2. Swap Operation
                * Swap the contents of nest `a` and nest `b` </br>
                    ```cpp
                    swap(nest[a], nest[b]);
                    ```
                * Since the nests have changed, we update their original assignments
                    ```cpp
                    id[nest[a]] = a;
                    id[nest[b]] = b;
                    ```
                * This maintains correct tracking of where each pigeon’s original nest now resides
            3. Query Operation
                * Given pigeon `a`, find where its original nest assignment is now located </br>
                    ```cpp
                    cout << id[pigeon[a]] << "\n";
                    ```
                * Here, `pigeon[a]` tells us the **current nest** where pigeon `a` is located, and `id[pigeon[a]]` retrieves the original nest assignment

### 【AtCoder】 Beginner Contest 398 - F. ABCBA

**Solved**

。Rolling Hash + Modular Arithmetic - O($N$)

* Core Concepts
    * Rolling Hash with Modular Arithmetic
        * Use a rolling hash function with a prime base `p = 48763` and modulus `M = 1e9 + 7` to efficiently compute and compare substrings
        * The modular arithmetic ensures we avoid overflow and efficiently calculate hash values </br>
            $Hash(S) = ( ( Hash(S_{cnt-1}) \times p ) \mod M + S_{cnt} ) \mod M$
        * Using the same principle in reverse order allows us to compute the hash from both directions
    * Prefix and Suffix Hash Comparison 
      * Since we want the shortest palindrome with `S` as a prefix, we check for the longest suffix of `S` that is also a prefix of its palindrome extension
      * This is efficiently achieved by comparing the rolling hash values of the forward and reversed substrings
* Solution Strategy
    1. Precompute Hash Values
       * Compute prefix hash and suffix hash
       * Precompute powers of `p` to enable fast range hash calculations
    2. Check Possible Palindrome Extensions
       * Iterate from the middle of the string towards the end
       * Compare prefix and suffix hash values using modular arithmetic
* Implementation Details
    * Modulo Inversion Handling 
        * Since direct division is not possible under modular arithmetic, I use </br>
            $H_{l,r} = (H_r - H_{l-1} \times p^{(r-l+1)} \mod M + M) \mod M$
        * This ensures correct hash extraction even under modulo constraints

### 【AtCoder】 Beginner Contest 398 - A. B. C.

**Solved**

### 【CSES】 1194. Monsters

**Solved**

。Multi-Source BFS + Path Reconstruction - O($NM$)

* Complexity Analysis
    * BFS for Monsters in O(N $\times$ M) ⮕ because each cell is processed only once
    * BFS for Player in O(N $\times$ M) ⮕ similar reasoning as above
    * Overall Complexity is O(N $\times$ M)
* Core Concept
    * Optimal Monster Movement
        * Since monsters always move optimally, if a monster can reach a cell before or at the same time as player, then that cell is unsafe for player
        * Therefore, player may only move to a cell if the distance from player to that cell is strictly less than the distance from the nearest monster
    * BFS for Reachability
        * By performing a multi-source BFS starting from all monster positions, we precompute the minimum time each monster takes to reach every cell
        * Then, a second BFS from the player’s starting position ensures that only cells where **player's shortest distance to current cell strictly less than any monster's shortest distance to current cell** are visited
    * Path Reconstruction
        * During the BFS for player, store the previous cell for every visited cell
        * Once player reaches an arrive at boundary cell, retrace the steps using these stored values to reconstruct the path in reverse order, then output the path with the corresponding move directions `U`, `D`, `L`, `R`
* Solution Strategy
    1. Precompute Monster Distances
        * Initialize a multi-source BFS using all monster locations
        * For each cell, record `mdis[i][j]`, the minimum time required for any monster to reach that cell
    2. Player BFS with Safety Check
        * Start a BFS from player with an array `dis[i][j]` for the player
        * At every step, only proceed to a neighboring cell if
            * It is within bounds and not a wall
            * The distance for player to that cell, `dis[current]` + 1, is strictly less than `mdis[i][j]`
    3. Path Reconstruction
        * As you perform the BFS for player, store the previous cell for each visited cell
        * Once player reaches the maze boundary, use this stored data to reconstruct the escape path
* Implementation Notes
    * The key observation is that, for player to safely move into any cell, the distance from player must be less than the distance from the nearest monster
    * Storing the previous cell during the BFS allows for an efficient retrace of the path once an exit is found, otherwise you will get TLE instead
    * This approach guarantees that player only visits cells that remain safe even if the monsters know player's path in advance

### style: Adjust README.md Format

* Feature
    * Delete Date

### style: Adjust README.md Format

### 【AtCoder】 Beginner Contest 397 - D. Cubes

**Adjust Answer**

* Feature
    * In the previous program, I utilized binary search within the range of $logd$. However, I should have performed the search within the range of $log\sqrt{N}$
    * This adjustment is necessary because I can only guarantee that when y > $\sqrt{N}$, the expression $x^{3} - y^3 = (x - y)(x^2 + xy + y^2)$ will be greater than N
* Remark
    * When we change the range of the binary search from $[1, d]$ to $[1, \sqrt{N}]$, we find that $10^6 \times 10^9 \times 10^9 = 10^{24}$ appears in the valid function, leading to overflow issues. Therefore, I have adjusted the valid function as follows

        ```cpp
        bool valid( int d, int y ){
            return 3 * y * y + 3 * d * y + d * d > n / d;
        }
        ```
    
        The actions I took involved dividing the entire valid value by d to prevent overflow issues

### style: Adjust README.md Format

### 【AtCoder】 Beginner Contest 397 - D. Cubes

**Solved**

> [!NOTE]
> This question has undergone some new adjustments as of March 22

。Mathematics + Binary Search - O($\sqrt[3]{N}log\sqrt{N}$)

* Complexity Analysis
    * Iterating over $d$ takes at most ⮕ O($\sqrt[3]{N}$)
    * Binary search over $y$ runs in ⮕ O($log\sqrt{N}$)
    * Overall complexity ⮕ O($\sqrt[3]{N}log\sqrt{N}$)
* Mathematical Derivation
    1. We start by factorizing the given equation using the identity for the difference of cubes $x^{3} - y^3 = (x - y)(x^2 + xy + y^2)$
    2. Define $d = x - y$, so that  $N = d(x^2 + xy + y^2)$
    3. Rewriting in terms of $d$ and $y$ </br>
        $N = d[(y+d)^2 + y(y+d) + y^2]$ </br>
        &nbsp; &nbsp; $\Longrightarrow d[y^2 + 2dy + d^2 + y^2 + dy + y^2]$ </br>
        &nbsp; &nbsp; $\Longrightarrow dy^2 + 2d^2y + d^3 + dy^2 + d^2y + dy^2$ </br>
        &nbsp; &nbsp; $\Longrightarrow 3dy^2 + 3d^2y + d^3$
* Solution Strategy
    1. Determine the range for $d = x - y$
        * At $( x - y )( x^2 + xy + y^2 ) \geq (x - y)^3$, it follows that $(x - y)^3 \leq N$, that is $d \leq \sqrt[3]{N}$, which allowing us to conclude that the enumeration of $d$ is O($\sqrt[3]{N}$)
    2. Find valid integer values of $y$ given $d$
        1. The judgment can be completed using the quadratic formula, and the time complexity is O(1); however, its implementation is more complicated to implement
        2. Considering that the coefficients of both the quadratic and linear terms are positive, the formula is monotonically increasing when $x > 0$. Therefore, we can apply binary search. Obviously, we only need to perform binary search within the interval $[1, \sqrt{N}]$, resulting in a time complexity of O($log\sqrt{N}$), which is relatively straightforward to implement
3. Binary Search Optimization
   * Instead of explicitly solving the quadratic equation, we can use **binary search** on $y$, since the function is monotonic for positive $y$
   * Given that $y$ is at most O($\sqrt{N}$), binary search runs in O($\sqrt[3]{N}log\sqrt{N}$)
4. Checking for Integer Solutions
   * If a valid $y$ is found for any $d = x - y$, output $x$ and $y$
   * If no such pair exists, return $-1$

### 【AtCoder】 Beginner Contest 397 - C. Variety Split Easy

**Solved**

。Sliding Window

### 【AtCoder】 Beginner Contest 397 - B. Ticket Gate Log

**Solved**

。Basic Operations

### 【AtCoder】 Beginner Contest 397 - A. Thermometer

**Solved**

。Basic Operations

### 【AtCoder】 Beginner Contest 396 - E. Min of Restricted Sum

**Solved**

。DFS + Bitwise Operation - O((N + M)logA)

* Complexity Analysis
    * The DFS/BFS traversal works in O(N + M) time per connected component
    * The bitwise optimization iterates over 32 bits, adding an extra factor of 32, leading to an effective time complexity of O((N + M) x 32) ≈ O(N + M)
    * Overall, the solution runs in O((N + M)logA) time
* Core Concepts
    * Graph Representation ⮕ Treat each index as a node in an undirected graph
    * DFS Traversal & Consistency Verification
        * DFS Assignment
            * Process each connected component independently
            * Start at an unvisited node ( assign it an arbitrary value, `0` ) and propagate values through DFS
            * For every edge from a current node to a neighboring node with weight `w`, assign `res[next] = res[current] ⊕ w`
        * Cycle Consistency Check 
            * When DFS reaches a node that has already been visited, the previously computed value must be consistent with the new value derived from the current DFS path. That is, if you encounter an edge from node `u` to node `v` with weight `w` and `v` is already visited, then it must hold that `res[v] = res[u] ^ w`. If this condition fails, it means the XOR relations along a cycle do not match.
            * Theoretical Justification 
                * Consider a cycle with nodes arranged as u<sub>1</sub>, u<sub>2</sub>, ......, u<sub>m</sub>. By the properties of XOR, we have 
                
                   A[u<sub>1</sub>] ^ A[u<sub>2</sub>] = (A[u<sub>2</sub>] ^ A[u<sub>3</sub>]) ^ (A[u<sub>3</sub>] ^ A[u<sub>4</sub>]) ^ ...... ^ (A[u<sub>m</sub>] ^ A[u<sub>1</sub>]) 
                   
                   This can be rearranged as
   
                   w(u<sub>1</sub>, u<sub>2</sub>) = w(u<sub>2</sub>, u<sub>3</sub>) ^ w(u<sub>3</sub>, u<sub>4</sub>) ^ ...... ^ w(u<sub>m</sub>, u<sub>1</sub>)

            * In other words, the XOR of the weights along the cycle must sum to zero ( or, equivalently, the XOR of a segment of edges must equal the XOR of the remaining edges). If not, the constraints are inherently contradictory, and the algorithm should output `-1`
    * Bitwise Optimization for Minimum Sum
        * For each connected component, count the number of `0`s and `1`s in every bit position across all nodes
        * Adjust the starting node’s value bit-by-bit
            * For bit position `j`, if the count of `1`s is greater than or equal to the count of `0`s, set the `j`th bit in the starting node’s value; otherwise, leave it as `0`
          This decision minimizes the overall sum when the XOR values are propagated through the connected component
        * After updating the starting value, a second DFS propagates the new values to ensure consistency throughout the component

### 【AtCoder】 Beginner Contest 396 - D. Minimum XOR Path

**Solved**

。DFS + Bitwise Operation

### 【AtCoder】 Beginner Contest 396 - C. Buy Balls

**Solved**

。Basic Operations

### 【AtCoder】 Beginner Contest 396 - B. Card Pile

**Solved**

。Basic Operations + Data Structure

### 【AtCoder】 Beginner Contest 396 - A. Triple Four

**Solved**

。Basic Operations + Sliding Window

### 【CSES】 2181. Counting Tilings

**Solved**

。Bitmask DP - Plug DP、Contour Line DP - O(M ${\times}$ N ${\times}$ 2<sup>N</sup>)

* Core Concepts
    * Approach
        * State Representation
            * `dp[col][row][mask]` ⮕ The number of ways to fill the first `col` columns, where the current column is partially filled up to row `row` with a given `mask`
            * `mask` is a bitmask of length `n`, each bit representing whether a row position is occupied or free
            * The state `dp[i][j][bit]` means
                * The first `i-2` rows are fully filled
                * The `i-1` row is partially filled up to `j-1`
                * `bit` encodes the occupied / free state for the next row’s transition
        * Base Cases
            * The base case starts with an empty grid `dp[0][0][(1 << n) - 2] = 1`, ensuring the transition is handled correctly by leaving the first cell empty
        * Transitions
            * For each column and each row, we iterate through possible bitmasks, which determine whether a cell is occupied
                * Transition from Previous Column
                    * If `j == 0 && i > 0`, we transition from `dp[i-1][n-1][bit ^ (1 << j)]`, ensuring the first cell in the new column is already occupied
                        * If `bit & 1 == TRUE`, we place a horizontal domino, inheriting from `dp[i-1][n-1][bit ^ 1]`
                        * If `bit & 1 == FALSE`, we inherit directly from `dp[i-1][n-1][bit ^ 1]` to maintain correctness
                * Placing Dominos
                    * If `mask & (1 << row) != 0`, this means the current cell is occupied, so we carry over `dp[col][row][mask] = dp[col][row-1][mask ^ (1 << row)]`
                    * If the cell is empty `mask & (1 << row) == 0`, we consider placing dominos
                        * Horizontal ⮕ We can extend the tiling by placing a `1 × 2` domino to cover the current cell and the next column
                        * Vertical ⮕ If the row above is free, we can place a `2 × 1` domino

### style: Adjust the Layout of README.md

### 【CSES】 1653. Elevator Rides

**Solved**

。Bitwise DP - O(N ${\times}$ 2<sup>N</sup>)

* Key Observations
    * Why Bitmask DP
        * The problem involves subsets, making it ideal for bitmaskin
    * Why Track `last[bit]`
        * This allows us to check if adding a person exceeds capacity or fits in the current ride
* Core Concepts
    * Approach
        * State Representation
            * `dp[bit]` ⮕ The minimum number of elevator rides required to transport the subset of people represented by `bit`
            * `last[bit]` ⮕ The remaining weight capacity in the last elevator ride used for this subset
            * `bit` ⮕ A bitmask of length `n` (`0` to `(1 << n) - 1`) representing which people have been taken so far
        * Base Cases
            * `dp[0] = 1` since an empty subset requires at least one elevator ride
            * `last[0] = 0` since no weight is carried in an empty subset
        * Transition
            * For each subset `bit`
                * Iterate through all people `i`
                * If person `i` is included in `bit` (`bit & (1 << i) != 0`)
                    * Consider the subset without `i` (`prev = bit ^ (1 << i)`)
                    * Retrieve `dp[prev]` and `last[prev]`
                    * If adding `i` to the last ride exceeds `x`, start a new ride
                        1. `dp[bit] = dp[prev] + 1`
                        2. `last[bit] = min(last[prev], arr[i])`
                    * Otherwise, add `i` to the current ride  
                        1. `dp[bit] = dp[prev]`
                        2. `last[bit] = last[prev] + arr[i]`
                    * Update `dp[bit]` with the optimal value
                        ```cpp
                        if(dp[bit] >= ride){
                            last[bit] = (ride == dp[bit]) ? min(last[bit], weight) : weight;
                            dp[bit] = ride;
                        }
                        ```
* Greedy Approach and Its Failure
    A naive greedy approach might try to fit the heaviest person into an existing ride whenever possible. However, this fails in cases where a better grouping is possible but not selected greedily
    * Example Failure Case
        Consider the following example
        ```
        n = 9, x = 10
        weights = {2, 2, 3, 3, 3, 4, 4, 4, 5}
        ```
        A greedy approach takes `{5, 4}` first, then `{4, 3, 3}` next, and `{3, 2, 2}` last, resulting in `3` rides. However, a DP solution takes `{5, 2, 3}`, `{4, 4, 2}`, `{4, 3, 3}` instead, which only uses three rides

### 【UVa】 737. Gleaming the Cubes

**Solved**

。Basic Operations

* Features
    * UVa doesn't support `#pragma GCC target("avx")` QQ

### Modify `tasks.json`

* Features
    * Make the compiler support C++17
        ```json
        {
            "version": "2.0.0",
            "tasks": [
                {
                    "label": "build",
                    "type": "shell",
                    "command": "g++",
                    "args": [
                        "-g", "-std=c++17", "${file}", "-o", "${fileBasenameNoExtension}.exe" // Modified Line
                    ],
                    "group": {
                        "kind": "build",
                        "isDefault": true
                    }
                }
            ]
        }
        ```

### Update `Set.cpp`

### 【UVa】 494. Kindergarten Counting Game

**Solved**

。Basic Operations

### 【UVa】 10633. Rare Easy Problem

**Solved**

。Basic Operations

### 【UVa】 118. Mutant Flatworld Explorers

**Solved**

。Basic Operations

### 【ZeroJudge】 c082. 00118 - Mutant Flatworld Expolrers

**Solved**

。Basic Operations

### 【ZeroJudge】 e549. 00737 - Gleaming the Cubes

**Solved**

。Basic Operations

### 【CSES】 1140. Projects

**Solved**

。Discretization + DP + BIT - O(NlogN)

* Core Concept
    * Sorting Strategy
        * Sort projects by their ending day in ascending order
        * This allows us to process each project sequentially while maintaining an optimal substructure  
            ```cpp
            bool cmp( pair<pii, int> x, pair<pii, int> y ){
                return x.F.S < y.F.S;
            }

            sort(arr.begin(), arr.end(), cmp);
            ```
    * BIT Approach
        * Maintain a BIT where `BIT[i]` stores the maximum profit attainable by day `i` ⮕ The Concept of DP
        * Query the maximum profit before the project starts and update accordingly  
            ```cpp
            for( auto i : arr ){
                int cnt = query(i.F.S);      // Max profit including projects that end at i.F.S
                int q = query(i.F.F - 1);    // Max profit before i.F.F

                if( q + i.S > cnt ) update(i.F.S, q + i.S);
            }
            ```

### Update `Templete.cpp`

* Features
    ```cpp
    /* ---------- BIT ---------- */
    int n, BIT[MAXN];

    int lowbit( int x ){ return x & -x; }

    int query( int pos ){
        int ans = 0;
        
        while( pos ){
            ans += BIT[pos];
            pos -= lowbit(pos);
        }

        return ans;
    }

    void update( int x, int val ){
        while( x < MAXN ){
            BIT[x] += val;
            x += lowbit(x);
        }
    }

    int sum( int l, int r ){
        if( l > r ) return 0;
        return query(r) - query(l - 1);
    }
    ```

### 【UVa】 382. Perfection

**Solved**

。Basic Operations

### 【UVa】 10038. Jolly Jumpers

**Solved**

。Basic Operations

### 【UVa】 12439. February 29

**Solved**

。Basic Operations

### 【CSES】 1145. Increasing Subsequence

**Solved**

。LIS - DP + BIT - O(NlogN)

* Core Concept
    * BIT Approach
        * Maintain a BIT where `BIT[i]` stores the length of the LIS ending at the compressed index `i`
        * Query the maximum LIS length of all values smaller than `arr[i]` and update accordingly
            ```cpp
            int query( int pos ){
                if( pos <= 0 ) return 0;

                int ans = -1;
                while( pos ){
                    ans = max(ans, BIT[pos]);
                    pos -= lowbit(pos);
                }

                return ans;
            }

            void update( int x, int val ){
                while( x <= n ){
                    BIT[x] = max(BIT[x], val);
                    x += lowbit(x);
                }
            }
            ```
    * Calculation
        * Iterate through the array, updating the BIT with the LIS length at each step  
            ```cpp
            for( int i = 0 ; i < n ; ++i ) update(arr[i], query(arr[i] - 1) + 1);
            ```
        * Retrieve the maximum LIS length stored in the BIT
            ```cpp
            int res = 0;
            for( int i = 0 ; i <= Max ; ++i ) res = max(res, BIT[i]);
            ```

### 【CSES】 1093. Two Sets II

**Solved**

。DP 0/1 Knapsack - O(N<sup>3</sup>) = O(N ${\times}$ ( N ${\times}$ ( N + 1 ) / 4 ) )

* Core Concept
    * Approach
        * Define the State
            * Let `dp[i][j]` be the number of ways to form sum `j` using the first `i` numbers
        * Base Cases
            * `dp[i][0] = 1` for all `i`, since there is exactly one way to form sum 0 ⮕ by choosing nothing
        * Transition Formula
            * `dp[i][j] = dp[i-1][j] + (i <= j ? dp[i-1][j-i] : 0)`
            * If we exclude `i`, the number of ways to form `j` is `dp[i-1][j]`
            * If we include `i`, we need to form `j-i` with the first `i-1` numbers, which is given by `dp[i-1][j-i]`
            * Special attention is needed when `i > j` to avoid memory access errors
* Implementation Details
    * Iteration Order
        * Iterate `i` from `1` to `n`, ensuring dependencies on `i-1` are computed beforehand
            ```cpp
            for (int i = 1; i <= n; ++i) {
                for (int j = 0; j <= sum; ++j) {
                    dp[i][j] = dp[i-1][j] + (i <= j ? dp[i-1][j-i] : 0);
                    dp[i][j] %= Mod;
                }
            }
            ```
    * Special Considerations
        * `if (sum % 2 == 1) cout << "0\n";`
            * If the total sum is odd, it is impossible to split it into two equal halves
        * `dp[i][j] %= Mod;`
            * To prevent overflow, take modulo `1e9 + 7` at each step

### 【CSES】 1097. Removal Game

**Solved**

。DP Game Theory - O(N<sup>2</sup>)

* Core Concept
    * Approach
        * Define the State
            * Let `dp[i][j]` be the maximum score the first player can obtain from the subarray `[i, j]`
        * Base Cases
            * `dp[i][i] = arr[i]`, since if there is only one element left, the first player takes it
        * Transition Formula
            * `dp[i][j] = max(arr[i] + (pf(i + 1, j) - dp[i + 1][j]), arr[j] + (pf(i, j - 1) - dp[i][j - 1]))`
            * If the first player picks `arr[i]`, the second player plays optimally on `[i+1, j]`, leaving the first player with `pf(i+1, j) - dp[i+1][j]`
            * If the first player picks `arr[j]`, the second player plays optimally on `[i, j-1]`, leaving the first player with `pf(i, j-1) - dp[i][j-1]`
* Implementation Details
    * Iteration Order
        * Iterate in decreasing order for `i` and increasing order for `j` to ensure dependencies are computed beforehand
            ```cpp
            for (int i = n - 1; i >= 0; --i) {
                for (int j = i + 1; j < n; ++j) {
                    dp[i][j] = max( arr[i] + (pf(i + 1, j) - dp[i + 1][j]),
                                    arr[j] + (pf(i, j - 1) - dp[i][j - 1])  );
                }
            }
            ```

### 【CSES】 1745. Money Sums

**Solved**  

。DP - O(N<sup>2</sup>X<sub>i</sub>)  

* Time Complexity Analysis - O(N<sup>2</sup>X<sub>i</sub>)  
    * The problem is a variation of the subset sum problem, where we determine all possible sums that can be formed using the given coins
    * NX<sub>i</sub> is the sum of all coins, at most 1e5.  
    * The approach uses a 1-dim boolean DP array of size NX<sub>i</sub>+1, iterating through `n` coins
* Core Concept
    * This problem is a **classic dynamic programming bounded knapsack problem**
    * Approach
        * Define the State
            * Let `dp[i]` be a boolean value that is true if we can form sum `i` using a subset of the given coins
        * Base Cases
            * Initially, `dp[0]` = true, because 0 is always achievable with no coins
        * Transition Formula
            * dp[j] = dp[j] OR dp[j - x_i]
            * If sum `j - x_i` was previously possible, then sum `j` is now possible by adding `x_i`  
            * We process each coin only once, ensuring a Bounded Knapsack
    * Result Collection
        * After processing all coins, count and output the indices where `dp[j]` = true, as they represent possible sums
* Implementation Details
    * DP Update
        ```cpp
        for( int i = 0 ; i < v.size() ; ++i ){
            for( int j = 0 ; j < v[i].F ; ++j ){
                int amt = 0;
                for( int k = j ; k < INF ; k += v[i].F ){
                    if( dp[k] ) amt = v[i].S;
                    else if( amt > 0 ){
                        amt--;
                        dp[k] = true;
                        res.insert(k);
                    }
                }
            }
        }
        ```
        This is the bounded knapsack update, ensuring each coin is used at most its given count
        * Outer loop：Iterate through unique coin values
        * Inner loop：Process sums in increasing order
        * Key logic  
            * If `dp[k]` is already `true`, reset `amt` to the coin count
            * If `dp[k]` is `false` and `amt > 0`, set `dp[k] = true` and decrease `amt` ⮕ ensuring limited use of each coin

### 【CSES】 1639. Edit Distance

**Solved**  

。Dynamic Programming - O(N<sup>2</sup>)

* Core Concept
    * Approach
        * Define the State
            * Let `dp[i][j]` represent the minimum number of operations required to convert the first `i` characters of first string into the first `j` characters of second string 
            * The three operations allowed
                1. **Insertion**：Insert a character into first string ⮕ `dp[i][j] = dp[i][j-1] + 1`
                2. **Deletion**：Remove a character from first string ⮕ `dp[i][j] = dp[i-1][j] + 1`
                3. **Replacement**：Change one character in first string ⮕ `dp[i][j] = dp[i-1][j-1] + 1` 
            * If `a[i-1] = b[j-1]`, no operation is needed ⮕ `dp[i][j] = dp[i-1][j-1]` 
        * Base Cases
            * Converting an empty string into prefix of second string requires `j` insertions ⮕ `dp[0][j] = j`
            * Converting a prefix string of into another string requires `i` deletions ⮕ `dp[i][0] = i`
        * Transition Formula
            * dp[i][j] =  dp[i-1][j-1], **if a[i-1] = b[j-1]**
            * min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1, **otherwise**
* Implementation Details
    * Initialization
        * We initialize `dp[i][0] = i`：deleting `i` characters to match an empty string
        * We initialize `dp[0][j] = j`：inserting `j` characters to match another string
    * Iterating Subproblems
        * Fill the `dp` table using bottom-up dynamic programming
        * If the characters match, carry over `dp[i-1][j-1]`
        * Otherwise, compute the minimum of insert, delete, replace operations
    * Final Result
        * The answer is stored in `dp[(first string).size()][(second string).size()]`, which gives the minimum operations needed to transform first string into second string

### 【CSES】 1632. Movie Festival II

**Solved**  

。Greedy + Multiset - O(NlogK)

* Time Complexity Analysis - O(NlogK)
    * Sorting the movie intervals takes O(NlogN)  
    * Each movie is processed once, with at most O(logK) operations due to multiset insertion and deletion
* Core Concept
    * Sort movies by ending time to prioritize movies that finish the earliest
    * Use a multiset to track the earliest available end times of currently assigned viewers
    * Iterate through movies and assign each one to the available viewer
        * If a viewer is available, perform a binary search on the viewers' end time to find the viewer whose end time is closest to the start time of the previous movie, and update the end time
        * If all viewers are busy but there are less than `k` viewers, assign a new one
        * If all `k` viewers are busy and no one is available before the movie starts, skip the movie
* Key Observations
    * Greedy Choice：Prioritizing earliest finishing movies allows us to maximize the number of movies watched
    * Efficient Viewer Assignment：Using a `multiset<int>` ensures we always assign movies in O(logK) time 
    * Binary Search：This efficiently finds the earliest available viewer who can watch the next movie
* Implementation Details
    * Sorting Strategy
        * Sort movies by ending time
        * If two movies have the same ending time, sort by starting time
    * Handling Movie Assignments
        * Use a `multiset<int>` to store the end times of currently assigned movies
            * If a viewer is avaliable
            * Reassign the earliest finished viewer using `lower_bound()`
                ```cpp
                auto it = mst.lower_bound(mv[i].F) != mst.begin() ? prev(mst.lower_bound(mv[i].F)) : mst.begin();
                mst.erase(it);
                ```
            * Replace their previous end time with the new movie’s end time
            * If the club still has less than `k` viewers active：Assign the movie to a new viewer

### 【CSES】 1077. Sliding Window Cost

**Solved**  

。Balanced Multiset + Sliding Window - O(NlogK)

* Time Complexity Analysis - O(NlogK)  
    * Each insertion, deletion, and balancing operation runs in O(logK)
    * Since there are N insertions and deletions across the entire array, the total complexity is O(NlogK)
* Core Concept
    * Balanced Multiset + Sliding Window：Same as `【CSES】 1076. Sliding Window Median` 
    * The Key Observation：The optimal target value for minimizing the cost is the **median** of the window
    * Finding the Minimum Cost
        * The cost is computed using the formula
            ```
            cost = (sum of larger elements - median x number of large elements) + (median x number of small elements - sum of smaller elements)
            ```
            * If `k` is **odd**, the **median** is the element at the boundary between `small` and `large`
            * If `k` is **even**, compare two possible median choices and pick the one yielding the **minimum cost**
* Implementation Details 
    * Maintain two variables large sum and smallsum to reduce the time complexity of calculating the difference answer to O(1)
        ```cpp
        /* ---------- Ans Calculation ---------- */
        if( k % 2 == 0 ){
            int s = ( largesum - (*small.rbegin() * large.size() ) ) + ( (*small.rbegin() * small.size()) - smallsum );
            int l = ( largesum - (*large.begin() * large.size() ) ) + ( (*large.begin() * small.size()) - smallsum );

            cout << min(s, l) << " ";
        }else{
            cout << ( largesum - (mid * large.size()) ) + ( (mid * small.size()) - smallsum ) << " ";
        }
        ```

### 【CSES】 1076. Sliding Window Median

**Solved**

。Balanced Multiset + Sliding window - O(NlogK)

* Time Complexity Analysis - O(NlogK)
    * Each insertion, deletion, and balancing operation runs in O(logK)
    * Since there are N insertions and deletions across the entire array, the total complexity is O(NlogK)
* Core Concept
    * Balanced Multiset
        * `multiset<int> small`：Stores the smaller half of the elements, including the median when `k` is odd
        * `multiset<int> large`：Stores the larger half of the elements
        * The elements are balanced between these two multisets such that
            * `small` always holds at least as many elements as `large` when `k` is odd
            * When `k` is even, the median is taken from `small`
    * Insertion and Balancing Strategy
        * Insert each new element into the appropriate multiset
            * If the element is greater than or equal to the smallest value in `large`, insert it into `large`
            * Otherwise, insert it into `small`
        * Balance the sets
            * If `large` has more elements than `small`, move the smallest element from `large` to `small`
            * If `small` has more elements than `large`, move the largest element from `small` to `large`
    * Finding the Median
        * The median is always the largest element in `small` when `k` is odd
        * If `k` is even, the problem specifies that the smaller of the two middle elements should be taken, which is also the largest in `small`
    * Handling Element Removal from the Window
        * When sliding the window forward, the outgoing element must be removed from the appropriate set
        * This is done efficiently using `find()` and `erase()`
        * Rebalancing is required after removal to maintain the correct structure
* Implementation Details 
    * In the implementation, when removing an element from `small` or `large`, use `small.erase(small.find(arr[i-k+1]));` instead of `small.erase(arr[i-k+1]);`  
        * The reason for this is that `erase(arr[i-k+1])` would remove all occurrences of `arr[i-k+1]` from the `multiset`, which is incorrect. Since we are maintaining a balance between `small` and `large`, we only want to remove **one occurrence** of the element that is sliding out of the window. Using `small.find(arr[i-k+1])` ensures that only a **single instance** of `arr[i-k+1]` is erased, preserving the correct structure of the data

### 【CSES】 2428. Subarray Distinct Values

**Solved**

。Discretization + Sliding Window + Frequency Count - O(N)

* Core Concept
    * Data Compression
        * Since the given values range up to 10<sup>9</sup>, direct frequency counting is impractical. Therefore, the input sequence is compressed using coordinate compression
        * This ensures that adjacent elements in the compressed sequence are always distinct, simplifying further calculations
        *  The compression result is stored in `amt`, a `vector<pair<int, int>>` where each entry represents a unique value and its frequency
    * Discretization
        * Since values can be large, compress them into a smaller range
        * This allows efficient tracking of the number of each distinct value
    * Sliding Window Technique
        * Uses two pointers, `left` and `right`, to maintain a valid subarray where the number of distinct values does not exceed `k`
        * Expands `right` while updating a frequency counter `counter[]` to track occurrences
        * If the distinct count exceeds `k`, moves `left` to restore validity
    * Frequency Count Strategy
        * Maintains a frequency array `counter[]` to track the occurrences of each distinct value
        * The number of valid subarrays ending at `right` is determined by the size of the current window
        * Originally, the sum of valid subarrays was computed by iterating over the window
            ```cpp
            res += amt[left].S * (amt[it_pointer].S);
            ```
            But this was optimized using prefix sums to reduce complexity from O(N<sup>2</sup>) to O(N)
            ```cpp
            res += amt[left].S * (pre[right] - pre[left]);
            ```
    * Edge Cases
        * Special case when `k = 1`：Ensures values are not counted multiple times
            ```cpp
            res += amt[left].S + (amt[left].S * (amt[left].S - 1) / 2);
            if( k != 1 ) res += amt[left].S * (pre[right] - pre[left]); 
            ```
        * When `right` reaches the end of `amt` and `distinct value < k`, special handling is needed
            ```cpp
            if (right == amt.size() - 1) {
                for (int i = left; i < amt.size(); ++i) {
                    res += amt[i].S + (amt[i].S * (amt[i].S - 1) / 2);
                    if (k != 1) res += amt[i].S * (pre[right] - pre[i]);
                }
                break;
            }
            ```

### Update `Templete.cpp`

* Features
    * Update Variable Name
        ```cpp
        /* ---------- Discretization ---------- */
        int discretization(){
            int n, tmp[MAXN], after[MAXN], before[MAXN]; 
            vector<int> distinct;

            cin >> n;
            for( int i = 0 ; i < n ; i++ ){
                cin >> before[i];
                tmp[i] = before[i];
            }

            sort(tmp, tmp + n);

            distinct.pb(tmp[0]);
            for( int i = 1 ; i < n ; i++ ){
                if( tmp[i] != tmp[i-1] ) distinct.pb(tmp[i]);
            }

            for( int i = 0 ; i < n ; i++ ) after[i] = lower_bound(distinct.begin(), distinct.end(), before[i]) - distinct.begin();
        }
        ```

### 【CSES】 1662. Subarray Divisibility

**Solved**

。Prefix Sum + Modulo - O(N)

* Core Concept
    * Prefix Sum with Modulo
        * Compute prefix sum `pre[i]` such that `pre[i] = (pre[i-1] + arr[i]) % n`
        * This reduces the problem to finding subarrays where the sum is divisible by `n`
    * Frequency Count Strategy
        * Maintain a frequency array `res[]` to count occurrences of each remainder when computing `pre[i]`
        * If a remainder appears more than once, it means there exist subarrays with sums that have the same remainder when divided by `n`, implying a subarray sum that is divisible by `n`
        * The number of valid subarrays is calculated using the combination formula
            ```cpp
            int acc = 0;
            for( int i = 0 ; i < n ; ++i ) acc += res[i] * ( res[i] - 1 ) / 2;
            ```
    * Handling Negative Modulo Values
        * Ensure non-negative values using `(value + n) % n`
            ```cpp
            pre[i] = ( ( pre[i-1] + ( arr[i] % n ) ) + n ) % n;
            ```
* Implementation Details
    * Initializing `res[0]`
        * `res[0]++` is used to handle cases where a prefix sum itself is already divisible by `n`
        * This ensures that subarrays starting from the beginning are correctly counted

### 【CSES】 2169. Nested Ranges Count

**Solved**

。Discretization + BIT - O(NlogN)

* Time Complexity Analysis - O(NlogN)
    * Sorting the right endpoints takes O(NlogN), and assigning indices takes O(N), resulting in a total of O(NlongN)
    * Sorting the intervals based on their left endpoints takes O(NlongN)
    * Each query and update operation in the BIT takes O(NlongN), and we perform O(N) such operations, leading to a total of O(NlongN)
* Implementation Details
    * Discretization
        * Since the right endpoints of the intervals can be too large, directly using them in BIT operations is inefficient and impractical
        * We use coordinate compression to reduce the maximum value needed in BIT to at most 2e5, preventing excessive memory usage
            ```cpp
            vector<int> disc;

            sort(pre, pre + n);
            
            disc.push_back(pre[0]);
            for( int i = 1 ; i < n ; ++i ){
                if( pre[i] != pre[i-1] ) disc.push_back(pre[i]);
            }
            
            for( int i = 0 ; i < n ; ++i ) arr[i].r = lower_bound(disc.begin(), disc.end(), arr[i].r) - disc.begin() + 1;
            ```
    * Counting Intervals Contained Within Another
        * Iterating from right to left, we check how many intervals are already in the BIT before inserting the current interval
        * If an interval has a right endpoint greater than or equal to the smallest seen so far, it is contained within some interval
            ```cpp
            int MIN = INF;
            for( int i = n - 1 ; i >= 0 ; --i ){
                if( arr[i].r >= MIN ) res[0][arr[i].id] = query(arr[i].r);
                else res[0][arr[i].id] = 0;

                update(arr[i].r, 1);
                MIN = min(MIN, arr[i].r);
            }
            ```
        * After this process, we reset BIT to ensure the next counting step starts with an empty BIT
            ```cpp
            mem(BIT, 0);
            ```
    * Counting Intervals That Contain Another
        * Iterating from left to right, we check how many previously seen intervals have right endpoints within the current interval’s range
            ```cpp
            int MAX = -1;
            for( int i = 0 ; i < n ; ++i ){
                if( arr[i].r <= MAX ) res[1][arr[i].id] = sum(arr[i].r, MAX);
                else res[1][arr[i].id] = 0;
                update(arr[i].r, 1);
                MAX = max(MAX, arr[i].r);
            }
            ```

### Modify `Template.cpp`

* Features
    1. Add `discretization()`
        ```cpp
            /* ---------- Discretization ---------- */
            int discretization(){
                int n, pre[MAXN], after[MAXN], before[MAXN]; 
                vector<int> arr;

                cin >> n;
                for( int i = 0 ; i < n ; i++ ){
                    cin >> before[i];
                    pre[i] = before[i];
                }

                sort(pre, pre + n);

                arr.pb(pre[0]);
                for( int i = 1 ; i < n ; i++ ){
                    if( pre[i] != pre[i-1] ) arr.pb(pre[i]);
                }

                for( int i = 0 ; i < n ; i++ ) after[i] = lower_bound(arr.begin(), arr.end(), before[i]) - arr.begin();
            }
        ```

### 【CSES】 2168. Nested Ranges Check

**Solved**

。Observation - O(NlogN)

* Core Concept
    1. Sorting Strategy
        - Sort intervals by left endpoint in ascending order
        - If two intervals have the same left endpoint, sort by right endpoint in descending order 
        - This ensures that larger intervals come before smaller ones when they start at the same position
    2. Check Strategy
        - Find intervals that **contain** others by tracking the maximum right endpoint seen so far
            ```cpp
            int MAX = -1;
            for( int i = 0 ; i < n ; ++i ){
                if( arr[i].r <= MAX ) res[1][arr[i].id] = true;
                else res[1][arr[i].id] = false;

                MAX = max(MAX, arr[i].r);
            }
            ```
        - Find intervals that are **contained** in others by tracking the minimum right endpoint seen so far
            ```cpp
            int MIN = INF;
            for( int i = n - 1 ; i >= 0 ; --i ){
                if( arr[i].r >= MIN ) res[0][arr[i].id] = true;
                else res[0][arr[i].id] = false;

                MIN = min(MIN, arr[i].r);
            }
            ```

### 【CSES】 2163. Josephus Problem II

**Solved**

。BIT + Binary Search - O(NlogN)

* Time Complexity Analysis - O(NlogN)
    * BIT Operations are O(logN)
    * Binary Search runs in O(logN) per step
    * Since we perform these operations N times, the total complexity is O(NlogN)
* Core Concept
    1. Use the p-th smallest number concept to determine eliminations
        * The key observation is that every round reduces the number of available people, meaning our modulo calculations must be adjusted accordingly.
    2. Efficiently locate the person to remove
        * Need a data structure that support
            1. Dynamically delete elements as people are removed
            2. Quickly find the person at a given rank
    3. Use BIT for efficient tracking
        * BIT is used instead of a Segment Tree because
            1. It efficiently tracks the number of remaining people
            2. It allows for fast prefix sum calculations to find the p-th smallest remaining number
* Implementation Details
    1. Updating the next person to skip
        * After removing a person, we update `cut` to determine how many people to skip in the next round
            ```cpp
            cut = k % (t-1);
            cut += 1;
            ```
        * Why is this needed
            * `t` represents the number of people left in the circle
            * Since we are skipping `k` people, taking `k % (t-1)` ensures that the count wraps around correctly
            * The `+1` ensures we move to the correct position
    2. Handling circular wraparounds
        * Since the Josephus problem involves cycling through a list, we must wrap around when we reach the end
        * The following code ensures that if we don’t have enough people left from start to the end, we reset to the beginning and adjust `cut`
            ```cpp
            if( ( q = sum(start, n) ) < cut ){
                start = 0;
                cut = cut - q;
            }
            ```

### 【CSES】 2162. Josephus Problem I

**Solved**

。Queue Simulation - O(N)：Each number is inserted into the queue once and removed once, meaning the total number of operations is O(N)

### Push All Programs That Have Been Finished Before But Not Pushed

### Modify `Template.cpp`

### Modify `tasks.json`

* Features
    * Make the compiler support C++17
        ```json
        {
            "version": "2.0.0",
            "tasks": [
                {
                    "label": "build",
                    "type": "shell",
                    "command": "g++",
                    "args": [
                        "-g", "-std=c++17", "${file}", "-o", "${fileBasenameNoExtension}.exe" // Modified Line
                    ],
                    "group": {
                        "kind": "build",
                        "isDefault": true
                    }
                }
            ]
        }
        ```

### Modify And Add Content To `Set.cpp`

* Features
    1. Modify - Pragma
        * Remove Invalid Space
        * Code 
            ```cpp
            /* Pragma */
            #pragma GCC optimize("Ofast")
            #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
            #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
            ```
    2. Add - sortV ( Vector )
        ```cpp
        #define sortV(x) sort(x.begin(), x.end());
        ```

### Add Content To `Set.cpp`

* Features
    1. Pragma
        ```cpp
        /* Pragma */
        #pragma GCC optimize("Ofast")
        #pragma GCC optimize("Ofast, unroll-loops, no-stack-protector, fast-math")
        #pragma GCC target("sse, sse2, sse3, ssse3, sse4, popcnt, abm, mmx, avx, tune=native")
        ```
    2. Memset Constant
        * Reason : `memset` is used to set each byte of memory to a specified value, but it only accepts an 8-bit integer (`unsigned char`). `INF` is 0x7FFFFFFF (a 32-bit integer), but `memset` only takes the lowest 8 bits, which is 0xFF (255). As a result, each byte of the `dp` array is set to 0xFF. If `dp` is of type `int`, each element (composed of 4 bytes) ends up being 0xFFFFFFFF (-1) instead of the intended `INF`.
        * Code
            ```cpp
            const int MEMINF = 0x3F;
            const int MEMINF_VAL = 0x3F3F3F3F;
            const int MEMLLINF_VAL = 0x3F3F3F3F3F3F3F3F;
            ```
        * Example
            ```cpp
            mem(dp, MEMINF);
            ```

### 【CSES】 2217. Collecting Numbers II

**Solved**

。Observation - O(max(N, M))

* Core Concept
    1. First get the result of the original array, and update the current answer while processing the operation
    2. Once you want to swap pairs { $i, j$ }, noew answer only depends on pairs { $i, i \pm 1$ } and { $j, j \pm 1$ }
* Implementation Details
    * Special handling is required of the case `abs(i - j) = 1`
        ```cpp
        /***** Reference Function *****/
        int check( int qa, int qb ){
            int preA = idx[qa];
            int preB = idx[qb];
            int dif = 0;
            
            swap( idx[arr[a]], idx[arr[b]] );

            int newA = idx[qa];
            int newB = idx[qb];
            int flag = qa > qb ? -1 : 1;

            if( preA < preB && newA > newB ) dif += 1 * flag;
            if( preA > preB && newA < newB ) dif -= 1 * flag;

            swap( idx[arr[a]], idx[arr[b]] );

            return dif;
        }
        
        /***** Main *****/
        if( abs( arr[a] - arr[b] ) == 1 ) res += check(arr[a], arr[b]) * -1;
        ```

### 【CSES】 2216. Collecting Numbers

**Solved - Another Better Solution ( Solution II )**

。Observation - O(N)

* Key to Solving the Problem
    * You have to found that the result only depends on how many pairs { $i, j$ } which satisfy `j = i + 1` and `index of j ( = i + 1 ) < index of i`

### 【CSES】 1673. High Score

**Solved**

。Bellman-ford + DFS

* Implementation Details
    * Bellman-Ford
        - Used in the `bell` function to calculate shortest paths.  
        - Initialize distances `dis` to a large value (`1e15`), with the starting node set to `0`.  
        - Relax edges for `n-1` iterations; if an edge is relaxed in the `n`th iteration, a negative weight cycle is detected.  
        - **Deformation** : Detected cycles are propagated using `getCycle`
            ```cpp
            int bell(int root) {
                for( int i = 1 ; i <= n ; i++ ) dis[i] = 1e15;
                dis[root] = 0;
                for( int i = 1 ; i <= n ; i++ ){
                    for( auto e : edge ){
                        int w = e.f, a = e.s.f, b = e.s.s;
                        if( dis[a] + w < dis[b] ){
                            if (i == n) {
                                negc[a] = true;
                                mem(used, false);
                                used[a] = true;
                                getCycle(a, a);
                            }
                            dis[b] = dis[a] + w;
                        }
                    }
                }
                return (flag && dfs(1, false)) ? -1 : (-1 * dis[n]);
            }
            ```
    * Negative Cycle Detection and Propagation  
        - `getCycle` recursively marks nodes affected by negative weight cycles 
            ```cpp
            bool getCycle( int root, int init ){
                for( auto i : graph[root] ){
                    if( negc[i] ) return true;
                    if( used[i] ) continue;
            
                    used[i] = true;
                    
                    if( getCycle(i, init) ){
                        negc[i] = true;
                        return true;
                    }

                    used[i] = false;
                }
            
                return false;
            }
            ```
    * DFS for Path Validation  
        - The `dfs` function ensures that there is a valid path from node `1` to node `n`
        - It also checks if negative cycles affect this path.
            ```cpp
            bool dfs( int root, bool state ){
                bool res = false;
                if( root == n ){
                    return negc[n] | state;
                }
                else{
                    bool tmp = state;
                    for( auto i : graph[root] ){
                        if( negc[i] ) tmp = true;
                        if( used[i] ) continue;
                        
                        used[i] = true;

                        res |= dfs(i, tmp);
            
                        used[i] = false;
                        tmp = state;
                    }

                    if( root == 1 ) return res | negc[root];
                    else return res;
                }
            }
            ```

### 【ZeroJudge】 n750. 10858 - Unique Factorization

**Solved**

。Prime + Brust Force

* Implementation Details
    * Output Data from `set<vector<int>>`
        ```cpp
            set<vector<int>> res;
            vector<int> path;

            for( auto st : res ){
                for( auto it : st ) cout << it << " ";
                cout << "\n";
            }
        ```

        This is very useful, but remember to clear all of the containers before use.

        ```cpp
            set<vector<int>> res;
            vector<int> path;

            path.clear();
            res.clear();
        ```
    * Bruse Force
        Use backtracking to generate all factorizations
        
        1. First define a backtracking function `dfs(`$x$`)`, where $x$ is the current number to be factored, and maintain a `path` to store the current factorization.
        2. When decreasing back, try concatenating $x$ as the product of two or more numbers and make sure the result is non-decreasing.
        3. In order to ensure that the result is non-decreasing, when looking for the next factor, we can limit the range of factors to $[pre, x]$, where $pre$ is the last number in `path`, if `path` is empty, Then $pre$ = 2.

### 【CSES】 1625. Grid Paths

**Solved**

。Brust DFS + Pruning

* Implementation Details
    * DFS Section
        ```cpp
            void solve( int cnt, int x, int y ){
                if( used[x][y] ) return;
                if( x == 1 && y == 7 && cnt < str.size() ) return;
                if( cnt == str.size() ){
                    /* Finish Operation */
                    ans++;
                    return;
                }
            
                used[x][y] = true;
            
                if( str[cnt] == 'D' ) solve(cnt+1, x, y + 1);
                if( str[cnt] == 'U' ) solve(cnt+1, x, y - 1);
                if( str[cnt] == 'L' ) solve(cnt+1, x - 1, y);
                if( str[cnt] == 'R' ) solve(cnt+1, x + 1, y);
                if( str[cnt] == '?' ) {
                    for( int t = 0 ; t < 4 ; t++ ){
                        solve(cnt+1, x + dir[t].F, y + dir[t].S);
                    }
                }
            
                used[x][y] = false;
            }
        ```
    * Pruning
        * Key to Pruning : If graph gonna create 2 different disconnected component, then cut it
        ```cpp
            /* Section 1 */
            /*
                Pruning State（'#' Stands for True or Visited, 'F' Stands for False, 'Now' Stands for Current Position）
                    | ?  #  ? | ?  F  ? |
                    | F Now F | # Now # |
                    | ?  #  ? | ?  F  ? |
             */
            if( used[x-1][y] && used[x+1][y] && !used[x][y+1] && !used[x][y-1] ) return;
            if( !used[x-1][y] && !used[x+1][y] && used[x][y+1] && used[x][y-1] ) return;

            /* Section 2 */
            /*
                Pruning State（'#' Stands for True or Visited, 'F' Stands for False, 'Now' Stands for Current Position）
                    | #  F  |  F   # | F Now | Now  F |
                    | F Now | Now  F | #  F  |  F   # |
             */
            if( used[x-1][y-1] && !used[x][y-1] && !used[x-1][y] ) return;
            if( used[x+1][y-1] && !used[x][y-1] && !used[x+1][y] ) return;
            if( used[x-1][y+1] && !used[x-1][y] && !used[x][y+1] ) return;
            if( used[x+1][y+1] && !used[x+1][y] && !used[x][y+1] ) return;
        ```

### 【CSES】 2431. Digit Queries

**Solved**

。Basic Math Problem

### 【CSES】 1631. Reading Books

**Solved**

。Greedy

### 【CSES】 1661. Subarray Sums II

**Solved**

。Map - O(NlogN)

### 【CSES】 1660. Subarray Sums I

**Solved**

。Binary Serach - O(NlogN)

### 【CSES】 1645. Nearest Smaller Values

**Solved**

。Monotonic Stack - O(N)

### 【CSES】 1642. Sum of Four Values

**Solved**

。Basic Enumerate & Sort Algorithm - O(N<sup>3</sup>)

* Key to Solving the Problem
    1. O(N<sup>2</sup>) method to get the first two elements
    2. O(N) method to get the last two elements like below

        ```cpp
            int k = j + 1, l = n - 1;
            while( k < l ){
                int sum = sum of four elements;
                if( sum > x ) l--;
                else if( sum < x ) k++;
                else Output index of four elements respectively
            }
        ```

        First initialize the `index value of the third and fourth` element to `j+1 and n-1`, respectively. <br>
        Then, if sum of four elements less than x, increase k by 1. Otherwise, check whether sum equals to x or not. <br>
        If sum doesn't equals to x, decrease l by 1. Otherwise, output the answer.

**Modify Problem Title**

**Solved** - 【CSES】 1645. Nearest Smaller Values

。 Segment Tree、Discretization - O(NlogN)

* Implementation Details
    * Notice to query like `query(1, n, 1, arr[i]-1, 1)` not `query(1, n, 1, arr[i], 1)`, but modify must be `modify(1, n, arr[i], arr[i], i, 1);`

**Solved** - 【CSES】 1644. Maximum Subarray Sum II

。 Basic Set Operation、Prefix Sum

* Notice 
    * `erase(val)` in `set` will erase all of the value which equals to val
    * `set` will be sorted `.first` and then `.second`

**Solved** - 【CSES】 1641. Sum of Three Values

**Solved** - 【CSES】 1164. Room Allocation

**Update Set.cpp**

**Solved** - 【Luogu】 P3376.【Template】Maximum Network Flow

**Solved** - 【Luogu】 P3379.【Template】LCA

**Modify File Name** - 【Luogu】 P3385.【Template】Negative Cycle

**Solved** - 【Luogu】 P3385.【Templete】Negative Cycle

**Update Set.cpp**

**Correct README.md**

**Solved** - 【CSES】 1647. Static Range Minimum Queries

。Segment Tree、DP

**Solved** - 【AtCoder】 Beginner Contest 368 - G. Add and Multiply Queries

**Update BIT Code**

**Update Answer II** - 【AtCoder】 Beginner Contest 368 - D. Minimum Steiner Tree

**Update Answer** - 【AtCoder】 Beginner Contest 368 - D. Minimum Steiner Tree

**Solved** - 【AtCoder】 Beginner Contest 368 - D. Minimum Steiner Tree

。DFS

* Implementation Theory    
    1. Taking the last specified vertices as the root, proceed DFS.
    2. Determine whether current vertex needs to retain or not during the DFS.
        * To know whether its subtree has vertices that need to be retained, and if so, the current vertex is needed to be retained.
    3. What DFS returned is whether the subtree has any vertex that need to be retained.
    4. The final answer is the number of vertices which needed to be retained.

* Implementation Details
    1. 【Line 32】Here use the characteristics of the OR operation to store whether any vertex in the subtree is a specified vertex. In addition, it is worth noting that Bool type variables can also be used to record here.
    
        ```cpp
            valid |= dfs(i, cnt);
        ```
    
    2. 【Line 59】Remember that the last specified vertex must be used as the root vertex here, otherwise problems will occur. For example, when there are two nodes, assuming No. 1 is the root node and No. 2 is the specified vertex, the output will be 2 instead of 1.

        ```cpp
            dfs(node, -1);
        ```

**Commit & Push All Unexist Files** - Remove `Setup.cpp`

**Solved** - 【AtCoder】 Beginner Contest 369 - C. Triple Attack

**Opt README.md Contents**

**Solved** - 【AtCoder】 Beginner Contest 369 - F. Gather Coins

。LIS in O(NlogN)

* Implementation Theory
    1. Given $k$ coins $(r_1, c_1)$, $(r_2, c_2)$, ⋯⋯ , $(r_k, c_k)$ ⮕ we can determine if there exist a path that can collect all the coins as follows.
        * First sort the coins in ascending order of $r$, then sort the coins in ascending order of $c$​.
        * There exists a path that can collect all the given $k$ coins if and only if $c_1′ ≤ c_2′ ≤$ ⋯⋯ $≤ c_k′$.
    
    2. Suppose that the given $N$ coins are sorted in ascending order of $(r,c)$. Then, by the fact above, this problem is boiled down to finding a **L**ongest （weakly） **I**ncreasing **S**ubsequence （LIS）.

    3. Simplify the Question into **" Given positive integer sequence $C$ = ( $C_1$, $C_2$, ⋯⋯ , $C$<sub>$N$</sub> ), one can find the length of a LIS of $C$ "**

    4. The standard **LIS** algorithm implementation definition should be as follows.
        1. Prepare a length- $N$ sequence $D$ initialized with $∞$.
        2. Do the following for $i = 1, 2,$ ⋯⋯ $, N$. For the minimum $j$ with $D_j > C_i$ , replace $D_j$  with $C_i$.
        3. The length of a LIS of $C$ is the maximum $j$ with $D_j < ∞$.

        Where each $D_j$ stands for the smallest last element of a length- $j$ （weakly） increasing subsequence of $C_1$, $C_2$, ⋯⋯ , $C_i$ （or $∞$ if there is no such subsequence）.
    
    5. However, if we just use the algorithm above, we will find that we cannot trace the path. Thus, to find an example of LIS instead of its length only, let us modify the algorithm as follows.

        1. Prepare a length- $N$ sequence $D$ initialized with $∞$.
        2. Prepare a length- $N$ sequence $Id$ and $Pre$.
        3. Do the following for $i = 1, 2,$ ⋯⋯ $, N$.
            * For the minimum $j$ with $D_j > C_i$​ , replace $D_j$ with $C_i$, and replace $Id_j$ with $i$. If $j > 1$, replace $Pre_i$​ with $Id_{j−1}$​, too.
        4. The length of a LIS of $C$ is the maximum $j$ with $D_j < ∞$.
        5. Let $L$ be the length of a LIS of C. Consider a length- $L$ sequence obtained by applying $L−1$ times the action $i ↦ Pre_i$​ to $Id_L$, same as $Id$<sub>$L$</sub>, $Pre$<sub>$Id$<sub>$L$</sub></sub>, $Pre$<sub>$Pre$<sub>$IdL$</sub></sub>，⋯⋯ . The reversal of this sequence is an example of a LIS of $C$.

* Implementation Details
    1. 【Line 41】Remember to use `upper_bound()` not `lower_bound()`, because we need the Longest **Weakly** Increasing Subsequence
    
        ```cpp
        41｜int it = upper_bound(dp.begin(), dp.end(), coin[i].S) - dp.begin();
        ```

**Solved** - 【AtCoder】 Beginner Contest 369 - D. Bonus EXP

。Dynamic Programming

**Opt IO Optimize & Add Long Long INF** - Set.cpp

**Solved** - 【AtCoder】 Beginner Contest 369 - E. Sightseeing Tour

。Flyod-Warshall、Enum

**Solved** - 【AtCoder】 Beginner Contest 369 - C. Count Arithmetic Subarrays

。Basic Mathematical Operations

**Update Quesiton Statement**

**Opt Setup Code**

**Solved** - 【AtCoder】 Beginner Contest 370 - A. Raise Both Hands

**Solved** - 【AtCoder】 Beginner Contest 370 - B. Binary Alchemy

**Solved** - 【AtCoder】 Beginner Contest 370 - C. Word Ladder

**Solved** - 【ZeroJudge】 a104. Sort - Quick Sort

。Sort Algorithm

**Correcnt Spelling Error** - 【ZeroJudge】 a104. Sort - Merge Sort

**Remove Redundant Array** - 【ZeroJudge】 a104. Sort - Merge Sort

**Oprtimize** - 【ZeroJudge】 a104. Sort - Merge Sort

**Solved** - 【ZeroJudge】 a104. Sort - Merge Sort

。Sort Algorithm

**Solved** - 【ZeroJudge】 a104. Sort - Insertion Sort

。Sort Algorithm

**Add Question Info** - 【ZeroJudge】 a104. Sort - Insertion Sort

**Solved** - 【ZeroJudge】 a104. Sort - Bubble Sort

。Sort Algorithm

**Solved** - 【ZeroJudge】 a104. Sort - Selection Sort

。Sort Algorithm

**Solved** - 【ZeroJudge】 d672. 10922 - 2 the 9s

。Recursive、Basic String Processing

**Solved** - 【ZeroJudge】 f928. Serial Bomb............Boom!

。Recursive、BFS

**Solved** - 【CSES】 2165. Tower of Hanoi

。Recursive Application

**Solved** - 【HWSH】 a155. Sum of Subsets（APCS201810, Subtask）

。Recursive with Subset

**Solved** - 【HWSH】 a062. Stick Midpoint Cut

。Recursive Application

**Solved** - 【ZeroJudge】 b967. 4. Blood Relationship

。 Simple Tree Diameter

**Solved** - 【AtCoder】 Beginner Contest 352 - C. Standing On The Shoulders

**Solved** - 【AtCoder】 Beginner Contest 352 - D. Permutation Subsequence

。 Set、vector<pii>、Sort

**Solved** - 【AtCoder】 Beginner Contest 351 - C. Merge the balls

**Solved** - 【ZeroJudge】 g276. 2. Demon King no Labyrinth

**Solved** - 【ZeroJudge】 j605. 1. Programming Exam

**Solved** - 【ZeroJudge】 a003. Two Lights Mage Divination

**Solved** - 【ZeroJudge】 d649. Digital Triangle

**Solved** - 【TCIRC】 1001. Hello World!

**Solved** - 【ZeroJudge】 a002. Simple Addition

**Solved** - 【AtCoder】 A. Three Dice

**Solved** - 【TCIRC】 d060. AP325 Q-4-19. The Meeting Place of the Leaders of The Five Sacred Mountains

**Solved** - 【TCIRC】 d057. AP325 Q-4-16. Making Money and Fines

**Solved** - 【TCIRC】 d058. AP325 Q-4-17. Deadline Master

**Solved** - 【TCIRC】 d059. AP325 Q-4-18. The Cabinet Sister of Shaolin Temple（@@）（＊）

**Solved** - 【TCIRC】 d050. AP325 P-4-11. Line Segment Union（APCS 201603）

**Solved** - 【TCIRC】 d051. AP325 P-4-12. One Transaction

**Solved** - 【TCIRC】 d055. AP325 P-4-14. Control Point（2D-max）

**Solved** - 【TCIRC】 d071. AP325 P-6-9. Free Large-Scale Moving in Hypermarkets

**Solved** - 【ZeroJudge】 k184. pA. House

**Solved** - 【TCIRC】 d054. AP325 Q-4-10. White Cloud Bear Gallbladder Pills to Restore Energy

**Solved** - 【TCIRC】 d070. AP325 P-6-7. LCS

**Solved** - 【TCIRC】 d074. Q-6-8. Local Alignment

**Solved** - 【TCIRC】 d069. AP325 P-6-6. Checkerboard Route

**Solved** - 【TCIRC】 d052. AP325 P-4-13. Maximum Continuous Subpermutation（Same As P-5-2）

**Solved** - 【TCIRC】 d073. AP325 Q-6-5. Two-Dimensional Maximum Submatrix

**Solved** - 【TCIRC】 d066. AP325 P-6-1. Minimum Cost for Children To Go Up Stairs

**Solved** - 【TCIRC】 d067. AP325 P-6-2. Discontinuous Performance Remuneration

**Solved** - 【TCIRC】 d068. AP325 P-6-3. Minimum Cost of Monitoring Neighbors

**Solved** - 【TCIRC】 d072. AP325 Q-6-4. Choose One of Two Levels

**Solved** - 【CSES】 2413. Counting Towers

**Solved** - 【CSES】 1744. Rectangle Cutting

**Solved** - 【CSES】 1746. Array Description

**Solved** - 【AtCoder】 Beginner Contest 342 - D. Square Pair

**Opt BIT Templete**

**Solved** - 【AtCoder】 Beginner Contest 342 - A. Yay!

**Solved** - 【AtCoder】 Beginner Contest 342 - B. Which is ahead

**Solved** - 【AtCoder】 Beginner Contest 342 - C. Many Replacement

**Solved** - 【AtCoder】 Beginner Contest 341 - E. Alternating String

**Solved** - 【CSES】 1073. Towers.cpp

**Solved** - 【AtCoder】 Beginner Contest 341 - D. Only one of two

**Solved** - 【TCIRC】 d049. AP325 P-4-9. Base Station（APCS201703）

**Solved** - 【AtCoder】 Beginner Contest 339 - E. Smooth Subsequence

**Solved** - 【TCIRC】 d047. AP325 Q-4-6. Automatic Lockers in Shaolin Temple（APCS201710）

**Solved** - 【TCIRC】 d048. AP325 P-4-7. Yue Buquns Two-Way Merge（＊）

**Solved** - 【TCIRC】 d053. AP325 Q-4-8. First Come First Served（＊）

**Solved** - 【ZeroJudge】 h557. pA. Entrance

**RePush** - 【AtCoder】 Beginner Contest 328 - A. Not Too Hard

**RePush** - 【AtCoder】 Beginner Contest 328 - B. 11/11

**RePush** - 【AtCoder】 Beginner Contest 328 - C. Consecutive

**RePush** - 【AtCoder】 Beginner Contest 328 - D. Take ABC

**Solved** - 【ZeroJudge】 h558. pB. Keyboard

**Solved** - 【AtCoder】 Beginner Contest 341 - A. Print 341

**Solved** - 【AtCoder】 Beginner Contest 341 - B. Foreign Exchange

**Solved** - 【AtCoder】 Beginner Contest 341 - C. Takahashi Gets Lost

**Solved** - 【AtCoder】 Beginner Contest 340 - E. Mancala 2

**Add INF Const** - Set.cpp

**Solved** - 【TCIRC】 d046. AP325 P-4-5. Problem of Songshan Mojianfang （Weighted Minimum Completion Time）

**Solved** - 【AtCoder】 Beginner Contest 340 - A. Arithmetic Progression

**Solved** - 【AtCoder】 Beginner Contest 340 - B. Append

**Solved** - 【AtCoder】 Beginner Contest 340 - C. Divide and Divide

**Solved** - 【AtCoder】 Beginner Contest 340 - D. Super Takahashi Bros.

**Opt Code** - 【TCIRC】 d046. AP325 P-4-5. Problem of Songshan Mojianfang （Weighted Minimum Completion Time）

**Solved** - 【TCIRC】 d045. AP325 P-4-4. Several Huashan Sword Debates（Activity Selection）

**Solved** - 【TCIRC】 d042. AP325 P-4-1. Shaolin Temple Tokens

**Solved** - 【TCIRC】 d043. AP325 P-4-2. The Three Battles of Swordsman

**Solved** - 【TCIRC】 d044. AP325 P-4-3. Ten Years of Sharpening a Sword（Minimum Completion Time）

**Solved** - 【AtCoder】 Beginner Contest 339 D. Synchronized Players

**Solved** - 【TCIRC】 d038. AP325 Q-3-14 Linear Function（@@）

**Opt Code** - 【TCIRC】 d037. AP325 Maximum Y Difference within X Difference Range

**Solved** - 【AtCoder】 Beginner Contest 339 - A. TLD

**Solved** - 【AtCoder】 Beginner Contest 339 - B. Langton's Takahashi

**Solved** - 【AtCoder】 Beginner Contest 339 - C. Perfect Bus

**Rename File** - 【TCIRC】 d036. AP325 Q-3-12. Perfect Ribbons（APCS201906）

**Solved** - 【TCIRC】 d037. AP325 Q-3-13. Maximum Y Difference within X Difference Range

**Solved** - 【TCIRC】 d036. AP325 Q-3-12. Perfect Ribbons（APCS201906）

**Solved** - 【TCIRC】 d032. AP325 P-3-8. Maximum Segment Difference for Fixed-length Intervals

**Solved** - 【TCIRC】 d035. AP325 Q-3-11. The Longest Distinct Color Band

**Solved** - 【TCIRC】 d034. AP325 P-3-10. Full-Color Ribbon（Requires Discretization or Dictionary）（@@）

**Solved** - 【TCIRC】 d033. AP325 P-3-9. Most Color Bands

**Solved** - 【TCIRC】 d021. AP325 Q-2-12. The Closest Submatrix Sum（108 High School National Competition）（＊）

**Solved** - 【TCIRC】 d031. AP325 P-3-7. The Closest Interval Sum of A Sequence of Positive Integers

**Solved** - 【TCIRC】 d025. AP325 P-3-1. Height and Root of Tree（Bottom-Up）（APCS201710）

**Solved** - 【TCIRC】 d052. AP325 P-5-2. Maximum Continuous Subarray（Divide and Conquer）

**Solved** - 【TCIRC】 d026. AP325 P-3-2. Bracket Matching

**Anti-Annotation** - 【TCIRC】 d026. AP325 P-3-2. Bracket Matching

**Solved** - 【TCIRC】 d027. AP325 Q-3-3. Addition, Subtraction, Multiplication and Division

**Solved** - 【TCIRC】 d028. AP325 P-3-4. The Closest Taller（APCS201902, Subtask）

**Remove Deleted File**

**Solved** - 【TCIRC】 d029. AP325 Q-3-5. The Taller with A Bench Cooking Chicken Steaks（APCS201902）

**Solved** - 【TCIRC】 d030. AP325 P-3-6. Cutting Down Trees（APCS202001）

**Working On It** - 【TCIRC】 d021. AP325 Q-2-12. The Closest Submatrix Sum（108 High School National Competition）（＊）

**Remove Unused Code** - 【TCIRC】 d023. AP325 Q-2-14. Pond（108 High School National Competition）（@@）

**Solved** - 【TCIRC】 d023. AP325 Q-2-14. Pond（108 High School National Competition）（@@）

**Solved** - 【TCIRC】 d022. AP325 Q-2-13. Exponentiation by Squaring with Irrational Numbers（108 High School National Competition, Simplifed）

**Change File Name** - 【TCIRC】 d020. AP325 P-2-11. The Closest Interval Sum（＊） 

**Solved** - 【TCIRC】 d018. AP325 P-2-9. Subset Product（Halved Enumeration）（@@）

**Solved** - 【TCIRC】 d019. AP325 Q-2-10. Subset Sum（Halved Enumeration）

**Solved** - 【TCIRC】 d020. AP325 P-2-11. The Closest Interval Sum（*）

**Solved** - 【TCIRC】 d016. AP325 Q-2-7. Complementary Teams（APCS201906）

**Opt** - 【TCIRC】 d016. AP325 Q-2-7. Complementary Teams（APCS201906）

**Solved** - 【TCIRC】 d018. AP325 Q-2-8 Modular Multiplicative Inverse

**Modify File Name** - 【TCIRC】 d017. AP325 Q-2-8 Modular Multiplicative Inverse

**Solved** - 【TCIRC】 d015. AP325 P-2-6. Two-Number Problem

**Solved** - 【TCIRC】 d014. AP325 Q-2-5. Exponentiation by Squaring with Fibonacci Numbers

**Solved** - 【TCIRC】 d013. AP325 Q-2-4. Exponentiation by Squaring — Integers Less than 200 Digits

**Modify File Name** - 【TCIRC】 d012. AP325 P-2-3. Exponentiation by Squaring

**Solved** - 【TCIRC】 d012. Exponentiation by Squaring

**Solved** - 【ZeroJudge】 f581. 3. Roundabout Exit

**Solved** - 【TCIRC】 d011. AP325 P-2-2. Discretization – Sort

**Solved** - 【TCIRC】 d009. AP325 Q-1-11. Delete Rectangle Edge — Recursive（APCS201910, Subtask）

**Solved** - 【ZeroJudge】 f640. Function Expression Evaluation

**Solved** - 【CSES】 1163. Traffic Lights

**Solved** - 【AtCoder】 Beginner Contest 330 - E. Mex and Update

**Solved** - 【AtCoder】 Beginner Contest 331 - A. Tomorrow

**Solved** - 【AtCoder】 Beginner Contest 331 - B. Buy One Carton of Milk

**Solved** - 【AtCoder】 Beginner Contest 331 - C. Sum of Numbers Greater Than Me

**Solved** - 【AtCoder】 Beginner Contest 329 - F. Colored Ball

**WA** - 【AtCoder】 Beginner Contest 329 - E. Stamp

**Solved** - 【AtCoder】 Beginner Contest 329 - D. Election Quick Report

**Solved** - 【CSES】 1141. Playlist

**Solved** - 【AtCoder】 Beginner Contest 328 - A. Not Too Hard

**Solved** - 【AtCoder】 Beginner Contest 328 - B. 11.11

**Solved** - 【AtCoder】 Beginner Contest 328 - C. Consecutive

**Solved** - 【AtCoder】 Beginner Contest 328 - D. Take ABC

**Solved** - 【CSES】 1640. Sum of Two Values

**Solved** - 【CSES】 1074. Stick Lengths

**Solved** - 【CSES】 1643. Maximum Subarray Sum 

**solved** - 【CSES】 2216. Collecting Numbers

**solved** - 【CSES】 2183. Missing Coin Sum

**Solved** - 【AtCoder】 Beginner Contest 327 - A. ab

**Solved** - 【AtCoder】 Beginner Contest 327 - B. A^A

**Solved** - 【AtCoder】 Beginner Contest 327 - C. Number Place

**Solved** - 【AtCoder】 Beginner Contest 327 - D. Good Tuple Problem

**Solved** - 【CSES】 1668. Building Teams

**Solved** - 【CSES】 1669. Round Trip

**Solved** - 【ZeroJudge】 b898. 1. Pythagorean Theorem

**Solved** - 【ZeroJudge】 c520. 5. Boss Baodao

**Solved** - 【ZeroJudge】 b899. 2. Item Detect

**Solved** - 【ZeroJudge】 b900. 3. Squirmy Worm

**Solved** - 【CSES】 1636. Coin Combinations II

**Solved** - 【CSES】 1637. Removing Digits

**Solved** - 【CSES】 1158. Book Shop

**Solved** - 【AtCoder】 Educational DP Contest - E. Knapsack 2

**Change Name** - 【AtCoder】 Educational DP Contest - D. Knapsack 1

**Solved** - 【AtCoder】 Educational DP Contest - G. Longest Path

**Solved** - 【AtCoder】 Educational DP Contest - H. Grid 1

**Solved** - 【AtCoder】 Beginner Contest 325 - A. Takahashi San

**Solved** - 【AtCoder】 Beginner Contest 325 - C. Sensors

**Solved** - 【AtCoder】 Beginner Contest 325 - D. Printing Machine

**Solved** - 【AtCoder】 Beginner Contest 325 - E. Our Clients, Please Wait a Moment

**Solved** - 【ZeroJudge】 c518. 3. String Encryption

**Solved** - 【ZeroJudge】 c517. 2. South Bird

**Solved** - 【CSES】 2195. Convex Hull

**Solved** - 【CSES】 2191. Polygon Area

**Solved** - 【CSES】 1673. High Score

**Solved** - 【AtCoder】 Beginner Contest 324 - E. Joint Two Strings

**Solving** - 【AtCoder】 Beginner Contest 324 - F. Beautiful Path

**TLE** - 【AtCoder】 Beginner Contest 324 - F. Beautiful Path

**Solved** - 【AtCoder】 Beginner Contest 324 - F. Beautiful Path

**Solved** - 【AtCoder】 Educational DP Contest - F. LCS

**Change File Name** - 【AtCoder】 Educational DP Contest - A. Frog 1

**Change File Name** - 【AtCoder】 Educational DP Contest - B. Frog 2

**Change File Name** - 【AtCoder】 Educational DP Contest - C. Vacation

**Solved** - 【AtCoder】 Educational DP Contest - D. Knapsack 1

**Solved** - 【Luogu】 P1901. Transmitting Station

**Solved** - 【CF】 APCS Practice Contest - B. Ladder String

**Solved** - 【CF】 APCS Practice Contest - A. ABC5

**Solved** - 【CSES】 2189. Point Location Test

**Opt** - 【CSES】 1646. Static Range Sum Queries

**Solved** - 【CSES】 1629. Movie Festival

**Solved** - 【CSES】 1111. Longest Palindrome

**Solved** - 【CSES】 1619. Restaurant Customers

**Solved** - 【CSES】 1666. Building Roads

**Solved** - 【CSES】 1131. Tree Diameter

**Solved** - 【TIOJ】 1224. Rectangular Coverage Area

**Solved** - 【CSES】 1623. Apple Division

**Solved** - 【AtCoder】 Beginner Contest 182 - A. Twiblr

**Solved** - 【AtCoder】 Beginner Contest 182 - B - Almost GCD

**Solved** - 【AtCoder】 Beginner Contest 182 - C - To 3

**TLE** - 【AtCoder】 Beginner Contest 182 - D. Wandering

**Solved** - 【Green Judge】 d086-2. Settle Accounts

**Solved** - 【TOJ】 628. Komachi

**Solved** - 【AtCoder】 Beginner Contest 314 - D. LOWER

**Solved** - 【TOJ】 630. EatAllLeftMost

**Solved** - 【TOJ】 273. Diamond

**Solved** - 【AtCoder】 Beginner Contest 320 - A - Leyland Number

**Remain 1 WA** - 【AtCoder】 Beginner Contest 320 - D. Relative Position

**Solved** - 【AtCoder】 Beginner Contest 320 - E. Somen Nagashi

**Solved** - 【CSES】 1753. String Matching

**Solved** - 【2023 MD Player Training】 Simulation Contest 1 - A. Fivesteps

**Solved** - 【CSES】 1628. Meet In The Middle

**Solved** - 【AtCoder】 Beginner Contest 318 - A - Full Moon

**Solved** - 【AtCoder】 Beginner Contest 318 - B - Overlapping sheets

**Solved** - 【AtCoder】 Beginner Contest 318 - C - Blue Spring

**Solved** - 【AtCoder】 Beginner Contest 315 - A - Tcdr

**Solved** - 【AtCoder】 Beginner Contest 315 - B - The Middle Day

**Solved** - 【AtCoder】 Beginner Contest 315 - C - Flavors

**Solved** - 【AtCoder】 Beginner Contest 315 - E - Prerequisites

**Solved** - 【CSES】 1190. Subarray Sum Queries

**1/3 WA** - 【AtCoder】 Beginner Contest 317 - E - Avoid Eye Contact

**Solved** - 【AtCoder】 Beginner Contest 317 - D - President

**Solved** - 【AtCoder】 Beginner Contest 317 - A - Potions

**Solved** - 【AtCoder】 Beginner Contest 317 - B - MissingNo

**Solved** - 【AtCoder】 Beginner Contest 317 - C - Remembering the Days

**Solved** - 【2023 MD Player Training】 Simulation Contest 1 - B. Conveyor

**Solved** - 【MDJudge】 B053. Go Alone

**Solved** - 【TIOJ】 1198. 8-puzzle

**15% Solution** - 【2023 MD Player Training】 Simulation Contest 1 - B. Conveyor

**20% Solution** - 【2023 MD Player Training】 Simulation Contest 1 - A. Fivesteps

**Solved** - 【2023 MD Player Training】 Simulation Contest 1 - C. Hsr

**Solved** - 【CSES】 1137. Subtree Queries

**Solved** - 【CSES】 1202. Investigation

**Solved** - 【AtCoder】 Beginner Contest 178 - F - Contrast

**Solved** - 【CSES】 1622. Creating Strings

**Solved** - 【CSES】 2205. Gray Code

**Solved** - 【CSES】 1143. Hotel Queries

**Solved** - 【AtCoder】 Beginner Contest 196 - D - Hanjo

**Solved** - 【AtCoder】 Beginner Contest 152 - D - Handstand 2

**Solved** - 【CSES】 1755. Palindrome Reorder

**Solved** - 【CSES】 1754. Coin Piles

**Solved** - 【CSES】 1618. Trailing Zeros

**Solved** - 【CSES】 1687. Company Queries I

**Solved** - 【CSES】 1688. Company Queries II

**Haven't Finish** - 【CSES】 1734. Distinct Values Queries

**Solved** - 【CSES】 1649. Dynamic Range Minimum Queries

**Haven't Finish** - 【Luogu】 P1313. [ NOIP2011 Improvement Group ] Calculation Coefficient

**Solved** - 【CSES】 1712. Exponentiation II

**Haven't Finish** - 【CF】 1394A. Orac and LCM

**Solved** - 【CSES】 1650. Range Xor Queries

**Solved** - 【ZeroJudge】 d799. Interval Summation

**Solved** - 【AtCoder】 Beginner Contest 119 - C - Synthetic Kadomatsu

**Solved** - 【CSES】 1195. Flight Discount

**Solved** - 【AtCoder】 Beginner Contest 100 - D - Patisserie ABC

**Solved** - 【TOJ】 36. Simple Problem

**Solved** - 【CSES】 1072. Two Knights 

**Solved** - 【CSES】 1161. Stick Divisions

**Solved** - 【CSES】 1630. Tasks and Deadlines

**TLE Answer** - 【AtCoder】 Beginner Contest 100 - D - Patisserie ABC

**Solved** - 【UVa】 441. Lotto

**Seems Like AC, but UVa Was Dead** - 【UVa】 441. Lotto

**Solved** - 【CSES】 1091. Concert Tickets

**Solved** - 【UVa】 291. The House Of Santa Claus

**Solved** - 【CSES】 1635. Coin Combinations I

**Solved** - 【CSES】 1085. Array Division

**Solved** - 【CSES】 1673. High Score

**Solved** - 【CSES】 1672. Shortest Routes II

**Solved** - 【CSES】 1671. Shortest Routes I

**Solved** - 【CSES】 1090. Ferris Wheel

**Solved** - 【Luogu】 P1396. Rescue

**Solved** - 【CSES】 1092. Two Sets

**Solved** - 【CSES】 1670. Swap Game

**Solved** - 【CSES】 1634. Minimizing Coins

**Solved** - 【CSES】 1617. Bit Strings

**Solved** - 【CSES】 1071. Number Spiral

**Solved** - 【TCIRC】 d097. AP325 P-7-10 Pit Jumping

**Solved** - 【AtCoder】 Competitive Professional Typical 90 Questions - 002 - Encyclopedia of Parentheses（★3）

**Solved** - 【CSES】 1624. Chessboard and Queens

**Solved** - 【UVa】 195. Anagram

**TLE Answer** - 【UVa】 195. Anagram

**Solved** - 【ZeroJudge】 e446. Arrangement Generation

**Solved** - 【CSES】 1070. Permutations

**Solved** - 【CSES】 1094. Increasing Array

**Solved** - 【CSES】 1096. Repetitions

**Solved** - 【MDJudge】 C040. Question 10 of the 2020 CIC Quarterfinals

**Solved** - 【ZeroJudge】 a674. 10048 - Audiophobia

**Solved** - 【Luogu】 P1629. Postman Delivering Letter

**Solved** - 【ZeroJudge】 k734. Open Treasure Box

**Solved** - 【CF】 510C. Fox And Names 

**Solved** - 【Luogu】 P1036. [ NOIP2002 Popularization Group ] Selection Number

**Solved** - 【Luogu】 P2677. [ USACO07DEC ] Bookshelf 2 B

**Solved** - 【AtCoder】 Beginner Contest 240 - C - Jumping Takahashi

**Solved** - 【Luogu】 P1100. High and Low Swap

**Solved** - 【TIOJ】 1081. B. Image recognition

**Solved** - 【Kattis】 Playfair Cipher

**Solved** - 【Luogu】 P1352. Prom Without Boss

**50% Solution** - 【TIOJ】 1081. B. Image recognition

**Solved** - 【CSES】 1674. Subordinates

**Solved** - 【Luogu】 P3374［Template］Binary Indexed Tree 1

**Solved** - 【NTFSOJ】 275 Dynamic Median

**Solved** - 【ZeroJudge】 a020. ID Verification

**Solved** - 【CF】 ( 2023 MD Subject Ability Intramural Competition ) E. Stock Analyst

**Solved** - 【CF】 ( 2023 MD Subject Ability Intramural Competition ) B. Tim Chen no Loli Base

**Solved** - 【CF】 ( 2023 MD Subject Ability Intramural Competition ) D. Checkered Arena

**Solved** - 【CSES】 1620. Factory Machines

**Solved** - 【CSES】 1667. Message Route

**Half AC Haven't Solved** - 【CSES】 1085. Array Division

**Solved** - 【AtCoder】 DP Contest - C - Vacation 

**Solved** - 【ZeroJudge】 b844. A Bunch of Buttons

## 2022. 07. 21

**Solved** - 【CSES】 1646. Static Range Sum Queries
