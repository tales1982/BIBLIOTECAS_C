/*
## Exercício 1: Lista Encadeada
Implemente uma lista encadeada que suporte as operações de inserção, deleção e busca de um elemento.
*/
#include <stdio.h>
#include <stdlib.h>

int ft_strcmp(const char *s1, const char *s2);
char *ft_strcpy(char *dest, const char *src);
void print_menu();

#define TAM 10
typedef struct
{
    char nomeClient[30];
} Cliente;

int main()
{
    Cliente clientes[TAM];
    char *client;
    char *findClient;
    int menu;
    int i;
    int j;
    int conf;
    int seachClient;

    client = malloc(sizeof(int));

    i = 0;
    j = 0;

    print_menu();
    scanf("%i", &menu);
    while (menu != 4)
    {

        if (menu == 1)
        {
            // Cadastro cliente;
            printf("Digite o nome do cliente a ser cadastrado..\n");
            scanf(" %[^\n]", client);
            printf("Confime o cadastro de %s digite (1) pra confirma ou (0) pra anular..:", client);

            scanf("%d", &conf);
            setbuf(stdin, NULL);

            if (conf == 1)
            {
                ft_strcpy(clientes[i].nomeClient, client);
                printf("%s foi adcionado a lista de clinets obigado\n\n", client);
            }
            else
                printf("Cadastro anulado\n\n");
            i++;
        }
        else if (menu == 2)
        {
            // Apagar cliente.
            printf("Digite o nome do cliente que deseja apagar..:");
            scanf(" %[^\n]", findClient);
            setbuf(stdin, NULL);

            while (j < TAM)
            {
                seachClient = ft_strcmp(clientes[j].nomeClient, findClient);
                printf("Retorn da comparacao = %d",seachClient);
                /*
                if (seachClient == 0)
                    printf("\nCliente encontrado !!\n\n");
                else
                    printf("Cliente nao encontrado!!\n");
                j++;
                */
            }
        }
        print_menu();
        scanf("%i", &menu);
        printf("\n");
    }
    // imprime clientes
    while (j < i)
    {
        printf("°%i cliente..: %s\n", j + 1, clientes[j].nomeClient);
        j++;
    }

    free(client);
    return 0;
}

int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

char *ft_strcpy(char *dest, const char *src)
{
    int i;

    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

void print_menu()
{
    printf(" ********** Cadatro de clientes **********\n");
    printf("|                                         |\n");
    printf("|            1 - Novo Cliente             |\n");
    printf("|            2 - Deleta Cliente           |\n");
    printf("|            3 - Consulta Cliente         |\n");
    printf("|            4 - EXIT                     |\n");
    printf("|                                         |\n");
    printf(" *****************************************\n");
}
