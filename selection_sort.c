void selectionSort (int *V, int N)
{
  int i ,j, menor, troca;
  for(i = 0; i < N-1; i++)
  {
    menor = i;
    /*Varre a partir do proximo indece referente ao I, e varre até o final no array*/
    for (j = i + 1; j < N; j++)
    {
      if(V[j] < V[menor])
        menor = j;
    }

    if(i != menor)
    {
      troca = V[i];
      v[i] = V[menor];
      V[menor] = troca;
    }

  }
}
