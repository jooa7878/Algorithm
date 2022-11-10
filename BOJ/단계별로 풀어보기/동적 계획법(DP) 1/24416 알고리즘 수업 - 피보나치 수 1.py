code_1 = 0

def fib(n):
  global code_1
  if n == 1 or n == 2: 
    code_1 += 1
    return 1
  else: return fib(n-1) + fib(n-2)

N = int(input())

fib(N)

print(code_1, N-2)
