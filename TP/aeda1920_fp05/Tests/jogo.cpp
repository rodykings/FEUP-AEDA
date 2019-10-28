/*
 * jogo.cpp
 */

#include "jogo.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <utility>

using namespace std;


unsigned int Jogo::numPalavras(string frase)
{
  if ( frase.length() == 0 ) return 0;

  unsigned n=1;
  size_t pos = frase.find(' ');
  while (pos != string::npos) {
    frase = frase.substr(pos+1);
    pos = frase.find(' ');
    n++;
  }
  return n;
}

// a implementar
Jogo::Jogo()
{

}

// a implementar
Jogo::Jogo(list<Crianca>& lc2)
{
    this->criancas = lc2;
}

// a implementar
void Jogo::insereCrianca(const Crianca &c1)
{
    this->criancas.push_back(c1);
}

// a implementar
list<Crianca> Jogo::getCriancasJogo() const
{
    return this->criancas;
}

// a implementar
string Jogo::escreve() const
{
    string finalStr;
    for(Crianca c : criancas){
        finalStr += c.escreve();
    }
    return finalStr;
}

// a implementar
Crianca& Jogo::perdeJogo(string frase)
{
    string sentence = frase;
    size_t iteracoes;
   list<Crianca>::iterator it = this->criancas.begin();
   while(this->criancas.size() != 1){
       iteracoes = numPalavras(sentence);
       for(iteracoes;iteracoes != 1; iteracoes--){
           it.operator++();
           if(it == this->criancas.end())
               it = this->criancas.begin();
       }
       this->criancas.erase(it);
       it = criancas.begin();
   }
   return *(this->criancas.begin());
}

// a implementar
list<Crianca>& Jogo::inverte()
{
    list<Crianca> inv;
    list<Crianca>::iterator it = this->criancas.end();
    size_t size = this->criancas.size();

    while(size != 0){
        it.operator--();
        inv.push_back(*it);
        size--;
    }
    this->criancas = inv;
    return this->criancas;
}

// a implementar
list<Crianca> Jogo::divide(unsigned id)
{
    list<Crianca> nova;
    list<Crianca>::iterator it = this->criancas.begin();
    for (it; it != this->criancas.end(); it++){
        if((*it).getIdade() > id){
            nova.push_back(*it);
            this->criancas.erase(it);
            it--;
        }
    }
    return nova;

}

// a implementar
void Jogo::setCriancasJogo(const list<Crianca>& l1)
{
    this->criancas = l1;
}

// a implementar
bool Jogo::operator==(Jogo& j2)
{
    if(j2.criancas != criancas)
        return false;
    return true;

}

// a implementar
list<Crianca> Jogo::baralha() const
{
    list<Crianca> c = this->criancas;
    list<Crianca> nova;
    size_t initialSize = this->criancas.size();

    list<Crianca>::iterator it = c.begin();

    while(nova.size() != initialSize){
        it = c.begin();
        int randNum = rand()%(c.size()-1 + 1) + 1;
        for(randNum; 1 < randNum;randNum--){
            it.operator++();
        }
        nova.push_back(*it);
        c.erase(it);
    }
    return nova;

}
