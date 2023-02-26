void merge(int *V, int inicio, int meio, int fim)
{
  int *temp, p1, p2, tamanho, i, j, k;
  int fim1 = 0, fim2 = 0;
  tamanho = fim-inicio+1;
  p1 = inicio;
  p2 = meio + 1;
  temp = (int *) malloc(tamanho *sizeof(int));
  if(temp != NULL)
  {
    for(i = 0;  i< tamnanho; i++)
    {
      if(!fim1 && !fim2)
      {
        /*Este bloco combina ordenando*/
        if(V[p1] < V[p2])
          temp[i] = V[p1++];
        else
          temp[i] = V[p2++];
        /*Verifica se o vetor acabou*/
        if(p1 > meio) fim1 = 1;
        if (p2>fim) fim2 = 1;
      }else{//copia o que sobrar
        if(!fim1)
          temp[i] = V[p1++];
        else
            temp[i] = V [p2++];
      }
    }
    /*Copia do auxiliar para o original*/
    for(j=0, k=inicio; j<tamanho; j++, k++)
      V[k]=temp[j];
  }
  free(temp);
}

void mergeSort(int *V, int inicio, int fim )
{
  int meio;
  if(inicio < fim)
  {
    meio = floor((inicio+fim)/2); //função floor aredonda um numero flutuante para baixo
    mergeSort(V, inicio, meio); //chama a si própria para essa metade
    mergeSort(V, meio+1,fim); //chama a si propria para essa metade
    merge(V, inicio, meio, fim);
  }
}
