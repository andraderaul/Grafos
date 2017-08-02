//Grafos Lista de adj - Raul

#include <bits/stdc++.h> // tem todas bibliotecas do c/c++
using namespace std;

class Grafo{ //classe grafetão
	int V; //num de vertices
	list<int> *adj; //lista de ponteiro

public:
	Grafo(int);// construtor
	void addAresta(int v1, int v2);
	int obterGrauDeSaida(int v); // obtem o grau de saida de um vertice v
	bool existeVizinho(int v1, int v2);// verifica se v2 é vizinho de v1
	
};
Grafo::Grafo(int V){
	this->V = V; //atribui o num de vertices
	adj = new list <int>[V]; // vetor de lista
}
void Grafo:: addAresta(int v1, int v2){
	adj[v1].push_back(v2); //add v2 a lista de vertices adj de v1
}
int Grafo::obterGrauDeSaida(int v){
	return adj[v].size(); // basta retornar o tamanho da lista
}
bool Grafo::existeVizinho(int v1, int v2){
	//find procura do inicio ate o fim da a existencia de v2
	if(find(adj[v1].begin(), adj[v1].end(), v2) != adj[v1].end())
		return true;
	return false;	
}
int main(){
	Grafo grafo(4);
	
	// adicionando as arestas
	grafo.addAresta(0, 1);
	grafo.addAresta(0, 3);
	grafo.addAresta(1, 2);
	grafo.addAresta(3, 1);
	grafo.addAresta(3, 2);

	
	// mostrando os graus de saída
	cout << "Grau de saida do vertice 1: " << grafo.obterGrauDeSaida(1);
	cout << "\nGrau de saida do vertice 3: " << grafo.obterGrauDeSaida(3);

	// verifica se existe vizinhos
	if(grafo.existeVizinho(0, 1))
		cout << "\n\n1 eh vizinho de 0\n";
	else
		cout << "\n\n1 NAO eh vizinho de 0\n";

	if(grafo.existeVizinho(0, 2))
		cout << "2 eh vizinho de 0\n";
	else
		cout << "2 NAO eh vizinho de 0\n";

	return 0;

	
}


