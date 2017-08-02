import numpy as np

def DFS(ead, v):
	
	n = len(ead)
	explorado = np.empty(n,bool)
	
	for i in range(0, n):
		explorado[i] = False
	
	explorado[v] = True
	stack = [v]
	
	while len(stack)!=0:
		w = stack.pop()
		print ("vertice: ", w)
		
		for i in ead[w]:
			if(not explorado[i]):
				explorado[i] = True
				stack.append(i)

	return explorado			

def DFSrec(ead,explorado,v):
	
	explorado[v] = True
	print("vertice: ", v)
	
	for i in ead[v]:
		if(not explorado[i]):
			DFSrec(ead,explorado,i)
	
	return explorado		

if __name__ == '__main__':
	
	n = 6 #numero de vertices
	
	
	ead = [set() for i in range(n)]
	
	ead[0].add(1)
	ead[0].add(2)
	ead[1].add(0)
	ead[1].add(3)
	ead[2].add(0)
	ead[2].add(4)
	ead[3].add(1)
	ead[3].add(5)
	ead[4].add(2)
	ead[4].add(5)
	ead[5].add(3)
	ead[5].add(4)
	
	print("EAD ")
	print (ead)
	
	print("DFS: ")
	print(DFS(ead,0))
	
	explorado = np.empty(n,bool)
	for i in range(0,n):
		explorado[i] = False
		
	print("DFSrec: ")
	print(DFSrec(ead,explorado,0))
		
	
	
