#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

int main()
{
    int t=10;
    double soma=0.0;
    clock_t start;
    double duration;
    start = clock();
    for (int i=1;i<=t;i++)
    {
        soma =0.0;
        for(int j=1;j<=t;j++)
            soma += 1.0/(j * j);
    }
    cout << "Pi: "<<soma<< endl;
    cout << "Pi Correto: "<<(pow(3.1415,2)/6)<< endl;
    duration=(clock() - start)/(double)CLOCKS_PER_SEC;
    cout<<"Duracao: "<<duration;
    return 0;
}
