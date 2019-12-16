#include <iostream>
#include <string>
#include <fstream>
#include "dicionario.h"
#include "bst.h"

using namespace std;

BST<PalavraSignificado> Dicionario::getPalavras() const {
	return palavras;
}

//a alterar
bool PalavraSignificado::operator < (const PalavraSignificado &ps1) const {
     return true;
}

//a alterar
void Dicionario::lerDicionario(ifstream &fich)
{

    string line;
    size_t counter = 0;

    string palavra;
    string significado;



        while(getline(fich, line)){
            switch(counter){
                case 0:
                    palavra = line;
                    break;
                case 1:
                    significado = line;
                    PalavraSignificado p(palavra, significado);
                    this->palavras.insert(p);
                    counter = 0;
                    break;
            }counter++;

        }


}

//a alterar
string Dicionario::consulta(string palavra) const
{
    return "";
}

//a alterar
bool Dicionario::corrige(string palavra, string significado)
{
    return true;
}

//a alterar
void Dicionario::imprime() const
{
    return;
}

