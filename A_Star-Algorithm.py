def a_star_search(graph, start, goal, heuristic):
    open_list = [start]  # Nodes to explore
    closed_list = []     # Explored nodes
    g_costs = {start: 0} # Cost to reach each node
    came_from = {}       # To track the path

    while open_list:
        # Find the node with the smallest g_cost + heuristic
        current_node = open_list[0]
        for node in open_list:
            if g_costs[node] + heuristic(node, goal) < g_costs[current_node] + heuristic(current_node, goal):
                current_node = node

        # If goal is reached, reconstruct the path
        if current_node == goal:
            path = []
            while current_node in came_from:
                path.append(current_node)
                current_node = came_from[current_node]
            path.append(start)
            return path[::-1]

        # Move the current node to the closed list
        open_list.remove(current_node)
        closed_list.append(current_node)

        # Explore neighbors
        for neighbor, cost in graph[current_node]:
            if neighbor in closed_list:
                continue  # Skip already explored nodes

            tentative_g_cost = g_costs[current_node] + cost
            if neighbor not in open_list:
                open_list.append(neighbor)
            elif tentative_g_cost >= g_costs.get(neighbor, float('inf')):
                continue  # Skip if this path isn't better

            # Update costs and path
            g_costs[neighbor] = tentative_g_cost
            came_from[neighbor] = current_node

    # If no path is found
    return None

# Example graph (nodes and weighted edges)
graph = {
    'A': [('B', 1), ('C', 3)],
    'B': [('D', 1), ('E', 4)],
    'C': [('F', 2)],
    'D': [('G', 3)],
    'E': [('G', 1)],
    'F': [('G', 5)],
    'G': []
}

# Example heuristic function
def heuristic(node, goal):
    # A predefined straight-line distance (heuristic) for this example
    distances = {
        'A': 7,
        'B': 6,
        'C': 4,
        'D': 3,
        'E': 2,
        'F': 5,
        'G': 0
    }
    return distances[node]

# Find the path
path = a_star_search(graph, 'A', 'G', heuristic)
print("Path:", path)
