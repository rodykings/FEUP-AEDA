#include <iostream>
#include <vector>

using namespace std;

/**
 * Versao da classe generica Grafo usando a classe vector
 */

template <class N, class A> class Aresta;

template <class N, class A>
class No {
public:
	N info;
	vector< Aresta<N,A> > arestas;
	No(N inf) {
		info = inf;
	}
};

template <class N, class A>
class Aresta {
public:
	A valor;
	No<N,A> *destino;
	Aresta(No<N,A> *dest, A val) {
		valor = val;
		destino = dest;
	}
};

template <class N, class A> 
class Grafo { 
	vector< No<N,A> *> nos;
  public: 
    Grafo();
    ~Grafo(); 
    Grafo & inserirNo(const N &dados);
    Grafo & inserirAresta(const N &inicio, const N &fim, const A &val);
    Grafo & eliminarAresta(const N &inicio, const N &fim);
    A & valorAresta(const N &inicio, const N &fim);
    int numArestas(void) const;
    int numNos(void) const;
    void imprimir(std::ostream &os) const; 
};

template<class N, class A>
Grafo<N, A>::Grafo() {

}

template<class N, class A>
Grafo<N, A>::~Grafo() {
    this->nos.clear();
}

template<class N, class A>
int Grafo<N, A>::numArestas(void) const {
    int counter=0;
    size_t  n_nos = numNos();

    for(size_t n=0; n< n_nos; n++){
        size_t n_ares = this->nos[n]->arestas.size();
        for(size_t a = 0; a<n_ares; a++){
            counter++;
        }
    }
    return counter;
}

template<class N, class A>
int Grafo<N, A>::numNos(void) const {

    return this->nos.size();
}

template <class N, class A>
std::ostream & operator<<(std::ostream &out, const Grafo<N,A> &g);


// excecao NoRepetido
template <class N>
class NoRepetido
{
public:
   N info;
   NoRepetido(N inf) { info=inf; }
};
template <class N> 
std::ostream & operator<<(std::ostream &out, const NoRepetido<N> &no)
{ out << "No repetido: " << no.info; return out; }


// excecao NoInexistente
template <class N>
class NoInexistente {
public:
	N info;
	NoInexistente(N inf) {
		info = inf;
	}
};

template <class N>
std::ostream & operator<<(std::ostream &out, const NoInexistente<N> &ni)
{ out << "No inexistente: " << ni.info; return out; }

template<class N, class A>
Grafo<N,A> &Grafo<N, A>::inserirNo(const N &dados) {

    No<N, A> novo_no(dados);

    size_t numNos = this->numNos();
    for (size_t i = 0; i < numNos; i++) {
        if (nos[i]->info == dados)
            throw NoRepetido<N>(novo_no.info);
    }
    this->nos.push_back(&novo_no);
    return *this;
}

template<class N, class A>
Grafo<N,A> &Grafo<N, A>::inserirAresta(const N &inicio, const N &fim, const A &val) {
    Aresta<N,A> nova_aresta(fim, val);
    size_t numNos = this->numNos();
    for (size_t i = 0; i < numNos; i++) {
        if (nos[i]->info == inicio)
            this->nos[i]->arestas.pushback(nova_aresta);
            return *this;
    }
    throw NoInexistente<N>(inicio);
}

