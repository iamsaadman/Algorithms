import random
import math

# A very simple function to minimize (e.g., f(x) = x^2)
def function(x):
    return x ** 2

# Simulated Annealing
def simulated_annealing():
    current_state = random.uniform(-10, 10)  # Start at a random position
    current_value = function(current_state)  # Compute the value at the start point
    temperature = 100  # Initial temperature
    cooling_rate = 0.95  # Cooling rate

    while temperature > 0.01:  # Stop when the temperature is very low
        # Generate a new random state near the current state
        new_state = current_state + random.uniform(-1, 1)
        new_value = function(new_state)

        # If the new state is better, accept it
        if new_value < current_value:
            current_state = new_state
            current_value = new_value
        else:
            # If the new state is worse, accept it with a small probability
            probability = math.exp((current_value - new_value) / temperature)
            if random.random() < probability:
                current_state = new_state
                current_value = new_value

        # Reduce the temperature
        temperature *= cooling_rate

    # Return the best state and its value
    return current_state, current_value

# Run the algorithm
best_state, best_value = simulated_annealing()
print("Best state:", best_state)
print("Best value:", best_value)
