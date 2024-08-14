print("FIRST COME FIRST SERVE SCHEDULING")
n = int(input("Enter number of processes: "))
processes = {}

# Input for arrival time and burst time for each process
for i in range(n):
    key = "P" + str(i + 1)
    arrival_time = int(input(f"Enter arrival time of process {i + 1}: "))
    burst_time = int(input(f"Enter burst time of process {i + 1}: "))
    processes[key] = [arrival_time, burst_time]

# Sort processes based on arrival time
sorted_processes = sorted(processes.items(), key=lambda item: item[1][0])

ET = [sorted_processes[0][1][1]]
for (key, process) in sorted_processes[1:]:
    ET.append(ET[-1] + process[1])

TAT = [ET_i - process[0] for (key, (process)) , ET_i in zip(sorted_processes, ET)]
WT = [TAT_i - process[1] for (key, process), TAT_i in zip(sorted_processes, TAT)]

avg_WT = sum(WT) / n  # Average Waiting Time

# Display only the average waiting time
print("Average Waiting Time:", avg_WT)
