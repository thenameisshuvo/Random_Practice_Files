n = int(input('Enter no of processes: '))
bt = [0] * n
at = [0] * n
abt = [0] * n

for i in range(n):
    abt[i] = int(input('Enter the burst time for process {}: '.format(i + 1)))
    at[i] = int(input('Enter the arrival time for process {}: '.format(i + 1)))

sumbt = sum(abt)
i = 0
ll = []

for i in range(sumbt):
    l = [j for j in range(len(bt)) if at[j] <= i]
    l = [j for j in l if bt[j] > 0]
    if not l:
        continue
    l.sort(key=lambda x: bt[x])
    bt[l[0]] -= 1
    ll.append([l[0], i + 1])

ct = [0] * n
tat = [0] * n
wt = [0] * n

for i in ll:
    ct[i[0]] = i[1]

for i in range(n):
    tat[i] = ct[i] - at[i]
    wt[i] = tat[i] - abt[i]

print('Average Waiting Time = {:.2f}'.format(sum(wt) / n))
