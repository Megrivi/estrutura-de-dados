#include <stdio.h>
#define MAX 20
#define ERRO -1
#define true 1
#define false 0

typedef int bool;

typedef int TIPOCHAVE;

typedef struct{
  TIPOCHAVE chave;
} REGISTRO;

typedef struct {
  REGISTRO A[MAX];
  int nroElem;
} LISTA;


void inicializarLista(LISTA* m){
  m->nroElem = 0;
} 

void exibirLista(LISTA* m){
  int i;
  printf("");
  for (i=0; i < m->nroElem; i++)
    printf("%i ", m->A[i].chave); 
  printf("\"\n");
}  

int tamanho(LISTA* m) {
  return m->nroElem;
}



void reinicializarLista(LISTA* m) {
  m->nroElem = 0;
} 


bool inserirElemLista(LISTA* m, REGISTRO inst, int i){
  int j;
  if ((m->nroElem >= MAX) || (i < 0) || (i > m->nroElem)) 
     return(false); 
  for (j = m->nroElem; j > i; j--) {
    m->A[j] = m->A[j-1];
  }
  m->A[i] = inst;
  m->nroElem++;
  return true;
} 

int buscaSequencial(LISTA* m, TIPOCHAVE ch) {
  int i = 0;
  while (i < m->nroElem){
    if(ch == m->A[i].chave) return i; 
    else i++;
  }
  return ERRO; 
} 



bool excluirElemLista(LISTA* m, TIPOCHAVE ch) { 
  int pos, j;
  pos = buscaSequencial(m,ch);
  if(pos == ERRO) return false; 
  for(j = pos; j < m->nroElem-1; j++) {
    m->A[j] = m->A[j+1];
  }
  m->nroElem--;
  return true;
} 



int main(){
  printf("\n\n um aluno de auto-escola precisa acertar as machas para passar no exame do detran, mas ao transitar no pátio do exame e ao ver o sinal ficar amarelo e o avaliador passar, ele não sabe que macha passar que corresponda a velocidade..  \n\n");
 
  printf("\n\n");
  
  LISTA nlista;
  
  inicializarLista(&nlista);
  
  exibirLista(&nlista);
  
  REGISTRO reg;
  
  reg.chave = 1;
  inserirElemLista(&nlista,reg,0);
  reg.chave=2;
  inserirElemLista(&nlista,reg,1);
  reg.chave=3;
  inserirElemLista(&nlista,reg,2);
  reg.chave=4;
  inserirElemLista(&nlista,reg,3);
  reg.chave=5;
  inserirElemLista(&nlista,reg,4);

  exibirLista(&nlista);
  
   printf("\nNumero de elementos da lista : %i.\n",tamanho(&nlista));
   printf("\nchave 3 na posição : %i do arranjo N.\n",buscaSequencial(&nlista,3));
  
  if (excluirElemLista(&nlista,3)){
    printf("\n\nNumero deletado com sucesso: 3 .\n");
  } 
else{
  printf("");
}

  exibirLista(&nlista);
  
   printf("\nNumero de elementos na lista: %i.\n",tamanho(&nlista));
  
   reinicializarLista(&nlista);
   exibirLista(&nlista);
  
  
LISTA nlocal;
  
  inicializarLista(&nlocal);
  
  exibirLista(&nlocal);
  
  REGISTRO r;
  r.chave = 1;
  inserirElemLista(&nlocal,r,0);
  r.chave=2;
  inserirElemLista(&nlocal,r,1);
  r.chave=3;
  inserirElemLista(&nlocal,r,2);
  r.chave=4;
  inserirElemLista(&nlocal,r,3);
  r.chave=5;
  inserirElemLista(&nlocal,r,4);
  r.chave = 6;
  inserirElemLista(&nlocal,r,5);
  r.chave=7;
  inserirElemLista(&nlocal,r,6);
  r.chave=8;
  inserirElemLista(&nlocal,r,7);
  r.chave=9;
  inserirElemLista(&nlocal,r,8);
  r.chave=10;
  inserirElemLista(&nlocal,r,9);

  exibirLista(&nlocal);
  
   printf("\nNumero de elementos da lista : %i.\n",tamanho(&nlocal));
   printf("\nchave 8 na posição : %i do arranjo P.\n",buscaSequencial(&nlocal,8));
  
  if (excluirElemLista(&nlocal,8)){
    printf("\n\nNumero deletado com sucesso: 8 .\n");
  } 
else{
  printf("");
}

  exibirLista(&nlocal);
  
   printf("\nNumero de elementos na lista: %i.\n",tamanho(&nlocal));
  
   reinicializarLista(&nlocal);
   exibirLista(&nlocal);
   return 0;
  }