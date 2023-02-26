/*A escolha do pivo influencia no desempenho do pivo*/
int particiona(int *V, int inicio, int final)
{
  int esq, dir, pivo, aux;
  esq = inicio;
  dir = final;
  pivo = V[inicio];
  while(esq < dir)
  {
    while (V[esq] <= pivo)// avança posição da esquerda
      esq ++;
    while(V[dir] > pivo) //Recua posição da direita
      dir--;

    /*Troca esquerda e diretia*/
    if(esq < dir)
    {
      aux =  V[esq];
      V[esq]= V[dir];
      V[dir] = aux;
    }
  }
  V[inicio] = V[dir];
  V[dir] = pivo ;

  return dir;
}

void quicksort(int *V, int inicio, int fim)
{
  int pivo;
  if(fim>inicio)
  {
    pivo = particiona(V  , inicio, fim);
    /*Chama a função para as duas metades*/
    quicksort(V, inicio, pivo-1);
    quicksort(V, pivo+1, fim);
  }
}
