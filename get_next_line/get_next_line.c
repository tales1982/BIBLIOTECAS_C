#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*aux;
	char		line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(aux);
		free(buffer);
		aux = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = read_line(fd, aux, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	aux = count_line(line);
	return (line);
}

/*
1°
	* Verificações iniciais: Antes de tentar ler qualquer coisa,
	* o código verifica se o descritor de arquivo é válido (fd < 0),
	* se o BUFFER_SIZE é um valor lógico positivo (BUFFER_SIZE <= 0),
	* e se é possível ler do arquivo (verificado por read(fd, 0,
	* 0) < 0). Se qualquer uma dessas condições falhar,
	* a função libera quaisquer recursos já alocados (aux e buffer) e retorna NULL,
	* indicando falha ou a impossibilidade de leitura.
/*
2°
	* Leitura da linha: A função read_line é chamada para ler dados do arquivo ou
	* fluxo até encontrar uma nova linha ou o fim do arquivo.
	* Essa função provavelmente manipula o buffer e o conteúdo "deixado" (aux)
	* para acumular a linha completa, considerando leituras anteriores.
*/
/*
3°
	* Liberação de recursos desnecessários: Após a leitura da linha,
	* o buffer temporário, que foi usado para a leitura do arquivo,
	* não é mais necessário e, portanto,
	* é liberado para evitar vazamento de memória.
*/
/*
4°
	* Processamento final da linha: A função set_line parece ajustar a linha lida,
	* possivelmente tratando caracteres de nova linha,
	* terminações de string ou preparando o left_c para a próxima chamada a get_next_line.
	* Esta etapa garante que a string retornada está em um formato adequado para o chamador.
*/
/*
5°
    * Retorno da linha: Finalmente,
	* a função retorna line ao chamador. Esta linha é o resultado direto da leitura e 
    * processamento feitos pelas funções auxiliares e contém a sequência de caracteres até 
    * a próxima nova linha (ou o final do arquivo). Retornar esta string é essencial,
	* pois é o resultado esperado pelo chamador,
	* permitindo-lhe processar o conteúdo linha por linha.
*/