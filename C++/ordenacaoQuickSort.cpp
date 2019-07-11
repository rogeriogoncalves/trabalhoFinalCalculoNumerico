#include <iostream>
using namespace std;

void troca (int* vet, int i, int j);
int particao (int* vet, int e, int d);
void quickSort (int* vet, int e, int d);
int main()
{
    int t=100;
    clock_t start;
    double duration;
    start = clock();
    int cresc[100];
    int decres[100];
    int e=0, d=99;
	for(int i=0;i<t;i++)
	{
		    quickSort(vet,e,d);	
	}
    cout<<"Duracao: "<<duration;
    return 0;
}
void quickSort (int* vet, int e, int d)
{
    if(d<=e)
        return;
    int p= particao(vet,e,d);
    quickSort(vet,e,p-1);
    quickSort(vet,p+1,d);
}
int particao (int* vet, int e, int d)
{
    int i=e;
    int j=d;
    int pivo=vet[(d+e)/2];
    while(1)
    {
        while(vet[i]<pivo)
            i++;
        while(pivo<vet[j])
            j--;
        if(i>=j)
            break;
        troca(vet,i,j);
        i++;
        j--;
    }
    return i;
}
void troca (int* vet, int i, int j)
{
    int aux;
    aux=vet[i];
    vet[i]=vet[j];
    vet[j]=aux;
}
