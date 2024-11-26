/*
В файле .txt записан полный адрес файла (возможно, без расширения).
Необходимо изменить его расширение на ".html" и записать результат в файл
.txt.
Данные на входе: Строка состоящая из символов: a-z, A-Z, 0-9, /
Данные на выходе: Исходная строка с измененным расширением.
*/

#include <stdio.h>
#include <string.h>

void changeExtension(char *line, const char *newExtension)
{
	char *dot = strrchr(line, '.');
	char *slash = strrchr(line, '/');

	if (dot != NULL && slash != NULL)
	{
		int posDot = dot - line + 1;
		int posSlash = slash - line + 1;
		if (posDot > posSlash)
		{
			*dot = '\0';
		}
	}

	strcat(line, newExtension);
}

const int MAX_LINE_SIZE = 10000 + 1;

int main()
{
	char *input_fn = "input.txt";
	char *output_fn = "output.txt";
	char *newExtension = ".html";

	char line[MAX_LINE_SIZE];

	FILE *fi = fopen(input_fn, "r");

	fscanf(fi, "%[^\n]", line);

	fclose(fi);

	FILE *fo = fopen(output_fn, "w");

	changeExtension(line, newExtension);
	fprintf(fo, "%s", line);

	fclose(fo);

	return 0;
}