# Class for Prim's
class Vertex:
    def __init__(self,vertex,key = float('inf'),parent = None):
        self.vertex = vertex
        self.key = key
        self.parent = parent
        self.belongsToQ = True
    
    def __str__(self):
        return f"N:{self.vertex}  P:{self.parent}  K:{self.key}"

# Class for Kruskal's
class Node:
    def __init__(self,node,parent = 0,rank = 0):
        self.node = node
        self.parent = parent
        self.rank = rank
    
    def __str__(self):
        return f"N:{self.node}  P:{self.parent}  R:{self.rank}"

# List of Edges in form (u,v,weight)
class EdgeList:
    def __init__(self):
        self.edges = []

    # Add an edge->(u,v) with weight->w as (u,v,w) in the edges list
    def addEdge(self,u,v,w):
        self.edges.append((u,v,w))
    
    # To Sort the edges according to weight -> w in (u,v,w) in the edge list 
    def sortEdges(self):
        for x in range(0,len(self.edges)):
            for y in range(x,len(self.edges)-1):
                if self.edges[x][2] > self.edges[y][2]:
                    self.edges[x],self.edges[y] = self.edges[y],self.edges[x]

    # Overriding __str__ method to return the Edge List 
    def __str__(self):
        s = "\n" + "EDGE LIST\n"
        s += "-"*75 +"\n"
        for edge in self.edges:
            s += str(edge) + '\t'
            if (self.edges.index(edge)+1) % 5 == 0:
                s += "\n\n"
        s += "\n" + "-"*75 +"\n"
        return s

# Graph Class 
class Graph:
    def __init__(self,nodes):
        self.nodes = nodes
        self.G = []
        self.E = EdgeList()
        self.V = [x+1 for x in range(self.nodes)]
        for x in range(self.nodes):
            self.G.append([float('inf') for x in range(self.nodes)])
            self.G[x][x] = 0

    # Add an Edge(u,v) that has weight => w in the Graph => G(V,E)
    def addEdge(self,u,v,w):
        if u <= self.nodes and v <= self.nodes:
            self.G[u-1][v-1] = w
            self.G[v-1][u-1] = w
            self.E.addEdge(u,v,w)
            self.E.sortEdges()
        else:
            print("Not a Valid Edge")
        
    # To Get the Adjacent Vertices to the vertex 'u'
    def adjacentVertices(self,u):
        adj = []
        for x in range(self.nodes):
            if self.G[u-1][x] != float('inf') and self.G[u-1][x] != 0:
                adj.append(x+1)   
        
        return adj

    # To Get the weight of a Edge (u,v)
    def weight(self,u,v):
        return self.G[u-1][v-1]

    # Overriding __str__ method to return the Adjacency Matrix 
    def __str__(self):
        s = "\n" +"ADJACENCY MATRIX\n"
        s += "-"*75 +"\n\n"
        s += "\t"
        for x in range(self.nodes):
            s += str(x+1) + "\t"
        s += "\n\n"
        for x in range(self.nodes):
            s += str(x+1) + "\t"
            for y in range(self.nodes):
                s += str((self.G[x][y])) + "\t"
            s += "\n\n"
        s += "-"*75 +"\n"
        return s