# Problem 1

Define indicator random variables $I_i$ for $i = 1, 2, \ldots, 2n$ such that:
$$
I_i = \begin{cases}
1 & \text{if ball } i \text{ is thrown into bin 1} \\
0 & \text{if ball } i \text{ is thrown into bin 2}
\end{cases}\\
 X_1 = \sum_{i=1}^{2n} I_i ,\quad X_2 = 2n - X_1
$$

$$
\mathbb{E}[X_1] = \sum_{i=1}^{2n} \mathbb{E}[I_i] = \sum_{i=1}^{2n} \frac{1}{2} = n\\

\text{Var}(X_1) = \sum_{i=1}^{2n} \text{Var}(I_i) = \sum_{i=1}^{2n} \left( \frac{1}{2} \cdot \frac{1}{2} \right) = \frac{2n}{4} = \frac{n}{2}
$$


$$
X_1 - X_2 = X_1 - (2n - X_1) = 2X_1 - 2n
$$
$$
\Pr[X_1 - X_2 > c \sqrt{n}] = \Pr[2X_1 - 2n > c \sqrt{n}] =\Pr [X_1 - n > \frac{c \sqrt{n}}{2}]
$$

According to Chebychev’s Inequality,
$$
\Pr(X_1-n\ge a )\le \frac{n}{2a^2}
$$

Let $a = \frac{c \sqrt{n}}{2}$​， then 
$$
\Pr [X_1 - n > a] \le \frac{2}{c^2}\\
\frac{2}{c^2} \le \epsilon\\
c \ge \sqrt{\frac{2}{\epsilon}} 
$$



---
# Problem 2

Let $ X_i $ be the indicator random variable for the $ i $-th run, where $ X_i = 1 $ if the algorithm produces the correct result on the $ i $-th run and $ X_i = 0 $ otherwise.

$$
\Pr(X_i = 1) = p \geq \frac{2}{3}
$$

Define $ X $ as the total number of correct results out of $ n $ runs:
$$
X = \sum_{i=1}^{n} X_i
$$

$$
\mu = \mathbb{E}[X] = np
$$

Suppose we need the majority of the runs to be correct for the final answer to be correct. Then the probability that this modified algorithm produces an incorrect result is:
$$
\Pr\left( X \leq \frac{n}{2} \right)
$$
According to Chernoff Bounds,
$$
\Pr(X \leq (1 - \delta)\mu) \leq e^{-\frac{\delta^2 \mu}{2}}
$$

$$
\frac{n}{2} = (1 - \delta)\mu \\
\delta = 1 - \frac{\frac{n}{2}}{np} = 1 - \frac{1}{2p} \leq \frac{1}{4}
$$

$$
\Pr\left( X \leq \frac{n}{2} \right) \leq e^{-\frac{\left(\frac{1}{4}\right)^2 np}{2}} = e^{-\frac{n p}{32}}\leq e^{-\frac{n \cdot \frac{2}{3}}{32}} = e^{-\frac{n}{48}}
$$

---

# Problem 3

Suppose the greedy algorithm uses $A$ piggy banks.

Let the optimal schedule uses $A^*$ piggy banks.

The total size of all coins is $C = \sum^n_{i = 1} c_i$.
$$
A^* \ge \frac{S}{V} \\
S \le A^* V
$$
According to our greedy algorithm, there is at most 1 piggy bank that is less than half full.
$$
S \ge \frac{V}{2}(A-1) \\
A^* V \ge \frac{V}{2}(A-1) \\
A^*  \ge \frac{1}{2}(A-1)\\
A^*  > \frac{A}{2}
$$
Therefore, this algorithm is a 2-approximation.

---

# Problem 4

## 1

Consider any node $ v \in T $.
- If $ v \in S $, the condition is trivially satisfied.
- If $ v \notin S $, it must have been removed from $ V $ at some step in the algorithm when one of its neighbors, say $ v' $, was added to $ S $.
  - By the algorithm, $ v' $ was chosen because $ w(v') $ was at least as large as any other weight in the remaining $ V $ at that step, which means $ w(v) \leq w(v') $ 

## 2

Let $S$  be the independent set given by the greedy algorithm with weight $W(S)$.

Let $S^*$  be an optimal independent set with maximum total weight $W(S^∗)$.

Each node  $v \in S^*$ is either in $S$ or is adjacent to a node in $S$ with weight at least as large as $v$.

Each node $v$ can have up to 4 neighbors in this grid graph $G$.

Since each node in $S$ can be adjacent to up to 4 nodes in $S^*$, the total weight of nodes in $ S^* $ covered by one node in $ S $ is at most 4 times the weight of that node in $S$.

Therefore, $W(S)\ge \frac{1}{4}W(S^*)$, the greedy algorithm is a 4-approximation for the problem.















