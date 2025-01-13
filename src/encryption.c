#include <stdio.h>
#include <string.h>
#include "encryption.h"

FILE* encryptfirst(FILE *input, int length,const char *output_file) {
    // Create temp file
    FILE *tempfile = fopen(output_file, "w");

    if (tempfile == NULL) {
        printf("tempfile is null on encryptfirst\n");
        return NULL;
    }else{
        printf("Encrypting... to %s\n",output_file);
    }

    unsigned char buffer;
    for (int i = 0; i < length; i++) {
        // Read a byte from the input file
        fread(&buffer, sizeof(unsigned char), 1, input);

        // Shift the byte by (i * 2)
        buffer = (buffer + (i * 5)) & 0xFF; // Ensures the byte wraps around at 0xFF

        // Write the shifted byte to the temporary file
        // printf(buffer);
        fwrite(&buffer, sizeof(unsigned char), 1, tempfile);
    }

    // Close the tempfile
    fclose(tempfile);

    return tempfile;
}

FILE* decryptfirst(FILE *input, int length,const char *output_file) {
    
    // Create temp file for decrypted data
    FILE *tempfile = fopen(output_file, "w");

    if (tempfile == NULL) {
        printf("tempfile is null on decryptfirst\n");
        return NULL;
    }else
    {
                printf("Decrypting.. to %s\n",output_file);

    }
    

    unsigned char buffer;
    for (int i = 0; i < length; i++) {
        // Read a byte from the input file
        fread(&buffer, sizeof(unsigned char), 1, input);

        // Shift the byte back by -(i * 2)
        buffer = (buffer - (i * 5)) & 0xFF;  // Ensure the byte wraps around at 0x00

        // Write the decrypted byte to the temporary file
        // printf(buffer);
        fwrite(&buffer, sizeof(unsigned char), 1, tempfile);
    }

    // Close the temporary file
    fclose(tempfile);

    return tempfile;
}