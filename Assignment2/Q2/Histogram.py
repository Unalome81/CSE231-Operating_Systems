import matplotlib.pyplot as plt
import numpy as np

def read_values(filename):
    with open(filename, 'r') as file:
        return [int(line.strip()) for line in file]

shed_fifo_values = read_values('SCHED_FIFO')
shed_rr_values = read_values('SCHED_RR')
shed_other_values = read_values('SCHED_OTHER')


print("Average SCHED_FIFO Time:", np.mean(shed_fifo_values))
print("Average SCHED_RR Time:", np.mean(shed_rr_values))
print("Average SCHED_OTHER TIME:", np.mean(shed_other_values))

n = len(shed_fifo_values) #number of values in the text file

x = np.arange(1, n + 1)

width = 0.2

plt.bar(x - width, shed_fifo_values, width, label='SCHED_FIFO', alpha=0.5)
plt.bar(x, shed_rr_values, width, label='SCHED_RR', alpha=0.5)
plt.bar(x + width, shed_other_values, width, label='SCHED_OTHER', alpha=0.5)

max_value = max(max(shed_fifo_values), max(shed_rr_values), max(shed_other_values))

plt.ylim(0, max_value * 1.1)  

plt.xlabel('Iterations')
plt.ylabel('Time (in milliseconds)')
plt.title('Time Distribution by Scheduling Policy')

plt.xticks(x, range(1, n + 1))

plt.legend()

plt.show()
