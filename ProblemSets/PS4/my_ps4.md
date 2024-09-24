# Problem 1

First prove Set-Packing is NP.

#### Verifier

- Certificate y is k subsets from D.

- Check whether these subsets are mutually disjoint.
- If so, output 1, else output 0.

#### If x is yes instance

- Then there exist k subsets from D which are mutually disjoint.
- Give y to V, and V outputs 1.

#### If x is no instance

- Then every k subsets from D which are not mutually disjoint.
- So V outputs 0, no matter what k subsets it gets.

#### V runs in polynomial time

- Checking whether these k subsets are mutually disjoint takes $O(C^2_k)=O(k^2)$​ time.



Then reduce from Independent Set.

Given a graph $ G = (V, E) $ and an integer, is there a subset $ V' \subseteq V $ such that $ |V'| \geq k $ and no two vertices in $ V' $ are adjacent?

#### Reduction

- $C = E$
-  $S_v = \{e|e\in E,e \text{ incident with } v \}$​ 
-  Use the same $k$​ from the Independent Set instance.

The reduction takes polynomial time $O(E+V^2)$.

#### Proof of correctness

- if $V'$ is a yes instance for Independent Set, then $ |V'| \geq k $ and no two vertices in $ V' $ are adjacent. For any two vertices $v',u' \in V'$, $S_{v’}$ and $S_{u'}$ are disjoint, since $S_{v'}$ are the set of all edges incident with $v'$, $S_{u'}$ are the set of all edges incident with $u'$, and $v', u'$ are not adjacent. Therefore, there are $k$ subsets from the collection which are pairwise disjoint.

- If there are $k$ subsets from the collection which are pairwise disjoint, then for any two subsets $S_{v’}$ and $S_{u'}$,  $v', u'$ are not adjacent. Therefore there is a subset $ V' \subseteq V $ such that $ |V'| = k $ and no two vertices in $ V' $ are adjacent.

---

# Problem 2

First prove Stingy-SAT is NP.

#### Verifier

- Certificate y is a Boolean CNF with at most k variables are set to true.

- Check whether the formula has a satisfying assignment.
- If so, output 1, else output 0.

#### If x is yes instance

- Then the formula has a satisfying assignment.
- Give y to V, and V outputs 1.

#### If x is no instance

- Then the formula doesn’t have a satisfying assignment.
- So V outputs 0.

#### V runs in polynomial time

- Checking whether the formula has a satisfying assignment takes $O(n)$ time if $n$ is the number of variables in the formula.



Then reduce from SAT.

### Reduction

Given an instance of SAT I, let (I, k) be an instance of stingy SAT where k = the number of variables in SAT instance I.

The reduction takes polynomial time $O(k)$.

### Proof of correctness

- If the SAT with k variables has a satisfying assignment, the corresponding STINGY SAT have a satisfiying assignment with true variables number less than k.

- If the SAT with k variables has no satisfying assignment, the STINGY SAT has no satisfying assignment.

---

# Problem 3

First prove Set-Cover is NP.

#### Verifier

- Certificate y is at most $k$ subsets from the collection of subsets of $C$.

- Check whether the subsets cover $C$.
- If so, output 1, else output 0.

#### If x is yes instance

- Then the subsets cover $C$.
- Give y to V, and V outputs 1.

#### If x is no instance

- Then the subsets don’t cover $C$.
- So V outputs 0.

#### V runs in polynomial time

- Checking whether the subsets cover $C$ by iterating over each element in the subsets of collection and mark the elements in $C$ which are covered. It takes polynomial time.



Then reduce from Vertex Cover.

Given a graph $G=(V,E)$ and an integer k, whether the graph has a vertex cover less or equal to k.

### Reduction

- $C=E$
- $S_v = \{e|e\in E,e \text{ incident with } v \}$ 
- Use the same $k$ from the Vertex Cover instance.

The reduction takes polynomial time $O(E+V^2)$.

### Proof of correctness

- If $G$ has a vertex cover $V'$ less or equal to k, then the union of $S_v$ for any vertex $v \in V'$ can cover all the edges, that is $C$ since $C=E$​. Therefore, there are at most k subsets from the collection which cover $C$.
- If there are at most $k$ subsets from the collection which cover $C$, then the union of these subsets includes all of $E$, therefore $G$ has a vertex cover $V'$ less or equal to k.

---

# Problem 4

Denote the list of unique positive integers as $\{a_1,a_2,…,a_n\}$.

For $1\le k \le n$, the probability that $a_k$ is the largest among the first $k$ numbers is $\frac{1}{k}$.
$$
E = \sum_{k=1}^{n} \frac{1}{k}
$$
When $n \to \infty$, $E\to \ln (n)$
