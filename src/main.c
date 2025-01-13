#include <stdio.h>
#include <string.h>
#include "encryption.h"

void process_files(const char *input_file, const char *output_file, int encrypt);

int main(int argc, char *argv[]) {
    if (argc != 6) {
        fprintf(stderr, "Usage: %s --encrypt|--decrypt -i input_file -o output_file\n", argv[0]);
        return 1;
    }

    const char *input_file = NULL;
    const char *output_file = NULL;
    int encrypt = -1;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--encrypt") == 0) {
            encrypt = 1;
        } else if (strcmp(argv[i], "--decrypt") == 0) {
            encrypt = 0;
        } else if (strcmp(argv[i], "-i") == 0) {
            input_file = argv[++i];
        } else if (strcmp(argv[i], "-o") == 0) {
            output_file = argv[++i];
        }
    }

    if (input_file == NULL || output_file == NULL || encrypt == -1) {
        fprintf(stderr, "Usage: %s --encrypt|--decrypt -i input_file -o output_file\n", argv[0]);
        return 1;
    }

    process_files(input_file, output_file, encrypt);

    return 0;
}

void process_files(const char *input_file, const char *output_file, int encrypt) {

    // build/example.txt
    FILE *infile = fopen(input_file, "rb");
    if (infile == NULL) {
        fprintf(stderr, "Error opening input file.\n");
        return;
    }

    fseek(infile, 0, SEEK_END);
    int length = ftell(infile);
    fseek(infile, 0, SEEK_SET);

    if (encrypt) {
        encryptfirst(infile, length,output_file);
    } else {
        decryptfirst(infile, length,output_file);
    }

    fclose(infile);
}