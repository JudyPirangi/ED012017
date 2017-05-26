#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Universidade de Brasilia
Instituto de Ciencias Exatas
Departamento de Ciencia da Computacao
Estrutura de Dados – 1/2017
Aluno(a): Rafael Silva Brito, Judy Pirangi Inacio Rodrigues
Matricula: 15/0145721, 16/0010438
Turma: B
Versão do compilador: GCC 6.3 / repl.it
Descricao: Desenvolver uma agenda eletrônica com inserção, edição, exclusão e ordenação.
*/

typedef struct tContato{
  char nome[100], email[100];
  long int telefone;
  struct tContato *prox;
} contato;

// Função com o menu principal
int menu(){
  int op;

  printf("\nESCOLHA A OPCAO\n");
	printf("1. Adicionar um contato\n");
  printf("2. Buscar um contato\n");
	printf("3. Editar um contato\n");
	printf("4. Remover um contato\n");
	printf("5. Exibir agenda completa\n");
	printf("6. Limpar agenda\n");
	printf("0. Sair\n");
	printf("Opcao: ");
  scanf("%d", &op);
  printf("\n");

  return op;
}

// Esta função irá verificar se a fila está ou não vazia
int vazia(contato *fila){
  if (fila->prox ==  NULL) {
    return 1; // Retorna 1 para fila vazia
  } else {
    return 0; // Retorna 0 para fila com pelo menos 1 elemento
  }
}

// Função de inserção na fila
void inserir(contato *fila){
  // Alocação do novo elemento da fila
  contato *novo = (contato *) malloc(sizeof(contato));
  // Variáveis auxiliares para percorer a fila
  contato *anterior, *atual;

  atual = fila->prox;
  anterior = NULL;

  printf("Informe os dados do contato:\n");
  printf("Nome: ");
  scanf("%s", novo->nome);
  printf("E-mail: ");
  scanf("%s", novo->email);
  printf("Telefone: ");
  scanf("%d", &novo->telefone);
  novo->prox = NULL;

  if (vazia(fila)) {
    fila->prox = novo;
  } else {
      // A inserção é ordenada alfabeticamente
  		while(atual != NULL && strcmp(atual->nome, novo->nome) <= 0){
        anterior = atual;
        atual = atual->prox;
      }
      novo->prox = atual;

      if(anterior == NULL){
          fila->prox = novo;
      } else{
          anterior->prox = novo;
      }
  }
}

// Função para exibir toda a lista de contatos
void exibir(contato *fila){
  contato *aux;

  if (vazia(fila)){
    printf("Agenda vazia!\n");
  } else {
    aux = fila->prox;
    printf("Contatos:\n\n");
    while (aux != NULL) {
      printf("Nome: %s\n", aux->nome);
      printf("Email: %s\n", aux->email);
      printf("Telefone: %d\n\n", aux->telefone);
      aux = aux->prox;
    }
  }
}

// Função para exibir um contato específico da lista
void buscar(contato *fila){
  char nome[100];
  contato *aux;
  int find = 0;

  if (vazia(fila)) {
    printf("A agenda está vazia!\n");
  } else {
    printf("Informe o contato: ");
    scanf("%s", nome);
    aux = fila->prox;
    while (aux != NULL) {
      if (strcmp(nome, aux->nome) == 0) { // Comparação do contato buscado com os contatos da lista
        printf("Nome: %s\n", aux->nome);
        printf("Email: %s\n", aux->email);
        printf("Telefone: %d\n", aux->telefone);
        find = 1; // Flag para controle da busca do contato
      }
      aux = aux->prox;
    }
    if (find != 1) {
      printf("Não foram encontrados resultados.\n");
    }
  }

}

// Função para editar um contato
void editar(contato *fila){
  char nome[100];
  contato *aux;
  int find = 0;

  if (vazia(fila)) {
    printf("A agenda está vazia!\n");
  } else {
    printf("Informe o contato que deseja editar: ");
    scanf("%s", nome);
    aux = fila->prox;
    while (aux != NULL) {
      if (strcmp(nome, aux->nome) == 0) {
        printf("Novo nome: ");
        scanf("%s", aux->nome);
        printf("Novo e-mail: ");
        scanf("%s", aux->email);
        printf("Novo telefone: ");
        scanf("%d", &aux->telefone);
        find = 1;
      }
      aux = aux->prox;
    }
    if (find != 1) {
      printf("Não foram encontrados resultados.\n");
    }
  }

}

// Função para remover um contato
void remover(contato *fila){
  contato *proximo, *anterior;
  char nome[100];
  int find;

  if (vazia(fila)) {
    printf("A agenda está vazia!\n");
  } else {
    printf("Informe qual contato deseja excluir:\n");
    printf("Nome: ");
    scanf("%s", nome);
    anterior = fila;
    proximo = fila->prox;
    while (proximo != NULL && strcmp(proximo->nome, nome) != 0) { // Comparação de resultados
      anterior = proximo;
      proximo = proximo->prox;
    }
    if (proximo != NULL){
        anterior->prox = proximo->prox;
        free(proximo);
        find = 1;  // Flag de controle
    }
    if (find == 1) {
      printf("Contato deletado!\n");
    } else {
      printf("Não foi encontrado resultado.\n");
    }
  }
}

// Função para limpar toda a lista
void limpar (contato *fila){
  if (vazia(fila)) {
    printf("A agenda já está vazia!\n");
  } else {
    contato *lixo; //contato que será excluido
    while(fila->prox != NULL){
      lixo = fila->prox;
      fila->prox = lixo->prox;
      free (lixo);
    }
    printf("Agenda Limpa!\n");
  }
}

int main(){
  int op, tamanho = 0;
  contato *fila = (contato *) malloc(sizeof(contato));

  fila->prox = NULL;

  do {
    op = menu();

    switch (op) {
      case 0: // sair
        break;

      case 1: // inserir
        inserir(fila);
        tamanho++;
        break;

      case 2: // buscar
        buscar(fila);
        break;

      case 3: // editar
        editar(fila);
        break;

      case 4: // remover
        remover(fila);
        tamanho--;
        break;

      case 5: // exibir todos
        exibir(fila);
        //printf("Total de %d contatos na agenda.\n", tamanho);
        break;

      case 6: // limpar
        limpar(fila);

        break;

      default:
        printf("Opção inválida tente novamente!\n");
    }

  } while(op != 0);

  free(fila);

  return 0;
}
