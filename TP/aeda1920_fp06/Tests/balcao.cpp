#include <queue>
#include <cstdlib>
#include "balcao.h"
#include "exceptions.h"

using namespace std;

//a alterar
Cliente::Cliente() {
    this->numPresentes =( rand()%5)+1;
}

//a alterar
int Cliente::getNumPresentes() const {
    return this->numPresentes;
}

//a alterar
Balcao::Balcao(int te): tempo_embrulho(te) {
    this->clientes_atendidos = 0;
    this->tempo_atual = 0;
    this->prox_chegada = rand() % 20 + 1;
    this->prox_saida = 0;
}

//a alterar
void Balcao:: proximoEvento()
{
}

//a alterar
void Balcao::chegada()
{
    Cliente c;
    this->prox_chegada = rand() % 20 + 1;
    if(clientes.empty()){
        this->prox_saida = tempo_atual + c.getNumPresentes() * tempo_embrulho;
    }
    this->clientes.push(c);
    cout << "tempo= " << tempo_atual << endl << "chegou novo cliente com "<< c.getNumPresentes() <<" presentes" << endl;

}



//a alterar
void Balcao::saida()
{
    Cliente c;
    try{
        c = getProxCliente();
    }
    catch (FilaVazia &fv){
        fv.getMsg();
    }
    clientes.pop();

}


int Balcao::getTempoAtual() const { return tempo_atual; }

int Balcao::getProxChegada() const { return prox_chegada; }

//a alterar
ostream & operator << (ostream & out, const Balcao & b1)
{
     return out;
}

//a alterar
int Balcao::getTempoEmbrulho() const {
	return this->tempo_embrulho;
}

//a alterar
int Balcao::getProxSaida() const {
	return this->prox_saida;
}

//a alterar
int Balcao::getClientesAtendidos() const {
    return this->clientes_atendidos;
}

//a alterar
Cliente & Balcao::getProxCliente() {

    if(clientes.empty())
        throw FilaVazia();
    else
        return this->clientes.front();
}

      
