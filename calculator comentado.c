//RM96196
//A explicacao de cada etapa sera escrita respetivamente acima.

#include <stdio.h>
#include <stdlib.h>

void	calculator(void);
float	valid_num(void);

int 	main(void)
{
	calculator();
	return (0);
}

//essa funcao possui como acao receber e manipular valores.
void	calculator(void)
{
	//2 vetores para float, para economizar espaco na criacao de variaveis.
	//serao usados para os numeros 1 e 2 nos calculos.
	float	num[2];
	//char utilizado para receber o sinal.
	char	signal;

	printf("Esta calculadora é continua!\nPara fechar, precione CTRL + C\n\n\n");
	printf("Digite o valor inicial\n");
	//variavel num[0] recebe o resultado da funcao valid_num().
	num[0] = valid_num ();
	//while em loop infinito.
	while (1)
	{
		printf("Digite o sinal da operacao\n");
		//pedido de entrada para valor do sinal.
		scanf("%c", &signal);
		//while de getchar para a limpesa do buffer de teclado.
		while ((getchar()) != '\n');
		//estrutura switch para validacao do sinal e continuacao da funcao.
		switch (signal)
	       {
		       //caso o valor de signal seja sinal de negativo.
			case '-':
				{
				printf("Digite o segundo numero\n");
				//variavel num[1] recebe o resultado da funcao valid_num.
				num[1] = valid_num ();
				//valor de num[0] é alterado pelo resultado do calculo.
				num[0] -= num[1];
				//printa o resultado com ate 2 casas decimais.
				printf("Resultado: %0.2f\n\n", num[0]);
				break;
				}
			//caso o valor de signal seja o sinal de positivo.
			case '+':
				{
				printf("Digite o segundo numero\n");
				num[1] = valid_num ();
				num[0] += num[1];
				printf("Resultado: %0.2f\n\n", num[0]);
				break;
				}
			//caso o valor de signal seja o sinal de multiplicacao.
			case '*':
				{
				printf("Digite o segundo numero\n");
				num[1] = valid_num ();
				num[0] *= num[1];
				printf("Rsultado: %0.2f\n\n", num[0]);
				break;
				}
			//caso o valor de signal seja o sinal de divisao.
			case '/':
				{
				printf("Digite o segundo numero\n");
				num[1] = valid_num ();
				//bloqueia o calculo de divisao por 0.
				if (num[1] != 0)
					num[0] /= num[1];
				else
					printf("Nao e possivel dividir por 0\n");
				printf("Resultado: %0.2f\n\n", num[0]);
				break;
				}
			default:
				{
				printf("Sinal invalido\n");
				break;
				}
	       }
	}
	return ;
}

//a ideia dessa funcao e receber e tratar os valores das variaveis num da funcao calculator().
float	valid_num(void)
{
	//variavel str para receber em forma de string ASCII os valores.
	char	str[20];
	//variavel index.
	int	i;

	//pede o valor de 17, ate no maximo 17 caracteres.
	scanf("%[^\n]17s", str);
	while ((getchar()) != '\n');
	//defini o valor de index = 0.
	i = 0;
	//while em loop enquanto o valor de str no vetor [i} nao chegar em nulo.
	while (str[i] != '\0')
	{
		//verifica se o valor de str no vetor [i] e diferente de um numero.
		if (str[i] < '0' || str[i] > '9')
		{
			printf("Digite somente numeros\n");
			//pede novamente o valor de str.
			scanf("%[^\n]17s", str);
			while ((getchar()) != '\n');
			//define o valor de index em -1.
			i = 0;
		}
		else
			//aumenta em 1 o valor de index.
			i++;
	}
	//retorna para a funcao calculator, o valor de str em forma de float.
	return (atof (str));
}
