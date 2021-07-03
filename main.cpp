#include <iostream>
#include <fstream>
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
    ofstream Gravar("BancoDados.txt");
    No* i=inicio;
    if(seVazia())
    {
      cout<<"Lista sem elementos!"<<endl;
    }
    else
    {
      while(i)
      {
        Gravar<< i->obterValor()<<endl;
        i = i->obterProximo();
      }      
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

  int Soma(int n1,int n2){
    int res = n1+n2;
    return res;
  }

  int Subtração(int n1,int n2){
    int res = n1-n2;
    return res;
  }

  int Multiplicação(int n1,int n2){
    int res = n1*n2;
    return res;
  }

  int Divisão(int n1,int n2){
    double res = n1/n2;
    return res;
  }


int main() {
  int quantidade,opção,valor,num,num2,i=0;
  double res;
  char op;
  ifstream Ler("BancoDados.txt"); 

  Lista A;

  cout<<"Gravar(1), Ler(2) ou encerrar(0)? "<<endl;
  cin>>opção;

  while(opção != 0){
    if(opção == 1){
      cout<<"Quantidade de números complexos?"<<endl;
      cin>>quantidade;
      cout<<"Informe os números complexos"<<endl;
      while(quantidade>i){
        cin>>valor;
        A.insereNoInicio(valor);
        i=i+1;
      }
      i=0;
      A.imprimirElementos();
      cout<<"Lista gravada no arquivo BancoDados.txt !"<<endl;

    }
    else{
      
    }

  }
    cout<<"Gravar(1), Ler(2) ou encerrar(0)? "<<endl;
    cin>>opção;
}