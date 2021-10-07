# Topological sort is an algorithm to sort taking into consideration
# dependences between nodes, so we need to figure out the order of the elements.
# Applications: Software dependences, path of educational courses, ...

# Input: DAG (Directed Acyclic Graph)
# Output: print all items in a permissible order.
from collections import deque


def generate_topological_order(dag):
    n = len(dag)
    in_degrees = [0] * n
    ans = []

    for vertex in dag:
        for i in range(len(vertex)):
            in_degrees[vertex[i]] += 1

    q = deque()

    # add independent items
    for i in range(n):
        if in_degrees[i] == 0:
            q.append(i)

    # traversal from independent ones to dependent ones
    while(len(q) > 0):
        item = q.popleft()
        vertex = dag[item]

        for v in vertex:
            in_degrees[v] -= 1

            if in_degrees[v] == 0:
                q.append(v)

        ans.append(item)

    return ans


if __name__ == '__main__':
    n = int(input("Number of items: "))

    dag = [[] for i in range(n)] # adjacency list

    edges = int(input("Number of edges: "))

    for i in range(edges):
        a, b = list(map(int, input().split()))

        dag[a].append(b)

    ans = generate_topological_order(dag)
    print(ans)
