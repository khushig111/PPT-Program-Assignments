# Coding questions 

''' 

Q17
17. Write a function that takes a list of numbers as input and returns a new list containing only the even numbers from the input list. Use list comprehension to solve this problem.

Example:

Input: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

Output: [2, 4, 6, 8, 10]







18. Implement a decorator function called ‘timer’ that measures the execution time of a function. The ‘timer’ decorator should print the time taken by the decorated function to execute. Use the ‘time’ module in Python to calculate the execution time.

Example:

import time

@timer
def my_function():
    # Function code goes here
    time.sleep(2)

my_function()

Output:
"Execution time: 2.00123 seconds"









19. Write a function called ‘calculate_mean’ that takes a list of numbers as input and returns the mean (average) of the numbers. The function should calculate the mean using the sum of the numbers divided by the total count.

Example:

def calculate_mean(numbers):
    total = sum(numbers)
    count = len(numbers)
    mean = total / count
    return mean

data = [10, 15, 20, 25, 30]
mean_value = calculate_mean(data)
print("Mean:", mean_value)

Output:
Mean: 20.0
















20. Write a function called ‘perform_hypothesis_test’ that takes two lists of numbers as input, representing two samples. The function should perform a two-sample t-test and return the p-value. Use the ‘scipy.stats’ module in Python to calculate the t-test and p-value.

Example:

from scipy import stats

def perform_hypothesis_test(sample1, sample2):
    t_statistic, p_value = stats.ttest_ind(sample1, sample2)
    return p_value

sample1 = [5, 10, 15, 20, 25]
sample2 = [10, 20, 30, 40, 50]
p_value = perform_hypothesis_test(sample1, sample2)
print("P-value:", p_value)

Output:
P-value: 0.1064706396450037

'''




