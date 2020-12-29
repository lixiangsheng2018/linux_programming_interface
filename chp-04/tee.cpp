#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <ctype.h>

static int append_mode = 0;

int parse_args(int argc, char *argv[])
{
	char c;
	while ((c = getopt(argc, argv, "a")) != -1) {
		switch (c) {
		case 'a':
			append_mode = 1;
			break;
		case '?':
			if (isprint(optopt))
				fprintf(stderr, "Unkonw option `-%c'.\n", optopt);
			else
				fprintf(stderr,
					"Unknown option character `\\x%x'.\n", optopt);
			return 1;
		default:
			abort();
			break;
		}
	}
	return 0;
}

int main(int argc, char *argv[])
{
	char buf[100];
	size_t len;
    int i;
	FILE *files[20];
	int num_files;

	if (parse_args(argc, argv)) {
		return 1;
	}

	const char* file_mode = append_mode ? "a" : "w";

	num_files = argc - optind;
	if (num_files > 0) {
		if (files == NULL) {
			fprintf(stderr, "Unable to allocate file buffer space\n");
			return 1;
		}

		/* go through file arguments and either open for writing
		   or append based on the -a flag */
		for (i = optind; i < argc; i++) {
			FILE *pFile = fopen(argv[i], file_mode);
			if (pFile == NULL)
			{
				fprintf(stderr, "Unable to open file %s for mode %s",
					argv[i], file_mode);
				if (num_files > 0) {
					for (i = 0; i < num_files; i++) {
						fclose(files[i]);
					}
				}
				return 0;
			}
			files[i - optind] = pFile; /* mind the offset */
		}
	}

	FILE *not_stdin = fopen("tee.cpp", "r");
	while ((len = fread(&buf[0], 1, sizeof(buf), not_stdin)) > 0) {
		fwrite(&buf[0], 1, len, stdout);
		for (i = 0; i < num_files; i++) {
			fwrite(&buf[0], 1, len, files[i]);
		}
	}

	if (num_files > 0) {
		for (i = 0; i < num_files; i++) {
				fclose(files[i]);
		}
	}


	return 0;
}
