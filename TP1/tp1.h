#ifndef _TP1_
#define _TP1_

char tp1_help[] = "Usage:\n\
	tp1 -h\n\
	tp1 -V\n\
	tp1 -i in_file -o out_file\n\
	Options:\n\
		-V, --version	Print version and quit.\n\
		-h, --help	Print this information and quit.\n\
		-i, --input	Specify input stream/file, \"-\" for stdin.\n\
		-o, --output	Specify output stream/file, \"-\" for stdout.\n\
	Examples:\n\
		tp1 < in.txt > out.txt\n\
		cat in.txt | tp1 -i - > out.txt;\n\0";

char tp1_version[] = "0.0.1";

#define FILENAME_MAX_LENGTH	255

/** Simply prints an array of ints for a given length */
void  tp1_print_array(int A[], int size);

/** Performs a merge sort op */
void  tp1_merge_sort(int *vec, size_t len);

/** Writes down the given array into a file */
void  tp1_write_array_in_file(int *num, int size, FILE* file);

/** char array to array of ints */
int tp1_line_to_array(char *line, int *array_num, int len);

#endif /** _TP1_ */
