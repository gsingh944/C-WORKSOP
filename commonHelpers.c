// ===================================================================================
//  Assignment: 2 
//  Milestone : 4
// ===================================================================================
//  Student Name  : Gurpinder Singh
//  Student ID    : 140515206
//  Student Email : gsingh944@myseneca.ca
//  Course Section: ZEE
// ===================================================================================


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i;
int j;
int p = 0;

void clear(void)
{
    while (getchar() != '\n')
        ;  // empty statement intentional 
}
void clearStandardInputBuffer(void) {
    while (getchar() != '\n') {
        ; // On purpose: do nothing}}
    }
    return;
}
int getInteger(void) {
    int faa;
    char fab;
    int fac;
    int fad = 1;



    do {

        fac = scanf("%d%c", &faa, &fab);
        if (fac == 0) {
            printf("ERROR: Value must be an integer: ");
            clear();
        }
        else if (fab == ' ') {
            printf("ERROR: Value must be an integer: ");
            clear();
        }
        else
            fad = 0;
    } while (fad == 1);

    return faa;

}

int getPositiveInteger(void) {
    int fba;

    int fbc;
    int fbd = 1;



    do {

        fbc = scanf("%d", &fba);
        //printf("fba=%d\n", fba);
        //printf("fbc=%d\n", fbc);

        if (fbc == 0) {
            printf("ERROR: Value must be an integer: ");
            //printf("fbc=%d", fbc);
            clear();

        }
        else if (fba < 0) {
            printf("ERROR: Value must be a positive integer greater than zero: ");
            //printf("fbc=%d", fbc);
            clear();

        }
        else {
            fbd = 0;
            //printf("fbc=%d", fbc);
        }
        fbc = 0;

    } while (fbd == 1);

    return fba;

}

int getPositiveorZeroInteger(void) {
    int fba;

    int fbc;
    int fbd = 1;



    do {

        fbc = scanf("%d", &fba);

        if (fbc == 0) {
            printf("ERROR: Value must be an integer: ");
            //printf("fbc=%d", fbc);
            clear();

        }
        else if (fba < 0) {
            printf("ERROR: Value must be positive or zero: ");
            //printf("fbc=%d", fbc);
            clear();

        }
        else {
            fbd = 0;
            //printf("fbc=%d", fbc);
        }
        fbc = 0;

    } while (fbd == 1);

    return fba;

}



int getIntFromRange(int fdx, int fdy) {
    int fda;

    int fdc;
    int fdd = 1;



    do {

        fdc = scanf("%d", &fda);
        if (fdc == 0) {
            printf("ERROR: Value must be an integer: ");
            clear();
        }
        else if ((fda < fdx) || (fda > fdy)) {
            printf("ERROR: Value must be between %d and %d inclusive: ", fdx, fdy);
            //printf("fbc=%d", fbc);
            clear();

        }
        else
            fdd = 0;
    } while (fdd == 1);

    return fda;

}

double getDouble(void) {
    int fea = 0;

    char fec[20];
    double fed = 1;
    double fee;
    int fef;



    do {
        fea = 0;
        scanf(" %[^\n]", fec);
        fef = strlen(fec);
        for (i = 0; i < fef; i++) {
            if ((fec[i] != '1') && (fec[i] != '2') && (fec[i] != '3') && (fec[i] != '4') && (fec[i] != '5') && (fec[i] != '6') && (fec[i] != '7') && (fec[i] != '8') && (fec[i] != '9') && (fec[i] != '0') && (fec[i] != ' ') && (fec[i] != '.') && (fec[i] != '-')) {
                fea += 1;

            }
        }
        fee = atof(fec);




        if (fea != 0) {


            printf("ERROR: Value must be a double floating-point number: ");
            clear();

        }
        else
            fed = 0;

    } while (fed == 1);

    return fee;

}

double getPositiveDouble(void) {
    int fea = 0;
    int feb = 0;
    char fec[20];
    double fed = 1;
    double fee;
    int fef;



    do {
        fea = 0;
        scanf(" %[^\n]", fec);
        fef = strlen(fec);
        for (i = 0; i < fef; i++) {
            if ((fec[i] != '1') && (fec[i] != '2') && (fec[i] != '3') && (fec[i] != '4') && (fec[i] != '5') && (fec[i] != '6') && (fec[i] != '7') && (fec[i] != '8') && (fec[i] != '9') && (fec[i] != '0') && (fec[i] != ' ') && (fec[i] != '.') && (fec[i] != '-')) {
                fea += 1;

            }
        }
        fee = atof(fec);
        if (fee <= 0) {
            feb += 1;
        }



        if ((fea == 0) && (fee <= 0)) {

            printf("ERROR: Value must be a positive double floating-point number: ");
            clear();
        }
        else if (fea != 0) {
            printf("ERROR: Value must be a double floating-point number: ");
            clear();

        }
        else
            fed = 0;

    } while (fed == 1);

    return fee;

}

char getCharOption(char fgg[7]) {
    char fga[7];


    int fgd = 1;
    int fge = 0;
    char fgh;
    i = 0;
    int len;
    len = strlen(fgg);


    do {

        scanf(" %s", fga);

        for (i = 0; i < len; i++) {
            for (j = 0; j < len; j++) {
                /*printf("fga[%d]=%c", i, fga[i]);

                printf("\nfgg[%d]=%c", j, fgg[j]);
                printf("\n fge=%d", fge);*/
                if (fga[i] == fgg[j]) {
                    fge += 1;
                    fgh = fga[i];
                    //printf("*");
                }
            }
        }
        if (fga[1] != '\0') {
            //printf("fga[1]=%c", fga[1]);
            fge = 0;
        }
        if (fge == 0) {
            printf("ERROR: Character must be one of [%s]: ", fgg);
            clear();
        }


        else
            fgd = 0;
    } while (fgd == 1);

    return fgh;



}

void getCString(char fhx[], int fhy, int fhz) {


    int fhc = 0;
    int fhd = 1;

    char value[150];

    i = 0;
    clear();

    do {

        scanf("%[^\n]", value);

        fhc = strlen(value);

        if (fhy != fhz) {
            if (fhc > fhz) {
                printf("ERROR: String length must be no more than %d chars: ", fhz);
                clear();
            }
            else if (fhc < fhy) {
                printf("ERROR: String length must be between %d and %d chars: ", fhy, fhz);
                clear();
            }
            else {
                fhd = 0;
            }
        }
        else {
            if (fhc != fhy) {
                printf("ERROR: String length must be exactly %d chars: ", fhy);
                clear();
            }
            else {
                fhd = 0;
            }
        }
    } while (fhd == 1);

    for (i = 0; i < (fhz + 1); i++) {
        fhx[i] = value[i];
    }
    return;
}








