   #include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char nome[50];
    float unitario;
    int qtde;
    float total_item;
} Item;

int main() {
    Item itens[MAX_ITEMS];
    int numItens, i, j;
    int codigo;
    float totalGeral = 0.0;

    printf("Informe o número de itens que deseja inserir: ");
    scanf("%d", &numItens);

    if (numItens > MAX_ITEMS) {
        printf("Número de itens excede o limite máximo de %d.\n", MAX_ITEMS);
        return 1;
    }

    for (i = 0; i < numItens; i++) {
        printf("\nInforme os dados do item %d:\n", i + 1);

        while (1) {
            printf("ID (Codigo do item): ");
            scanf("%d", &codigo);
            int codigoDuplicado = 0;
            for (j = 0; j < i; j++) {
                if (itens[j].id == codigo) {
                    codigoDuplicado = 1;
                    break;
                }
            }
            if (codigoDuplicado) {
                printf("Erro: Código já existe. Por favor, insira um código diferente.\n");
            } else {
                itens[i].id = codigo;
                break;
            }
        }

        printf("Nome: ");
        scanf("%s", itens[i].nome);
        printf("Valor Unitário: ");
        scanf("%f", &itens[i].unitario);
        printf("Quantidade: ");
        scanf("%d", &itens[i].qtde);

        itens[i].total_item = itens[i].unitario * itens[i].qtde;
        totalGeral += itens[i].total_item;
    }

    printf("\n%-10s %-20s %-10s %-10s %-10s\n", "CODIGO", "NOME", "QTDE", "UNIT", "TOTAL");
    for (i = 0; i < numItens; i++) {
        printf("%-10d %-20s %-10d %-10.2f %-10.2f\n", itens[i].id, itens[i].nome, itens[i].qtde, itens[i].unitario, itens[i].total_item);
    }

    printf("\n%-50s %-10.2f\n", "TOTAL FINAL", totalGeral);

    return 0;
}
