#include <stdio.h>

void mostrarDatos(int *data, int len );
void bubbleSort(int *data, int len, int asc );

int main() 
{
    int inputs[]= {15, 35, -8, 7, 7};
    int inputLen = sizeof(inputs) / sizeof(inputs[0]);

    mostrarDatos(inputs, inputLen);
    bubbleSort(inputs, inputLen, 0);
    mostrarDatos(inputs, inputLen);
    return 0;
}

void bubbleSort(int *data, int len, int asc )
{
    int nCount, mCount;
    int aux;

    for(nCount = 0 ; nCount < len; nCount++) {

        for(mCount = 0 ; mCount < len-nCount-1; mCount++) {

            if(asc){
                if(data[mCount] > data[mCount+1]){
                    aux = data[mCount];
                    data[mCount] = data[mCount+1];
                    data[mCount+1]= aux;
                }
            }
            else{
                if(data[mCount] < data[mCount+1]){
                    aux = data[mCount];
                    data[mCount] = data[mCount+1];
                    data[mCount+1]= aux;
                }
            }
        }
    }
    return;
}

void mostrarDatos(int *data, int len )
{
    int counter;
    for(counter = 0; counter < len; counter++) {
        printf("%d ", data[counter]);
    }
    printf("\n");
}