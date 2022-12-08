import sys
sys.setrecursionlimit(100000)
n, m = map(int, sys.stdin.readline().split())
parent = [i for i in range(n+1)]

def find(node):
  if parent[node] != node:
    parent[node] =  find(parent[node])
  return parent[node]

def union(a, b):
  aParent = find(a)
  bParent = find(b)
  if aParent < bParent : parent[bParent] = aParent
  else: parent[aParent] = bParent

for _ in range(m):
  flag, node_1, node_2 = map(int, sys.stdin.readline().strip().split())
  if flag == 0: # 합집합, node_1과 node_2를 합치겠다
    union(node_1, node_2)
  else:
    print('YES' if find(node_1) == find(node_2) else 'NO')

