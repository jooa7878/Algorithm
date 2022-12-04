str = input()

s = set()

for i in range(len(str)):
  for j in range(i+1,len(str)+1):
    s.add(str[i:j])

print(len(list(s)))
