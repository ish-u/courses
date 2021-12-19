from helpers import *

# Helper Functions for Q (a Array of Vertices)
# To Extract the Minimum from the Queue
def extractMin(Q):
    if Q == []:
        return None
    minimum = Vertex(0)
    for V in Q:
        if V.key < minimum.key:
            minimum = V
    return minimum

# To Get the Vertex Object associated with vertex 'v'
def getVertex(Q,v): 
    for vertex in Q:
        if vertex.vertex == v:
            return vertex
    return None


# Prim's Algortihm that returns the Edges of the Minimum Spanning Tree
def prim(G,s):
    MST = []
    
    # Creating a Priority Queue
    Q = []
    for V in G.V:
        Q.append(Vertex(V))

    # Setting the First Vertex to Source
    Q[s-1].key = 0
    while Q != [] :
        # Gettng the Vertex in Q with the Minimum Key Value 
        u = extractMin(Q) 
        
        # Finding all the adjacent vertices of the vertex 'u'
        neighbours = G.adjacentVertices(u.vertex)
        
        # Findig the vertex with the least weight local to 'u' using Greedy Strategy
        for v in neighbours:
            _v = getVertex(Q,v)
            if _v is not None:
                if _v.belongsToQ and (_v.key > G.weight(u.vertex,v)):
                    _v.parent = u.vertex
                    _v.key = G.weight(u.vertex,v)
        Q.remove(u)

        # Getting the edge with the least weight that is not yet been selected
        selectedEdge = extractMin(Q)
        if selectedEdge is not None:
            MST.append((selectedEdge.parent,selectedEdge.vertex,selectedEdge.key))
    
    S = "\n" + "EDGES IN THE MST - (u, v, weight)" + "\n" + "-"*75 + "\n"
    for edge in MST:
        S += str(edge) + "\t"
        if (MST.index(edge)+1) % 5 == 0:
            S += "\n\n"
    S += "\n" + "-"*75
    return S

         
                
def main():
    # creating the graph Object 
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

    # get the MST
    print(prim(graph,10))

main()
