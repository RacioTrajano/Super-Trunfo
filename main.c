#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// criação do registro
typedef struct carta{
  char classe;
  char trunfo;
  int idade;
  float peso;
  char nome[50];
}card;

void imprime_classe(char letra){
  switch (letra){
      case 'M' : printf("mamífero\n"); break;
      case 'A' : printf("ave\n"); break;
      case 'R' : printf("réptil\n"); break;
      case 'P' : printf("peixe\n"); break;
      case 'N' : printf("anfíbio\n"); break;
  }
}

int main () {
// criação das variáveis

int pos_trunfo;
int velho=0;
int pos_velho;
float gordo=0;
int pos_gordo;
int profeta=0;
int pos_profeta;
char nome[50]={0};
int n;
// criação das variáveis da classe
int mamiferos=0;
int repteis=0;
int peixes=0;
int anfibios=0;
int aves=0;



scanf ("%d", &n);

//criação do vetor de deck de cartas
card deck[n];

// estruturação das leituras
for (int i=0; i< n; i++){
  scanf(" %c", &deck[i].classe);
    switch(deck[i].classe){
      case 'M' : mamiferos++; break;
      case 'A' : aves++; break;
      case 'R' : repteis++; break;
      case 'P' : peixes++; break;
      case 'N' : anfibios++; break;
    }
  scanf(" %c", &deck[i].trunfo);
  scanf("%d", &deck[i].idade);
  scanf("%f", &deck[i].peso);
  fgets(nome,50, stdin);
  nome[strlen(nome) -1] = '\0';
  strcpy(deck[i].nome, nome);
}

// verifica o mais velho
for(int i=0; i<n; i++){
  if(deck[i].idade > velho){
    velho = deck[i].idade;
    pos_velho=i;
  }
}

// verifica o mais pesado
for(int i=0; i<n; i++){
  if(deck[i].peso > gordo){
    gordo = deck[i].peso;
    pos_gordo = i;
  }
}

// verifica o maior nome
for (int i=0; i<n; i++){
  if(strlen(deck[i].nome) > profeta){
    profeta= strlen(deck[i].nome);
    pos_profeta=i;
  }
}

// verifica o trunfo
for (int i=0; i<n; i++){
  if(deck[i].trunfo == 'S'){
    pos_trunfo =i;
  }
}

//impressão das respostas######################

// tempo de vida
printf("Carta com maior tempo de vida:\n");
printf("Nome: %s\n",deck[pos_velho].nome);
printf("Idade máxima: %d\n",deck[pos_velho].idade);
printf("Peso médio: %.2f\n", deck[pos_velho].peso);
printf("Classe: ");
imprime_classe(deck[pos_velho].classe);
printf("Supertrunfo? ");
if (deck[pos_velho].trunfo == 'S')
  printf("sim\n");
else printf("não\n");
printf("\n");
// peso

printf("Carta com maior peso:\n");
printf("Nome: %s\n",deck[pos_gordo].nome);
printf("Idade máxima: %d\n",deck[pos_gordo].idade);
printf("Peso médio: %.2f\n", deck[pos_gordo].peso);
printf("Classe: ");
imprime_classe(deck[pos_gordo].classe);
printf("Supertrunfo? ");
if (deck[pos_gordo].trunfo == 'S')
  printf("sim\n");
else printf("não\n");
printf("\n");
//nome mais longo

printf("Carta com nome mais longo:\n");
printf("Nome: %s\n",deck[pos_profeta].nome);
printf("Idade máxima: %d\n",deck[pos_profeta].idade);
printf("Peso médio: %.2f\n", deck[pos_profeta].peso);
printf("Classe: ");
imprime_classe(deck[pos_profeta].classe);
printf("Supertrunfo? ");
if (deck[pos_profeta].trunfo == 'S')
  printf("sim\n");
else printf("não\n");
printf("\n");
// supertrunfo

printf("Supertrunfo:\n");
printf("Nome: %s\n",deck[pos_trunfo].nome);
printf("Idade máxima: %d\n",deck[pos_trunfo].idade);
printf("Peso médio: %.2f\n", deck[pos_trunfo].peso);
printf("Classe: ");
imprime_classe(deck[pos_trunfo].classe);
printf("Supertrunfo? ");
if (deck[pos_trunfo].trunfo == 'S')
  printf("sim\n");
else printf("não\n");
printf("\n");
// total de cartas

printf("Total de cartas em cada classe:\n");
printf("Mamíferos: %d\n", mamiferos);
printf("Répteis: %d\n", repteis);
printf("Peixes: %d\n", peixes);
printf("Anfíbios: %d\n", anfibios);
printf("Aves: %d\n", aves);

  return 0;
}