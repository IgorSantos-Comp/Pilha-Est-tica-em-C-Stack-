#include <stdio.h>
#include <stdlib.h> // Necessário para system("pause") e system("cls") no linux ele acaba ignorando...

#define MX 10

// Inicializando topo como -1 por segurança
int pilha[MX], topo = -1; 

void menu()
{
    printf("\n****** Menu Pilha ******\n");
    printf("1 - Criar pilha\n");
    printf("2 - Inserir elemento\n");
    printf("3 - Remover elemento\n");
    printf("4 - Exibir topo\n");
    printf("5 - Exibir pilha\n");
    printf("6 - Tamanho Pilha\n");
    printf("7 - Sair\n");
}

void pilha_cria()
{
    topo = -1;
    printf("\nA pilha foi criada/resetada.\n");
}

int pilha_vazia()
{
    if(topo == -1)
    {
        return 1; // pilha vazia
    }
    else
    {
        return 0; // pilha tem elemento
    }
}

int pilha_cheia()
{
    if(topo == MX-1)
    {
        return 1; // pilha cheia
    }
    else
    {
        return 0;
    }
}

void inserir(int elemento)
{
    if(!pilha_cheia())
    {
        topo++;
        pilha[topo] = elemento;
        printf("\nElemento %d inserido com sucesso!\n", elemento);
    }
    else
    {
        printf("\nA pilha esta cheia!\n");
    }
}

int excluir() 
{
    int elemento;
    
    if(pilha_vazia()) 
    {
        printf("\nImpossivel remover, pilha vazia!\n");
        return -1; // Retorno de erro
    }
    else
    {
        elemento = pilha[topo];
        topo--;
        return elemento;
    }
}

void exibir_topo()
{
    if(!pilha_vazia())
    {
        printf("\nO topo da pilha e %d\n", pilha[topo]);
    }
    else
    {
        printf("\nPilha vazia!!\n");
    }
}

void mostrar_pilha() 
{
    int i;
    if(!pilha_vazia())
    {
        printf("\nElementos da pilha:\n");
        for(i = topo; i >= 0; i--)
        {
            printf("%d\n", pilha[i]);
        }
    }
    else
    {
        printf("\nPilha vazia!\n");
    }
}

int tamanho()
{
    // O tamanho da pilha sempre será (topo + 1). Se topo for -1, tamanho será 0.
    return topo + 1; 
}

int main()
{
    int op = 0, valor;

    while(op != 7)
    {
        menu();
        printf("\nEscolha a opcao desejada: ");
        scanf("%d", &op);
        
        switch(op)
        {
            case 1: 
                pilha_cria();
                break;
            case 2: 
                printf("Informe um valor: ");
                scanf("%d", &valor);
                inserir(valor);
                break;
            case 3:
                if(!pilha_vazia()) {
                    printf("\nElemento %d removido!\n", excluir());
                } else {
                    excluir(); // Chama apenas para exibir a mensagem de erro
                }
                break;
            case 4: 
                exibir_topo();
                break;
            case 5: 
                mostrar_pilha();
                break;
            case 6: 
                printf("\nO tamanho atual da pilha e %d\n", tamanho());
                break;
            case 7:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }

        if (op != 7) {
            printf("\n");
            system("pause"); // Pausa a tela (Funciona no Windows)
            system("cls");   // Limpa a tela (Funciona no Windows)
        }
    }

    return 0;
}