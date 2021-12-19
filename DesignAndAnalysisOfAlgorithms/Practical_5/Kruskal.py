from helpers import *

# Make Set operation
def makeSet(x):
    n = Node(x,x,0)
    return n

# Find Set Operation
def findSet(n,sets):
    x = ""
    for i in sets:
        if i.node == n:
            x = i
            break
    if x.node != x.parent:
        return findSet(x.parent.node,sets)
    return x

# Link Operation
def link(x,y):
    if x.rank > y.rank:
        y.parent = x
    else:
        x.parent = y
        if x.rank == y.rank:
            y.rank += 1

# Union Operation
def union(x,y,sets):
     return link(findSet(x,sets),findSet(y,sets))

# Kruskal's Algortihm that returns the Edges of the Minimum Spanning Tree
def kruskal(G): 
    A = [] 
    SETS = []

    # Create Set of Individual Vertices
    for x in G.V:
        SETS.append(makeSet(x))
    
    # Sort the Edges according to their "weights"
    G.E.sortEdges()

    # Findig the edge with the least cost locally using Greedy Strategy
    for x in G.E.edges:
        if findSet(x[0],SETS) != findSet(x[1],SETS):
            A.append(x)
            union(x[0],x[1],SETS)
            
    MST = "\n" + "EDGES IN THE MST -(u, v, weight)" + "\n" + "-"*75 + "\n"
    for edge in A:
        MST += str(edge) + "\t"
        if (A.index(edge)+1) % 5 == 0:
            MST += "\n\n"
    MST += "\n" + "-"*75
    return MST

def main():
    # creating the graph Object 
    # graph = Graph(9)

    # # adding edges in the Graph using addEdge() method
    # graph.addEdge(1,2,4)
    # graph.addEdge(2,3,8)
    # graph.addEdge(3,4,7)
    # graph.addEdge(4,5,9)
    # graph.addEdge(5,6,10)
    # graph.addEdge(6,7,2)
    # graph.addEdge(7,8,1)
    # graph.addEdge(8,9,7)
    # graph.addEdge(9,1,8)
    # graph.addEdge(2,8,11)
    # graph.addEdge(9,3,2)
    # graph.addEdge(9,7,6)
    # graph.addEdge(3,6,4)
    # graph.addEdge(4,6,14)

    graph = Graph(10)

    graph.addEdge(1,5,190)
    graph.addEdge(2,4,110)
    graph.addEdge(3,6,240)
    graph.addEdge(5,4,90)
    graph.addEdge(4,6,130)
    graph.addEdge(5,8,90)
    graph.addEdge(5,7,150)
    graph.addEdge(4,7,250)
    graph.addEdge(6,7,120)
    graph.addEdge(7,8,100)
    graph.addEdge(7,10,250)
    graph.addEdge(7,9,110)
    graph.addEdge(6,9,80)
    graph.addEdge(9,10,280)
    graph.addEdge(10,8,300)
    

    # displaying the Adjacency Matrix
    print(graph)   

    # displaying the edge list
    print(graph.E)

    # get the MST
    print(kruskal(graph))

main()