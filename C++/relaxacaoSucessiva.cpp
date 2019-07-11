#include <iostream>
using namespace std;

int main()
{
    clock_t start;
    double duration;
    start = clock();
    double w = 1.6, tolerancia = 0.00001;
    int lin =5, col=5, iterMax = 500;
    int a[lin][col] = {{4, -2, 1, 3, 0},
        {-1, 10, 0, 8, 1},
        {-1, 1, 15, 2, 4},
        {0, 1, 10, 5, 1},
        {2, -3, 1, 2, 20}};
    int b[5] = {15, 56, 74, 57, 107};
    int n = col;
    double r;
    int x[5];
    for(int i=0; i<n;i++)
    {
        r = 1/a[i][i];
        for(int j=0;j<n;j++)
        {
            if(i != j)
                a[i][j] = a[i][j] * r;
        }
        b[i]= b[i] * r;
        x[i] = b[i];
    }
    int iter =0;
    double normaRel = 1000;
    int v[5];
    while (normaRel > tolerancia && iter < iterMax)
    {
        iter+=1;
        for(int i=0;i<n;i++)
        {
            int soma = 0;
            for(int j=0;j<n;j++)
            {
                if(i !=j)
                {
                    soma = soma + a[i][j] * x[j];
                }
            }
            v[i] = x[i];
            x[i] = w * (b[i]- soma) + (1 - w) * x[i];
        }
        double normaNum = 0;
        double normaDen = 0;
        for(int i=0;i<n;i++)
        {
            double t = abs(x[i]- v[i]);
            if (t < normaNum)
            {
                normaNum = t;
            }
            if (abs(x[i])> normaDen)
            {
                normaDen = abs(x[i]);
            }
        }
        normaRel = normaNum / normaDen;
    }
    if(normaRel <=tolerancia)
        cout << "CondErro=0 "<< endl;
    else
        cout << "CondErro=1 "<< endl;
    duration=(clock() - start)/(double)CLOCKS_PER_SEC;
    cout<<"Duracao: "<<duration;
    return 0;
}
