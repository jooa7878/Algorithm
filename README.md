# Algorithm_with_Cpp


Greedy
=====

> 현재 상황에서 지금 당장 좋은 것만 고르는 방법

+ 대표 문제 거스름돈
  + <https://www.acmicpc.net/problem/5585>

Backtracking
============

> 가능한 모든 방법을 탐색한다. 대표적으로 DFS(Depth First Search, 깊이 우선 탐색)가 있다.


```
  DFS는 현재 지점에서 방문할 곳이 있으면 재귀 호출을 이용해서 계속 이동하는 것으로
  무한히 깊은 곳을 찾아야할 때 효과적이다. 굳이 목표지점이 있지 않는 경로를 탐색한다는 비효율성이 존재한다.
  따라서 이러한 비효율성을 차단하고 목표지점에 갈 수 있는 가능성을 검사하는 방법이 Backtracking 알고리즘이다.
  DFS에 가지치기(Pruning)를 통해 가지 않아도 되는 루트를 고려하는 완전탐색 기법이다.
```

+ 대표 문제 N-Queen
  + <https://www.acmicpc.net/problem/9663>
