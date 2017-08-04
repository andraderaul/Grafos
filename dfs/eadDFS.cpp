#include <bits/stdc++.h> // tem todas bibliotecas do c/c++
using namespace std;

ifstream input;
ofstream output;

typedef struct tEAD{
    bool marcado;
    vector <int> adj;
}tEAD;

tEAD* criaGrafo(int V){
	tEAD *G;	
	G = new tEAD[V];
	return G;	
}
void inicializaEAD(tEAD* G, int V){
	for(int i = 0; i < V; i++)
		G[i].marcado = false;	
}
void addAresta(tEAD* G,int v1, int v2){
	G[v1].adj.push_back(v2);
}
int grauDoVertice(tEAD* G, int v){
	return G[v].adj.size(); 
}
bool existeVizinho(tEAD* G, int v, int w){
	if(find(G[v].adj.begin(),G[v].adj.end(), w) != G[v].adj.end())
		return true;
	return false;	
}
void DFSrec(tEAD* G,int v){
	G[v].marcado = true; //marque v
//	cout << "Visitado: " << v << endl;
	output << "Visitado: " << v << endl;	
	for(size_t i = 0; i < G[v].adj.size(); i++){ //para todas as arestas (v,w)
		int w = G[v].adj[i]; // w pertence ADJ (v)		
		if(!G[w].marcado) // se w é não marcado 
			DFSrec(G,w);
	}	
}
void DFS(tEAD* G, int v){
	stack <int> visitado; // pilha de visitado	
	G[v].marcado = true; // marque v
	visitado.push(v); // empilhe v
	
	while(!visitado.empty()){ // enquanto pilha n for vazia
		int u = 0;
		int w = visitado.top(); // pegue o topo
		G[w].marcado = true; //marque w
		
		cout << "Visitado: "<< w << endl;
		output << "Visitado: "<< w << endl;	
		for(size_t i = 0; i < G[w].adj.size(); i++){ // para todas as arestas (w,u)
			u = G[w].adj[i]; // u pertence ADJ(w)
			if(!G[u].marcado){ // se u é não marcado
				visitado.push(u); // empilhe u
				break;
			}			
		}
		if(G[u].marcado){
			visitado.pop();
		}
		
	}
}
void leituraArquivo(tEAD* G, int V){
	
	int n, c, s;
	for(int i = 0; i < V; i++){
		input >> c >> n;
		for(int j = 0; j < n; j++){
			input >> s;
			addAresta(G,c,s);	
		}
	}  
}
void salvaArquivo(tEAD* G, int V){
	output << endl << "[Marcados]" << endl;
	for(int i = 0; i < V; i++){
		output << "Vertice["<< i << "]-> " << G[i].marcado << endl;
	}
}
int main(){
	
	input.open("input.txt"); //abrindo entrada
	output.open("output.txt"); //abrindo saida
    
    int n; // numero total de vertices
	tEAD *ead;
    input >> n;
    ead  = criaGrafo(n);
	leituraArquivo(ead, n);
    
    inicializaEAD(ead,n);
//	DFSrec(ead,0);
 //   output << endl;
    
	inicializaEAD(ead,n);
	DFS(ead,0);
	
	salvaArquivo(ead,n);
			
    return 0;
}
