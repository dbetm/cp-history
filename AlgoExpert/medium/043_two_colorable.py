# solved
# tags: colorable-graph, graph


def twoColorable(edges):
    """My solution
    Time: O(v + e)
    Space: O(v)

    Where e is the number of edges and n the number of vertices
    """
    sets = {"red": set(), "blue": set()}
    vertex_color = "red"
    node_color = "blue"
    ans = True

    for vertex, nodes in enumerate(edges):
        print(f"{vertex = }")

        if vertex in sets[node_color]:
            node_color, vertex_color = vertex_color, node_color
        else:
            sets[vertex_color].add(vertex)

        for node in nodes:
            if node in sets[vertex_color]:
                ans = False
                break

            sets[node_color].add(node)

        if not ans:
            break

    print(sets)

    return ans


if __name__ == "__main__":
    vertices = int(input())
    edges = list()

    for i in range(vertices):
        arr = eval(input())
        edges.append(arr)

    print(twoColorable(edges))