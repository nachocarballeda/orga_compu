#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <ctype.h>
#include "tp1.h"

static int input_flag = 0, output_flag = 0;

int main (int argc, char *argv[])
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

  while (1) {
    static struct option long_options[] =
    {
      {"help",  no_argument,  0,  'h'},
      {"version", no_argument,  0,  'V'},
      {"input", required_argument, 0,  'i'},
      {"output",  required_argument,  0,  'o'},
      {0, 0,  0,  0}
    };

    int c = getopt_long (argc, argv, "hV:i:o:",long_options, &option_index);

    /* Detect the end of the options. */
    if (c == -1) break;

    switch (c)
    {
      case 0:
        /* If this option set a flag, do nothing else now. */
        if (long_options[option_index].flag != 0)
          break;
        printf ("option %s", long_options[option_index].name);
        if (optarg)
          printf (" with arg %s\n", optarg);
        break;
      case 'h':
        fprintf (stdout, "%s", tp1_help);
        break;
      case 'V':
        fprintf (stdout, "tp1.c version is %s\n", tp1_version);
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
        abort ();
    }
  }

  if(!input_flag || !output_flag) {
    fprintf (stdout, "Please insert %s%s%s file%s, use -h or --help to see the help menu.\n",
            !input_flag?"input":"",(!input_flag && !output_flag)?" & ":"",!output_flag?"output":"",
            (!input_flag && !output_flag)?"s":"");
    return 1;
  }

  /* Print any remaining command line arguments (not options). */
  if (optind < argc) {
    printf ("non-option ARGV-elements: ");
    while (optind < argc)
      printf ("%s ", argv[optind++]);
    putchar ('\n');
  }

  f_in = fopen(filename_in, "r");
  f_out = fopen(filename_out, "w");

  if(f_in==NULL) {
    fprintf(stderr, "Input file '%s' does not exist.\n", filename_in);
    return 1;
  }

  ssize_t read;
  char * line = NULL;
  size_t len = 0;
  int amount = 0;


  while ((read = getline(&line, &len, f_in)) != -1) {
    array_num = (int*) malloc((read/sizeof(char)/2)*sizeof(int));
    amount = tp1_line_to_array(line, array_num, read/sizeof(char));
    tp1_merge_sort(array_num, amount);
    tp1_write_array_in_file(array_num, amount, f_out);
  }

  free(array_num);

  fclose(f_in);
  fclose(f_out);
  return 0;
}

void tp1_write_array_in_file(int *num, int size, FILE* file)
{
  int i = 0;
  for (; i < size; i++) {
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

void tp1_merge_sort(int *vec, size_t len)
{
    if (len > 1)
    {
        int mid = len / 2;
        int *left = (int *)malloc(mid * sizeof(int));
        int *right = (int *)malloc((len - mid) * sizeof(int));
        for (int i = 0; i < mid; i++)
            left[i] = vec[i];
        for (int i = mid; i < len; i++)
            right[i - mid] = vec[i];
        tp1_merge_sort(left, mid);
        tp1_merge_sort(right, len - mid);
        int i, j, k;
        i = 0;
        j = 0;
        k = 0;
        while (i < mid && j < len - mid)
        {
            if (left[i] < right[j])
                vec[k++] = left[i++];
            else
                vec[k++] = right[j++];
        }
        while (i < mid)
            vec[k++] = left[i++];
        while (j < len - mid)
            vec[k++] = right[j++];
        free(left);
        free(right);
    }
}

int numDigits(int n) {
  if (n < 0)
    return 1 + numDigits(abs(n));
  if (n < 10) return 1;
    return 1 + numDigits(n / 10);
}

int tp1_line_to_array(char *line, int *array_num, int len)
{
  int i = 0, j = 0, digits=0;
  while(i <= len) {
    while(*line==' ') {
      ++i;
      line++;
    }
    array_num[j] = atoi(line);
    digits = numDigits(array_num[j]);
    i = digits + i;
    line = line + digits;
    if(i>=len) break;
    j++;
  }
  return j;
}
