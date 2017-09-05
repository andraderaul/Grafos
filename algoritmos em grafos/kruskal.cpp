#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef pair <int,int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

class UnionFind{ //estilo POO
	
	private:
		vi p, rank,setSize; //vi vetor de int
		int numSets;
	public:
		UnionFind(int N){
			setSize.assign(N,1);
			numSets = N;
			rank.assign(N,0);
			p.assign(N,0);
			for(int i = 0;  i < N; i++ )
				p[i] = i;
		
		}
		int findSet(int i ){
			return (p[i] == i) ? i : (p[i] = findSet(p[i]));
		}
		
		bool isSameSet(int i, int j){
			return findSet(i) == findSet(j);
		}
		void unionSet(int i, int j){
			if(!isSameSet(i,j)){
				numSets--;
				int x = findSet(i), y = findSet(j);	
				// rank é usado para nao deixar a arvore crescer muito
				if(rank[x] > rank[y]){
					p[y] = x;
					setSize[x] += setSize[y];
				}
				else{
					p[x] = y;
					setSize[y] += setSize[x];
				}	
				if(rank[x] == rank[y]){
					rank[y]++;
				}
			}		
		}
		int numDisjointSets(){
			return numSets;
		}	
		int sizeOfSet(int i){
			return setSize[findSet(i)];
		}
};

vector <vii> AdjList;
vi taken; // flag pra evitar ciclos
priority_queue <ii> pq; //fila de prioridade para escolher a aresta mais leve

void process(int vtx){ //-v é usado so para inverter a ordem de classificacão
	taken[vtx] = 1;
	for(int j = 0; j < (int)AdjList[vtx].size(); j++){
		ii v = AdjList[vtx][j];
		if(!taken[v.first])
			pq.push(ii(-v.second,-v.first));
	}	
}
// Árvore geradora de custo mínimo(MST)
int main(){
	int V, E, u,v,w;
	freopen("kruskal.txt","r",stdin);
	
	scanf("%d %d", &V, &E);

	AdjList.assign(V, vii());
	vector< pair<int, ii> > EdgeList;   // (peso, dois vertices) da Aresta
	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &u, &v, &w);            // lê os tres (u, v, w)
		EdgeList.push_back(make_pair(w, ii(u, v))); // (w, u, v)
		AdjList[u].push_back(ii(v, w));
		AdjList[v].push_back(ii(u, w));
	}
	sort(EdgeList.begin(), EdgeList.end()); // sort por peso da aresta O(E log E)
                      // obs: o objeto tipo pair tem funcao de comparacao embutida

	int mst_cost = 0;
	UnionFind UF(V);                     // todos os V sao conjuntos disjuntos inicialmente
	for (int i = 0; i < E; i++) {                      // para cada aresta O(E)
		pair<int, ii> front = EdgeList[i];
		if (!UF.isSameSet(front.second.first, front.second.second)) {  // check
			mst_cost += front.first;                // adicioneo o peso ao MST
			UF.unionSet(front.second.first, front.second.second);    // ligue os
		}
   }                       // obs: o custo de execucao de UFDS é muito leve

  // obs: o numero de conjuntos disjuntos deve ser eventualmente 1 para um MST
  printf("custo da MST = %d (Kruskal's)\n", mst_cost);




}
