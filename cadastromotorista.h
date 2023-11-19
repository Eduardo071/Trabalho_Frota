#include <stdio.h>
#include <stdlib.h>
typedef struct {
  int iCodigo;
  char sNome[50];
  int sIdade;
  char sCategoria_Cnh[20];
  char sEndereco[50];
  int sNumero_Residencia;
  char sCidade[50];
  char sEmail[50];
  char sObservacao[100];
  char sVencimento[20];
  char sData_Cadastro[20];
  char sTelefone;
} st_motorista;

void cadastrar_motorista() {
  FILE *arq_motorista = fopen("motorista.bin", "a+b");

  if (arq_motorista == NULL) {
    printf("\nFalha ao abrir arquivo(s)!\n");
    exit(1);
  }

  int cont_bytes = 0;
  fseek(arq_motorista, 0, SEEK_END);
  cont_bytes = ftell(arq_motorista);

  st_motorista motorista;

  if (cont_bytes == 0) {
    motorista.iCodigo = 1;
  } else {
    st_motorista ultima_motorista;
    fseek(arq_motorista, cont_bytes - sizeof(st_motorista), SEEK_SET);
    fread(&ultima_motorista, sizeof(st_motorista), 1, arq_motorista);
    motorista.iCodigo = ultima_motorista.iCodigo + 1;
  }

  printf("\nNome do Motorista.......: ");
  scanf(" %49[^\n]%*c", motorista.sNome);

  printf("Idade do motorista......: ");
  scanf("%d", &motorista.sIdade);
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
  printf("Categoria da CNH........: ");
  scanf(" %19[^\n]%*c", motorista.sCategoria_Cnh);

  printf("Endereço................: ");
  scanf(" %49[^\n]%*c", motorista.sEndereco);

  printf("Numero da Residência....: ");
  scanf("%d", &motorista.sNumero_Residencia);
  while ((c = getchar()) != '\n' && c != EOF)
    ;
  printf("Cidade..................: ");
  scanf(" %49[^\n]%*c", motorista.sCidade);

  printf("Email...................: ");
  scanf(" %49[^\n]%*c", motorista.sEmail);

  printf("Observação..............: ");
  scanf(" %99[^\n]%*c", motorista.sObservacao);

  printf("Venc.Toxicologico.......: ");
  scanf(" %19[^\n]%*c", motorista.sVencimento);

  printf("Data do Cadastro........: ");
  scanf(" %19[^\n]%*c", motorista.sData_Cadastro);

  printf("Telefone................: ");
  scanf("%d", &motorista.sTelefone);

  fseek(stdin, 0, SEEK_END);
  fseek(arq_motorista, 0, SEEK_END);
  fwrite(&motorista, sizeof(st_motorista), 1, arq_motorista);

  fclose(arq_motorista); // Mova esta linha para dentro do bloco if/else

  printf("\nMotorista \"%s\" cadastrado com sucesso!\n", motorista.sNome);
  printf("\nPressione <Enter> para continuar...");
  scanf("%*c");
  fseek(stdin, 0, SEEK_END);
}

/*=================================================================fun  o para
 * listar
 * motorista=================================================================================*/

void listar_motorista() {
  FILE *arq_motorista = fopen("motorista.bin", "rb");

  if (arq_motorista == NULL) {
    printf("\nFalha ao abrir arquivo(s) ou ");
    printf("Nenhum Motorista cadastrado.\n");
    printf("\nPressione <Enter> para continuar...");
    scanf("%*c");
    fseek(stdin, 0, SEEK_END);
    return;
  }

  int encontrou_motorista = 0;
  st_motorista motorista;

  printf("\nListando todos os Motoristas(s)...\n");

  while (fread(&motorista, sizeof(st_motorista), 1, arq_motorista) != 0) {
    encontrou_motorista = 1;

    printf("\nCódigo do Motorista: %d\n", motorista.iCodigo);
    printf("Nome do Motorista: %s\n", motorista.sNome);
    printf("Categoria da CNH: %s\n", motorista.sCategoria_Cnh);
    printf("Venc.Toxicologico: %s\n", motorista.sVencimento);
    printf("Telefone: %d\n", motorista.sTelefone);
    printf("Observações: %s\n", motorista.sObservacao);
  }

  if (encontrou_motorista == 0)
    printf("\nNenhum Motorista Cadastrado.\n");

  fclose(arq_motorista);

  printf("\nPressione <Enter> para continuar...");
  scanf("%*c");
  fseek(stdin, 0, SEEK_END);
}