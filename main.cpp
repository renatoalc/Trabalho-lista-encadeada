#include <iostream>
using namespace std;

class No
{
  public:
  int valor;
  No* proximo;

  No(int valor)
  {
    this->valor=valor;
    this->proximo=NULL;
  }

  int obterValor()
  {
    return valor;
  }

  No* obterProximo()
  {
    return proximo;
  }

  void definirProximo(No* prox)
  {
    proximo=prox;
  }
};

class Lista
{
  public:
  No* inicio;
  No* fim;

  Lista()
  {
    inicio = NULL;
    fim=NULL;
  }

  Lista(int num)
  {
    inicio = new No(num);
    fim = inicio;
  }
 
  bool seVazia()
  {
    return (inicio == NULL);
  }

  void imprimirElementos()
  {
    cout<<"ELEMENTOS DA LISTA"<<endl;
    No* i=inicio;
    if(seVazia())
    {
      cout<<"Lista sem elementos!"<<endl;
    }
    else
    {
      while(i)
      {
        cout<< i->obterValor()<<endl;
        i = i->obterProximo();
      }
      cout<<endl;
    }
  }

  bool existeElemento(int valor)
  {
    No* i = inicio;
    while(i)
    {
      if(i->obterValor()==valor)
      {
        return true;
      }else
      {
        i = i->obterProximo();
      }
    }
    return false;
  }

  void insereNoInicio(int valor)
  {
    No* novo = new No(valor);

    if(seVazia())
    {
      inicio= novo;
      fim=novo;
    }
    else
    {
      novo -> definirProximo(inicio);
      inicio = novo;
    }
  }

};


int main() {
  int quantidade,valor,num,num2,i=0;
  char op;

  Lista A;
  
  cout<<"QUANTIDADE DE NÚMEROS COMPLEXOS?"<<endl;
  cin>>quantidade;
  cout<<"INFORME OS NÚMEROS COMPLEXOS"<<endl;

  while(quantidade>i){
    cin>>valor;
    A.insereNoInicio(valor);
    i=i+1;
  }
  i=0;

  cout<<"INFORME UM NÚMERO COMPLEXO DA LISTA"<<endl;
  cin>>num;

  if(A.existeElemento(num)){
    cout<<"INFORME OUTRO NÚMERO COMPLEXO E A OPERAÇÃO ((+,-,*,/)) A SER REALIZADA COM O NÚMERO COMPLEXO DA LISTA"<<endl;
    cin>>num2>>op;
  }    
  else{
    cout<<"NÚMERO COMPLEXO "<<num<<" NÃO EXISTE NA LISTA"<<endl;
  }

  //OPERAÇÕES
  

    
  









}