from collections import defaultdict

class Graph:

    def __init__(self, vertices):
        self.V = vertices
        self.graph = defaultdict(list)

    def addEdge(self,u,v):
        self.graph[u].append(v)
        self.graph[v].append(u)

    def show(self):
        for i in range(self.V):
            print(i, self.graph[i])

    # --------- DFS ------------
    def DFSUtil(self,v,visited):
        visited[v] = True
        print("%d " %v, end="")
        for i in self.graph[v]:
            if visited[i] == False:
                self.DFSUtil(i,visited)

    def DFS(self, v):
        visited = [False]*self.V
        print("[ ",end="")
        self.DFSUtil(v,visited)
        print("]")
    # -----------------------------

    # ------ CONNECTED ------------
    def isConnected(self,v,visited):
        visited[v] = True
        for i in self.graph[v]:
            if visited[i] == False:
                self.isConnected(i,visited)

    def Connected(self):
        #case disconnected graph
        n_comp = 0
        visited = [False]*self.V
        for i in range(self.V):
            if visited[i] == False:
                self.isConnected(i,visited)
                n_comp += 1
        if n_comp > 1: #n_comp maior que um significa que tem dois ou mais componentes
            return False
        return True
    # -----------------------------------

    # ----------- CYCLE -----------------
    def isCycle(self,v,visited,parent):
        visited[v] = True
        for i in self.graph[v]:
            if visited[i] == False:
                if (self.isCycle(i,visited,v)):
                    return True
            # Se um a vertice adj foi visitado e nao é o pai do vertice atual
            #temos um ciclo
            elif parent !=i :
                return True

        return False

    def Cycle(self):
        visited = [False]*self.V
        #caso grafo seja desconexo
        for i in range(self.V):
            if visited[i] == False:
                if (self.isCycle(i,visited,-1)):
                    return True
        return False
    #--------------------------------------------

g = Graph(5)
g.addEdge(1, 0)
g.addEdge(0, 2)
g.addEdge(2, 0)
g.addEdge(0, 3)
g.addEdge(3, 4)

print('Contem Ciclo:', g.Cycle())
print("Conexo: ", g.Connected())
print('DFS', end=' ')
g.DFS(1)
g.show()
