void bubbleSort(int *V, int N)
{
  int i, continua, aux, fim = N;
  do
  {
    continua = 0;
    for (i = 0 ; i< fim-1; i++)
    {
      if (V[i] > V[i+1])
      {
        aux = V[I];
        V[i] = V[i+1];
        V[i + 1] = aux;
        continua = i;
      }

    }

  fim--;
  }while(continua != 0);

  /*
    do-while termina se avariavel CONTINUA for diferente de zero.Isso é feito para otimizar o algoritmo.
    Desse modo, se nenhuma troca ocorrer, o algoritmo será finalizado mais cedo
  */
}
