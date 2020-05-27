#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <ctype.h>
#include "tp1.h"

static int input_flag = 0, output_flag = 0;

int main(int argc, char *argv[])
{
  FILE *f_in;
  FILE *f_out;

  /* Filenames are stored here.*/
  char filename_in[FILENAME_MAX_LENGTH];
  char filename_out[FILENAME_MAX_LENGTH];
  /* getopt_long stores the option index here. */
  int option_index = 0;
  /* Some Aux vars */
  int *array_num;

  while (1)
  {
    static struct option long_options[] =
        {
            {"help", no_argument, 0, 'h'},
            {"version", no_argument, 0, 'V'},
            {"input", required_argument, 0, 'i'},
            {"output", required_argument, 0, 'o'},
            {0, 0, 0, 0}};

    int c = getopt_long(argc, argv, "hV:i:o:", long_options, &option_index);

    /* Detect the end of the options. */
    if (c == -1)
      break;

    switch (c)
    {
    case 0:
      /* If this option set a flag, do nothing else now. */
      if (long_options[option_index].flag != 0)
        break;
      printf("option %s", long_options[option_index].name);
      if (optarg)
        printf(" with arg %s\n", optarg);
      break;
    case 'h':
      fprintf(stdout, "%s", tp1_help);
      break;
    case 'V':
      fprintf(stdout, "tp1.c version is %s\n", tp1_version);
      break;
    case 'i':
      input_flag = 1;
      strncpy(filename_in, optarg, FILENAME_MAX_LENGTH);
      break;
    case 'o':
      output_flag = 1;
      strncpy(filename_out, optarg, FILENAME_MAX_LENGTH);
      break;
    case '?':
      /* getopt_long already printed an error message. */
      break;
    default:
      abort();
    }
  }

  if (input_flag)
    f_in = fopen(filename_in, "r");
  else
    f_in = stdin;

  if (output_flag)
    f_out = fopen(filename_out, "w");
  else
    f_out = stdout;

  if (input_flag && f_in == NULL)
  {
    fprintf(stderr, "Input file '%s' does not exist.\n", filename_in);
    return 1;
  }

  if (output_flag && f_out == NULL)
  {
    fprintf(stderr, "Output file '%s' does not exist.\n", filename_out);
    return 1;
  }

  ssize_t read;
  char *line = NULL;
  size_t len = 0;
  int amount = 0;

  while ((read = getline(&line, &len, f_in)) != -1)
  {
    array_num = (int *)malloc((read / sizeof(char) / 2) * sizeof(int));
    amount = tp1_line_to_array(line, array_num, read / sizeof(char));
    if (amount != -1)
    {
      merge_sort(array_num, amount);
      tp1_write_array_in_file(array_num, amount, f_out);
    }
    else
    {
      fprintf(stderr, "There are errors in the input, cant ensure a valid output\n");
    }
  }

  free(array_num);

  fclose(f_in);
  fclose(f_out);
  return 0;
}

void tp1_write_array_in_file(int *num, int size, FILE *file)
{
  int i = 0;
  for (; i < size; i++)
  {
    fprintf(file, "%d", num[i]);
    fputc(' ', file);
  }
  fputc('\n', file);
}

void tp1_print_array(int A[], int size)
{
  int i;
  printf(">> ");
  for (i = 0; i < size; i++)
    printf("%d ", A[i]);
  printf("\n");
}

int numDigits(int n)
{
  if (n < 0)
    return 1 + numDigits(abs(n));
  if (n < 10)
    return 1;
  return 1 + numDigits(n / 10);
}

int tp1_line_to_array(char *line, int *array_num, int len)
{
  int i = 0, j = 0, digits = 0;
  while (i <= len)
  {
    while (*line == ' ')
    {
      ++i;
      line++;
    }
    int aux = atoi(line);
    digits = numDigits(aux);
    char *word = malloc(digits * sizeof(char));
    for (int m = 0; m < digits; m++)
    {
      word[m] = line[m];
    }
    if (aux == 0 && word[0] != '0' && word[0] != '\n')
      return -1;
    array_num[j] = aux;
    i = digits + i;
    line = line + digits;
    if (i >= len)
      break;
    j++;
  }
  return j;
}
