/*
Artur Henrique Pagno - 21013037
Carlos Eduardo Fontes Camacho  - 21008649
Cesar Augusto Camote Inocencio - 20018446
Felipe de Moura Tayar - 201019634
João Victor Moreira Vidal - 19291384
Patrick Pimentel Corrêa Leite - 21007850

Opcionais funcionando: 2 e 7.

Valor do Projeto: 10 Pontos
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <locale.h>


using namespace std;


typedef struct animal {
    char nome[50];
    char especie[50];
    char raca[50];
    char sexo[50];
    char idade[50];
    char caracteristicas[50];
    struct animal* prox;
}Animal;

typedef struct lista {
    Animal* inicio;
    Animal* fim;
}Lista;

void mudafundo (int cor){
    CONSOLE_SCREEN_BUFFER_INFO var;
    HANDLE Saida;
    Saida = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(Saida, &var);
    var.wAttributes &= 0x000F;
    SetConsoleTextAttribute (Saida, var.wAttributes |= (cor << 4));
}




void mudacor(int cor)
{

/*
0    Preto
1    Azul
2    Verde
3    Verde-Água
4    Vermelho
5    Roxo
6    Amarelo
7    Branco
8    Cinza
9    Azul-Claro
10    Verde-Claro
11    Verde-Água-Claro
12    Vermelho-Claro
13    Lilás
14    Amarelo-Claro
15    Branco-Brilhante

0 = Preto		8 = Cinza
1 = Azul		9 = Azul Claro
2 = Verde		A = Verde Claro
3 = Verde-Agua	        B = Verde-Agua Claro
4 = Vermelho	        C = Vermelho Claro
5 = Roxo		D = Lilas
6 = Amarelo		E = Amarelo Claro
7 = Branco		F = Branco Brilhante
*/
	HANDLE Saida;
	Saida = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(Saida,cor);

}


void inicializar(Lista* l) {
    l->inicio = NULL;
    l->fim = NULL;
}

void inserir(Lista* l, char nome[], char especie[], char raca[], char sexo[], char idade[], char caracteristicas[]) {
	FILE* PetsArch;
	PetsArch = fopen("PetsArch.txt","a");
	if (PetsArch == NULL) {
		printf("Erro na Abertura do Arquivo");
	} else {

	
    Animal* aux = (Animal*)malloc(sizeof(Animal));
    strcpy(aux->nome, nome);
    strcpy(aux->especie, especie);
    strcpy(aux->raca, raca);
    strcpy(aux->sexo, sexo);
    strcpy(aux->idade, idade);
    strcpy(aux->caracteristicas, caracteristicas);
    fprintf(PetsArch,"\nNome: %s",aux->nome);
    fprintf(PetsArch,"\nespecie: %s",aux->especie);
    fprintf(PetsArch,"\nraca: %s",aux->raca);

    fprintf(PetsArch,"\nsexo: %s",aux->sexo);
    fprintf(PetsArch,"\nidade: %s",aux->idade);
    fprintf(PetsArch,"\ncaracteristicas: %s",aux->caracteristicas);
    fprintf(PetsArch,"\n--------------------");
    aux->prox = NULL;
    if (l->inicio == NULL) {
        l->inicio = aux;
        l->fim = aux;
    }
    else {
        l->fim->prox = aux;
        l->fim = aux;
    }
    	}
    fclose(PetsArch);

}

void remover(Lista* l, char nome[]) {
    Animal* aux = l->inicio;
    Animal* anterior = NULL;
    while (aux != NULL) {
        if (strcmp(aux->nome, nome) == 0) {
            if (aux == l->inicio) {
                l->inicio = aux->prox;
            }
            else {
                anterior->prox = aux->prox;
            }
            if (aux == l->fim) {
                l->fim = anterior;
            }
            free(aux);
            break;
        }
        anterior = aux;
        aux = aux->prox;
    }
}

void alterar(Lista* l, char nome[], char especie[], char raca[], char sexo[], char idade[], char caracteristicas[]) {
    Animal* aux = l->inicio;
    while (aux != NULL) {
        if (strcmp(aux->nome, nome) == 0) {
            strcpy(aux->especie, especie);
            strcpy(aux->raca, raca);
            strcpy(aux->sexo, sexo);
            strcpy(aux->idade, idade);
            strcpy(aux->caracteristicas, caracteristicas);
            break;
        }
        aux = aux->prox;
    }
}

void buscar(Lista* l, char nome[]) {
    Animal* aux = l->inicio;
    while (aux != NULL) {
        if (strcmp(aux->nome, nome) == 0) {
            printf("Nome: %s\n", aux->nome);
            printf("Espécie: %s\n", aux->especie);
            printf("raca: %s\n", aux->raca);
            printf("Sexo: %s\n", aux->sexo);
            printf("Idade: %s\n", aux->idade);
            printf("Características: %s\n", aux->caracteristicas);
            break;
        }
        aux = aux->prox;
    }
}

void buscar_especie(Lista* l, char especie[]) {
    Animal* aux = l->inicio;
    while (aux != NULL) {
        if (strcmp(aux->especie, especie) == 0) {
            printf("Nome: %s\n", aux->nome);
            printf("Espécie: %s\n", aux->especie);
            printf("raca: %s\n", aux->raca);
            printf("Sexo: %s\n", aux->sexo);
            printf("Idade: %s\n", aux->idade);
            printf("Características: %s\n", aux->caracteristicas);
        }
        aux = aux->prox;
    }
}

void buscar_especie_raca(Lista* l, char especie[], char raca[]) {
    Animal* aux = l->inicio;
    while (aux != NULL) {
        if (strcmp(aux->especie, especie) == 0 && strcmp(aux->raca, raca) == 0) {
            printf("Nome: %s\n", aux->nome);
            printf("Espécie: %s\n", aux->especie);
            printf("raca: %s\n", aux->raca);
            printf("Sexo: %s\n", aux->sexo);
            printf("Idade: %s\n", aux->idade);
            printf("Características: %s\n", aux->caracteristicas);
        }
        aux = aux->prox;
    }
}

void buscar_especie_raca_sexo(Lista* l, char especie[], char raca[], char sexo[]) {
    Animal* aux = l->inicio;
    while (aux != NULL) {
        if (strcmp(aux->especie, especie) == 0 && strcmp(aux->raca, raca) == 0 && strcmp(aux->sexo, sexo) == 0) {
            printf("Nome: %s\n", aux->nome);
            printf("Espécie: %s\n", aux->especie);
            printf("raca: %s\n", aux->raca);
            printf("Sexo: %s\n", aux->sexo);
            printf("Idade: %s\n", aux->idade);
            printf("Características: %s\n", aux->caracteristicas);
        }
        aux = aux->prox;
    }
}

int contar(Lista* l) {
    int cont = 0;
    Animal* aux = l->inicio;
    while (aux != NULL) {
        cont++;
        aux = aux->prox;
    }
    return cont;
}

int contar_especie(Lista* l, char especie[]) {
    int cont = 0;
    Animal* aux = l->inicio;
    while (aux != NULL) {
        if (strcmp(aux->especie, especie) == 0) {
            cont++;
        }
        aux = aux->prox;
    }
    return cont;
}

void listar(Lista* l) {
	
	FILE* PetsArch;
	PetsArch = fopen("PetsArch.txt","r");
	
    Animal* aux = l->inicio;
    
	while (aux != NULL) {
        fread(&l,sizeof(animal),210,PetsArch);
		printf("Nome: %s\n", aux->nome);
        printf("Espécie: %s\n", aux->especie);
        printf("raca: %s\n", aux->raca);
        printf("Sexo: %s\n", aux->sexo);
        printf("Idade: %s\n", aux->idade);
        printf("Características: %s\n", aux->caracteristicas);
        printf("\n------------");
        aux = aux->prox;
    }

    fclose(PetsArch);
	
}

void listar_especie(Lista* l, char especie[]) {
    Animal* aux = l->inicio;
    while (aux != NULL) {
        if (strcmp(aux->especie, especie) == 0) {
            printf("Nome: %s\n", aux->nome);
            printf("Espécie: %s\n", aux->especie);
            printf("raca: %s\n", aux->raca);
            printf("Sexo: %s\n", aux->sexo);
            printf("Idade: %s\n", aux->idade);
            printf("Características: %s\n", aux->caracteristicas);
        }
        aux = aux->prox;
    }
}

void listar_especie_raca(Lista* l, char especie[], char raca[]) {
    Animal* aux = l->inicio;
    while (aux != NULL) {
        if (strcmp(aux->especie, especie) == 0 && strcmp(aux->raca, raca) == 0) {
            printf("Nome: %s\n", aux->nome);
            printf("Espécie: %s\n", aux->especie);
            printf("raca: %s\n", aux->raca);
            printf("Sexo: %s\n", aux->sexo);
            printf("Idade: %s\n", aux->idade);
            printf("Características: %s\n", aux->caracteristicas);
        }
        aux = aux->prox;
    }
}

void listar_especie_raca_sexo(Lista* l, char especie[], char raca[], char sexo[]) {
    Animal* aux = l->inicio;
    while (aux != NULL) {
        if (strcmp(aux->especie, especie) == 0 && strcmp(aux->raca, raca) == 0 && strcmp(aux->sexo, sexo) == 0) {
            printf("Nome: %s\n", aux->nome);
            printf("Espécie: %s\n", aux->especie);
            printf("raca: %s\n", aux->raca);
            printf("Sexo: %s\n", aux->sexo);
            printf("Idade: %s\n", aux->idade);
            printf("Características: %s\n", aux->caracteristicas);
        }
        aux = aux->prox;
    }
}

int main() {
	system("title Cadastro de Pets");
	setlocale (LC_ALL,"Portuguese");
	mudafundo(0);
	
    Lista lista;
    inicializar(&lista);
    char nome[50], especie[50], raca[50], sexo[50], idade[50], caracteristicas[50];
    int opcao;
    
printf("\n\n\n\t     Cadastro de Animais");


	do {
        
		mudacor(6);
        printf("\n\n\n===============================================\n"
            "=================== MENU ======================\n"
            "===============================================\n\n");
        mudacor(2);
		printf("\n1 - Inserir\n2 - Remover\n3 - Alterar\n4 - Buscar\n5 - Buscar por Especie\n6 - Buscar por Especie e raca\n7 - Buscar por Especie, raca e Sexo\n8 - Contar\n9 - Contar por Especie\n10 - Listar\n0 - Sair\n\n");
        printf(">>>Digite a sua escolha: ");
        scanf("%d", &opcao);
        switch (opcao) {
       
        case 1:
       		mudacor(4);
            printf("Por favor, insira os dados do animal:\n");
            printf("Nome: ");
            scanf("%s", nome);
            printf("Espécie: ");
            scanf("%s", especie);
            printf("raca: ");
            scanf("%s", raca);
            printf("Sexo: ");
            scanf("%s", sexo);
            printf("Idade: ");
            scanf("%s", idade);
            printf("Características: ");
            scanf("%s", caracteristicas);
            inserir(&lista, nome, especie, raca, sexo, idade, caracteristicas);
            break;
        case 2:
        	 mudacor(4);
            printf("Nome: ");
            scanf("%s", nome);
            remover(&lista, nome);
            break;
        case 3:
        	 mudacor(4);
            printf("Digite o nome do animal a ser alterado:\n");
            printf("Nome: ");
            scanf("%s", nome);
            printf("Agora digite os novos dados:\n");
            printf("Espécie: ");
            scanf("%s", especie);
            printf("raca: ");
            scanf("%s", raca);
            printf("Sexo: ");
            scanf("%s", sexo);
            printf("Idade: ");
            scanf("%s", idade);
            printf("Características: ");
            scanf("%s", caracteristicas);
            alterar(&lista, nome, especie, raca, sexo, idade, caracteristicas);
            break;
        case 4:
        	 mudacor(4);
            printf("Nome: ");
            scanf("%s", nome);
            buscar(&lista, nome);
            break;
        case 5:
        	      	 mudacor(4);
            printf("Especie: ");
            scanf("%s", especie);
            buscar_especie(&lista, especie);
            break;
        case 6:
        	mudacor(4);
            printf("Especie: ");
            scanf("%s", especie);
            printf("raca: ");
            scanf("%s", raca);
            printf("\n");
            buscar_especie_raca(&lista, especie, raca);
            break;
        case 7:
        	mudacor(4);
            printf("Especie: ");
            scanf("%s", especie);
            printf("raca: ");
            scanf("%s", raca);
            printf("Sexo: ");
            scanf("%s", sexo);
            printf("\n");
            buscar_especie_raca_sexo(&lista, especie, raca, sexo);
            break;
        case 8:
        	mudacor(4);
            printf("Quantidade: %d\n", contar(&lista));
            break;
        case 9:
        	mudacor(4);
            printf("Digite a especie a ser consultada: ");
            scanf("%s", especie);
            printf("Quantidade: %d\n", contar_especie(&lista, especie));
            break;
        case 10:
        	mudacor(4);
            printf("\n\n==============================================================\n"
                "=================== ANIMAIS CADASTRADOS ======================\n"
                "==============================================================\n\n");
            listar(&lista);
            break;
        case 0:
        	mudacor(6);
            printf("\nObrigado por utilizar este programa! :)");
            break;
        default:
        	mudacor(8);
            printf("Opção inválida!\n");
        }
    } while (opcao != 0);
    return 0;
}