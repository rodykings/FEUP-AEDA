#include "parque.h"
#include <vector>

using namespace std;


ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli):lotacao(lot), numMaximoClientes(nMaxCli){
    vagas = lot;
}

bool ParqueEstacionamento::adicionaCliente(const string &nome) { //done


    if(posicaoCliente(nome)==-1 && (getNumClientesAtuais() != getNumMaximoClientes())) {
        InfoCartao n;
        n.nome = nome;
        n.presente = false;
        clientes.push_back(n);
        return true;
    }

    return false;
}

bool ParqueEstacionamento::retiraCliente(const string &nome) { //done
    size_t numeroCliente = posicaoCliente(nome);

    if(numeroCliente != -1 && clientes[numeroCliente].presente == false){
        clientes.erase(clientes.begin() + numeroCliente);

        return true;
    }
    else
        return false;

}

unsigned int ParqueEstacionamento::getNumLugares() const { //done
    return this->lotacao;
}

unsigned int ParqueEstacionamento::getNumMaximoClientes() const { //done
    return this->numMaximoClientes;
}

int ParqueEstacionamento::posicaoCliente(const string &nome) const { //done
    size_t numeroDeClientes = clientes.size();
    for(int cliente=0; cliente<numeroDeClientes; cliente++){
        if (this->clientes[cliente].nome == nome)
            return cliente;
    }
    return -1;
}

bool ParqueEstacionamento::entrar(const string &nome) { //done
    size_t numCliente = posicaoCliente(nome);
    if(numCliente!=-1 && vagas != 0 && clientes[numCliente].presente == false) {
        clientes[numCliente].presente = true;
        vagas--;
        return true;
    }
    return false;
}

bool ParqueEstacionamento::sair(const string & nome) { //done
    size_t numCliente = posicaoCliente(nome);
    if(numCliente != -1 && clientes[numCliente].presente == true){
        clientes[numCliente].presente = false;
        return true;
    }
    return false;
}

unsigned int ParqueEstacionamento::getNumLugaresOcupados() const {
    return (this->lotacao-this->vagas);
}

unsigned int ParqueEstacionamento::getNumClientesAtuais() const {
    return this->clientes.size();
}

const ParqueEstacionamento &ParqueEstacionamento::operator+=(const ParqueEstacionamento &p2) {
    this->vagas += p2.vagas;
    size_t p2Size = p2.clientes.size();
    for(int cliente=0; cliente<=p2Size; cliente++ ){
        if(posicaoCliente(clientes[cliente].nome)!=-1){
            this->clientes.push_back(clientes[cliente]);
        }
    }

    unsigned int *ltcPtr;
    ltcPtr = (unsigned int*)( &lotacao );
    *ltcPtr += p2.lotacao;

    unsigned int *nmcPtr;
    nmcPtr = (unsigned int*)( &numMaximoClientes );
    *nmcPtr += p2.numMaximoClientes;

}

