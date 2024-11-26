/*
В файле .txt необходимо удалить все лишние пробелы (в начале предложения
и сдвоенные пробелы). Для решения задачи разработать функцию. Результат
записать в .txt.
Данные на входе: Строка из английских букв, знаков препинания и
пробелов. Не более 1000 символов.
Данные на выходе: Строка из английских букв, знаков препинания и
пробелов.
*/

#include <stdio.h>
#include <string.h>

void removeSpaces(char *str)
{
	int length = strlen(str);
	int i, j;
	int spaceCount = 0;

	while (str[0] == ' ')
	{
		for (i = 0; i < length; i++)
		{
			str[i] = str[i + 1];
		}
		length--;
	}

	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
		{
			spaceCount++;
		}
		else
		{
			if (spaceCount > 1)
			{
				for (j = i - spaceCount + 1; str[j + spaceCount - 1]; j++)
				{
					str[j] = str[j + spaceCount - 1];
				}
				length -= spaceCount - 1;
			}
			spaceCount = 0;
		}
	}

	while (str[length - 1] == ' ')
	{
		str[length - 1] = '\0';
		length--;
	}
}

const int MAX_LINE_SIZE = 1000 + 1;

int main()
{
	char *input_fn = "input.txt";
	char *output_fn = "output.txt";

	char line[MAX_LINE_SIZE];

	FILE *fi = fopen(input_fn, "r");

	fscanf(fi, "%[^\n]", line);

	fclose(fi);

	FILE *fo = fopen(output_fn, "w");

	removeSpaces(line);
	fprintf(fo, "%s", line);

	fclose(fo);

	return 0;
}