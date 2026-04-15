#include<stdio.h>
#include<string.h>

#define MAX_TERRITORIO 5
#define MAX_STRING 30
#define MAX_COR 10

struct Territorio
{
    char nome[MAX_STRING];
    char cor[MAX_COR];
    int tropas;
};

void limparBuffer(){
    int c;
    while((c=getchar()) != '\n' && c != EOF);
}

int main() {
    struct Territorio war[MAX_TERRITORIO];
    int territorio = 0;

    printf("\n\n=== Vamos cadastrar os 5 territórios do nosso mundo! ===\n");
    
    for (territorio; territorio < MAX_TERRITORIO; territorio++)
    {
        printf("\n--- Cadastro do território %d: ---\n", territorio + 1);
        printf("Nome do território: ");
        fgets(war[territorio].nome, MAX_STRING, stdin);
        war[territorio].nome[strcspn(war[territorio].nome, "\n")] = '\0';

        printf("Cor do território: ");
        fgets(war[territorio].cor, MAX_COR, stdin);
        war[territorio].cor[strcspn(war[territorio].cor, "\n")] = '\0';

        printf("Número de tropas: ");
        scanf("%d", &war[territorio].tropas);
        limparBuffer();
    }

    printf("\n==================================\n");
    printf("   MAPA DO MUNDO - ESTADO ATUAL");
    printf("\n==================================\n");
    
    for (int i = 0; i < territorio; i++)
    {
        printf("\nTERRITORIO: %d\n", i + 1);
        printf("Nome: %s\n", war[i].nome);
        printf("Dominado por: Exercito %s\n", war[i].cor);
        printf("Tropas: %d\n", war[i].tropas);
    }
    
    return 0;
}