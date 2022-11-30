n = int(input())

arr = list(map(int, input().split()))

mx = int(input())
ans = 0
def solution():
  global ans
  if mx > sum(arr):
    print(max(arr))
    return

  left = 0 
  right = max(arr)
  while left <= right:
    mid = (left + right) // 2
    temp = 0
    for i in arr:
      temp += mid if i > mid else i
    if temp <= mx:
      ans = mid
      left = mid + 1
      continue
    right = mid - 1

  print(ans)

solution()
