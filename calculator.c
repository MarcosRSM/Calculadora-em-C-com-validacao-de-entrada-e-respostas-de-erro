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
				printf("Digite o segundo numero\n");
				num[1] = valid_num ();
				num[0] -= num[1];
				printf("Resultado: %0.2f\n\n", num[0]);
				break;
				}
			case '+':
				{
				printf("Digite o segundo numero\n");
				num[1] = valid_num ();
				num[0] += num[1];
				printf("Resultado: %0.2f\n\n", num[0]);
				break;
				}
			case '*':
				{
				printf("Digite o segundo numero\n");
				num[1] = valid_num ();
				num[0] *= num[1];
				printf("Rsultado: %0.2f\n\n", num[0]);
				break;
				}
			case '/':
				{
				printf("Digite o segundo numero\n");
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
	char	str[17];
	char	*ptr;
	int	i;

	scanf("%17s", str);
	while ((getchar()) != '\n');
	ptr = str;
	i = 0;
	while (ptr[i] != '\0')
	{
		if (ptr[i] < '0' || ptr[i] > '9')
		{
			printf("Digite somente numeros\n");
			scanf("%17s", str);
			while ((getchar()) != '\n');
			i = -1;
		}
		i++;
	}
	return (atof (str));
}