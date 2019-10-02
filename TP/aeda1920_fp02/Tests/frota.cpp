#include "frota.h"
#include <string>

using namespace std;


void Frota::adicionaVeiculo(Veiculo *v1) {
    this->veiculos.push_back(v1);
}

int Frota::numVeiculos() const {
    return this->veiculos.size();
}

int Frota::menorAno() const{
    int numeroVeiculos = numVeiculos();

    if(numeroVeiculos==0)
        return 0;

    int menorAno = this->veiculos[0]->getAno();

    for(int veiculo=1; veiculo<numeroVeiculos; veiculo++){
        if (this->veiculos[veiculo]->getAno()<menorAno)
            menorAno = this->veiculos[veiculo]->getAno();
    }
    return menorAno;
}

ostream & operator<<(ostream & o, const Frota & f)
{
    vector<Veiculo *>::const_iterator it=f.veiculos.begin();
    while(it!=f.veiculos.end()) {
        (*it)->info();
        it++;
    }
    return o;
}

vector<Veiculo *> Frota::operator()(int anoM) const {
    vector<Veiculo *> veiculosDesseAno;
    size_t numeroVeiculos = this->numVeiculos();
    for(int veiculo=0; veiculo<numeroVeiculos; veiculo++){
        if(this->veiculos[veiculo]->getAno() == anoM)
             veiculosDesseAno.push_back(this->veiculos[veiculo]);
    }
    return veiculosDesseAno;
}

float Frota::totalImposto() const{
    float total;
    for(Veiculo* v : veiculos){
        total += v->calcImposto();
    }
    return total;
}

