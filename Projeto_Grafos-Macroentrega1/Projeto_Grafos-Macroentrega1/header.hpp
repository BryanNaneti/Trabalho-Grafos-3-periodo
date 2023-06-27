#include <iostream>
using namespace std;

#define NAO_DEFINIDO -1

// instancia (as 10 primeiras linhas do arquivo)
struct Instancia{
	string name;
	string location;
	string comment;
	string type;
	int size;
	string distribution;
	string depot;
	int routeTime;
	int timeWindow;
	int capacity;

	// solucao
	int nVeiculos; // numero de veiculos
	int nPacotes; // numero de pacotes

	void mostrarCampos(){
		cout << "Nome: " << name << endl;
		cout << "Localizacao: " << location << endl;
		cout << "Commentario: " << comment << endl;
		cout << "Tipo: " << type << endl;
		cout << "Tamanho: " << size << endl;
		cout << "Distribuicao: " << distribution << endl;
		cout << "Deposito: " << depot << endl;
		cout << "Tempo de Rota: " << routeTime << endl;
		cout << "Janela de Tempo: " << timeWindow << endl;
		cout << "Capacidade: " << capacity << endl;
	}
};

// nós (ou pontos) (NODES)
struct Node{
	int id;
	float lat;
	float lon;
	int dem;
	int etw;
	int ltw;
	int dur;
	int p;
	int d;

	int idPacote = NAO_DEFINIDO;

	void mostrarCampos(){
		cout << "Id: " << id << endl;
		cout << "Latitude: " << lat << endl;
		cout << "Longitude: " << lon << endl;
		cout << "Demanda: " << dem << endl;
		cout << "Inicio: " << etw << endl;
		cout << "Final: " << ltw << endl;
		cout << "Duracao: " << dur << endl;
		cout << "Par de coleta: " << p << endl;
		cout << "Par de entrega: " << d << endl;
	}
};

// Os pacotes que serão coletados e entregues
// cada pacote tem seu id armazenado no seu ponto de coleta e de entrega
// além de flags de coletado e entregue e o id do veículo que o coletou
struct Pacote{
	int id;
	int pColeta; // ponto de coleta
	int pEntrega; // ponto de entrega
	bool coletado;
	bool entregue;
	int idVeiculo; // id veiculo que coletou o pacote

	// colocar a janela de tempo do pacote???

	void mostrarCampos(){
		cout << "Id: " << id << endl;
		cout << "Ponto de coleta: " << pColeta << endl;
		cout << "Ponto de Entrega: " << pEntrega << endl;
	}
};

// Cada veiculo tem sua rota armazenada num vetor
// a rota segue a ordem dos índices do vetor 0 -> 1 -> 2 -> ... -> nPontos-1
struct Veiculo{
	int id;
	int nPontos; // tamanho do vetor de rota
	int *rota; // vetor com os pontos em que ele irá passar
	int carga; // qtd que o veiculo está carregando

	void mostrarRota(){
		cout << id << ": ";
		for(int i=0; i<nPontos; i++)
			cout << rota[i] << "->";
		cout << endl;
	}
};



