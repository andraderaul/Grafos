#include <bits/stdc++.h> 
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
void addAresta(tEAD* G, int v1, int v2){
	return G[v1].adj.push_back(v2);
}
int grauDoVertice(tEAD* G, int v){
	return G[v].adj.size();
}
bool existeVizinho(tEAD* G, int v, int w){
	if(find(G[v].adj.begin(),G[v].adj.end(), w) != G[v].adj.end())
		return true;
	return false;	
}
void BFS(tEAD* G, int v){
	queue <int> visitado; //fila de visitado
	G[v].marcado = true; // marque v
	visitado.push(v); //coloque na fila	
	cout << "Visitado: " << v << endl;
	output << "Visitado: " << v << endl;
	while(!visitado.empty()){ //enquanto a fila n for vazia
		int u = 0;
		for(size_t i = 0; i < G[v].adj.size(); i++){ // para todas as arestas (w,u)	
			u = G[v].adj[i]; // u pertence ADJ(w)
			if(!G[u].marcado){ // se u é não marcado
				cout << "Visitado: " << u << endl;
				output << "Visitado: " << u << endl;
				G[u].marcado = true;
				visitado.push(u); // coloque na fila
			}
		}
		v = visitado.front();
		visitado.pop();
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
int main(int argc, char* argv[]){
	
	input.open(argv[1]); //abrindo entrada
	output.open(argv[2]); //abrindo saida
    
    int n; // numero total de vertices
	tEAD *ead;
    input >> n;
    ead  = criaGrafo(n);
	leituraArquivo(ead, n);
    
    inicializaEAD(ead,n);
    
	inicializaEAD(ead,n);
	BFS(ead,0);
	
	salvaArquivo(ead,n);
			
    return 0;
}
