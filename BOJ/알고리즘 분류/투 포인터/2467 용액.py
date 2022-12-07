import sys

n = int(input())

MAX = 2_000_000_001

arr = list(map(int, sys.stdin.readline().strip().split()))

mn = MAX

left = 0
right = len(arr)-1
ans = [[0,0]]
while left < right:
  value = arr[left] + arr[right]
  if abs(mn) > abs(value):
    mn = value
    ans[0] = [arr[left], arr[right]]
    continue
  flag = left + 1 < right and abs(arr[left] + arr[right-1]) >= abs(arr[left+1] + arr[right])
  if flag: left += 1 
  else: right -= 1


print(*ans[0])
