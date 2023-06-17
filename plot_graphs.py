import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import numpy as np
from scipy import stats

# Read the CSV file
data = pd.read_csv('Queueing_System_Simulator/simulation_results.csv')

# Filter rows for M/M/1 system with different lambda values
mm1_data = data[(data['Number of Servers'] == 1) & (data['System Capacity'] == 100) & (data['Simulation Time'] == 100)]

# Select the relevant columns
lambda_values = mm1_data['lambda']
avg_waiting_time = mm1_data['Average Waiting Time in Queue']

# Calculate the 95% confidence interval
confidence = 0.95
n = len(mm1_data)
std_err = stats.sem(avg_waiting_time)
margin_error = std_err * stats.t.ppf((1 + confidence) / 2, n - 1)
ci_lower = avg_waiting_time - margin_error
ci_upper = avg_waiting_time + margin_error

# Create the plot
sns.set(style="whitegrid")
plt.errorbar(lambda_values, avg_waiting_time, yerr=margin_error, fmt='o', capsize=4, label='Average Waiting Time in a Queue (with 95% CI)')

# Add lambda and average waiting time values to the graph
for x, y, lam, avg in zip(lambda_values, avg_waiting_time, lambda_values, avg_waiting_time):
    plt.text(x, y, f"lambda={lam}\navg={avg:.2f}", ha='left', va='bottom')

plt.xlabel('Lambda (per sec)')
plt.ylabel('Average Waiting Time in Queue (sec)')
plt.title('M/M/1 System - Average Waiting Time in Queue with 95% CI')
plt.legend()
plt.show()
