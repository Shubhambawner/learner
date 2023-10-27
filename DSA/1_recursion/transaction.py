import itertools

# Function to check if a number is prime
def is_prime(num):
    if num < 2:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True

# Function to count sets of three prime numbers whose XOR is zero and are less than N
def good_keys(N):
    count = 0

    for num1 in range(2, N):
        if is_prime(num1):
            for num2 in range(num1 + 1, N):
                if is_prime(num2):
                    for num3 in range(num2 + 1, N):
                        if is_prime(num3) and (num1 ^ num2 ^ num3 == 0):
                            count += 1

    return count

# Example usage:
N = 459  # Replace with your desired value of N
result = good_keys(N)
print(f"Number of sets of three prime numbers XOR zero less than {N}: {result}")
