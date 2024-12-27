#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TEXT_RECORD_LENGTH 30

int main() 
{
    char label[10], opcode[10], operand[10], symbol[10], code[10], mnemonic[10];
    int locctr, start, length, address;
    int text_start, text_length;
    FILE *fp1, *fp2, *fp3, *fp4, *fp5;
    
    fp1 = fopen("out.txt", "r");
    fp2 = fopen("optab.txt", "r");
    fp3 = fopen("symtbl.txt", "r");
    fp4 = fopen("output2.txt", "w");
    fp5 = fopen("length.txt", "r");
    
    fscanf(fp5, "%d", &length);
    fclose(fp5);
    
    fscanf(fp1, "%s %s %s", label, opcode, operand);
    if(strcmp(opcode, "START") == 0) {
        start = (int)strtol(operand, NULL, 16);
        locctr = start;
        fprintf(fp4, "H^%-6s^%06X^%06X\n", label, start, length);
        fscanf(fp1, "%s %s %s", label, opcode, operand);
    }
    
    text_start = locctr;
    text_length = 0;
    fprintf(fp4, "T^%06X^", text_start);
    
    while(strcmp(opcode, "END") != 0) {
        if(strcmp(opcode, "RESW") == 0 || strcmp(opcode, "RESB") == 0) {
            if(text_length > 0) {
                fseek(fp4, -(text_length*2+1), SEEK_CUR);
                fprintf(fp4, "%02X", text_length);
                fseek(fp4, text_length*2, SEEK_CUR);
                fprintf(fp4, "\nT^%06X^", locctr);
                text_start = locctr;
                text_length = 0;
            }
            if(strcmp(opcode, "RESW") == 0)
                locctr += 3 * atoi(operand);
            else
                locctr += atoi(operand);
        } else {
            if(text_length >= MAX_TEXT_RECORD_LENGTH) {
                fseek(fp4, -(text_length*2+1), SEEK_CUR);
                fprintf(fp4, "%02X", text_length);
                fseek(fp4, text_length*2, SEEK_CUR);
                fprintf(fp4, "\nT^%06X^", locctr);
                text_start = locctr;
                text_length = 0;
            }
            
            if(strcmp(opcode, "BYTE") == 0) {
                if(operand[0] == 'C') {
                    for(int i = 2; operand[i] != '\''; i++) {
                        fprintf(fp4, "%02X", operand[i]);
                        text_length += 1;
                    }
                } else if(operand[0] == 'X') {
                    for(int i = 2; operand[i] != '\''; i += 2) {
                        char hex[3] = {operand[i], operand[i+1], '\0'};
                        fprintf(fp4, "%s", hex);
                        text_length += 1;
                    }
                }
                locctr += strlen(operand) - 3;
            } else if(strcmp(opcode, "WORD") == 0) {
                fprintf(fp4, "%06X", atoi(operand));
                text_length += 3;
                locctr += 3;
            } else {
                rewind(fp2);
                fscanf(fp2, "%s %s", code, mnemonic);
                while(strcmp(code, "END") != 0) {
                    if(strcmp(opcode, code) == 0) {
                        rewind(fp3);
                        fscanf(fp3, "%s %d", symbol, &address);
                        while(strcmp(symbol, operand) != 0 && !feof(fp3)) {
                            fscanf(fp3, "%s %d", symbol, &address);
                        }
                        if(!feof(fp3)) {
                            fprintf(fp4, "%s%04X", mnemonic, address);
                        } else {
                            fprintf(fp4, "%s0000", mnemonic); // Assuming direct addressing if symbol not found
                        }
                        text_length += 3;
                        locctr += 3;
                        break;
                    }
                    fscanf(fp2, "%s %s", code, mnemonic);
                }
            }
        }
        fscanf(fp1, "%s %s %s", label, opcode, operand);
    }
    
    if(text_length > 0) {
        fseek(fp4, -(text_length*2+1), SEEK_CUR);
        fprintf(fp4, "%02X", text_length);
        fseek(fp4, text_length*2, SEEK_CUR);
    }
    
    fprintf(fp4, "\nE^%06X\n", start);
    
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    
    return 0;
}
