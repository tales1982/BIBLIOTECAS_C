#include <fcntl.h>  // Para open()
#include <stdio.h>  // Para printf()
#include <unistd.h> // Para read(), close()

int	main(void)
{
	int fd;         // vai receber o endereco do arquivo.
	char buf[10];   // vai armezena o valor do texto a cada passage.
	size_t n_bytes; // o numero de caracteres lido;

	// o fd vai receber o endereco e oque devo executa,O_RDONLY (somente leitura).
		
	fd = open("/home/tlima-de/Documents/get_next_line/teste", O_RDONLY);
	// se o retorno de fd for -1 algo deu errado.
	if (fd == -1)
		printf("Erro ao ler o arquivo\n");
	else
		// se tido estiver ok vai executar o read
		// vou salvar o retorno do read em n_bytes para ver quantos caracter foran lidos
		n_bytes = read(fd, buf, 5);
	// depois de executar o read tenho que fechar.
	close(fd);
	// agora vou testa para ver se meu arquivo tem alguma coisa dentro dele
	if (n_bytes == 0)
    {
        printf("O arquivo esta vazio\n");
    }
	else
	{
		buf[n_bytes] = '\0'; // Garante que a string é terminada corretamente
		// vou imprimir a contidade de bites imprimido e o buf q e o texto que vou imprimir
		// lembrando que tenho que fazer um cast de size_t pra int para imprimir.
		printf("Tamanho de n_bytes..: %d\n Valor do Buf..: %s\n", (int)n_bytes,
			buf);
	}

	return (0);
}