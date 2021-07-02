#include <iostream>
using namespace std;

class No
{
  public:
  int valor;
  No* proximo;

  No(int elemento)
  {
    this->valor=elemento;
    this->proximo=NULL;
  }

  void definirProximo(No* end)
  {
    proximo=end;
  }

  int obterValor()
  {
    return valor;
  }

  No* obterProximo()
  {
    return proximo;
  }
};

class Lista
{
  public:
  No* inicio;
  No* fim;

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
  cout << "Hello World!\n";
}