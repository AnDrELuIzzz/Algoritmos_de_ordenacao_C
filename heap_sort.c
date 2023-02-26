void criaHeap(int *vet, int pai, int fim)
{
  int aux = vet[pai];
  int filho = 2 * pai + 1;
  while (filho <= fim)
  {
    if (filho < fim)
    {
        if(vet[filho] < vet[filho+1]){ //qual o maior dos dois filhos
          filho ++;
        }
    }
    if(aux < vet[filho]){  //filho maior que  o pai?
      vet[pai] = vet[filho]; //filho se torna pai
      pai = filho;
      filho = 2 * pai +1
    }else{
      filho = fim + 1;
    }
  }
  vet[pai] = aux;//antigo pai ocupa lugar do ultimo filho analisado
}

void heapSort(int *vet, int N){
  int i, aux;
  for(i=(N-1)/2; i >= 0; i--){ //Cria a heap a partir dos dados------------Neste caso o I representa o pai
    criaHeap(vet, i, N-1);
  }
  for(i = N-1; i>=1; i--){ // neste caso o i representa o final
    aux = vet[0];
    vet[i]= aux;
    criaHeap(vet, 0, i - 1);//reconstroi a heaps ----- A posição 0 sempre vai ser o pai, ou seja, sempre o maio pela função criarHeap
  }
}
