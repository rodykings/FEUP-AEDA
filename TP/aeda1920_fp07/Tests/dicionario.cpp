#include <string>
#include "dicionario.h"
#include "bst.h"

using namespace std;

BST<PalavraSignificado> Dicionario::getPalavras() const {
	return palavras;
}

//a alterar
bool PalavraSignificado::operator < (const PalavraSignificado &ps1) const {
     return this->palavra < ps1.palavra;
}

//a alterar
void Dicionario::lerDicionario(ifstream &fich)
{

    string palavra = "";
    string significado = "";

    while(getline(fich, palavra)){
        getline(fich, significado);
        PalavraSignificado p(palavra, significado);
        this->palavras.insert(p);
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

