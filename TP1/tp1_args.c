#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "tp1.h"

/* Flag set by `--verbose'. */
static int verbose_flag;

int main (int argc, char *argv[])
{
  FILE *fp;
  char buff[255];
  while (1) {
    static struct option long_options[] =
    {
      /* This option set a flag. */
      {"verbose", no_argument,  &verbose_flag, 1},
      /* These options don't set a flag. We distinguish them by their indices. */
      {"help",  no_argument,  0,  'h'},
      {"version", no_argument,  0,  'V'},
      {"input", required_argument, 0,  'i'},
      {"output",  required_argument,  0,  'o'},
      {0, 0,  0,  0}
    };

    /* getopt_long stores the option index here. */
    int option_index = 0;

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
        fprintf (stderr, "%s", tp1_help);
        break;
      case 'V':
        fprintf (stderr, "tp1.c version is %s\n", tp1_version);
        break;
      case 'i':
        fprintf (stderr, "input '%s'\n", optarg);
        fp = fopen(optarg, "r");
        fgets(buff, 255, (FILE*)fp);
        printf("1 : %s\n", buff );
        break;
      case 'o':
        fprintf (stderr, "output '%s'\n", optarg);
        break;
      case '?':
        /* getopt_long already printed an error message. */
        break;

      default:
        abort ();
    }
  }

  if (verbose_flag) puts ("verbose flag is set");

  /* Print any remaining command line arguments (not options). */
  if (optind < argc) {
    printf ("non-option ARGV-elements: ");
    while (optind < argc)
      printf ("%s ", argv[optind++]);
    putchar ('\n');
  }

  fclose(fp);

  return 0;
}
