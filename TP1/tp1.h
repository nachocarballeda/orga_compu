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

#endif /** _TP1_ */
