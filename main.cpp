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

struct tComplexos{
  double real;
  double imag;
};

void LerComplexo (struct tComplexos *nc){

cout << "Parte real" << endl;
cin >> nc->real;
cout << "Parte imaginaria" << endl;
cin >> nc->imag;
cout << endl;

}
//SOMA
struct tComplexos* Soma (struct tComplexos *nc1, struct tComplexos *nc2){
  struct tComplexos *ncRes = (struct tComplexos*)malloc(sizeof(struct tComplexos));
  ncRes->real = nc1->real + nc2->real;
  ncRes->imag = nc1->imag + nc2->imag;
  return ncRes;
}

//SUBTRAÇÃO
struct tComplexos* Subtração (struct tComplexos *nc1, struct tComplexos *nc2){
  struct tComplexos *ncRes = (struct tComplexos*)malloc(sizeof(struct tComplexos));
  ncRes->real = nc1->real - nc2->real;
  ncRes->imag = nc1->imag - nc2->imag;
  return ncRes;
}

//MULTIPLICAÇÃO
struct tComplexos* Multiplicação (struct tComplexos *nc1, struct tComplexos *nc2){
  struct tComplexos *ncRes = (struct tComplexos*)malloc(sizeof(struct tComplexos));
  ncRes->real = (nc1->real * nc2->real)+(nc1->imag * nc2->imag * -1);
  ncRes->imag = (nc1->real * nc2->imag)+(nc1->imag * nc2->real);
  return ncRes;
}

//DIVISÃO
struct tComplexos* Divisão (struct tComplexos *nc1, struct tComplexos *nc2){
  struct tComplexos *ncRes = (struct tComplexos*)malloc(sizeof(struct tComplexos));
  ncRes->real = ((nc1->real * nc2->real)+(nc2->imag * nc1->imag))/((nc2->real * nc2->real)+(nc2->imag * nc2->imag));
  ncRes->imag = ((nc1->imag * nc2->real)-(nc1->real * nc2->imag))/((nc2->real * nc2->real)+(nc2->imag * nc2->imag));
  return ncRes;
}

int main() {
  int quantidade,num,num2,res,valor,i=0;
  struct tComplexos numc,n1,n2,*res;
  char op;

  Lista A;
  
  cout<<"QUANTIDADE DE NÚMEROS COMPLEXOS?"<<endl;
  cin>>quantidade;
  cout<<"INFORME OS NÚMEROS COMPLEXOS"<<endl;

  while(quantidade>i){
    LerComplexo (&numc);
    A.insereNoInicio(&numc);
    i=i+1;
  }
  i=0;

  cout<<"INFORME UM NÚMERO COMPLEXO DA LISTA"<<endl;
  LerComplexo (&n1);

  if(A.existeElemento(&n1))
    cout<<"INFORME OUTRO NÚMERO COMPLEXO E A OPERAÇÃO ((+,-,*,/)) A SER REALIZADA COM O NÚMERO COMPLEXO DA LISTA"<<endl;
    LerComplexo (&n2)>>op;

    if (op == '+')
      res = Soma (&num,&num2);    

    if (op == '-')
      res = Subtração (&num,&num2);    

    if (op == '*')
      res = Multiplicação (&num,&num2);    

    if (op == '/')
      res = Divisão (&num,&num2);
    
  









}