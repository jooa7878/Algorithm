n, m = map(int, input().split())

truth = list(map(int, input().split()))
truth_list = truth[1:]

parent = [i for i in range(n+1)]


def find(node):
  if parent[node] != node:
    parent[node]  = find(parent[node])  
  return parent[node]


def union(a, b):
  aParent = find(a)
  bParent = find(b)
  if bParent in truth_list:
    before = parent[aParent]
    parent[aParent] = parent[bParent]
    for i in range(len(parent)):
      if parent[i] == before:
        parent[i] = parent[bParent]
  elif aParent in truth_list:
    before = parent[bParent]
    parent[bParent] = parent[aParent]
    for i in range(len(parent)):
      if parent[i] == before:
        parent[i] = parent[aParent]
  elif aParent < bParent :
    before = parent[bParent]
    parent[bParent] = aParent
    for i in range(len(parent)):
      if parent[i] == before:
        parent[i] = aParent
  elif aParent >= bParent:
      before = parent[aParent]
      parent[aParent] =bParent
      for i in range(len(parent)):
        if parent[i] == before:
          parent[i] = bParent

def solve():
  if truth[0] == 0:
    return m

  ans = 0
  party_list = []
  for _ in range(m):
    temp = list(map(int, input().split()))
    party_list.append(temp)
    num = temp[0]
    arr = temp[1:]
    for i in range(num-1):  
      union(arr[i], arr[i+1])
    
  
  for i in range(len(party_list)):
    party = party_list[i][1:]
    flag = True
    for i in range(len(party)):
      if parent[party[i]] in truth_list:
        flag =False
        break
    if flag : ans += 1

  return ans
  

print(solve())
