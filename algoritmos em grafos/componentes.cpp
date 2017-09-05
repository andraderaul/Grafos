#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

typedef pair <int,int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

#define DFS_WHITE -1
#define DFS_BLACK 1

vector<vii> AdjList;

vi dfs_num;
int numCC;

void mensagem() {
  printf("==================================\n");
  printf("DFS Padrão (grafo de entrada não direcionado)\n");
  printf("==================================\n");
}


void dfs(int u){ //DFS padrao
	printf("%d ", u); // vertice visitado
	dfs_num[u] = DFS_BLACK; //marcar o vertice como visitado
	for(int j = 0; j < (int)AdjList[u].size();j++){ 
		ii v = AdjList[u][j]; // v (vizinho,peso)
		if(dfs_num[v.first] == DFS_WHITE) //verififcacao para evitar ciclos
			dfs(v.first); // para visitar vizinhos nao visitados
	}
}

int main(){
	int V, total_vizinhos,id,peso;
	
	freopen("componentes.txt","r",stdin);
	
	scanf("%d", &V);
	AdjList.assign(V, vii()); //
	for (int i = 0; i < V; i++) {
		scanf("%d", &total_vizinhos);
		for (int j = 0; j < total_vizinhos; j++) {
			scanf("%d %d", &id, &peso);
			AdjList[i].push_back(ii(id, peso));
		}
	}

  mensagem();
  numCC = 0;
  dfs_num.assign(V, DFS_WHITE);    // isso define todos os vertices como DFS_WHITE
  for (int i = 0; i < V; i++)                   // para todos os vertices i em [0..V-1]
    if (dfs_num[i] == DFS_WHITE)            // esses vertices ainda não foram visitados
      printf("componentes %d:", ++numCC), dfs(i), printf("\n");   // tres linhas!
  printf("Existem %d componetes conectados\n", numCC);
  
  
}
