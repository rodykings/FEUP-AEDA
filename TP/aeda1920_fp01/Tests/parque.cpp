#include "parque.h"
#include <vector>

using namespace std;


ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli):lotacao(lot), numMaximoClientes(nMaxCli){
}

bool ParqueEstacionamento::adicionaCliente(const string &nome) { //done

    if(posicaoCliente(nome)==-1) {
        InfoCartao novoCliente;
        novoCliente.nome = nome;
        novoCliente.presente = false;
        clientes.push_back(novoCliente);
        return true;
    }

    return false;
}

bool ParqueEstacionamento::retiraCliente(const string &nome) { //done
    size_t numeroCliente = posicaoCliente(nome);

    if(clientes[numeroCliente].presente == false){
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
    for(int cliente; cliente<=numeroDeClientes; cliente++){
        if (clientes[cliente].nome == nome)
            return cliente;
        else
            continue;
    }
    return -1;
}

bool ParqueEstacionamento::entrar(const string &nome) { //done
    size_t numCliente = posicaoCliente(nome);
    if(numCliente!=-1 && vagas != 0 && clientes[numCliente].presente == false) {
        clientes[numCliente].presente = true;
    }
    return false;
}

bool ParqueEstacionamento::sair(const string & nome) { //done
    size_t numCliente = posicaoCliente(nome);
    if(!adicionaCliente(nome) || clientes[numCliente].presente == false)
        return false;
    else
        clientes[numCliente].presente == false;
}

unsigned int ParqueEstacionamento::getNumLugaresOcupados() const {
    return (this->lotacao-this->vagas);
}

unsigned int ParqueEstacionamento::getNumClientesAtuais() const {
    return this->clientes.size();
}

