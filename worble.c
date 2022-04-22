#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_VAL 16900
#define MAX_LEN 12950

int generator();
int checker();
int indexOf(const int elm, const int *array, int count);

struct poss {
    char wow[6];
};

struct vaild {
    char word[6];
};

struct poss meow[MAX_LEN];
struct vaild clack[MAX_VAL];
int g = 0;

int main() {
    int b = 0;
    b = generator();
    if (b == -1) {
        return 1;
    }

    checker();
}

int generator() {
    int gg = 0;
    int bb = 0;
    int cc = 0;
    /* char unknown[26] = {0};
    printf("What letters are unknown? (as in untested or tested but wrong place grey/yellow): ");
    fgets(unknown, 26, stdin);
    int len3 = strlen(unknown);
    unknown[len3] = '\0';

    char known[6] = {0};
    int stablePos[5] = {0};
    printf("What letters are known? (mark unknown values with a '.'): ");
    fgets(known, 6, stdin);
    int len4 = strlen(known);
    known[len4] = '\0'; */

    // ONLY WORKS TESTED WITH GCC ON WINDOWS
    // CHANGE THESE AND RECOMPILE TO USE
    char known[6] = "mo...\0";
    int stablePos[5];
    int len4 = strlen(known);
    char unknown[26] = "rotqwyjzxv\0";
    int len3 = strlen(unknown);


    if (strlen(known) == 0) {
        printf("You have not entered any letters.\n");
        return -1;
    }

    printf("\nLet me get to work then! (output will be in answers.txt)\n");

    for (int op = 0; op < len4; op++) {
        if (known[op] == '.') {
            stablePos[op] = 0;
        }
        else {
            stablePos[op] = 1;
        }
    }

    char prol[6] = {0};
    memcpy(prol, known, 6);

    FILE *worbler = fopen("worbler.txt", "w");

    if (worbler == NULL) {
        printf("Could not open worbler.txt\n");
        return -1;
    }

    int plen = sizeof(stablePos)/sizeof(stablePos[0]);

    //for (int u = 0; u < len4; u++) {
        int o = indexOf(0, stablePos, plen);
        for (int y = 0; y <= (len3); y++) {
            prol[o] = unknown[y];
            stablePos[o] = 1;
            gg = indexOf(0, stablePos, plen);
            if (gg == -1) {
                fprintf(worbler, "%s\n", prol); g++;
                if (y == strlen(unknown) - 1){
                    break;
                }
            }
            else {
                for (int r = 0; r < (len3); r++) {
                    prol[gg] = unknown[r];
                    stablePos[gg] = 1;
                    bb = indexOf(0, stablePos, plen);
                    if (bb == -1) {
                        fprintf(worbler, "%s\n", prol); g++;
                    }
                    else {
                        for (int e = 0; e < (len3); e++) {
                            prol[bb] = unknown[e];
                            stablePos[bb] = 1;
                            cc = indexOf(0, stablePos, plen);
                            if (cc == -1) {
                                fprintf(worbler, "%s\n", prol); g++;
                            }
                            else {
                                for (int t = 0; t < (len3); t++) {
                                    prol[cc] = unknown[t];
                                    stablePos[cc] = 1;
                                    fprintf(worbler, "%s\n", prol); g++;
                                }
                            }
                            stablePos[cc] = 0;
                        }
                        stablePos[bb] = 0;
                    }
                }
                stablePos[gg] = 0;
            }
        }
    //}

    fclose(worbler);
    return 0;
}

int checker() {
    char lineContainer[MAX_VAL] = {0};
    FILE *import = fopen("worbler.txt", "r");
    if (import == NULL) {
        printf("your file is broken idiot\n");
        return 1;
    }

    for (int i = 0; i < g; i++) {
        fgets(lineContainer, MAX_VAL, import);
        sscanf(lineContainer, "%s", &clack[i].word);
    }

    fclose(import);

    FILE *possible = fopen("possible.txt", "r");
    char lineBox[MAX_VAL] = {0};
    if (possible == NULL) {
        printf("you expect me to be able to do my job without a dictionary?\n");
        return 1;
    }

    for (int j = 0; j < MAX_LEN; j++) {
        fgets(lineBox, MAX_LEN, possible);
        sscanf(lineBox, "%s", &meow[j].wow);
    }

    fclose(possible);

    FILE *export = fopen("answers.txt", "w");
    if (import == NULL) {
        printf("read only???\n");
        return 1;
    }

    for (int k = 0; k < g; k++) {
        for (int l = 0; l < MAX_LEN; l++) {
            if (strcmp(clack[k].word, meow[l].wow) == 0) {
                fprintf(export, "%s\n", meow[l].wow);
            }
        }
    }

    fclose(export);
    return 0;
}

int indexOf(const int elm, const int *array, int count)
{
    while (count--)
    {
        if (array[count] == elm)
            return count;
    }
    return -1;
}