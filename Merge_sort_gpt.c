#include <stdio.h>
#include <stdlib.h>

void merge(int array[], int leftIndex, int middleIndex, int rightIndex)
{
    int i, j, k;
    int leftSize = middleIndex - leftIndex + 1;
    int rightSize = rightIndex - middleIndex;

    /* Cria arrays temporários */
    int leftArray[leftSize], rightArray[rightSize];

    /* Copia os dados para os arrays temporários leftArray[] e rightArray[] */
    for (i = 0; i < leftSize; i++)
        leftArray[i] = array[leftIndex + i];
    for (j = 0; j < rightSize; j++)
        rightArray[j] = array[middleIndex + 1 + j];

    /* Junta os arrays temporários de volta para o array original */
    i = 0;
    j = 0;
    k = leftIndex;
    while (i < leftSize && j < rightSize) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    /* Copia os elementos restantes de leftArray[] se houver */
    while (i < leftSize) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    /* Copia os elementos restantes de rightArray[] se houver */
    while (j < rightSize) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

/* leftIndex é para o índice esquerdo e rightIndex é para o índice direito do subarray do array que precisa ser ordenado */
void mergeSort(int array[], int leftIndex, int rightIndex)
{
    if (leftIndex < rightIndex) {
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

        /* Divide o array ao meio */
        mergeSort(array, leftIndex, middleIndex);
        mergeSort(array, middleIndex + 1, rightIndex);

        /* Junta as duas metades */
        merge(array, leftIndex, middleIndex, rightIndex);
    }
}

/* Função auxiliar para imprimir o array */
void printArray(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

/* Driver program para testar acima */
int main()
{
    int array[] = { 12, 11, 13, 5, 6, 7 };
    int size = sizeof(array) / sizeof(array[0]);

    printf("Dado array não ordenado: \n");
    printArray(array, size);

    mergeSort(array, 0, size - 1);

    printf("\nArray ordenado pelo Mergesort");
