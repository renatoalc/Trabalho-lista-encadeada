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
    float res = n1/n2;
    return res;
  }


int main() {
  int quantidade,opção,valor,num,num2,i=0;
  float res;
  char op;
  ifstream Ler("BancoDados.txt"); 

  Lista A;

  cout<<"Digite a opção:"<<endl;
  cout<<"[1] - Gravar"<<endl<<"[2] - Ler"<<endl<<"[0] - Encerrar"<<endl;
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
       while(!Ler.eof()){
         Ler>>valor;
	       A.insereNoInicio(valor);
        }

      if(A.seVazia()){
        cout<<"A lista está vazia!"<<endl;
      }
      else{//Se a lista foi lida e não está vazia, então faz as operações
        cout<<"Escolha um número da lista"<<endl;
        cin>>num;
        if(A.existeElemento(num)){
          cout<<"Informe outro número e a operação desejada(+,-,*,/) com o número da lista escolhido"<<endl;
          cin>>num2;
          cin>>op;

          if (op=='+'){
            res = Soma(num,num2);      
          }

          if (op=='-'){
            res = Subtração(num,num2);      
          }

          if (op=='*'){
            res = Multiplicação(num,num2);      
          }

          if (op=='/'){
            res = Divisão(num,num2);      
          }

          cout<<"Resultado da operação: "<<res<<endl;

        }
        else{
          cout<<"Número escolhido não existe na lista!"<<endl;
        }
      }      
    }
    cout<<"Gravar(1), Ler(2) ou encerrar(0)? "<<endl;
    cin>>opção;
  }
}