# CP-Question-Record

## 2024. 11. 02

**Solved** - 【CSES】 1645. Nearest Smaller Values

。 Segment Tree + Discretization - O(NlogN)

* Implementation Details
    * Notice to query like `query(1, n, 1, arr[i]-1, 1)` not `query(1, n, 1, arr[i], 1)`, but modify must be `modify(1, n, arr[i], arr[i], i, 1);`

**Solved** - 【CSES】 1644. Maximum Subarray Sum II

* Notice 
    * `erase(val)` in `set` will erase all of the value which equals to val
    * `set` will be sorted `.first` and then `.second`

## 2024. 10. 24

**Solved** - 【CSES】 1641. Sum of Three Values

## 2024. 10. 12

**Solved** - 【CSES】 1164. Room Allocation

## 2024. 10. 07

**Update Set.cpp**

## 2024. 09. 28

**Solved** - 【Luogu】 P3376.【Template】Maximum Network Flow

**Solved** - 【Luogu】 P3379.【Template】LCA

**Modify File Name** - 【Luogu】 P3385.【Template】Negative Cycle

**Solved** - 【Luogu】 P3385.【Templete】Negative Cycle

**Update Set.cpp**

**Correct README.md**

**Solved** - 【CSES】 1647. Static Range Minimum Queries

。Segment Tree / DP

## 2024. 09. 26

**Solved** - 【AtCoder】 Beginner Contest 368 - G. Add and Multiply Queries

**Update BIT Code**

## 2024. 09. 24

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

## 2024. 09. 22

**Solved** - 【AtCoder】 Beginner Contest 369 - C. Triple Attack

## 2024. 09. 20

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

## 2024. 09. 19

**Solved** - 【AtCoder】 Beginner Contest 369 - D. Bonus EXP

。Dynamic Programming

**Opt IO Optimize & Add Long Long INF** - Set.cpp

## 2024. 09. 18

**Solved** - 【AtCoder】 Beginner Contest 369 - E. Sightseeing Tour

。Flyod-Warshall + Enum

**Solved** - 【AtCoder】 Beginner Contest 369 - C. Count Arithmetic Subarrays

。Basic Mathematical Operations

**Update Quesiton Statement**

## 2024. 09. 14

**Opt Setup Code**

## 2024. 09. 12

**Solved** - 【AtCoder】 Beginner Contest 370 - A. Raise Both Hands

**Solved** - 【AtCoder】 Beginner Contest 370 - B. Binary Alchemy

**Solved** - 【AtCoder】 Beginner Contest 370 - C. Word Ladder

## 2024. 08. 29

**Solved** - 【ZeroJudge】 a104. Sort - Quick Sort

。Sort Algorithm

## 2024. 08. 24

**Correcnt Spelling Error** - 【ZeroJudge】 a104. Sort - Merge Sort

**Remove Redundant Array** - 【ZeroJudge】 a104. Sort - Merge Sort

**Oprtimize** - 【ZeroJudge】 a104. Sort - Merge Sort

**Solved** - 【ZeroJudge】 a104. Sort - Merge Sort

。Sort Algorithm

## 2024. 08. 21

**Solved** - 【ZeroJudge】 a104. Sort - Insertion Sort

。Sort Algorithm

**Add Question Info** - 【ZeroJudge】 a104. Sort - Insertion Sort

## 2024. 08. 10

**Solved** - 【ZeroJudge】 a104. Sort - Bubble Sort

。Sort Algorithm

**Solved** - 【ZeroJudge】 a104. Sort - Selection Sort

。Sort Algorithm

## 2024. 07. 15

**Solved** - 【ZeroJudge】 d672. 10922 - 2 the 9s

。Recursive + Basic String Processing

**Solved** - 【ZeroJudge】 f928. Serial Bomb............Boom!

。Recursive / BFS

## 2024. 07. 02

**Solved** - 【CSES】 2165. Tower of Hanoi

。Recursive Application

**Solved** - 【HWSH】 a155. Sum of Subsets（APCS201810, Subtask）

。Recursive with Subset

## 2024. 06. 26

**Solved** - 【HWSH】 a062. Stick Midpoint Cut

。Recursive Application

## 2024. 06. 07

**Solved** - 【ZeroJudge】 b967. 4. Blood Relationship

。 Simple Tree Diameter

## 2024. 05. 13

**Solved** - 【AtCoder】 Beginner Contest 352 - C. Standing On The Shoulders

**Solved** - 【AtCoder】 Beginner Contest 352 - D. Permutation Subsequence

。 Set + vector<pii> + sort

## 2024. 05. 08

**Solved** - 【AtCoder】 Beginner Contest 351 - C. Merge the balls

## 2024. 05. 07

**Solved** - 【ZeroJudge】 g276. 2. Demon King no Labyrinth

## 2024. 05. 06

**Solved** - 【ZeroJudge】 j605. 1. Programming Exam

## 2024. 05. 02

**Solved** - 【ZeroJudge】 a003. Two Lights Mage Divination

**Solved** - 【ZeroJudge】 d649. Digital Triangle

## 2024. 04. 30

**Solved** - 【TCIRC】 1001. Hello World!

**Solved** - 【ZeroJudge】 a002. Simple Addition

**Solved** - 【AtCoder】 A. Three Dice

## 2024. 04. 12

**Solved** - 【TCIRC】 d060. AP325 Q-4-19. The Meeting Place of the Leaders of The Five Sacred Mountains

## 2024. 04. 11

**Solved** - 【TCIRC】 d057. AP325 Q-4-16. Making Money and Fines

**Solved** - 【TCIRC】 d058. AP325 Q-4-17. Deadline Master

**Solved** - 【TCIRC】 d059. AP325 Q-4-18. The Cabinet Sister of Shaolin Temple（@@）（＊）

## 2024. 04. 09

**Solved** - 【TCIRC】 d050. AP325 P-4-11. Line Segment Union（APCS 201603）

**Solved** - 【TCIRC】 d051. AP325 P-4-12. One Transaction

**Solved** - 【TCIRC】 d055. AP325 P-4-14. Control Point（2D-max）

## 2024. 03. 10

**Solved** - 【TCIRC】 d071. AP325 P-6-9. Free Large-Scale Moving in Hypermarkets

**Solved** - 【ZeroJudge】 k184. pA. House

## 2024. 03. 09

**Solved** - 【TCIRC】 d054. AP325 Q-4-10. White Cloud Bear Gallbladder Pills to Restore Energy

**Solved** - 【TCIRC】 d070. AP325 P-6-7. LCS

**Solved** - 【TCIRC】 d074. Q-6-8. Local Alignment

## 2024. 03. 08

**Solved** - 【TCIRC】 d069. AP325 P-6-6. Checkerboard Route

## 2024. 03. 07

**Solved** - 【TCIRC】 d052. AP325 P-4-13. Maximum Continuous Subpermutation（Same As P-5-2）

**Solved** - 【TCIRC】 d073. AP325 Q-6-5. Two-Dimensional Maximum Submatrix

## 2024. 03. 06

**Solved** - 【TCIRC】 d066. AP325 P-6-1. Minimum Cost for Children To Go Up Stairs

**Solved** - 【TCIRC】 d067. AP325 P-6-2. Discontinuous Performance Remuneration

**Solved** - 【TCIRC】 d068. AP325 P-6-3. Minimum Cost of Monitoring Neighbors

**Solved** - 【TCIRC】 d072. AP325 Q-6-4. Choose One of Two Levels

## 2024. 03. 05

**Solved** - 【CSES】 2413. Counting Towers

**Solved** - 【CSES】 1744. Rectangle Cutting

## 2024. 03. 04

**Solved** - 【CSES】 1746. Array Description

## 2024. 03. 01

**Solved** - 【AtCoder】 Beginner Contest 342 - D. Square Pair

## 2024. 02. 29

**Opt BIT Templete**

## 2024. 02. 25

**Solved** - 【AtCoder】 Beginner Contest 342 - A. Yay!

**Solved** - 【AtCoder】 Beginner Contest 342 - B. Which is ahead

**Solved** - 【AtCoder】 Beginner Contest 342 - C. Many Replacement

## 2024. 02. 24

**Solved** - 【AtCoder】 Beginner Contest 341 - E. Alternating String

**Solved** - 【CSES】 1073. Towers.cpp

## 2024. 02. 23

**Solved** - 【AtCoder】 Beginner Contest 341 - D. Only one of two

**Solved** - 【TCIRC】 d049. AP325 P-4-9. Base Station（APCS201703）

## 2024. 02. 22

**Solved** - 【AtCoder】 Beginner Contest 339 - E. Smooth Subsequence

**Solved** - 【TCIRC】 d047. AP325 Q-4-6. Automatic Lockers in Shaolin Temple（APCS201710）

**Solved** - 【TCIRC】 d048. AP325 P-4-7. Yue Buquns Two-Way Merge（＊）

**Solved** - 【TCIRC】 d053. AP325 Q-4-8. First Come First Served（＊）

## 2024. 02. 21

**Solved** - 【ZeroJudge】 h557. pA. Entrance

## 2024. 02. 20

**RePush** - 【AtCoder】 Beginner Contest 328 - A. Not Too Hard

**RePush** - 【AtCoder】 Beginner Contest 328 - B. 11/11

**RePush** - 【AtCoder】 Beginner Contest 328 - C. Consecutive

**RePush** - 【AtCoder】 Beginner Contest 328 - D. Take ABC

**Solved** - 【ZeroJudge】 h558. pB. Keyboard

## 2024. 02. 19

**Solved** - 【AtCoder】 Beginner Contest 341 - A. Print 341

**Solved** - 【AtCoder】 Beginner Contest 341 - B. Foreign Exchange

**Solved** - 【AtCoder】 Beginner Contest 341 - C. Takahashi Gets Lost

## 2024. 02. 17

**Solved** - 【AtCoder】 Beginner Contest 340 - E. Mancala 2

**Add INF Const** - Set.cpp

## 2024. 02. 16

**Solved** - 【TCIRC】 d046. AP325 P-4-5. Problem of Songshan Mojianfang （Weighted Minimum Completion Time）

**Solved** - 【AtCoder】 Beginner Contest 340 - A. Arithmetic Progression

**Solved** - 【AtCoder】 Beginner Contest 340 - B. Append

**Solved** - 【AtCoder】 Beginner Contest 340 - C. Divide and Divide

**Solved** - 【AtCoder】 Beginner Contest 340 - D. Super Takahashi Bros.

**Opt Code** - 【TCIRC】 d046. AP325 P-4-5. Problem of Songshan Mojianfang （Weighted Minimum Completion Time）

## 2024. 02. 10

**Solved** - 【TCIRC】 d045. AP325 P-4-4. Several Huashan Sword Debates（Activity Selection）

## 2024. 02. 09

**Solved** - 【TCIRC】 d042. AP325 P-4-1. Shaolin Temple Tokens

**Solved** - 【TCIRC】 d043. AP325 P-4-2. The Three Battles of Swordsman

**Solved** - 【TCIRC】 d044. AP325 P-4-3. Ten Years of Sharpening a Sword（Minimum Completion Time）

## 2024. 02. 07

**Solved** - 【AtCoder】 Beginner Contest 339 D. Synchronized Players

**Solved** - 【TCIRC】 d038. AP325 Q-3-14 Linear Function（@@）

**Opt Code** - 【TCIRC】 d037. AP325 Maximum Y Difference within X Difference Range

## 2024. 02. 03

**Solved** - 【AtCoder】 Beginner Contest 339 - A. TLD

**Solved** - 【AtCoder】 Beginner Contest 339 - B. Langton's Takahashi

**Solved** - 【AtCoder】 Beginner Contest 339 - C. Perfect Bus

## 2024. 02. 01

**Rename File** - 【TCIRC】 d036. AP325 Q-3-12. Perfect Ribbons（APCS201906）

**Solved** - 【TCIRC】 d037. AP325 Q-3-13. Maximum Y Difference within X Difference Range

## 2024. 01. 30

**Solved** - 【TCIRC】 d036. AP325 Q-3-12. Perfect Ribbons（APCS201906）

## 2024. 01. 29

**Solved** - 【TCIRC】 d032. AP325 P-3-8. Maximum Segment Difference for Fixed-length Intervals

**Solved** - 【TCIRC】 d035. AP325 Q-3-11. The Longest Distinct Color Band

## 2024. 01. 28

**Solved** - 【TCIRC】 d034. AP325 P-3-10. Full-Color Ribbon（Requires Discretization or Dictionary）（@@）

## 2024. 01. 27

**Solved** - 【TCIRC】 d033. AP325 P-3-9. Most Color Bands

## 2024. 01. 24

**Solved** - 【TCIRC】 d021. AP325 Q-2-12. The Closest Submatrix Sum（108 High School National Competition）（＊）

**Solved** - 【TCIRC】 d031. AP325 P-3-7. The Closest Interval Sum of A Sequence of Positive Integers

## 2024. 01. 12

**Solved** - 【TCIRC】 d025. AP325 P-3-1. Height and Root of Tree（Bottom-Up）（APCS201710）

## 2024. 01. 06

**Solved** - 【TCIRC】 d052. AP325 P-5-2. Maximum Continuous Subarray（Divide and Conquer）

**Solved** - 【TCIRC】 d026. AP325 P-3-2. Bracket Matching

**Anti-Annotation** - 【TCIRC】 d026. AP325 P-3-2. Bracket Matching

**Solved** - 【TCIRC】 d027. AP325 Q-3-3. Addition, Subtraction, Multiplication and Division

**Solved** - 【TCIRC】 d028. AP325 P-3-4. The Closest Taller（APCS201902, Subtask）

**Remove Deleted File**

**Solved** - 【TCIRC】 d029. AP325 Q-3-5. The Taller with A Bench Cooking Chicken Steaks（APCS201902）

**Solved** - 【TCIRC】 d030. AP325 P-3-6. Cutting Down Trees（APCS202001）

## 2024. 01. 05

**Working On It** - 【TCIRC】 d021. AP325 Q-2-12. The Closest Submatrix Sum（108 High School National Competition）（＊）

**Remove Unused Code** - 【TCIRC】 d023. AP325 Q-2-14. Pond（108 High School National Competition）（@@）

**Solved** - 【TCIRC】 d023. AP325 Q-2-14. Pond（108 High School National Competition）（@@）

**Solved** - 【TCIRC】 d022. AP325 Q-2-13. Exponentiation by Squaring with Irrational Numbers（108 High School National Competition, Simplifed）

**Change File Name** - 【TCIRC】 d020. AP325 P-2-11. The Closest Interval Sum（＊） 

## 2023. 12. 31

**Solved** - 【TCIRC】 d018. AP325 P-2-9. Subset Product（Halved Enumeration）（@@）

**Solved** - 【TCIRC】 d019. AP325 Q-2-10. Subset Sum（Halved Enumeration）

**Solved** - 【TCIRC】 d020. AP325 P-2-11. The Closest Interval Sum（*）

## 2023. 12. 30

**Solved** - 【TCIRC】 d016. AP325 Q-2-7. Complementary Teams（APCS201906）

**Opt** - 【TCIRC】 d016. AP325 Q-2-7. Complementary Teams（APCS201906）

**Solved** - 【TCIRC】 d018. AP325 Q-2-8 Modular Multiplicative Inverse

**Modify File Name** - 【TCIRC】 d017. AP325 Q-2-8 Modular Multiplicative Inverse

## 2023. 12. 29

**Solved** - 【TCIRC】 d015. AP325 P-2-6. Two-Number Problem

**Solved** - 【TCIRC】 d014. AP325 Q-2-5. Exponentiation by Squaring with Fibonacci Numbers

## 2023. 12. 16

**Solved** - 【TCIRC】 d013. AP325 Q-2-4. Exponentiation by Squaring — Integers Less than 200 Digits

**Modify File Name** - 【TCIRC】 d012. AP325 P-2-3. Exponentiation by Squaring

**Solved** - 【TCIRC】 d012. Exponentiation by Squaring

**Solved** - 【ZeroJudge】 f581. 3. Roundabout Exit

**Solved** - 【TCIRC】 d011. AP325 P-2-2. Discretization – Sort

## 2023. 12. 15

**Solved** - 【TCIRC】 d009. AP325 Q-1-11. Delete Rectangle Edge — Recursive（APCS201910, Subtask）

## 2023. 12. 14

**Solved** - 【ZeroJudge】 f640. Function Expression Evaluation

## 2023. 12. 10

**Solved** - 【CSES】 1163. Traffic Lights

## 2023. 12. 08

**Solved** - 【AtCoder】 Beginner Contest 330 - E. Mex and Update

## 2023. 12. 02

**Solved** - 【AtCoder】 Beginner Contest 331 - A. Tomorrow

**Solved** - 【AtCoder】 Beginner Contest 331 - B. Buy One Carton of Milk

**Solved** - 【AtCoder】 Beginner Contest 331 - C. Sum of Numbers Greater Than Me

## 2023. 11. 29

**Solved** - 【AtCoder】 Beginner Contest 329 - F. Colored Ball

**WA** - 【AtCoder】 Beginner Contest 329 - E. Stamp

## 2023. 11. 19

**Solved** - 【AtCoder】 Beginner Contest 329 - D. Election Quick Report

## 2023. 11. 14

**Solved** - 【CSES】 1141. Playlist

## 2023. 11. 12

**Solved** - 【AtCoder】 Beginner Contest 328 - A. Not Too Hard

**Solved** - 【AtCoder】 Beginner Contest 328 - B. 11.11

**Solved** - 【AtCoder】 Beginner Contest 328 - C. Consecutive

**Solved** - 【AtCoder】 Beginner Contest 328 - D. Take ABC

## 2023. 11. 10

**Solved** - 【CSES】 1640. Sum of Two Values

**Solved** - 【CSES】 1074. Stick Lengths

**Solved** - 【CSES】 1643. Maximum Subarray Sum 

**solved** - 【CSES】 2216. Collecting Numbers

**solved** - 【CSES】 2183. Missing Coin Sum

## 2023. 11. 04

**Solved** - 【AtCoder】 Beginner Contest 327 - A. ab

**Solved** - 【AtCoder】 Beginner Contest 327 - B. A^A

**Solved** - 【AtCoder】 Beginner Contest 327 - C. Number Place

**Solved** - 【AtCoder】 Beginner Contest 327 - D. Good Tuple Problem

**Solved** - 【CSES】 1668. Building Teams

**Solved** - 【CSES】 1669. Round Trip

## 2023. 11. 03

**Solved** - 【ZeroJudge】 b898. 1. Pythagorean Theorem

**Solved** - 【ZeroJudge】 c520. 5. Boss Baodao

**Solved** - 【ZeroJudge】 b899. 2. Item Detect

**Solved** - 【ZeroJudge】 b900. 3. Squirmy Worm

**Solved** - 【CSES】 1636. Coin Combinations II

**Solved** - 【CSES】 1637. Removing Digits

**Solved** - 【CSES】 1158. Book Shop

## 2023. 10. 31

**Solved** - 【AtCoder】 Educational DP Contest - E. Knapsack 2

**Change Name** - 【AtCoder】 Educational DP Contest - D. Knapsack 1

**Solved** - 【AtCoder】 Educational DP Contest - G. Longest Path

**Solved** - 【AtCoder】 Educational DP Contest - H. Grid 1

## 2023. 10. 30

**Solved** - 【AtCoder】 Beginner Contest 325 - A. Takahashi San

**Solved** - 【AtCoder】 Beginner Contest 325 - C. Sensors

**Solved** - 【AtCoder】 Beginner Contest 325 - D. Printing Machine

**Solved** - 【AtCoder】 Beginner Contest 325 - E. Our Clients, Please Wait a Moment

## 2023. 10. 27

**Solved** - 【ZeroJudge】 c518. 3. String Encryption

## 2023. 10. 26

**Solved** - 【ZeroJudge】 c517. 2. South Bird

## 2023. 10. 25

**Solved** - 【CSES】 2195. Convex Hull

**Solved** - 【CSES】 2191. Polygon Area

**Solved** - 【CSES】 1673. High Score

## 2023. 10. 24

**Solved** - 【AtCoder】 Beginner Contest 324 - E. Joint Two Strings

**Solving** - 【AtCoder】 Beginner Contest 324 - F. Beautiful Path

**TLE** - 【AtCoder】 Beginner Contest 324 - F. Beautiful Path

**Solved** - 【AtCoder】 Beginner Contest 324 - F. Beautiful Path

**Solved** - 【AtCoder】 Educational DP Contest - F. LCS

**Change File Name** - 【AtCoder】 Educational DP Contest - A. Frog 1

**Change File Name** - 【AtCoder】 Educational DP Contest - B. Frog 2

**Change File Name** - 【AtCoder】 Educational DP Contest - C. Vacation

## 2023. 10. 18

**Solved** - 【AtCoder】 Educational DP Contest - D. Knapsack 1

## 2023. 10. 17

**Solved** - 【Luogu】 P1901. Transmitting Station

## 2023. 10. 16

**Solved** - 【CF】 APCS Practice Contest - B. Ladder String

## 2023. 10. 14

**Solved** - 【CF】 APCS Practice Contest - A. ABC5

## 2023. 10. 09

**Solved** - 【CSES】 2189. Point Location Test

## 2023. 10. 07

**Opt** - 【CSES】 1646. Static Range Sum Queries

**Solved** - 【CSES】 1629. Movie Festival

**Solved** - 【CSES】 1111. Longest Palindrome

## 2023. 10. 06

**Solved** - 【CSES】 1619. Restaurant Customers

**Solved** - 【CSES】 1666. Building Roads

## 2023. 10. 04

**Solved** - 【CSES】 1131. Tree Diameter

## 2023. 10. 03

**Solved** - 【TIOJ】 1224. Rectangular Coverage Area

## 2023. 09. 30

**Solved** - 【CSES】 1623. Apple Division

**Solved** - 【AtCoder】 Beginner Contest 182 - A. Twiblr

**Solved** - 【AtCoder】 Beginner Contest 182 - B - Almost GCD

**Solved** - 【AtCoder】 Beginner Contest 182 - C - To 3

**TLE** - 【AtCoder】 Beginner Contest 182 - D. Wandering

## 2023. 09. 27

**Solved** - 【Green Judge】 d086-2. Settle Accounts

## 2023. 09. 26

**Solved** - 【TOJ】 628. Komachi

## 2023. 09. 22

**Solved** - 【AtCoder】 Beginner Contest 314 - D. LOWER

**Solved** - 【TOJ】 630. EatAllLeftMost

## 2023. 09. 20

**Solved** - 【TOJ】 273. Diamond

## 2023. 09. 16

**Solved** - 【AtCoder】 Beginner Contest 320 - A - Leyland Number

**Remain 1 WA** - 【AtCoder】 Beginner Contest 320 - D. Relative Position

**Solved** - 【AtCoder】 Beginner Contest 320 - E. Somen Nagashi

## 2023. 09. 13

**Solved** - 【CSES】 1753. String Matching

## 2023. 09. 07

**Solved** - 【2023 MD Player Training】 Simulation Contest 1 - A. Fivesteps

**Solved** - 【CSES】 1628. Meet In The Middle

## 2023. 09. 02

**Solved** - 【AtCoder】 Beginner Contest 318 - A - Full Moon

**Solved** - 【AtCoder】 Beginner Contest 318 - B - Overlapping sheets

**Solved** - 【AtCoder】 Beginner Contest 318 - C - Blue Spring

**Solved** - 【AtCoder】 Beginner Contest 315 - A - Tcdr

**Solved** - 【AtCoder】 Beginner Contest 315 - B - The Middle Day

**Solved** - 【AtCoder】 Beginner Contest 315 - C - Flavors

**Solved** - 【AtCoder】 Beginner Contest 315 - E - Prerequisites

## 2023. 09. 01

**Solved** - 【CSES】 1190. Subarray Sum Queries

## 2023. 08. 29

**1/3 WA** - 【AtCoder】 Beginner Contest 317 - E - Avoid Eye Contact

## 2023. 08. 28

**Solved** - 【AtCoder】 Beginner Contest 317 - D - President

## 2023. 08. 27

**Solved** - 【AtCoder】 Beginner Contest 317 - A - Potions

**Solved** - 【AtCoder】 Beginner Contest 317 - B - MissingNo

**Solved** - 【AtCoder】 Beginner Contest 317 - C - Remembering the Days

## 2023. 08. 25

**Solved** - 【2023 MD Player Training】 Simulation Contest 1 - B. Conveyor

## 2023. 08. 24

**Solved** - 【MDJudge】 B053. Go Alone

## 2023. 08. 23

**Solved** - 【TIOJ】 1198. 8-puzzle

## 2023. 08. 22

**15% Solution** - 【2023 MD Player Training】 Simulation Contest 1 - B. Conveyor

**20% Solution** - 【2023 MD Player Training】 Simulation Contest 1 - A. Fivesteps

**Solved** - 【2023 MD Player Training】 Simulation Contest 1 - C. Hsr

**Solved** - 【CSES】 1137. Subtree Queries

## 2023. 08. 19

**Solved** - 【CSES】 1202. Investigation

## 2023. 08. 18

**Solved** - 【AtCoder】 Beginner Contest 178 - F - Contrast

## 2023. 08. 17

**Solved** - 【CSES】 1622. Creating Strings

**Solved** - 【CSES】 2205. Gray Code

**Solved** - 【CSES】 1143. Hotel Queries

**Solved** - 【AtCoder】 Beginner Contest 196 - D - Hanjo

## 2023. 08. 16

**Solved** - 【AtCoder】 Beginner Contest 152 - D - Handstand 2

**Solved** - 【CSES】 1755. Palindrome Reorder

## 2023. 08. 12

**Solved** - 【CSES】 1754. Coin Piles

## 2023. 08. 11

**Solved** - 【CSES】 1618. Trailing Zeros

## 2023. 08. 10

**Solved** - 【CSES】 1687. Company Queries I

**Solved** - 【CSES】 1688. Company Queries II

## 2023. 08. 09

**Haven't Finish** - 【CSES】 1734. Distinct Values Queries

## 2023. 08. 07

**Solved** - 【CSES】 1649. Dynamic Range Minimum Queries

## 2023. 08. 06

**Haven't Finish** - 【Luogu】 P1313. [ NOIP2011 Improvement Group ] Calculation Coefficient

**Solved** - 【CSES】 1712. Exponentiation II

## 2023. 08. 05

**Haven't Finish** - 【CF】 1394A. Orac and LCM

## 2023. 08. 04

**Solved** - 【CSES】 1650. Range Xor Queries

## 2023. 08. 03

**Solved** - 【ZeroJudge】 d799. Interval Summation

## 2023. 08. 02

**Solved** - 【AtCoder】 Beginner Contest 119 - C - Synthetic Kadomatsu

## 2023. 08. 01

**Solved** - 【CSES】 1195. Flight Discount

## 2023. 07. 31

**Solved** - 【AtCoder】 Beginner Contest 100 - D - Patisserie ABC

## 2023. 07. 30

**Solved** - 【TOJ】 36. Simple Problem

**Solved** - 【CSES】 1072. Two Knights 

## 2023. 07. 29

**Solved** - 【CSES】 1161. Stick Divisions

**Solved** - 【CSES】 1630. Tasks and Deadlines

## 2023. 07. 26

**TLE Answer** - 【AtCoder】 Beginner Contest 100 - D - Patisserie ABC

**Solved** - 【UVa】 441. Lotto

## 2023. 07. 25

**Seems Like AC, but UVa Was Dead** - 【UVa】 441. Lotto

## 2023. 07. 24

**Solved** - 【CSES】 1091. Concert Tickets

## 2023. 07. 22

**Solved** - 【UVa】 291. The House Of Santa Claus

## 2023. 07. 21

**Solved** - 【CSES】 1635. Coin Combinations I

**Solved** - 【CSES】 1085. Array Division

## 2023. 07. 20

**Solved** - 【CSES】 1673. High Score

**Solved** - 【CSES】 1672. Shortest Routes II

**Solved** - 【CSES】 1671. Shortest Routes I

## 2023. 07. 19

**Solved** - 【CSES】 1090. Ferris Wheel

**Solved** - 【Luogu】 P1396. Rescue

## 2023. 07. 18

**Solved** - 【CSES】 1092. Two Sets

**Solved** - 【CSES】 1670. Swap Game

**Solved** - 【CSES】 1634. Minimizing Coins

**Solved** - 【CSES】 1617. Bit Strings

## 2023. 07. 17

**Solved** - 【CSES】 1071. Number Spiral

**Solved** - 【TCIRC】 d097. AP325 P-7-10 Pit Jumping

## 2023. 07. 16

**Solved** - 【AtCoder】 Competitive Professional Typical 90 Questions - 002 - Encyclopedia of Parentheses（★3）

**Solved** - 【CSES】 1624. Chessboard and Queens

## 2023. 07. 14

**Solved** - 【UVa】 195. Anagram

## 2023. 07. 13

**TLE Answer** - 【UVa】 195. Anagram

## 2023. 07. 12

**Solved** - 【ZeroJudge】 e446. Arrangement Generation

## 2023. 07. 09

**Solved** - 【CSES】 1070. Permutations

**Solved** - 【CSES】 1094. Increasing Array

## 2023. 07. 08

**Solved** - 【CSES】 1096. Repetitions

**Solved** - 【MDJudge】 C040. Question 10 of the 2020 CIC Quarterfinals

## 2023. 07. 04

**Solved** - 【ZeroJudge】 a674. 10048 - Audiophobia

## 2023. 07. 02

**Solved** - 【Luogu】 P1629. Postman Delivering Letter

## 2023. 06. 25

**Solved** - 【ZeroJudge】 k734. Open Treasure Box

**Solved** - 【CF】 510C. Fox And Names 

## 2023. 06. 18

**Solved** - 【Luogu】 P1036. [ NOIP2002 Popularization Group ] Selection Number

**Solved** - 【Luogu】 P2677. [ USACO07DEC ] Bookshelf 2 B

**Solved** - 【AtCoder】 Beginner Contest 240 - C - Jumping Takahashi

**Solved** - 【Luogu】 P1100. High and Low Swap

**Solved** - 【TIOJ】 1081. B. Image recognition

## 2023. 06. 17

**Solved** - 【Kattis】 Playfair Cipher

**Solved** - 【Luogu】 P1352. Prom Without Boss

**50% Solution** - 【TIOJ】 1081. B. Image recognition

## 2023. 06. 09

**Solved** - 【CSES】 1674. Subordinates

**Solved** - 【Luogu】 P3374［Template］Binary Indexed Tree 1

## 2023. 06. 02

**Solved** - 【NTFSOJ】 275 Dynamic Median

## 2023. 05. 28

**Solved** - 【ZeroJudge】 a020. ID Verification

## 2023. 05. 27

**Solved** - 【CF】 ( 2023 MD Subject Ability Intramural Competition ) E. Stock Analyst

**Solved** - 【CF】 ( 2023 MD Subject Ability Intramural Competition ) B. Tim Chen no Loli Base

## 2023. 05. 26

**Solved** - 【CF】 ( 2023 MD Subject Ability Intramural Competition ) D. Checkered Arena

## 2023. 05. 24

**Solved** - 【CSES】 1620. Factory Machines

**Solved** - 【CSES】 1667. Message Route

## 2023. 05. 23

**Half AC Haven't Solved** - 【CSES】 1085. Array Division

**Solved** - 【AtCoder】 DP Contest - C - Vacation

## 2023. 05. 18 

**Solved** - 【ZeroJudge】 b844. A Bunch of Buttons

## 2022. 07. 21

**Solved** - 【CSES】 1646. Static Range Sum Queries
