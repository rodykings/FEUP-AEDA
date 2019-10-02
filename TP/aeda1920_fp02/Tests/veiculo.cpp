#include "veiculo.h"
#include <iostream>

using namespace std;

Veiculo::Veiculo(string mc, int m, int a) {
    this->marca = mc;
    this->mes = m;
    this->ano = a;
}

string Veiculo::getMarca() const {
    return this->marca;
}

int Veiculo::info() const {
    cout << "MARCA: " << this->marca << endl;
    cout << "ANO: " << this->ano << endl;
    cout << "MES: " << this->mes << endl;
    return 3;
}

bool Veiculo::operator<(const Veiculo &v) const {
    if(this->ano < v.ano)
        return true;
    else if(this->ano == v.ano){
        if(this->mes < v.mes)
            return true;
        else
            return false;
    }
    else{
        return false;
    }
}

int Veiculo::getAno() const {
    return this->ano;
}

Motorizado::Motorizado(string mc, int m, int a, string c, int cil):Veiculo(mc, m , a){
    this->combustivel = c;
    this->cilindrada = cil;
}

string Motorizado::getCombustivel() const {
    return this->combustivel;
}

int Motorizado::info() const {
    cout << "COMBUSTIVEL: " << this->combustivel << endl;
    cout << "CILINDRADA: " << this->cilindrada << endl;
    return Veiculo::info() + 2;
}

float Motorizado::calcImposto() const {
    float imposto=0;
    if(this->getAno() > 1995){
        if(this->combustivel == "gasolina"){
            if(cilindrada<=1000)
                imposto+=14.56;
            else if(cilindrada>1000 && cilindrada<=1300)
                imposto+=29.06;
            else if(cilindrada>1300 && cilindrada<=1750)
                imposto+=45.15;
            else if(cilindrada>1750 && cilindrada<=2600)
                imposto+=113.98;
            else if(cilindrada>2600 && cilindrada<=3500)
                imposto+=181.17;
            else
                imposto+=320.89;
        }
        else{
            if(cilindrada<=1500)
                imposto+=14.56;
            else if(cilindrada>1500 && cilindrada<=2000)
                imposto+=29.06;
            else if(cilindrada>2000 && cilindrada<=3000)
                imposto+=45.15;
            else if(cilindrada>3000)
                imposto+=113.98;
        }
    }else{
        if(this->combustivel == "galosina"){
            if(cilindrada<=1000)
                imposto+=8.10;
            else if(cilindrada>1000 && cilindrada<=1300)
                imposto+=14.56;
            else if(cilindrada>1300 && cilindrada<=1750)
                imposto+=22.65;
            else if(cilindrada>1750 && cilindrada<=2600)
                imposto+=54.89;
            else if(cilindrada>2600 && cilindrada<=3500)
                imposto+=87.13;
            else
                imposto+=148.27;
        }
        else{
            if(cilindrada<=1500)
                imposto+=8.10;
            else if(cilindrada>1500 && cilindrada<=2000)
                imposto+=14.56;
            else if(cilindrada>2000 && cilindrada<=3000)
                imposto+=22.65;
            else if(cilindrada>3000)
                imposto+=54.89;
        }
    }
    return imposto;
}

Automovel::Automovel(string mc, int m, int a, string c, int cil) : Motorizado(mc, m, a, c, cil) {}

int Automovel::info() const {
    return Motorizado::info();
}

Camiao::Camiao(string mc, int m, int a, string c, int cil, int cm): Motorizado(mc, m, a, c, cil){
    this->carga_maxima = cm;
}

int Camiao::info() const {
    cout << "CARGA MÁXIMA: " << carga_maxima << endl;
    return Motorizado::info() + 1;
}

Bicicleta::Bicicleta(string mc, int m, int a, string t):Veiculo(mc, m , a) {
    this->tipo = t;
}

int Bicicleta::info() const {
    cout << "TIPO: "<< this->tipo << endl;
    return Veiculo::info() + 1;
}

float Bicicleta::calcImposto() const {
    return 0;
}
