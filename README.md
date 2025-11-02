# CP-Question-Record

### 【UVa】11488. Hyper Prefix Sets

**Solved**

。Trie - $\sum len(S_i)$

* Complexity Analysis
    * Each string insertion ⮕ $len(S)$
    * Total time complexity ⮕ $\sum len(S)$
    * Space complexity ⮕ $\sum len(S)$
* Core Concepts
    * Trie Construction
        * Each input string consists only of binary digits `0` and `1`
        * For every inserted string, traverse the trie character by character
        * Each node represents a unique binary prefix shared among inserted strings
    * Prefix Frequency Counting
        * Each node keeps a counter `val[cnt]` denoting how many strings share that prefix
        * While inserting a string, increment this counter for each visited node
    * Result Tracking
        * The maximum "score" is updated at each step as `res = max(res, (prefix_length) × (prefix_frequency))`
        * This ensures that for every possible prefix, we evaluate the contribution of how long it is and how many strings share it
* Implementation Strategy
  1. Initialization
        * Before each test case, reset the global arrays using `memset`
            * `nxt[MAXN][2]` ⮕ next nodes for `0` and `1`
            * `val[MAXN]` ⮕ prefix count per node
        * Reset counters ⮕ `res = 0`, `amt = 0`
    2. Insertion Function
        * Start from the root node
        * For each character `s[i]` in the current string
            * If the next node doesn’t exist, create it
            * Move to the child node
            * Increment its `val` counter
            * Update the answer `res = max(res, (i + 1) * val[cnt])`
    3. Solve Function
        * Read `n`, the number of binary strings
        * Insert each string using the `insert()` function
        * Output the final `res` after all insertions
* Key Insight
    * The problem leverages trie traversal to simultaneously capture prefix frequency and prefix length
    * The optimal answer emerges from balancing **how deep** the prefix is and **how many strings** share it

### 【UVa】242. Stamps and Envelope Size

**Solved**

。Bounded Knapsack - $N \times M \times S \times V$

* Core Concepts
    * Bounded Knapsack Formulation
        * Each denomination can be used up to `S` times ⮕ bounded
        * Goal ⮕ find the **maximum continuous postage value** that can be formed from value 1 up to some limit without any gap
        * DP state ⮕ `dp[v]` = minimum number of stamps needed to form value `v`
    * Transition
        * For each denomination `arr[t][i]` and each quantity `amt` from 1 to `S`
            * `dp[j] = min(dp[j], dp[j - amt * arr[t][i]] + amt)`
        * Each `dp[v]` records the fewest number of stamps needed to form postage `v`
    * Maximal No-Gap Coverage
        * After filling DP, the smallest postage `i` where `dp[i] > S` means that value `i` cannot be formed with ≤ `S` stamps ⮕ Max coverage = `i − 1`
  * Comparison Rule
        * Sort all denomination sets by
            1. Higher maximal coverage first
            2. Fewer denominations second
            3. Smaller largest denomination third
            4. Lexicographically smaller overall if still tied
* Solution Strategy
    1. Initialize
        * Initialize `dp` with a large constant (`MEMINF`) ⮕ Unreachable
        * Set `dp[0] = 0`
        * Iterate through each denomination and simulate bounded knapsack updates
    2. Coverage Detection
        * Scan from `i = 0` upward until the first `i` such that `dp[i] > S`
        * Record `arr[t][0] = i` as this set’s coverage indicator
    4. Result Selection
        * Sort all sets using `cmp()` according to the above rules
        * Select and print the first set with maximal coverage

> [!NOTE]
> Be careful with the output format

### 【UVa】10819. Trouble of 13-Dots

**Solved**

。0/1 Knapsack - $N \times (M+200)$

* Core Concepts
    * Two Initialization Paradigms
        * *At-most spend* ⮕ don’t need to spend all
            * `val[j]` can be initialized to **0**; result is `max(val[0..limit])` ⮕ **Wrong for this problem** when $M ≤ 2000 < M+200$ states in the **illegal "gap" $(M, 2000]$** can inflate later states and **pollute** valid answers in the refund zone
        * *Exact spend* ⮕ must spend exactly `j`
            * initialize `val[0]=0`, and **all others to `-INF`**. A state `val[j]` becomes valid **only** if `val[j - P[i]]` is valid ⮕ **Use this** to **preserve** all valid totals and avoid cross-contamination from the illegal gap.
    * Transition
        * `val[j] = max(val[j], val[j - P[i]] + D[i])` **iff** `val[j - P[i]] != -INF`
        * Iterate `j` **downward** to enforce 0/1 usage
    * Refund Rule as Split Budget
        * If total **exceeds 2000**, you get **+ 200** refund ⇒ effective cap may extend to $M+200$, but totals in $(M, 2000]$ are **illegal** when $M ≤ 2000$
        * Handle by **DP up to $M + 200$**, then **choose max over valid regions**
* Solution Strategy
    1. DP Setup
        * `val[0] = 0`; for `j>0`, `val[j] = -INF`
        * For each item `(P[i], D[i])`, update `j = M+200 … P[i]`
    2. Why exact-spend init
        * Prevents any value built via **illegal totals** in $(M, 2000]$ when $M ≤ 2000$ from leaking forward and **overwriting** the true optimum in the refund region.
    3. Pick the Answer by Regions
        * Let `cap = M + 200`
            * **Case A: `M > 2000`** ⮕ answer is `max(val[0..cap])`
            * **Case B: `M ≤ 2000` and `M + 200 ≤ 2000`** (i.e., effectively no refund) ⮕ answer is `max(val[0..M])`
            * **Case C: `M ≤ 2000` and `M + 200 > 2000`** ⮕ answer is `max( max(val[0..M]), max(val[2001..cap]) )`. Skip the **illegal gap** $(M, 2000]$
* Key Insight
    * Initializing all `val[j] = 0` (at-most spend) lets **illegal** totals in $(M, 2000]$ spuriously improve `val[j]` for $j > 2000$, **corrupting** the refund-zone optimum.
    * Enforcing **exact-spend validity** (`-INF` init) guarantees each `val[j]` is derived only from **legal** predecessors, so the final **region-based max** yields the correct answer.

### 【UVa】990. Diving for Gold

**Solved**

。0/1 Knapsack + Reconstruction - $N \times T$

* Core Concepts
    * State Definition
        * Let `dp[i][j]` represent the **maximum gold** that can be collected using the first `i` treasures within time `j`
        * Each treasure $i$ has
            * Depth `w[i]`
            * Gold amount `arr[i]`
            * Time cost `3 * k * w[i]` ⮕ descent + ascent
    * Transition Formula
        * If the diver can afford the time cost
            * `dp[i][j] = max(dp[i-1][j], dp[i-1][j - 3*k*w[i]] + arr[i])`
    * Otherwise
        * `dp[i][j] = dp[i-1][j]`
    * Initialization
        * `dp[0][j] = 0` for all `j`, since no treasure can be collected without diving
    * Reconstruction
        * Start from `dp[n][t]` and trace back
        * If `dp[i][j] - arr[i] == dp[i-1][j - 3*k*w[i]]`, treasure `i` was taken
        * Decrease `j` by the corresponding time cost until reaching 0
        * Reverse the collected sequence to restore input order
* Solution Strategy
    1. **Input Parsing**
        * Read total available time `t`, weight factor `k`, and number of treasures `n`
        * For each treasure, store `(depth, gold)` in arrays `w[i]`, `arr[i]`
    2. **DP Table Construction**
        * Iterate `i = 1..n`, and for each time `j = t..0`
        * Update `dp[i][j]` based on whether taking treasure `i` is beneficial
    3. **Traceback**
        * Start from `dp[n][t]` and retrieve which treasures were chosen
        * Store chosen `(w[i], arr[i])` pairs in `ans` and reverse at the end
    4. **Output**
        * Print the maximum gold `dp[n][t]`, number of treasures taken, and the chosen treasures in order
        * Print a blank line between datasets

### 【UVa】10449. Traffic

**Solved**

。Bellman-Ford - $N \times M$

* Core Concepts
    * Each junction has a **busyness value**, where the cost from junction `u` to `v` is defined as $(busyness[v] - busyness[u])^3$
    * If a node’s distance is affected by a **negative cycle**, or if its minimum total earning is **less than 3**, the answer should be `?`
* Solution Strategy
    1. Graph Construction
        * Read `n` and busyness values `arr[1..n]`
        * For each directed road `(u, v)`, compute weight `w = (arr[v] - arr[u])³` and store it in `edge`
        * Build adjacency list `graph` for DFS traversal
    2. Bellman-Ford Relaxation
        * Initialize all distances `dis[i] = INF`, except `dis[1] = 0`
        * Repeat for `n` iterations
            * For each edge with weight `w`, relax `dis[y]` if `dis[x] + w < dis[y]`
            * On the `n`-th iteration, any further relaxation marks `y` as **reachable from a negative cycle**
            * Perform DFS from such nodes to mark all affected nodes as invalid
    3. Query Processing
        * For each query `ask`, print
            * `?` if `!valid[ask]` or `dis[ask] < 3` or `dis[ask] >= INF`
            * Otherwise print `dis[ask]`
* Key Implementation Details
    * `dfs()` is used to propagate invalidity from negative-cycle nodes
    * `trp(x)` computes the cubic cost $x^3$
    * `bell()` performs Bellman-Ford relaxation and detects negative cycles

### 【UVa】11517. Exact Change

**Solved**

。0/1 Knapsack DP - $N \times V$

* Core Concepts
    * Problem Nature
        * Given an item price `val` and `n` coins (each usable **once**), find the **smallest total payment $≥$ val**
        * Among all such payments, also minimize the **number of coins** used
        * This is a **0/1 Knapsack** problem where each coin can either be taken or skipped
    * DP Definition
        * Let `dp[x]` = the **minimum number of coins** needed to make an exact sum of `x` cents
        * Initialize all `dp[x]` as infinity, except `dp[0] = 0`
    * Transition
        * For each coin `c`, iterate `j` **backward** from `MAXN` down to `c` ⮕ `dp[j] = min(dp[j], dp[j - c] + 1)`
        * Backward iteration ensures each coin is only used **once**, satisfying the 0/1 constraint
    * Result Extraction
        * After all coins are processed, scan from `val` upward to find the first achievable amount `i` where `dp[i]` is finite, then output `(i, dp[i])`
* Solution Strategy
    1. Initialization
        * Clear arrays `coin[]` and `dp[]` using `memset` before each test case
        * Set `dp[0] = 0` since no coins are needed to reach total `0`
    2. DP Computation
        * For every coin, update `dp[j]` in descending order to enforce the 0/1 constraint
        * Each update represents taking or not taking that coin

> [!NOTE]
> * The backward loop is the **core of 0/1 knapsack**, preventing a single coin from being reused
> * If the loop ran forward instead, it would become **unbounded knapsack**, which would yield incorrect results for this problem

### 【UVa】10721. Bar Code

**Solved**

。3D Dynamic Programming Precomputation - $N^{3}M$

* Core Concepts
    * **State Definition**
        * Let `dp[i][j][k]` denote the number of possible bar code arrangements that
            * occupy exactly `i` total units
            * use exactly `j` bars
            * with each bar having a maximum width of `k`
        * Bars **alternate colors**, starting with a dark one, so only their widths matter for counting combinations
    * **Base Case**
        * `dp[0][0][x] = 1` for all `x` ⮕ zero total units with zero bars is one valid empty arrangement
    * **State Transition**
        * For each `dp[i][j][k]`, consider the width `x` of the last bar (ranging from $1$ to $min(i,k)$) <br>
            $dp[i][j][k] += dp[i - x][j - 1][k]$
        * Meaning: add one bar of width `x` to all valid configurations of $j−1$ bars occupying $i−x$ units
    * **Computation**
        * Precompute all states for $i, j, k ∈ [1, 50]$ before processing input
        * For each query `(n, m, k)`, output the precomputed value `dp[n][m][k]`
* Solution Strategy
    1. **Initialization**
        * Set all `dp[0][0][i] = 1` for `i` from 0 to 50
    2. **DP Precomputation**
        * Triple nested loops iterate through possible total units, bar counts, and maximum widths
        * Inner loop aggregates transitions by possible final bar widths
    3. **Answer Retrieval**
        * For each input triple `(n, m, k)`, simply print `dp[n][m][k]`

### 【UVa】10128. Queue

**Solved**

。Combinatorics + Dynamic Programming -$N^3$

* Core Concepts
    * **State Definition**
        * Let `dp[n][f][b]` denote the number of permutations of `n` distinct people such that
        exactly `f` people are visible from the **front** and `b` people are visible from the **back**
        * A person is visible from one side if they are **taller** than everyone before them in that direction
    * **State Transition**
        * When adding the shortest person ( height `n` ) into the queue of `n−1` people, there are three possibilities
            1. Place at the **front** ⮕ increases visible count from front by 1
                → `dp[n][f][b] += dp[n−1][f−1][b]`
            2. Place at the **end** ⮕ increases visible count from back by 1
                → `dp[n][f][b] += dp[n−1][f][b−1]`
            3. Place **anywhere in the middle** (positions `2` to `n−1`) ⮕ doesn’t change visible count
                → `dp[n][f][b] += dp[n−1][f][b] * (n−2)`
        * Therefore, $dp[n][f][b] = dp[n−1][f−1][b] + dp[n−1][f][b−1] + (n−2) \times dp[n−1][f][b]$
    * **Base Case**
        * `dp[1][1][1] = 1` since with one person, one is visible from both ends
* Solution Strategy
    1. **Precomputation**
        * Precompute all `dp[n][f][b]` for $1 ≤ n ≤ 13$ using the recurrence above
        * This covers the full constraint range.
    2. **Answer Queries**
        * For each test case `(n, f, b)`, directly output `dp[n][f][b]`
        * Since all values are precomputed, query time is constant

### 【UVa】11228. Transportation System

**Solved**

。Minimum Spanning Tree (Kruskal) - $N^{2}\log{N^2}$

* Core Concepts
    * MST Classification
        * The problem requires building an **optimal transportation system** connecting all cities with minimal total cost
        * Two types of connections
            * **Roads** ⮕ between cities **within the same state**, where distance ≤ `r`
            * **Railroads** ⮕ between cities **in different states**, where distance > `r`
        * A “state” is defined as a connected component formed using only edges ≤ `r`
    * Kruskal’s Algorithm
        * All possible city pairs are inserted into a **min-heap priority queue** based on Euclidean distance
        * The algorithm greedily selects the smallest edge that connects two different components, merging them via **DSU**
    * DSU Structure
        * Each city initially belongs to its own component
        * On combining two components, their roots are updated and sizes merged
        * Used to efficiently track connected components while forming the MST
    * Edge Classification
        * When merging two components
            * If `distance ≤ r`, it contributes to **road length**
            * If `distance > r`, it contributes to **railroad length** and increments the number of **states**
    * Distance Computation
        * Euclidean distance formula <br>
           &nbsp; &nbsp; $\displaystyle dist(A, B) = \sqrt{ (A_x − B_x)^{2} + (A_y − B_y)^{2} }$
        * All edges are precomputed between every pair `(i, j)` to populate the MST edge pool
* Solution Strategy
    1. Input Parsing
        * Read the number of cities `n` and the threshold radius `r`
        * Store all city coordinates in a vector `arr`
    2. Edge Construction
        * For every pair of cities `(i, j)`, compute their distance and push `{distance, {i, j}}` into a **min priority queue**
    3. Kruskal’s MST Construction
        * Initialize DSU with all cities as separate nodes
        * Pop the smallest edge from the queue
        * If the two cities are not already connected, merge them and
            * Add to `road` if `distance ≤ r`
            * Add to `rail` and increment `state count` if `distance > r`
* Notes
    * The MST ensures global minimal total cost under the state constraints
    * The DSU structure avoids forming cycles while efficiently counting state boundaries
    * Final rounding uses `setprecision(0)` to match the required integer output

### 【UVa】13211. Geonosis

**Solved**

。All-Pairs Shortest Path + Reverse Order Processing - $N^3$

* Complexity Analysis
    * Each node addition requires an $N^2$ update
    * Across $N$ nodes, total runtime is $N^3$
* Core Concepts
    * Problem Reformulation
        * We are given a weighted complete directed graph of $n$ towers
        * Towers are destroyed in a fixed order, and after each destruction we must compute the sum of shortest path distances between all remaining towers
        * Equivalent to progressively adding nodes **in reverse destruction order** and maintaining shortest paths
    * Reverse Simulation
        * The destruction order is reversed so that we simulate adding nodes one by one
        * At each step, insert tower `cnt = del[k]` into the current set of nodes
    * Floyd–Warshall Update
        * For each new node `cnt`, update shortest paths
            * `dp[i][j] = min(dp[i][j], dp[i][cnt] + dp[cnt][j])`
        * Ensures all-pairs shortest paths are correctly maintained after the node is included
    * Result Accumulation
        * Keep a list of currently active nodes
        * After each insertion, accumulate the total distance sum
            * `res += sum(dp[u][v])` for all active pairs $(u, v), u ≠ v$
* Solution Strategy
    1. Reverse Order
        * Reverse the destruction order so simulation proceeds as additions
    3. Floyd–Warshall Iteration
        * For each node added, update all pairs shortest paths
    4. Summation
        * For each step, compute and add the sum of shortest paths among currently added nodes

### 【UVa】10655. Contemplation! Algebra

**Solved**

。Matrix Fast Exponentiation - $\log{N}$

* Core Concepts
    * Characteristic Recurrence
        * The sequence satisfies $A_N = S \cdot A_{N-1} - P \cdot A_{N-2}$ with $A_0 = 2$, $A_1 = S$
        * Edge Initialization
            * `n == 0 ⮕ 2`
            * `n == 1 ⮕ sum`
            * Otherwise multiply $M^{N-1}$ by transition matrix
        * Transition matrix 
```math
   \begin{bmatrix} 
       S & -P \\
       1 & 0
   \end{bmatrix}
```
* Solution Strategy
    1. Build Matrices
        * `original = [[sum], [2]]`
        * `ksm = [[sum, -mul], [1, 0]]`
    2. Binary Exponentiation
        * `mpow(ksm, n-1)` computes $M^{N-1}$ with repeated squaring
    3. Final Multiply
        * `original = mat(ksm, original)` and output `original[0][0]`
    4. Input Handling
        * Must use **EOF termination** instead of checking `sum == 0 && mul == 0`
        * This is because valid test cases may include `sum = 0, mul = 0` and should still be processed
* Notes
    * The judge includes cases where both parameters are zero; hence **EOF-driven loop is required**
    * Code uses `long long` via `#define int long long`; overflow is possible if results exceed 64-bit range. For full safety, replace with a wider integer type consistently across all matrix operations

### 【UVa】1665. Islands

**Solved**

。DSU + Offline Query Processing - $NM\log{NM}+Q$

* Complexity Analysis
    * Sorting/Heap insertion of all grid cells by height ⮕ $NM\log{NM}$
    * DSU operations with union-by-rank ⮕ almost $1$ per operation
    * Processing $Q$ queries ⮕ $Q$
    * Total Time Complexity ⮕ $NM\log{NM}+Q$
* Core Concepts
    * Flood Simulation
        * Each cell has a height `arr[i][j]`
        * A cell is flooded if `height <= sea_level`
        * Queries ask the number of **connected unflooded areas** at a given sea level
    * Offline Query Reversal
        * Instead of simulating sea levels **increasing**, process queries in **reverse order**
        * Start from highest sea level and progressively **unflood** cells by lowering threshold
    * DSU for Connected Components
        * Each unflooded cell corresponds to a DSU node
        * When a cell becomes unflooded, connect it with already unflooded neighbors
        * Maintain `amt` = current number of connected components of unflooded areas
* Solution Strategy
    1. Preprocessing
        * Push all grid cells into a priority queue, sorted by height ⮕ descending
    2. Reverse Query Processing
        * Read queries, reverse their order
        * For each query `year = i`, pop all cells with `height > i` from the heap and mark them valid
        * Each new valid cell increases `amt` by 1
        * If any of its 4 neighbors is already valid, merge them in DSU and reduce `amt`
    3. Result Collection
        * Store answers in reverse order while processing queries
        * Reverse `res[]` at the end to restore original query order
    4. Output
        * Print the number of unflooded areas for each query in correct order

### 【UVa】 544. Heavy Cargo

**Solved**

。Maximum Spanning Tree via Kruskal — $M\log{M}$

* Core Concepts
    * City ID Compression
        * Uses `map<string,int> mp` to collect all city names while reading edges, then assigns consecutive IDs before processing
    * Max-Heap of Edges
        * Stores edges as `priority_queue<pair<int, pii>> pq` with items `{ w, {u, v} }`, making the **largest capacity** edge pop first
    * Disjoint Set Union
        * `DSU<int>` with `query(a)` and `comb(a, b)` maintains connected components
        * Union picks parent by smaller representative ID, which is sufficient for constraints
    * Descending Bottleneck via Kruskal
        * Repeatedly take the **maximum** edge and union its endpoints until the components of `s` and `t` become the same
        * The weight `w` of the **edge that first connects** `s` and `t` is the **maximum possible bottleneck capacity** between them
* Solution Strategy
    1. Read & Normalize
        * Read $n, m$ until `0 0`; clear `mp`, `input`, and reset `pq` by swapping with an empty queue
        * For each of the $m$ routes `(u, v, w)`, store as `input.push_back({w, {u, v}})` and mark `mp[u] = mp[v] = 1`
        * After reading all edges, assign IDs to city names by iterating the `map` and writing back `mp[name] = ++no`
    2. Build Max-Heap
        * Convert stored edges into `(w, {mp[u], mp[v]})` and `push` into `pq`
        * Read source and target names `s, t`
    3. Run Kruskal Until Connected
        * In `mst()`, create a fresh `DSU<int>` and repeatedly
            * Pop the largest edge `(w, {u, v})`
            * `dsu.comb(u, v)`
            * If `query(mp[s]) == query(mp[t])`, **return $w$**
* Correctness Sketch
  * Running Kruskal in **descending** order builds a **maximum spanning forest**; the unique path between two nodes in any maximum spanning tree maximizes the **minimum edge** on that path
  * Stopping as soon as `s` and `t` become connected returns exactly that **bottleneck capacity**

### 【UVa】 11420. Chest of Drawers

**Solved**

。Basic DP - $N^2$

* Core Concepts
    * DP State Definition
        * `dp[n][s][0]` ⮕ Number of ways to arrange `n` drawers with exactly `s` secured drawers, when the **top drawer is unlocked**
        * `dp[n][s][1]` ⮕ Number of ways to arrange `n` drawers with exactly `s` secured drawers, when the **top drawer is locked**
    * State Transition
        * If top drawer is **unlocked**
            * It cannot secure itself, so total secure drawers come only from the rest
                `dp[n][s][0] = dp[n-1][s-1][0] + dp[n-1][s-1][1]`
        * If top drawer is **locked**
            * It becomes secured only if the drawer below is also locked, otherwise it contributes nothing
                `dp[n][s][1] = dp[n-1][s][1] + dp[n-1][s+1][0]`
    * Base Cases
        * `dp[0][0][0] = 1` ⮕ No drawers, zero secured, unlocked top is one valid configuration
        * `dp[1][1][0] = 1` ⮕ Single drawer unlocked, secures nothing, only one valid way
        * `dp[1][0][1] = 1` ⮕ Single drawer locked but not secured, still one way
    * Solution Strategy
        1. Precomputation
            * Fill DP table up to `n = 65`, since the problem constraints are small
            * Each entry `dp[n][s][0 or 1]` is built from smaller states
        2. Query Answering
            * For each input `(n, s)`, output `dp[n][s][0] + dp[n][s][1]`
            * This represents total ways with `s` secured drawers regardless of top drawer state
        3. Termination
            * Stop processing when both `n` and `s` are `0`

### 【UVa】1207. AGTC

**Solved**

。LCS - $NM$

* Core Concepts
    * DP State
        * Let `dp[i][j]` represent the **minimum number of operations** required to transform the first $i$ characters of string `s` into the first $j$ characters of string `t`
    * State Transition
        * If `s[i-1] == t[j-1]` ⮕ `dp[i][j] = dp[i-1][j-1]`
        * Otherwise ⮕ `dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1`
            * `dp[i-1][j] + 1` ⮕ Deletion
            * `dp[i][j-1] + 1` ⮕ Insertion
            * `dp[i-1][j-1] + 1` ⮕ Change
    * Base Case
        * `dp[0][j] = j` ⮕ Transforming empty string into `t[0..j]` requires $j$ insertions
        * `dp[i][0] = i` ⮕ Transforming `s[0..i]` into empty string requires $i$ deletions

### 【UVa】10003. Cutting Sticks

**Solved**

。Interval DP - $N^3$

* Core Concepts
    * DP State
        * Let `dp[i][j]` be the **minimum cost** to cut the stick between position `arr[i]` and `arr[j]`
    * Transition
        * For every possible cutting point `k` between `i` and `j`
        * `dp[i][j] = min(dp[i][k] + dp[k][j] + arr[j] - arr[i])`
        * The additional cost `arr[j] - arr[i]` is the current stick length
    * Base Case
        * `dp[i][i] = 0` and `dp[i][i+1] = 0`, since no cut is needed for adjacent positions
    * Input Handling
        * Positions are stored in `arr[]` with `arr[0] = 0` and `arr[n+1] = l` to include both stick ends
* Solution Strategy
    1. Initialization
        * Read stick length `l` and number of cuts `n`
        * Read cutting positions into `arr[1..n]`, and append `0` and `l`
        * Initialize `dp` with large values using `memset`
    2. DP Computation
        * Iterate over all segment lengths from `2` to `n+1`
        * For each interval `(i, i+len)`, try all possible cutting points `k` inside
        * Update `dp[i][i+len]` with the minimum cost
    3. Output
        * Final answer is `dp[0][n+1]`, the minimum cost to cut the full stick

### 【CSES】 1676. Road Construction

**Solved**

。Connected Component - $N+M$

* Core Concepts
    * Connected Components Tracking
        * Maintain `amt` as the current number of connected components
        * Maintain `large` as the size of the largest component
    * DSU Operations
        * `query(x)` ⮕ returns the root of `x`
        * `comb(a, b)` ⮕ merges the two components if their roots differ, updates:
            * parent pointer of one root to the other
            * component sizes via `ARRAY[root].size`
            * `large = max(large, new_size)`
            * `amt--` after a successful merge
* Solution Strategy
    1. Initialization
        * Read `n, m`
        * Build DSU for nodes `1..n` with `fa[i] = i`, `size[i] = 1`
        * Set `amt = n`, `large = 1`
    2. **Process Roads**
        * For each road `(a, b)`
            * Find `faa = query(a)`, `fab = query(b)`
            * If `faa != fab` ⮕ call `comb(a, b)` and decrement `amt`
        * After each road, output `amt` and `large`

### 【CSES】 1675. Road Reparation

**Solved**

。Kruskal MST - $M\log{M}$

* Core Concepts
    * Kruskal’s Algorithm
        * Always pick the next **minimum-weight** edge that connects two **different** components
        * Accumulate the total weight as edges are accepted
    * Disjoint Set Union - DSU
        * `query(x)` ⮕ finds the representative of the set containing `x`
        * `comb(a, b)` ⮕ merges two components and maintains component size
        * `SZ(x)` ⮕ returns the size of the component whose representative is `x`
    * Connectivity Check
        * After processing edges, if the size of the component containing node `1` is not `N`, the graph is **disconnected** ⮕ print `IMPOSSIBLE`
* Solution Strategy
    1. Read Input & Build Min-Heap
        * For each road `(u, v, w)`, push `{w, {u, v}}` into a `priority_queue` so the smallest-weight edge is always on top
    2. Initialize DSU
        * Each node starts as its own parent with size `1`
    3. Kruskal Process
        * While the heap is non-empty
            * Pop the smallest edge `(w, (u, v))`
            * If `query(u) != query(v)`, call `comb(u, v)` and add `w` to `res`
    4. Verify Spanning
        * If `SZ(query(1)) == n`, output `res`
        * Otherwise, output `IMPOSSIBLE`

> [!NOTE]
> * Using a **min-heap** avoids sorting an explicit edge array and still ensures edges are considered in **nondecreasing** order by weight
> * The DSU here tracks component sizes and merges by representative index; it is sufficient for correctness for MST construction
> * The final connectivity check via `SZ(query(1))` guarantees that exactly one component covers all nodes before printing the total MST cost

### 【CSES】 1678. Round Trip II

**Solved**

。DFS - $N+M$

* Core Concepts
    * Component Timestamping
        * Each fresh DFS start assigns a new **timer id**; all nodes visited in that DFS get the same `t[u]`
        * This avoids cross-component interference and lets us recognize **back-edges inside the current DFS component** via `t[v] == t[u]`
    * On-Path Validity
        * Simulates the recursion stack ⮕ nodes currently **active** in the DFS tree have `valid[u] == true`
        * When we finish exploring a node without finding a cycle, set `valid[u] = false` to mark it **off the current path**
    * Successor Link
        * While exploring edges, we set `to[u] = v` to record the **forward pointer** we followed
        * Once a back-edge inside the same component to a **still-valid** node is found, we remember `start = u` and later reconstruct the cycle by walking `to[]`
    * Cycle Detection Rule
        * When scanning `u → v`
            * If `t[v] == t[u]` **and** `valid[v] == true`, we detected a back-edge to an active node ⇒ a directed cycle exists
            * If `t[v] == -1`, continue DFS by labeling `v` with the same timer and set `to[u] = v`
            * If `t[v] != -1` but `v` isn’t active or belongs to another timer then ignore
* Solution Strategy
    1. Input & Graph
        * Read `n, m` and build `edge[1..n]` as a directed adjacency list
    2. Initialization
        * `MEM(t, -1)` to mark all nodes unvisited
        * `MEM(valid, true)` so DFS can flip nodes to inactive upon exit
        * `timer = 0`, `start = 0`
    3. DFS over Components
        * For each node `i` with `t[i] == -1`
            * Set `t[i] = ++timer`, then call `dfs(i)`
            * `dfs(u)` explores all $v ∈ edge[u]$
                * If `t[v] == t[u]`
                    * Set `to[u] = v`
                    * If `valid[v] == true`, a cycle is found ⮕ `start = u`, return `true`
                    * Otherwise mark `valid[u] = false` and continue
            * Else if `t[v] == -1`:
                * Label `v` with `t[u]`, set `to[u] = v`, and recurse; if recursion returns `true`, bubble up success
        * If none succeed, set `valid[u] = false` and return `false`
    4. Reconstruction & Output
        * If `start == 0` ⮕ print `"IMPOSSIBLE"`
        * Otherwise
            * Build `res` by pushing `start`, then repeatedly follow `to[i]` until returning to `start`, and push `start` again
            * Print `res.size()` and the route in order
* Notes
    * The approach **stops at the first cycle** found, which satisfies the problem
    * Nodes are **1-indexed** and multiple disconnected components are handled via the per-component `timer`
    * The `valid[]` flag is crucial-without it, edges to already-finished nodes could be mistaken for on-stack back-edges

### 【CSES】 1680. Longest Flight Route

**Solved**

。DP + DFS - $N + M$

* Core Concepts
    * DAG Longest Path
        * Since the graph is a DAG, **DFS with memoization** yields the longest route length in linear time
    * DP State
        * `dp[x]` = **maximum number of cities** on any valid route starting from city `x` and ending at city `n`
    * Base Case
        * `dp[n] = 1`
    * Transition
        * For `x != n`, iterate all outgoing edges `x -> y`
            * Let `tmp = dfs(y)`
            * If `tmp != 0`, candidate answer is `tmp + 1`
            * Keep the best `y` and record it in `to[x]`
        * If no child leads to `n`, set `dp[x] = 0`
    * Path Reconstruction
        * Start from city `1` and follow `to[i]` until reaching `n`
        * The recorded chain forms one optimal route
* Solution Strategy
    1. Reachability Pre-check
        * Run `check(1)` to mark all nodes reachable from city `1`
        * If city `n` is **not** marked, print `"IMPOSSIBLE"` immediately
    2. DFS + Memoized DP
        * Initialize all `dp[] = -1`
        * Call `dfs(1)` to compute the maximum route length from city `1`
        * Store next-hop decisions in `to[]` when improving `dp[x]`
    3. Output Construction
        * Print `dp[1]` as the number of cities on the longest route
        * Print the chain `1 ⮕ ... ⮕ n` by repeatedly following `to[]`
    4. Correctness Notes
        * The graph is guaranteed **acyclic**, so DFS has no back edges
        * `dp[x]` is computed once due to memoization, ensuring linear complexity
        * The `tmp != 0` guard ensures only paths that actually reach `n` are considered
* Edge Cases
    * No path from `1` to `n` ⮕ Output `"IMPOSSIBLE"`
    * Direct edge `1 -> n` ⮕ Output `2` with route `1 n`
    * Multiple optimal routes ⮕ Any one constructed via `to[]` is acceptable

### 【CSES】 1733. Finding Periods

**Solved**

。Rolling Hash - $N\log{N}$

* Complexity Analysis
    * Prefix hash & power precomputation ⮕ O($N$)
    * Period check over all lengths $L = 1 \cdots N$ with block jumps of size <br>
        &nbsp; &nbsp; $\displaystyle L ⮕ \sum_{L=1}^{N} \lceil N/L \rceil = O(N\log{N})$
    * Total Time Complexity ⮕ O($N\log{N}$)
* Core Concepts
    * Polynomial Rolling Hash
        * The code builds `hsh[i]` as the hash of `str[0...i]`
            * `hsh[0] = str[0]`
            * `hsh[i] = (hsh[i-1] * p + str[i]) % Mod`
        * Powers `ksm[i]` are precomputed to enable concatenation
    * Hash Concatenation
        * If `A` and `B` are strings with hashes `HA`, `HB` and lengths $|A|$, $|B|$, then
        $hash( str(A + B) ) = (HA * p^{|B|} + HB) (Mod M)$
        * The code uses this to **synthesize** the hash of a string formed by repeating the **prefix of length `i`** enough times to reach length $N$
    * Full & Partial Blocks
        * For a candidate period length `i`, it repeatedly appends the prefix-hash `hsh[i-1]` in steps of `i` ( `j += i` ), accumulating into `tmp` using the concatenation rule
        * If the last repetition is **partial** ( i.e., `n` is not a multiple of `i` ), it appends the first `n - j` characters by multiplying `tmp` with $p^{n-j}$ and adding `hsh[n-j-1]`
* Solution Strategy
    1. Input & Precompute
        * Read `str`, set `hsh[0] = str[0]`, `ksm[0] = 1`
        * For `i = 1...n-1`
            * `hsh[i] = (hsh[i-1] * p + str[i]) % Mod`, `ksm[i] = (ksm[i-1] * p) % Mod`
    2. Enumerate Period Lengths
        * For each `i = 1...n`
            * Initialize `tmp = 0`, accumulate full blocks of length `i`
                * `tmp = (tmp * ksm[i] + hsh[i-1]) % Mod` while `j += i` stays `<= n`
            * If there is a remainder `r = n - (j - i)` ( i.e., `j != n` ), append the **partial** prefix
                * `tmp = (tmp * ksm[r] + hsh[r-1]) % Mod`
* Correctness Intuition
    * If the string `S` can be generated by repeating its first `i` characters ( with a possibly partial final block ), then the **hash of that generated string** must equal the **hash of `S`** under the same polynomial base and modulus. The construction uses exact polynomial concatenation rules, so equality of constructed hash and `hsh[n-1]` certifies `i` as a period ( modulo negligible collision probability )


### 【CSES】 1196. Flight Routes

**Solved**

。K-shortest Paths - $NK\log{NK}$

* Core Concepts
    * **Multi-visit Dijkstra Idea**
        * Unlike classic Dijkstra, here each node can be **finalized up to $k$ times** ⮕ once per distinct shortest route to that node
        * Every time we pop `(cnt, u)` from `pq`, if we haven’t already collected enough costs for `u`, we **append `cnt` to `res[u]`** and relax all outgoing edges
* Correctness Notes
    * The priority queue ensures routes are explored by **nondecreasing total cost**; thus each time we append to `res[u]` we are fixing the next shortest route to `u`
    * Because the problem allows revisiting cities and counts equal-price routes separately, the algorithm **does not deduplicate** ⮕ it records every popped cost in order
    * Important guard condition (Line 82) must be `>`
        * Using `==` or `>=` can drop a valid answer in corner cases due to the initial seeding `res[1].pb(0)` and the timing of when the k-th entry is appended. Keeping it as `>` ensures the k-th shortest path to any node (especially the target) is not skipped
* Edge Cases Covered
    * Multiple routes with the **same total price** are preserved because every popped state for a node is appended to `res[u]`
    * Cycles are harmless ⮕ costs grow monotonically along a path, and the guard prevents infinite recording once we have enough entries per node

### 【CSES】 1735. Range Updates and Sums

**Solved**

。Lazy Segment Tree - $(N+Q)\log{N}$

* Core Concepts
    * **Two lazy tags per node**
        * `tag` ⮕ pending **range add**
        * `val` ⮕ pending **range assign**
        * Effective segment sum on demand ⮕ `rv()`
            * If `val == 0` ⮕ `sum + len * tag`
            * Else ⮕ `len * val + len * tag`
    * **Propagation precedence**
        * **Assign overrides everything below**
            * When pushing, if parent has `val != 0`, children get `val = parent.val` and their add-tag becomes **exactly** `parent.tag`
        * If only an add is pending, it is **accumulated** into children’s `tag`
    * **Sum maintenance strategy**
        * Node’s `sum` is updated **lazily** via `rv()` and during `push()`
        * On covering updates, only tags are set; recomputation uses `rv()` to avoid forced descents
* Implementation Strategy
    1. **Data structure**
        * `struct Node { len, sum, tag, val; int rv(); }`
        * Global `seg[4 * MAXN]`, `arr[]`
    2. **Build**
        * `build(L,R,x)` sets `len` and leaf `sum`, and aggregates `sum` upward
    3. **Lazy propagation**
        * `push(x)` applies the current node’s lazy to its children with the precedence rules above, fixes `seg[x].sum = seg[x].rv()`, then clears `val` and `tag`
    4. **Operations**
        * **Range add** ⮕ `modifyA(L,R,mL,mR,val,x)`; On full cover, do `seg[x].tag += val`; else `push()` and recurse, then set `seg[x].sum = seg[nL].rv() + seg[nR].rv()`
        * **Range assign** ⮕ `modifyB(L,R,mL,mR,val,x)`; On full cover, do `seg[x].val = val; seg[x].tag = 0`; else `push()` and recurse, then aggregate with `rv()`
        * **Range sum** ⮕ `query(L,R,qL,qR,x)` On full cover, return `seg[x].rv()`; otherwise `push()` and sum children
* Notes & Edge Considerations
    * Sentinel for **no assign** ⮕ `val == 0`. This is valid under the problem constraints because we never need to assign zero.
    * Correctness of precedence ⮕ a parent **assign** wipes children’s pending ops and replaces them with the parent’s `val` and `tag`. A parent **add** is simply accumulated into children’s `tag`.
    * Avoids pushing on fully covered ranges, relying on `rv()` to return the correct contributed sum without materializing children.

### 【CSES】 2206. Pizzeria Queries

**Solved**

。Segment Tree with Two Linear Transforms — $(N + Q)\log{N}$

* Core Concepts
    * Absolute value split
        * For a fixed destination $k$, the delivery cost from $i$ is <br>
            $p_i + |i - k| =$ <br>
            &nbsp; &nbsp; $\Longrightarrow ( p_i + i ) - k,$ &nbsp; $i \ge k$ <br>
            &nbsp; &nbsp; $\Longrightarrow ( p_i - i ) + k,$ &nbsp; $i \le k$ <br>
        * Hence the answer is <br>
            &nbsp; &nbsp; $\min \displaystyle \Big( \min_{i \in [k, n] }(p_i + i) - k,$ &nbsp; $\displaystyle \min_{i \in[1 , k]}(p_i - i ) + k \Big)$
    * Two segment trees
        * Maintain minima of $p_i + i$ (right side) and $p_i - i$ (left side)
        * Point updates at $i = k$ change both maintained values
    * Implementation detail in code
        * The **left** tree stores $p_i - i$ implicitly as `downward[i] = p_i + (n-i-1)` and later subtracts $(n-k-1)$
        * This is algebraically identical <br>
            &nbsp; &nbsp; $\min(p_i + n - i - 1) - n + k + 1 = \min(p_i - i) + k$
* Solution Strategy
    1. Build
        * Construct two segment trees over indices $[1..n]$
            * `upward` stores $(p_i + i)$
            * `downward` stores $(p_i + n - i - 1)$ to emulate $(p_i - i)$
    2. Point Update (`1 k x`)
        * Set $p_k \leftarrow x$
        * Update leaf $k$ in both trees
            * `upward[k] = x + k`
            * `downward[k] = x + n - k - 1`
        * Recompute mins on the path to root
    3. Query (`2 k`)
        * Right side ⮕ `min_up = min(upward[k..n]) - k`
        * Left side ⮕  `min_down = min(downward[1..k]) - n + k + 1`  ⮕ equals $\min(p_i - i) + k$
        * Answer ⮕ `min(min_up, min_down)`
* Correctness Sketch
    * For any $k$, splitting by $i \ge k$ and $i \le k$ is exhaustive and disjoint
    * Each half transforms the absolute value into a linear form; taking range minima yields the optimal source index on that side
    * Taking the minimum of the two sides gives the global minimum cost

### 【CSES】 1734. Distinct Values Queries

**Solved**

。Mo’s Algorithm + Coordinate Compression - $(N+Q)\sqrt{N}$

* Complexity Analysis
    * Sorting Queries ⮕ $Q\log Q$
    * Pointer Moves ⮕ Each step changes `l` or `r` by 1 with O($1$) updates; amortized total $(N+Q)\sqrt{N}$
* Core Concepts
    * Coordinate Compression
        * Values can be up to $10^9$; compress each $x_i$ to its rank in the sorted unique list so we can index a frequency array `amt[]` in O($1$)
    * Mo’s Algorithm ⮕ Offline
        * Each query `[a, b]` is processed after sorting all queries by **block of `a`**, where block size $k = \lfloor \sqrt{N} \rfloor$ and then by `b`
        * Maintain a sliding window `[l, r]` and a running answer `cnt` $=$ number of values with frequency $> 0$ in the window
    * Add and Delete Operations
        * `add(pos)` ⮕ increase `amt[arr[pos]]`; if it goes from 0 to 1, increase `cnt`
        * `del(pos)` ⮕ decrease `amt[arr[pos]]`; if it goes from 1 to 0, decrease `cnt`
* Solution Strategy
    1. Read & Compress
        * Read array, copy to a temp vector, sort & unique, then remap each `arr[i]` to 1…`D`
    2. Build Queries
        * For each query `(a, b)`, store `(a-1, b-1, id)` to use 0-based indices
    3. Sort for Mo
        * Sort by `(a / k, b)` where $k = \lfloor \sqrt{N} \rfloor$
    4. Sweep the Window
        * Initialize `[l, r]` to the first query’s left, include that element
        * For each sorted query, move `l` and `r` using `add()` and `del()` until the window equals `[a, b]`
        * Store `cnt` into `res[id]`
    5. Output
        * Print answers in original query order
* Correctness Invariants
    * At any time, `cnt = |{ v : amt[v] > 0 }|` over the current window
    * Only `add()` and `del()` change `amt[]`; transitions keep the invariant true as the window changes by $±1$ at the ends
* Edge Cases & Implementation Notes
    * Indexing ⮕ Convert input queries to 0-based before storing

### 【CSES】 3421. Distinct Values Subsequences

**Solved**

。Combinatorics + Frequency Counting - $N\log{N}$

* Core Concepts
    * Distinct-in-subsequence constraint
        * A valid subsequence may include **at most one occurrence of each value**
        * If a value $v$ appears $c_v$ times, then when $v$ is chosen to appear in a subsequence, there are **$c_v$ choices** for which occurrence to use
    * Product-sum identity
        * For each distinct value $v$, you either **skip** it or **pick** it
        * Independent choices across values multiply <br><br>
            $\Longrightarrow \displaystyle \prod_{v}(c_v+1)$
          <br>
        * Subtract the empty choice to exclude the empty subsequence <br><br>
            $\Longrightarrow \displaystyle \boxed{\sum_{\text{valid subseq}} 1 = \prod_{v}(c_v+1) - 1}$
          <br>
* Solution Strategy
    1. Frequency Count
        * Read the array and compute multiplicities $c_v$ for each distinct value using a hash map or ordered map
    2. Multiplicative Accumulation
        * Initialize `res = 1`
        * For every distinct value with count `c`, update `res = res * (c + 1) % Mod`
    3. Exclude Empty Subsequence
        * Output `(res - 1 + MOD) % Mod` to avoid negative underflow
      
### 【CSES】 2136. Hamming Distance

**Solved**

。Bitmask - O($N^2$)

* Core Concepts
    * Bit Encoding
        * Each length-$k$ bit string fits in a 32-bit integer
        * convert input lines into masks
    * Hamming via XOR
        * For two masks `a` and `b`, `__builtin_popcount(a ^ b)` equals their Hamming distance
    * Running Minimum
        * Maintain a global minimum `res`

### 【CSES】 3226. Subarray Sum Queries II

**Solved**

。Segment Tree - $Q\log{N}$

* Core Concepts
    * Segment Tree with Custom Node Structure
        * Each node stores
            * `sum` ⮕ total sum of the range
            * `pre` ⮕ maximum prefix sum in the range
            * `suf` ⮕ maximum suffix sum in the range
            * `ans` ⮕ maximum subarray sum in the range
        * Merge two segments `L` and `R` with
            * `pre = max(L.pre, L.sum + R.pre)`
            * `suf = max(R.suf, R.sum + L.suf)`
            * `sum = L.sum + R.sum`
            * `ans = max(L.ans, R.ans, L.suf + R.pre)`
    * Query Processing
        * For each query $[a, b]$, return the `ans` field in the corresponding segment
        * Return `max(0, ans)` to account for the empty subarray possibility
* Solution Strategy
    1. Segment Tree Initialization
        * Read the array of size $N$
        * Build the segment tree in O($N$) using recursion
    2. Query Evaluation
        * For each query $[a, b]$
            * Recursively evaluate the maximum subarray sum in the range using the segment tree
            * Print `max(0, result.ans)` for each query
    3. Node Merge Logic
        * Carefully combine child nodes to maintain accurate prefix, suffix, and maximum subarray sums
        * This is similar to combining states in the classic **Kadane’s algorithm**, but within a tree structure

### 【CSES】 1750. Planets Queries I

**Solved**

。Binary Lifting - $Q\log{K}$

* Core Concepts
    * Binary Lifting
        * Precompute a table `fa[i][j]` where `fa[i][j]` stores the $2^j$-th ancestor
        * Allows efficient jump-by-power-of-two strategy to simulate $K$ teleportations in $\log{K}$
    * Jump Simulation
        * For each query $(X, K)$
            * Starting from $X$, repeatedly jump to `fa[x][j]` while $2^j \leq K$
            * Subtract the corresponding power of two from $K$ at each step
* Solution Strategy
    1. Binary Lifting Table Construction
        * For each $j$ from 1 to 30
            * Compute `fa[i][j] = fa[ fa[i][j-1] ][j-1]` for all $i$
            * This ensures $2^j$ jumps can be simulated by two $2^{j-1}$ jumps
    2. Query Answering
        * For each query $(x, k)$
            * From the highest power of 2 downward, jump whenever $k \geq 2^j$
            * Update $x$ $=$ `fa[x][j]`, and reduce $K$ by $2^j$
        * Output the final value of $X$
     
### 【CSES】 3304. Visible Buildings Queries

**Solved**

。Monotonic Stack + Binary Lifting - $N\log{N}$

* Complexity Analysis
    * Monotonic Stack Preprocessing ⮕ $N$
    * Binary Lifting Table Construction ⮕ $N\log{N}$
    * Each Query ⮕ $\log{N}$
    * Total Time Complexity ⮕ $N\log{N}$ $+$ $Q\log{N}$
* Core Concepts
    * Monotonic Stack
        * Used to compute, for each building, the **next building to the right** that is taller
        * This allows us to define a jump pointer to the next visible building
    * Binary Lifting
        * Build a `fa[i][j]` table where `fa[i][j]` is the $2^{j-1}$-th next visible building from `i`
        * Enables jumping across multiple visible buildings in $\log{N}$ time
        * Be cautious ⮕ **binary lifting should not be combined with binary search** in this context, or it will degrade performance and result in TLE
* Solution Strategy
    1. Preprocessing - Monotonic Stack
        * Traverse from left to right
        * For each building `i`, assign `fa[prev][1] = i` for any shorter building `prev` on the stack
        * Stack maintains a decreasing sequence of building heights
    2. Binary Lifting Table
        * Fill `fa[i][j] = fa[fa[i][j−1]][j−1]` for all `j > 1`
        * Each `fa[i][j]` represents the $2^{j-1}$-th visible building from `i`
    3. Answering Queries
        * Start from index `a` and repeatedly jump via the highest possible `fa[a][j]` that stays within range `b`
        * For each valid jump, increment visible building count by $2^{j−1}$
        * Stop once next jump exceeds `b` or becomes invalid
* Key Observations
    * Unlike normal LCA or jump pointer use cases, we must **strictly stay within the query range $[a, b]$**
    * Precomputed `fa[i][j]` allows jumping in powers of two without revisiting intermediate nodes
    * This method guarantees each query runs in $\log{N}$, even for large $Q$

> [!NOTE]
> Binary lifting should **NOT** be combined with binary search in this problem
> It would increase query complexity and cause **TLE** for large inputs. Stick to pure top-down greedy jump pointer traversal


### 【CSES】 3426. Sliding Window Xor

**Solved**

。Bitwise XOR + Sliding Window Technique - $N$

* Core Concepts
    * Prefix-Free Property of XOR
        * XOR is both associative and invertible: $A \oplus A = 0$
        * Hence, removing the leftmost and adding the rightmost element via XOR yields the next window's result efficiently
* Solution Strategy
    1. Input Parsing & Sequence Generation
        * Read input parameters $n, k, x, a, b, c$
        * Construct the array `arr` of length $N$ using the recurrence rule
    2. Initial Window XOR
        * Compute the XOR of the first $K$ elements and store it in `res`
    3. Sliding Window XOR Updates
        * Maintain a `cnt` variable representing the XOR of the current window
        * For each step $i$ from $K$ to $N - 1$, update `cnt` by removing `arr[i - k]` and adding `arr[i]`
        * Update the global `res` by XORing `cnt`
    4. Final Output
        * Print the XOR of all window xors

### 【CSES】 2166. Prefix Sum Queries

**Solved**

。Segment Tree with Lazy Propagation - $(N + Q)\log{N}$

* Core Concepts
    * Prefix Sum Preprocessing
        * Compute `pre[i] = A[1] + A[2] + ... + A[i]` so that prefix queries become range queries over `pre[]`
    * Segment Tree
        * Store the prefix sum array in a Segment Tree
        * Each node holds the **maximum value** in its segment, along with a **lazy tag** to enable fast updates
    * Lazy Propagation
        * Updates to `A[k]` affect `pre[i]` for all $i \ge k$
        * So we perform **range additions** to the segment `[k, n]` with the delta `u - A[k]`
* Solution Strategy
    1. Precompute Prefix Sums
        * Initialize `pre[i] = pre[i-1] + A[i]`
    2. Build Segment Tree
        * Each leaf stores `pre[i]`
        * Internal nodes store the max of their children's values
    3. Update Query
        * To update `A[k]` to `u`, compute delta = `u - A[k]`
        * Apply this delta to the range `[k, n]` in the Segment Tree using lazy propagation
        * Update `A[k] = u`
    4. Max Prefix Sum Query
        * Query the maximum in `pre[a..b]`
        * If $a > 1$, subtract `pre[a-1]` to get max prefix sum starting at $a$
        * Take `max(0, result)` as the answer

> [!NOTE]
> This problem reduces to range maximum queries and range additions on a prefix sum array, making lazy Segment Tree a perfect fit.

### 【CSES】 1144. Salary Queries

**Solved**

。Discretization + Segment Tree - $Q\log{N}$

* Complexity Analysis
    * Coordinate Compression ⮕ $(N+Q)\log(N+Q)$
    * Segment Tree Operation ⮕ $\log(N+Q)$ Per Operation
    * Total Time Complexity ⮕ $(N+Q)\log(N+Q)$
* Core Concepts
    * Segment Tree
        * Maintain a frequency count of the compressed salary values
        * Supports both point updates and range sum queries
    * Coordinate Compression
        * Due to the large salary range ($1 \sim 10^9$), directly using salary values as segment tree indices is infeasible
        * Instead, all distinct salary values are collected and compressed into a smaller range
        * This reduces memory usage and avoids TLE from sparse mapping
    * TLE Avoidance
        * **Do not use `map` or `unordered_map`** for dynamic coordinate mapping during query time ⮕ it is too slow
        * Preprocess all possible salary values before building the segment tree
* Solution Strategy
    1. Input Preprocessing
        * Read all salaries into `arr[1..n]`
        * For each query, if it is an update `! k x`, store the `x`
        * If it is a query `? a b`, store both `a` and `b`
        * Merge all these values into a temporary array for compression
    2. Coordinate Compression
        * Sort and deduplicate the temporary array
        * Map each salary to its compressed index using `lower_bound`
    3. Segment Tree Initialization
        * Build a segment tree on the compressed salary indices
        * For initial salaries, increment frequency at corresponding compressed index
    4. Query Handling
        * For `? a b` ⮕ compress both `a` and `b`, then query the segment tree in that range
        * For `! k x` ⮕ decrement frequency at previous salary of employee `k`, and increment at new salary `x` after compression
    5. Output
        * For each `?` query, output the count of employees with salary in range

> [!NOTE]
> Due to tight time constraints, this problem **must** avoid STL structures like `map` or `set` for frequency management
> Segment Tree + Coordinate Compression is the optimal and accepted approach

### 【CSES】 1749. List Removals

**Solved**

。BIT + Binary Search - O($N\log{N}$)

* Core Concepts
    * Binary Indexed Tree
        * BIT is used to efficiently maintain which indices are still `alive`
        * Each index in BIT starts with a value of 1, which stands for alive
        * On removal, we decrement that index’s value in BIT to mark it as removed
    * Order Statistics via BIT
        * To find the $k$-th remaining element, we use a custom binary search `LowerB(k)` on the prefix sums of BIT
        * This simulates the process of removing the $k$-th alive number from the dynamic array
* Solution Strategy
    1. BIT Initialization
        * Read array `arr[1..n]` and update BIT with `1` at each index to indicate all elements are initially alive
    2. Process Removals
        * For each removal query `q`, do the following
            1. Find index `idx = bit.LowerB(q)` ⮕ this is the $q$-th alive number
            2. Print `arr[idx]`
            3. Mark it as removed via `bit.update(idx, -1)`
    3. Output the sequence of removed elements

### 【CSES】 1652. Forest Queries

**Solved**

。2D Prefix Sum - O( max($N^2$, $Q$) )

* Core Concepts
    * 2D Prefix Sum Array
        * Let `pre[i][j]` denote the total number of trees in the rectangle from $(1,1)$ to $(i,j)$
        * This is built using the recurrence
            ```
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + (grid[i][j] == '*' ? 1 : 0);
            ```
    * Fast Rectangle Sum Query
        * For any rectangle $(a, b)$ to $(c, d)$, compute
            ```
            pre[c][d] - pre[c][b-1] - pre[a-1][d] + pre[a-1][b-1];
            ```
        * This formula ensures constant-time answering of each query after preprocessing
* Solution Strategy
    1. Input Parsing
        * Read the grid and initialize the prefix sum matrix `pre`
    2. Prefix Sum Construction
        * Iterate through each cell and build `pre[i][j]` based on the surrounding values and current cell's content
    3. Query Answering
        * For each query, use the precomputed `pre[][]` to return the count of trees in the given rectangle in O($1$)

### 【CSES】 1651. Range Update Queries

**Solved**

。Segment Tree with Lazy tag - O($max(N, Q)\log{N}$)

* Core Concepts
    * Segment Tree with Lazy tag
        * Each node in the segment tree maintains
            * `val` ⮕ the actual sum of the segment
            * `tag` ⮕ the lazy tag value
            * `len` ⮕ the length of the segment
        * When applying a range update, update the `tag` and defer actual computation until the node is accessed
    * Push Operation
        * Before any child query or update, propagate the lazy value down to children
        * This ensures correctness without unnecessary recalculation
    * Query Logic
        * When querying a point $k$, we perform a recursive query with lazy tag to get the correct updated value
    * Update Logic
        * To update $[a, b]$, recursively add to the tags of overlapping segments
        * When moving back up, calculate new values from the children's updated values
* Solution Strategy
    1. Segment Tree Initialization
        * Read the initial array of $N$ elements
        * Build the segment tree bottom-up with each node maintaining its sum and length
    2. Lazy Range Update
        * For update operation `1 a b u`, call `modify()` on the segment tree to lazily add $u$ to all nodes in range $[a, b]$
        * Accumulate updates in `tag` to delay computation until required
    3. Point Query
        * For query `2 k`, call `query()` on the segment tree to retrieve the true value at position $k$ using lazy tag
    4. Efficiency
        * Ensures all $Q$ operations run efficiently within O($\log{N}$) per query and update by using lazy tag
        * Handles large value ranges due to use of `long long`

### 【CSES】 1743. String Reorder

**Solved**

。Greedy + Character Frequency Validation - O($N$)

* Core Concepts
    * Feasibility Condition
        * A necessary and sufficient condition for a valid reordering is $\text{max character frequency} \leq \left\lceil \frac{n}{2} \right\rceil$
        * If one character appears more than half the length of the string (rounded up), it's impossible to place it without having two adjacent duplicates
    * Greedy Strategy
        * At each step, try to **place the lexicographicall smallest possible character lexicographically** that
            1. Different from the previously placed character
            2. Leaves the remaining multiset still valid
* Solution Strategy
    1. Character Frequency Map
        * Build a frequency map `mp[ch]` of all characters in the input string
    2. Feasibility Check
        * Before placing any character, verify that no character appears more than $\left\lceil \frac{n}{2} \right\rceil$ times
        * Re-check this condition **after every character placement** to ensure future rearrangements are still valid
    3. Lexicographically Minimal Placement
        * Iterate over characters from `'A'` to `'Z'`
        * For each character
            * Skip if it's the same as the previously placed character
            * Try to place it, tentatively reduce its count
            * Check if the remaining characters still satisfy the feasibility condition
            * If yes, commit the placement; otherwise, backtrack and try the next smallest character
    4. Termination
        * Continue until all characters are placed
        * If no valid character can be placed at some point, output `-1`

### 【CSES】 1079. Binomial Coefficients

**Solved**

### 【CSES】 2134. Path Queries II

**Solved**

。Heavy-Light Decomposition + Segment Tree - O($Q\log{\log{N}}$)

* Complexity Analysis
    * HLD Build ⮕ O($N$)
    * Segment Tree Build ⮕ O($N$)
    * Modify Query ⮕ O($\log{N}$)
    * Max on Path Query ⮕ O($\log{\log{N}}$)
    * Total Time Complexity ⮕ O($Q\log{\log{N}}$)
* Core Concepts
    * Heavy-Light Decomposition
        * Decompose the tree into multiple paths, or you can say `chains`,  such that each path has a heavy edge from parent to child with largest subtree size
        * Enables path queries to be broken into O($\log{N}$) segments
        * Each node is assigned a unique ID in a DFS-like order, so that segment tree operations can be performed on IDs
    * Segment Tree
        * Supports point update and range maximum queries in O($\log{N}$)
        * After HLD decomposition, a segment tree is built over the IDs to maintain values of the nodes
    * Path Queries
        * To query max on the path from $a$ to $b$, repeatedly lift the deeper node to the higher chain head using segment tree queries on intervals of node IDs
        * Once on the same chain, query directly on the segment between IDs of $a$ and $b$

> [!NOTE]
> * This problem is tight on time complexity constraints.
> * Be sure to
>   * Add `ios::sync_with_stdio(0); cin.tie(0);`
>   * Avoid using `long long` unless strictly necessary, you can use `int` instead
>   * Add `#pragma GCC optimize("O3")` for performance optimization

### 【CSES】 1130. Tree Matching

**Solved**

。Tree DP - O($N$)

* Core Concepts
    * Tree DP
        * For each node, maintain a pair `dp[node] = {not_used, used}`
            * `not_used` ⮕ max matching size if current node is **not** matched
            * `used` ⮕ max matching size if current node is **matched with one of its children**
        * Transition
            1. For each child, recursively calculate its DP values
            2. Aggregate total value `res` as sum of `max(dp[child].F, dp[child].S)` for all children
                * This assumes the current node is not used
            3. Try to match the current node with **one of its children**, and calculate the gain from switching that child to unmatched:
                * Gain = `res - max(dp[child].F, dp[child].S) + dp[child].F + 1`
                * Store the **best gain** across all children
            4. `dp[node] = { res, res - best_dif + 1 }`
* Solution Strategy
    1. Tree Construction
        * Use an adjacency list to store the undirected edges
    2. DFS Traversal
        * Start from the root
        * For each node, apply the recursive DP strategy
        * At leaf nodes, return `{0, 0}` since no matching is possible
* Edge Case
    * Single-node tree → No edges → Matching size is 0
* Final Remark
    * Elegant use of bottom-up recursion and greedy selection embedded inside dynamic programming on tree structures


### 【CSES】 1132. Tree Distances I

**Solved**

。Tree Diameter + Double DFS - O($N$)

* Problem Summary
    * You are given an unweighted tree with $N$ nodes
    * For each node, find the **maximum distance to any other node**
* Core Concepts
    * Tree Diameter
        * The longest path in a tree is called its **diameter**
        * For any node, its farthest distance is either from one end of the diameter or the other
    * Double DFS Technique
        * First DFS from any node to find one endpoint of the diameter
        * Second DFS from `start` to find the opposite endpoint
    * Distance Propagation
        * Do two additional DFS traversals
            * `dfs(start)` computes distance from one end
            * `dfs(end)` computes distance from the other end
        * For each node, take the **maximum** of the two distances as the final answer
* Key Observations
    * In an unweighted tree, the farthest node from any node always lies on the tree’s diameter
    * By taking max distance from both ends of the diameter, we ensure correctness for all nodes

### 【CSES】 1648. Dynamic Range Sum Queries

**Solved**

### 【AtCoder】 DP Contest - Q. Flowers

**Solved**

。Segment Tree + DP - O($N\log{N}$)

* Core Concepts
    * DP State
        * Let `dp[h]` denote the **maximum sum of beauties** achievable for an increasing subsequence ending at height `h`
    * Transition
        * For each flower `i` with height `h[i]` and beauty `a[i]`
            * Query the maximum `dp[k]` for all `k < h[i]`
            * Then set `dp[h[i]] = max(dp[h[i]], dp[k] + a[i])`
        * This ensures only increasing height subsequences are formed
    * Segment Tree Optimization
        * Use a **segment tree** to maintain `dp[]` and perform
            * `query(1, h[i])` ⮕ get max dp value of all lower heights
            * `update(h[i], dp[h[i]])` ⮕ update dp value at current height
        * Since $1 \leq h[i] \leq N$, we can use a segment tree of size $N$
* Solution Strategy
    1. Read input arrays `h[]` and `a[]`
    2. For each flower `i = 0` to `n - 1`
            * Query `max(dp[1..h[i]-1])` from segment tree
            * Compute new `dp[h[i]] = max(dp[h[i]], query + a[i])`
            * Update the segment tree at `h[i]` with the new value
  3. Final answer is the max value in the segment tree

> [!NOTE]
> * The height values are **unique and within $[1, N]$**, which allows direct use as segment tree indices
> * Segment tree is initialized with all values 0, as base DP values are 0 before any flower is chosen

### 【UVa】1521. GCD Guessing Game

**Solved**

。Mathematics + Greedy - O($N$) Preprocessing + O( phi($N$) ) Per Query

* Core Concepts
    * If the response to a guess $x$ is `gcd(x, p) = d`, then Paul's age is a multiple of $d$
        * If $d = 1$ ⮕ age is coprime with $x$, eliminates all multiples of $x$
        * If $d > 1$ ⮕ age is a multiple of $d$, and lies in a smaller set of candidates
    * So, guessing larger composite numbers can reduce the search space more effectively
* Strategy Reformulation
    * Suppose we know the set of prime numbers $\leq N$
    * Try to pair primes $(p\_i, p\_j)$ such that $p\_i \cdot p\_j \leq N$ to eliminate multiple candidates in one query
        * This pairing is critical to reducing the number of queries ⮕ one query might eliminate two or more possibilities
    * If two primes can't be paired, i.e., $p\_i \cdot p\_j > N$ for all remaining $p\_j$, then they must be tested individually
* Solution Strategy
    1. For each input $N$
        * Get all primes $\leq N$
        * Use **two pointers** $(l, r)$ from both ends of the prime list
            * If $p\_l \cdot p\_r \leq n$ ⮕ pair them, count 1, move both pointers
            * Else ⮕ test $p\_r$ alone, count 1, move right pointer
        * Total count is the number of worst-case queries needed

### 【AtCoder】 DP Contest - I. Coins

**Solved**

。DP - O($N^2$)

* Core Concepts
    * DP State Definition
        * Let `dp[i][j]` represent the **probability** that after tossing the first $i$ coins, **exactly $j$ heads** appear
    * Base Case
        * `dp[1][0] = 1 - p[1]` ⮕ First coin is tail
        * `dp[1][1] = p[1]` ⮕ First coin is head
    * State Transition
        * When processing coin $i$
            * `dp[i][j] = dp[i-1][j] * (1 - p[i]) + dp[i-1][j-1] * p[i]`
                * Coin $i$ is tail ⮕ stay at $j$ heads
                * Coin $i$ is head ⮕ move from $j - 1$ to $j$ heads
    * **Final Result**
        * Sum over all `dp[N][j]` for $j > N/2$
* Solution Strategy
    1. DP Initialization
        * Initialize `dp[i][j] = 1.0` for all $i, j$
        * Set base cases for `dp[1][0]` and `dp[1][1]`
    2. DP Computation
        * Iterate over coins from $2$ to $N$
        * For each `j = 0 to i`, compute `dp[i][j]` using the recurrence
    3. Result Computation
        * For $j = N/2 + 1$ to $N$, accumulate `dp[N][j]`
        * Print result with `10` digits of precision

> [!NOTE]
> * Since the output must be accurate within $10^{-9}$, `double` precision with `fixed` and `setprecision(10)` is used
> * This is a classic DP setup for coin toss probability modeling with head-count tracking

### 【CSES】 3221. Sliding Window Minimum

**Solved**

。Monotonic Queue - O($N$)

* Core Concepts
    * Sliding Window Minimum using Monotonic Queue
        * Maintain a **deque** that stores **indices** of candidates for the window minimum
        * Always ensure
            1. The front of the deque is the index of the minimum for the current window
            2. Elements outside the window or larger than the current one are removed
* Solution Strategy
    1. Initialize First Window
        * For $i = 0$ to $K - 1$
            * While the deque is not empty and `arr[dq.back()] > arr[i]`, pop from back
            * Push current index `i` into deque
        * The first minimum is `arr[dq.front()]`, add it to result
    2. Slide the Window
        * For $i = k$ to $N - 1$
            * Remove elements from the back that are larger than current value
            * Remove elements from the front that are outside the window
            * Push current index into deque
            * XOR the front of the deque with the result

> [!NOTE]
> The deque operations are **amortized O(1)**, ensuring that the entire scan is linear
> The algorithm is optimized for large input sizes up to $10^7$

### 【CSES】 1748. Increasing Subsequence II

**Solved**

。DP on LIS Count + Discretization + BIT - O($N\log{N}$)

* Complexity Analysis
    * Discretization ⮕ O($N\log{N}$)
    * BIT Query + Update per element ⮕ O($\log{N}$)
    * Overall Time Complexity ⮕ O($N\log{N}$)
* DP Formulation
    * State Definition
        * `dp[i]` = Number of increasing subsequences **ending at `arr[i]`**
    * Base Case
        * All `dp[i]` initialized to `0`
    * Transition
        * For each index `i`, `dp[i] = sum(dp[j]) + 1` for all `j` such that `arr[j] < arr[i]` and `j < i`
        * `+1` accounts for the new subsequence of length 1 ⮕ `[arr[i]]` itself
    * Final Answer
        * Sum of all `dp[i]` over `i = 0 .. n-1`
* Core Concepts
    * Discretization
        * Since `arr[i]` can be up to $10^9$, compress them to range $[1, n]$ using sorting and `lower_bound()` in order to fit in BIT
    * BIT Optimization
        * To efficiently compute the sum of all `dp[j]` such that `arr[j] < arr[i]`, maintain a BIT indexed by the compressed values
        * BIT performs prefix sum queries and updates in O($\log{N}$)
    * Modular Arithmetic
        * All operations are performed modulo $10^9 + 7$
        * Use custom modular integer type `M<int>` to ensure correctness
* Solution Strategy
    1. Discretize Input
        * Copy `arr[]` to a temp array, sort and remove duplicates
        * Replace each `arr[i]` with its compressed rank (**1-based**)
    2. Process DP with BIT
        * Initialize BIT
        * For each `i` from `0` to `n-1`
            * Query BIT for prefix sum of values less than `arr[i]`
            * Add `1` to account for `[arr[i]]` itself
            * Update BIT at `arr[i]` with this new `dp[i]`
            * Accumulate `dp[i]` to the final answer

> [!NOTE]
> While BIT is used for speed, this is fundamentally a **DP Problem**

### 【CSES】 3314. Mountain Range

**Solved**

。Monotonic Stack + Tree DP - O($N$)

* Complexity Analysis
    * Monotonic Stack Preprocessing ⮕ O($N$)
    * DFS for DP ⮕ O($N$)
    * Total Time Complexity ⮕ O($N$)
* Problem Summary
    * You are given an array of $N$ mountain heights. You can start hang gliding from any mountain, and you may glide to another mountain **only if**
        * It is strictly **lower** than your current mountain
        * All mountains between the two are also lower than your current mountain
    * Find the **maximum number of mountains** you can visit in one such glide route
* Core Concepts
    * Next Greater Element ⮕ Monotonic Stack
        * Use a **monotonic decreasing stack** to precompute for each mountain the **nearest taller mountain to the left and to the right**
    * Graph Representation
        * Each mountain is treated as a **node**, with directed edges to its left and right "glide" targets if they exist
        * A mountain can glide left or right to the next taller peak, forming a type of **jump pointer graph**
    * Tree DP via DFS
        * Use DFS to compute the **maximum glide path length** starting from each mountain
        * Store intermediate results in a `dp[i]` array
        * Transition: `dp[i] = max(dp[l[i]] + 1, dp[r[i]] + 1)` where `l[i]` and `r[i]` are the glide targets
* Solution Strategy
    2. Compute Glide Targets
        * Use monotonic stacks to compute
            * `l[i]` ⮕ nearest higher mountain to the left of $i$
            * `r[i]` ⮕ nearest higher mountain to the right of $i$
    3. Tree-Like DP Computation
        * Initialize all `dp[i] = -1`
        * Use DFS to compute `dp[i]` if not already computed
        * At each node, consider transitions to `l[i]` and `r[i]`, and take the maximum
    4. Track Global Maximum
        * After computing all `dp[i]`, take the maximum as the final result

### 【CSES】 1713. Counting Divisors

**Solved**

。Mathematics - Sieve + Prime Factorization - O($NlogX$) per query after O($NloglogN$) preprocessing

* Core Concepts
    * **Approach**
        * Precompute smallest prime factor for all integers up to $10^6$ using a linear sieve
        * For each input number $X$, perform prime factorization using `mpf[x]` and compute the number of divisors based on the formula
            * If $X = p_1^{a_1} \cdot p_2^{a_2} \cdot \ldots \cdot p_{k}^{a_k}$, then $\text{divisors}(X) = (a_1 + 1)(a_2 + 1) \ldots (a_k + 1)$
    * **Sieve of Eratosthenes**
        * Linear time sieve computes
            * `is_prime[i]` ⮕ whether $i$ is prime
            * `mpf[i]` ⮕ the smallest prime factor of $i$
            * Also computes Euler’s totient `phi[]` and Möbius `mu[]`
            * Time Complexity ⮕O($N\log{\log{N}}$)
* Solution Strategy
    1. Sieve Construction
        * Linear sieve ensures smallest prime factor for each number is known
        * Store primes in a list for fast iteration
    2. Divisor Count
        * For each input number, factorize it using `mpf[]`
        * Count the exponent of each prime and compute total number of divisors from the formula
    3. Edge Case
        * For $x = 1$, the number of divisors is exactly 1

### 【CSES】 3403. Longest Common Subsequence

**Solved**

。Classic LCS - O($NM$)

* Core Concepts
    * DP State
        * Let `dp[i][j]` represent the **length of LCS** between the first `i` elements of array `A` and the first `j` elements of array `B`
    * State Transition
        * If `A[i] == B[j]`, then `dp[i][j] = dp[i-1][j-1] + 1`
        * Otherwise, `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`
    * Base Case
        * `dp[0][j] = 0` and `dp[i][0] = 0` for all $i, j$, since empty subsequences have length $0$
* Implementation Strategy
    1. Initialization
        * Read input arrays `A` and `B`, where $1 \leq N$, $M \leq 1000$
        * Initialize `dp[n+1][m+1]` with all zeros using `memset`
    2. DP Computation
        * Fill in the 2D DP table in O($NM$) time
    3. LCS Reconstruction
        * Start from `dp[n][m]` and trace back to reconstruct one valid LCS
        * At each step, if current cell equals the top cell, move up
        * If it equals the left cell, move left
        * Otherwise, record the matched value and move diagonally

### feat: Update README.md

### 【UVa】 12749. John's Tree

**Solved**

。Mathematics + Modular Arithmetic + Fast Exponentiation - O($TlogD$)

* Mathematical Derivation
    1. Let $V$ be the **maximum degree**, and we assume the **root** uses at most $V$ children
    2. For each level $i$ from 1 to D
        * The number of nodes at level $i$ is $(V−1)^i$ for $i \geq 1$, since each child node can generate at most $V−1$ more
    3. The total number of nodes is $1 + V + V(V-1) + V(V-1)^2 + \dots + V(V-1)^{D-1}$ </br>
     &nbsp; &nbsp; which is $\Longrightarrow 1 + V \times \frac{(V-1)^{D}-1}{V-2}$ for $V \neq 2$
* Special Case Handling
    1. If `D == 0` ⮕ The tree only contains the root $\Longrightarrow$ Output 1
    2. If `D == 1` ⮕ The tree contains the root and at most V neighbors $\Longrightarrow$ Output `1 + V`
    3. If `V == 1` and `D > 1` ⮕ Only a **chain** is possible, and it can't reach depth D $\Longrightarrow$ Output `-1`
    4. If `V == 2` $\Longrightarrow$ The tree becomes a straight line (chain), so the number of nodes is `2D + 1`
* Solution Strategy
    1. Use modular arithmetic to avoid overflow
    2. Use a custom `Mod` struct with
        * Modular addition, subtraction, multiplication
        * Modular inverse using **Extended Euclidean Algorithm**
        * Binary exponentiation for $(V-1)^D$ in O($logD$)
* Complexity Analysis
    * Each test case runs in O($logD$) due to modular exponentiation
    * Space usage is constant ⮕ O($1$)
    * Overall time complexity is O($TlogD$) where $T$ is the number of test cases
* Notes
    * The custom `Mod` class is carefully designed to handle modular division even when `MOD` is not prime
    * Avoid using Fermat's Little Theorem, and instead use `exgcd()` to compute the inverse to ensure correctness in all cases

### 【UVa】10036. Divisibility

**Solved**

。Modulo Optimization - O($NK$)

* Core Concepts
    * Approach
        * This problem can be formulated as below, whether it's possible to get a cumulative sum modulo $K$ equal to $0$ using `+` or `-` between numbers
        * Transitions are based on adding or subtracting the current number modulo $K$
    * Optimization
        * Since only the current and next states are needed, we can use two alternating `queue`s to avoid full allocation
        * We use a boolean `used[0..K-1]` array to avoid redundant computation of the same modulo in the same stage
* Problem Breakdown
    1. Modulo Normalization
        * Since input numbers can be negative, all numbers are first converted to positive modulo `arr[i] = (arr[i] % K + K) % K`
    2. Initial Setup
        * If all numbers are $0$ (mod $K$), then the sequence is trivially divisible
        * Otherwise, start from the first number and initialize `q.push(arr[0])`
    3. BFS-based Transition
        * For each position $i$, simulate all reachable modulo values from the previous position
        * From a current mod $m$, we can move to `(m + arr[i]) % K` and `(m - arr[i]) % K`
        * If at any point the modulo becomes 0 at the last element, we conclude `Divisible`
    4. Termination
        * If no path reaches 0 modulo after processing all elements, output `Not divisible`

### 【CSES】 1136. Counting Paths

**Solved**

。LCA - O( max($Nlog{N}$, $Qlog{N}$) )

* Complexity Analysis
    * Binary Lifting Preprocessing ⮕ O($Nlog{N}$)
    * Processing Queries ⮕ O($Qlog{N}$)
    * DFS Traversal ⮕ O($N$)
    * Overall Time Complexity ⮕ O($(N+Q)log{N}$)
* Core Concepts
    * Tree Representation
        * Use an adjacency list to store the tree edges
        * Use DFS to preprocess binary lifting parent table and node depths
    * LCA
        * For each pair $(u, v)$, compute the LCA
        * This allows us to find the overlapping region of paths in O($log{N}$) per query
        * Preprocessing table `fa[x][i]` such that `fa[x][i]` is the 2ⁱ-th ancestor of node `x`
* Solution Strategy
    1. Difference Array on Tree
        * For each path $(u, v)$
            * `ans[u]++` and `ans[v]++` to mark both ends
            * `ans[lca(u, v)]--` and `ans[parent_of_lca]--` to subtract the overlap
        * This works similarly to a prefix sum difference array on a tree
    2. DFS to Aggregate Result
        * Perform a DFS from root to accumulate results
        * `res[x] = ans[x] + sum of all res[child]` over its subtree
        * Ensures each node counts the number of times it is passed through by a path
* Summary of Key Functions
    * `create_table(root, parent)` ⮕ Builds the depth and ancestor table for LCA
    * `lca(a, b)` ⮕ Computes the lowest common ancestor of nodes `a` and `b`
    * `dfs(root)` ⮕ Accumulates the number of paths through each node based on the difference array

> [!NOTE]
> This technique of using difference arrays on trees is powerful for counting path intersections or frequency propagation in subtree-related problems

### feat: Update Tamplate.cpp

### 【CSES】 1138. Path Queries

**Solved**

。Heavy-Light Decomposition HLD with Segment Tree - O($log{log{N}}$)

* Time Complexity
    * Each modify and query takes O($log{N}$) for the segment tree
    * Since a path from a node to the root is broken into at most O($log{N}$) chains, the total per-query cost is O($log{log{N}}$)
    * Preprocessing, HLD + Segment Tree build, is O($N$)
* Core Concepts
    * Heavy-Light Decomposition
        * Decomposes a tree into **chains** where each chain maintains the **heaviest** child connection, allowing **path queries** to be broken into O($log{N}$) segments
        * This allows efficient traversal and updates on a path between any node and the root (or between any two nodes in general cases)
    * Segment Tree with Lazy Propagation
        * Used to maintain values on the linearized tree
        * Allows efficient range updates and point queries with O(${logN}$) time complexity per operation
        * The `tag` is used to implement lazy propagation, accumulating updates until necessary
* Implementation Strategy
    1. Tree Construction
        * Run `tree_build()` DFS to calculate subtree sizes and identify heavy children
        * Run `tree_decom()` to assign unique ids to nodes for segment tree mapping and chain identification\
    2. Processing Queries
        * Modify
            * Retrieve the current value via `query()`, then modify via `modify()` to set it to `x`
        * Path Sum
            * Climb up the tree using HLD by chains
            * For each chain, perform a range sum query
            * Accumulate and print the result
* Additional Notes
    * The segment tree operates on a **flattened representation** of the tree using DFS order
    * The `id` assigned in `tree_decom()` maps each node to its position in the segment tree
    * `id2pos[]` reverses this mapping, from timer to segment id, is **NECESSARY**

### feat: Update Tamplate.cpp

### 【CSES】 1694. Download Speed

**Solved**

。Dinic - O($V^{2}E$)

* Core Concepts
    * Dinic’s Algorithm, which consists of two phases
        1. Level Graph Construction by BFS
            * Construct a level graph to find shortest augmenting paths from source to sink
        2. Blocking Flow Computation by DFS
            * Perform DFS to send blocking flows along the level graph
    * Repeat the two phases until no more augmenting paths exist
* Implementation Details
    1. Edge Structure
        * Each edge stores target node `v`, current residual capacity `flow`, and a reverse edge index `rev`
        * Reverse edges are automatically added with `0` initial capacity for residual graph construction
     2. Level Array
        * Used to record the level of each node from the source during BFS
        * Ensures that DFS only proceeds to the next level, preventing cycles
    3. DFS Flow Propagation
        * DFS attempts to push as much flow as possible along valid paths, updating both forward and reverse edges
        * If a node cannot contribute to any flow, it is marked `-1` to prune the search space
    4. Flow Accumulation
        * Repeatedly perform BFS + DFS while level graph is valid
        * Accumulate flow until saturation

### 【CSES】 1722. Fibonacci Numbers

**Solved**

。Matrix Exponentiation - O($logN$)

* Core Concepts
    * Matrix Formulation of Fibonacci
        * The Fibonacci sequence can be represented using matrix exponentiation
        * The transformation matrix `T = [[1, 1], [1, 0]]` can be raised to the power of (n-1), and its top-left entry gives `F_n`
    * Modulo Arithmetic
        * Since the answer must be output modulo \$10^9 + 7\$, all matrix multiplication operations are performed under modulo
* Implementation Strategy
    * Matrix Exponentiation
        * Repeatedly square the matrix while halving the exponent (fast exponentiation)
        * Time complexity: O(log n)
    * Edge Case Handling
        * If `n == 0`, directly return `0` as per definition

### feat: Update Tamplate.cpp and Set.cpp

### feat: Update Tamplate.cpp

### 【CSES】 1135. Distance Queries

**Solved**

。Binary Lifting+ LCA - O($NlogN$)

* Core Concepts
    * Approach
        * Tree Preprocessing
            * Use DFS to annotate each node’s depth and build a binary lifting table `fa[node][i]` where `fa[node][i]` is the $2^i$-th ancestor of `node`
            * Preprocessing runs in O($NlogN$) because each level $i$ builds on top of the previous level
    * Binary Lifting for LCA
        * Equalize Depths
            * If `u` is deeper than `v`, we first move `u` up until both nodes are at the same depth
            * Each jump of size $2^i$ adds that value to the distance accumulator
        * Find LCA
            * From top-down, if `fa[u][i] != fa[v][i]`, then move both `u` and `v` up by $2^i$
            * Each such move adds `2 × 2^i` to the total distance
            * After this, both nodes will have the same parent, which is the LCA
        * Final Adjustment
            * If `u != v`, a final move of `2` steps (1 for each node) completes the distance
* Preprocessing Details
    1. `dfs(1, 0)` initializes the root node with depth 1, setting all ancestors using the formula:
        `fa[u][i] = fa[ fa[u][i-1] ][i-1]`
    2. The lifting table is built for up to 20 levels, sufficient for $N \leq 2 \times 10^5$

### 【CSES】 3420. Distinct Values Subarrays

**Solved**

。Two Pointers or Sliding Window - O($N$)

* Core Concepts
    * Sliding Window Technique
        * Maintain a window `[pL, pR]` such that all elements within it are distinct
        * Use a hash map `mp[x]` to track the frequency of elements inside the window
        * When a duplicate is encountered at `arr[pR]`, advance `pL` to the right until the window becomes valid again
    * Count of Subarrays
        * For each valid `pR`, the number of valid subarrays ending at `pR` is `(pR - pL + 1)`
        * Accumulate this for all valid `pR` to get the final result
* Algorithm Strategy
    1. Initialize `pL = 0`, `pR = 0` and increment frequency of `arr[0]`
    2. Move `pR` forward while ensuring the subarray `[pL, pR]` contains only distinct elements
    3. If a duplicate is added, move `pL` right and decrement frequencies until the window is valid
    4. At each step, add `pR - pL + 1` to the result
    5. Output the final accumulated result

### 【CSES】 3359. Minimal Grid Path

**Solved**

。Greedy + BFS-like Level Expansion - O($N^2$)

* Core Concepts
    * Observation
        * This problem can be viewed as a pathfinding task over a grid, where at each step, we can only move right or down
        * The key idea is to **always expand to the smallest character** at the next level, similar to Dijkstra or BFS using lexicographical priority
* Solution Strategy
    1. Greedy BFS Expansion
        * We maintain a **queue of positions** we can reach in the current step
        * For each of these positions, we examine their **right** and **down** neighbors
        * From all these neighbors, we **only keep those with the smallest lexicographical character** at that level
        * This guarantees we construct the minimal string, character by character
    2. Avoiding Revisits
        * A `used[i][j]` boolean array is maintained to avoid re-inserting the same cell into the queue
        * Once a cell is added at its minimal character level, it's skipped in future steps
    3. Path Construction
        * We start from (0, 0) and repeatedly select the next minimal character from valid adjacent cells
        * This process continues for `2n - 1` steps
* Implementation Notes
    * Standard BFS is used, but instead of distance, we track **lexicographical priority**
    * Greedy pruning ensures that we **never explore non-minimal paths**

### feat: Update Set.cpp

### 【CSES】 3311. Grid Coloring I

**Solved**

。Backtracking + DFS Brute Force - O($4^{NM}$) worst-case with aggressive pruning

* Core Concepts
    * DFS + Backtracking Strategy
        * Traverse the grid cell-by-cell in row-major order
        * At each cell $(x, y)$, attempt all possible replacements from `{A, B, C, D}`
        * Skip the character if it matches the original one
        * Skip if it causes a conflict with the top or left cell
        * Use recursion and restore the previous state, backtrack, if a path fails
        * If the traversal reaches the end, output the modified grid and halt the program immediately
* Complexity Analysis
    * Each cell has at most 3 coloring options
    * Worst-case time complexity is O($3^{NM}$), but pruning adjacent conflicts significantly reduces the search space
    * Works efficiently for $N, M \leq 500$ due to early halt the program immediately upon first solution
* Edge Considerations
    * In certain pathological cases, no valid coloring may exist — code will correctly output `IMPOSSIBLE`
* Implementation Highlights
    * Clean separation between input parsing, DFS traversal, and constraint checks
    * The state is restored after each recursive attempt to avoid corruption

> [!NOTE]
> *Why does such an exponential-time backtracking solution pass the time limits*
> 
> Despite the worst-case complexity of O($3^{NM}$), the actual number of recursive calls is drastically reduced due to aggressive pruning and structural constraints in the problem
> 1. Strong Local Constraints Reduce the Search Space
>       * For each cell $(x, y)$, the algorithm only considers characters `{A, B, C, D}` that
>           * Differ from the original character ⮕ eliminates 1 possibility
>           * Differ from the character above
>           * Differ from the character to the left
>       * As a result, most cells have at most **2 valid choices**, sometimes even just 1, effectively transforming the exponential branching factor into a manageable constant
> 2. Grid Coloring Is Highly Constrained
>       * Many branches of the DFS are terminated early as soon as a conflict is detected, leading to **shallow recursion trees**

### 【CSES】 3419. Mex Grid Construction

**Solved**

。Divide and Conquer - O($N^2$)

* Solution Strategy
    1. Build a sufficiently large grid, $128 \times 128$, recursively, then output the first $N \times N$ part
    2. Use divide and conquer
        * Divide the square into four quadrants of size $\frac{N}{2}$
        * Propagate values around edges to maintain the mex condition
        * Use different filling rules depending on quadrant ID
        * When reaching base case, fill diagonals directly
* Key Observations
    * Using a fixed $128 \times 128$ base grid covers the constraint $N \leq 100$
    * For each cell $(i, j)$, we use previous cells in its row or column to determine the current value without needing additional data structures
    * Divide and conquer method avoids the naive method of checking mex at each step explicitly, which would be O($N^3$)

### 【CSES】 3217. Knight Moves Grid

**Solved**

。BFS - O($N^2$)

* Core Concepts
    * Approach
        * State Representation
            * We maintain a `dis[i][j]` array to record the minimum number of knight moves needed to reach square `(i, j)` from `(0, 0)`
            * The BFS queue holds coordinates `(x, y)` of visited squares
        * Base Cases
            * Start from `(0, 0)` with distance 0
        * Transitions
            * For each square in the queue, iterate over the 8 knight move directions, if the next square is within bounds and unvisited, set its distance to `current + 1` and enqueue it
    * Termination
        * Continue BFS until all squares are visited
* Solution Strategy
    1. Initialize the `dis` array with `-1`, as unvisited
    2. Mark `(0, 0)` as `0` and enqueue it
    3. While queue is not empty
        * Dequeue `(x, y)`
        * For each knight move direction, check bounds and update `dis[nx][ny]` if unvisited
    4. Print the `dis` array row by row

> [!NOTE]
> This problem is classic BFS on an unweighted grid graph, where each move has cost 1


### 【CSES】 3399. Raab Game I

**Solved**

。Observation + Construction - O($TN$)

* Solution Strategy
    1. Basic Constraints
        * If $A + B \neq N$, it is impossible since there are $N$ rounds and each point comes from a round won by exactly one player
        * If exactly one of $a$ or $b$ is zero but not both, impossible due to the problem constraints, brcause it forces symmetry of wins and losses
    2. Constructing the Game
        * Reduce $N$ until $A + B = N$, since we cannot have more rounds than points
        * Construct player sequences by assigning strongest cards to the player needing more points
        * Fill remaining rounds with non-conflicting choices ensuring total score constraints are met
    3. Check Feasibility
        * If after reduction $N == 1$, impossible to satisfy scoring conditions simultaneously
* Implementation Details
    * Using greedy approach to assign high cards to winning player in each round
    * Handle edge conditions separately to ensure correctness

### 【CSES】 1681. Game Routes

**Solved**

。Topological Sort + DP - O($N + M$)

* Core Concepts
  * Approach
    * Topological Sort
        * Every node with `indegree == 0` ( except node `1` ) is pushed into the queue before the process begins
        * Special Rule
            * Node `1` must be pushed into the queue at the beginning, even if its `indegree != 0`
    * DP Transition
        * `dp[v] += dp[u]` for each edge `u ⮕ v`
        * Represents the number of ways to reach node `v` via all incoming paths
        * Modulo must be applied during each transition to avoid overflow
    * Final result
        * `dp[n]` gives the total number of distinct paths from level `1` to level `n`
* Algorithm Strategy
    * Topological Sort Initialization
        * Traverse from `2` to `n` and push all nodes with `indegree == 0` into the queue
        * Push node `1` into queue explicitly, even if its `indegree > 0`
    * Processing Queue
        * For every node popped from the queue
            * Traverse all its neighbors
            * Decrement their `indegree`
            * Perform transition: `dp[neighbor] += dp[current] (mod 1e9 + 7)`
            * Push neighbor to queue only if `indegree == 0 && neighbor != 1`
                * This ensures node `1` is only processed once at the start
* Edge Case Handling
    * Explicitly push node 1
        * It's the source node, and the player starts at level 1
        * If we rely solely on `indegree == 0`, node `1` might be excluded
    * Avoid pushing node 1 again
        * To prevent duplicate processing since `1` is the starting point and already processed

### feat: Update Set.cpp

### 【CSES】 1679. Course Schedule

**Solved**

。Topological Sort - O($N$)

* Description
    * This is just a template question

### 【CSES】 2220. Counting Numbers

**Solved**

。Digit DP - O($digits \times 10 \times 2 \times 2$)

* Key Observations
  * Design a recursive function `get(idx, pre, leading, tight)` which computes the number of valid digit sequences based on current digit position and constraints
* Approach
    * State Representation
        * `idx` ⮕ Current digit index
        * `pre` ⮕ Previous digit used
        * `leading` ⮕ Boolean indicating whether leading zeros are still allowed
        * `tight` ⮕ Boolean indicating whether the current digit must stay within the bounds of the original number
    * Base Cases
        * If `idx < 0`, a valid number has been constructed ⮕ return 1
    * Transition
        1. **Limit Selection**
            * If `tight == true`, only consider digits up to `arr[idx]`; otherwise, up to 9
        2. **Recursive Transitions**
            * Skip digits that match the `pre` if `leading == false`
            * For each possible digit `i` in range $[0, limit]$
                * If `leading == true && i == 0`, continue treating as leading zero ⮕ `get(idx-1, i, true, false)`
                * If `tight == true && i == limit`, preserve tight bound ⮕ `get(idx-1, i, false, true)`
* Solution Strategy
    1. Calculate `na`
        * For number `a-1`, convert to string `sa`, store digits in `arr[]`, and run `get()` to count all valid numbers less than `a-1`
    2. Calculate `nb`
        * For number `b`, convert to string `sb`, store digits in `arr[]`, and run `get()` to count all valid numbers up to `b`
    3. Final Answer
        * The number of valid integers in range $[a, b]$ is `nb - na`

### 【UVa】 101. The Blocks Problem

**Solved**

### feat: Modify Set.cpp Content

* Feature
    * Remove
        ```cpp
        #define vsort(x) sort(x.begin(), x.end());
        ```
    * Add
        ```cpp
        #define all(v) x.begin(), v.end()
        ```

### 【AtCoder】 Beginner Contest 399 - F. Range Power Sum

**Solved**

。Binary Exponentiation + Binomial Expansion + DP - O($NK^2log{K}$)

* Mathematical Derivation and Problem-Solving Strategies
    1. Before Starting the Mathematical Derivation
        * We consider that the numbers are assigned to the sequence $A$ sequentially, from the beginning to the end
        * Specifically, for each number $A_{i}$, we only consider the contributions of the right endpoints in the intervals $[1, i], [2, i], \cdots [i, i]$ to the answer
    2. Let $T[i][k]$ denote the total contribution of all subarrays ending at index $i$, raised to the $k^{th}$ power
    3. $T[i][k]$ are defined as follow </br>
        $\because$ &nbsp; $(x + y)^k = \sum_{t=0}^{k} \binom{k}{t} x^{k-t} y^t$ </br>
        $\therefore$ &nbsp; $T[i][k] = (A_{i})^k + (A_{i} + A_{i-1})^k + (A_{i} + A_{i-1} + A_{i-2})^k + \cdots$ </br>
        &nbsp; &nbsp; &nbsp; $\Longrightarrow [A_{i}]^k + [A_{i} + (A_{i-1})]^k + [A_{i} + (A_{i-1} + A_{i-2})]^k + \cdots$ </br>
        &nbsp; &nbsp; &nbsp; $\Longrightarrow [A_{i}]^k + [\sum_{t=0}^{k}\binom{k}{t}(A_{i})^{k-t}(A_{i-1})^{t}] + [\sum_{t=0}^{k}\binom{k}{t}(A_{i})^{k-t}(A_{i-1} + A_{i-2})^{t}] \cdots$ </br>
        &nbsp; &nbsp; &nbsp; $\Longrightarrow [A_{i}]^k + \sum_{t=0}^{k}\binom{k}{t}(A_{i})^{k-t}[(A_{i-1})^t + (A_{i-1} + A_{i-2})^t + \cdots ]$ </br>
        &nbsp; &nbsp; &nbsp; $\Longrightarrow [A_{i}]^k + \sum_{t=0}^{k}\binom{k}{t}(A_{i})^{k-t}T[i-1][t]$
    4. Therefore, the answer will be $T[0][k] + T[1][k] + \cdots + T[k][k]$

### style: Adjust README.md Format

### 【AtCoder】 Beginner Contest 399 - D. Switch Seats

**Solved**

。Greedy + Observational Optimization - O($N$)

* Key Observations
    1. For a couple to become adjacent, their two occurrences must be in positions that can be rearranged to be next to each other
    2. For a pair `(a, b)` to satisfy the condition
        * Positions of `a` are `p1`, `p2`, and positions of `b` are `q1`, `q2`
        * After sorting `[p1, p2, q1, q2]`, the only acceptable order is
            * `(x1, x2, x3, x4)` such that `x1 + 1 == x2` and `x3 + 1 == x4`
* Solution Strategy
    1. Read the input sequence `A` of size `2N`
    2. Track the **positions** of each number using a `vector<vector<int>> pos`
    3. Iterate all **consecutive** pairs `(i, i+1)` in `A`
        * Check if both `A[i]` and `A[i+1]` are non-adjacent couples
        * Form a 4-element vector with their positions
        * Sort the positions and verify if adjacent pair conditions are satisfied
    4. Use a `set<pair<int,int>>` to store valid unordered pairs to ensure uniqueness
    5. Output the size of the set as the final answer
* Optimization Tips
    * Avoid checking couples that are already adjacent
        * Key Fixes from the Wrong Version
            * Incorrect condition
                * Skipping pairs based on `if(x > y) continue;` might omit valid (a, b) that should be checked
                    ```
                    For Example ⮕ 3 2 1 3 2 1
                    ```
            * Correct condition
                * Use `set<pii>` with `min(x,y), max(x,y)` to avoid duplicates without skipping valid permutations
    * Use `min(a, b), max(a, b)` when storing pairs in the set to prevent duplicates
    * Swapping simulation is **not needed**, only need to check index positions

### upload: AtCoder Beginner Contest 399

### style: Add Problem Info

* Affected Files
    1. AtCoder\Beginner Contest 398\A. Doors in the Center.cpp
    2. AtCoder\Beginner Contest 398\B. Full House 3.cpp
    3. AtCoder\Beginner Contest 398\C. Uniqueness.cpp

### 【CSES】 1197. Cycle Finding

**Solved**

。Bellman-Ford - O($NM$)

* Complexity Analysis
    * Bellman-Ford runs in O($NM$)
    * Extracting the cycle requires O($N$)
    * Overall complexity is O($NM$)
* Core Concepts
    * Approach
        * Useing the **Bellman-Ford algorithm** to detect a **negative cycle** in a directed graph
        * Since Bellman-Ford relaxes each edge **N times**, any negative cycle will cause an update in the **Nth iteration**
    * Detecting a Negative Cycle
        * We maintain a `fa[]` array to track the previous node for each node, which being relaxed, in the shortest path
        * If an update happens on the **Nth iteration**, it means a negative cycle exists
        * The last updated node `lst` might be part of the cycle, but it also may not be inside the cycle itself
    * Extracting the Cycle
        * To ensure that `lst` is inside the negative cycle, we perform **N additional steps** using `lst = fa[lst]`
        * This guarantees that `lst` lands within the negative cycle
        * Then, backtrack using `fa[]` to reconstruct the cycle path
        * Since the order of backtracking is reversed, it is necessary to use the vector's member function `reverse()` to adjust its content
* Edge Cases Considered and Observed
    1. 【WA】A graph displaying both a positive cycle and a negative cycle simultaneously, but arranged in the different order
    2. 【WA】A graph that contains both positive and negative cycles simultaneously
    3. 【WA】A graph with many negative edges, however, some of them don't belong to a negative cycle
    4. 【WA】A graph with a self-negative ring
    5. 【TLE】A large graph that contains the maximum number of nodes and edges, which together form a complete cycle

### style: Adjust README.md Format

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
            * Construct an array `nxt[i]` which stores the index of the next occurrence of `arr[i]`, -1 if none exists
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

### 2022. 07. 21

**Solved** - 【CSES】 1646. Static Range Sum Queries
