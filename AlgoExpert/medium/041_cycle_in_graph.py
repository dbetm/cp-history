# solved
# tags: graph, dfs


def cycleInGraph(edges):
    """My solution
    Time: O(v+e)
    Space: O(v)

    where v is the number of vertex and e the number of edges
    """
    v = len(edges)
    vertices_checked = set()

    for vertex in range(v): 

        if vertex in vertices_checked:
            continue

        stack = [vertex]
        visited = set() 

        while stack:
            current_node = stack.pop()
            print(f"{current_node = }")

            visited.add(current_node)

            nodes = edges[current_node]

            if len(nodes) == 0:
                visited.remove(current_node)

            for node in nodes:
                if node in visited:
                    print(f"{node = } already exists")
                    return True
                print("adding ", node)
                stack.append(node)

        vertices_checked.add(vertex)

    return False


colors = list()
UNVISITED = 0
IN_STACK = 1
DONE = 2


def dfs(edges, vertex):
    if len(edges[vertex]) == 0:
        return False

    global colors

    print(f"{vertex = }")

    if colors[vertex] == IN_STACK:
        return True

    colors[vertex] = IN_STACK

    nodes = edges[vertex]
    ans = False

    for node in nodes:
        ans |= dfs(edges, node)

        if ans:
            break

    colors[vertex] = DONE

    return ans



def cycleInGraph2(edges):
    """Proposal - using a 3-color depth-first-search

    Time: O(v+e)
    Space: O(v)

    0 code is unvisited (white)
    1 code is in stack (grey)
    2 code is done (black)
    """
    v = len(edges)

    global colors
    colors = [UNVISITED]*v

    for vertex in range(v):
        if colors[vertex] == UNVISITED:
            print("dfs for", vertex)
            ans = dfs(edges, vertex)

            if ans:
                return ans

    return False


if __name__ == "__main__":
    vertices = int(input())
    edges = list()

    for i in range(vertices):
        arr = eval(input())
        edges.append(arr)

    print(cycleInGraph2(edges))