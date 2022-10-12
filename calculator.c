#include <stdio.h>
#include <stdlib.h>

void	calculator(void);
float	valid_num(void);

int	main(void)
{
	calculator();
	return (0);
}

void	calculator(void)
{
	float	num[2];
	char	signal;

	printf("Esta calculadora é continua!\nPara fechar, precione CTRL + C\n\n\n");
	printf("Digite o valor inicial\n");
	num[0] = valid_num ();
	while (1)
	{
		printf("Digite o sinal da operacao\n");
		scanf("%c", &signal);
		while ((getchar()) != '\n');
		switch (signal)
		{
			case '-':
				{
				printf("Digite o proximo numero\n");
				num[1] = valid_num ();
				num[0] -= num[1];
				printf("Resultado: %0.2f\n\n", num[0]);
				break;
				}
			case '+':
				{
				printf("Digite o proximo numero\n");
				num[1] = valid_num ();
				num[0] += num[1];
				printf("Resultado: %0.2f\n\n", num[0]);
				break;
				}
			case '*':
				{
				printf("Digite o proximo numero\n");
				num[1] = valid_num ();
				num[0] *= num[1];
				printf("Rsultado: %0.2f\n\n", num[0]);
				break;
				}
			case '/':
				{
				printf("Digite o proximo numero\n");
				num[1] = valid_num ();
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

float	valid_num(void)
{
	char	str[20];
	int	i;

	scanf("%[^\n]17s", str);
	while ((getchar()) != '\n');
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
		{
			printf("Digite somente numeros\n");
			scanf("%[^\n]17s", str);
			while ((getchar()) != '\n');
			i = 0;
		}
		else
			i++;
	}
	return (atof (str));
}
