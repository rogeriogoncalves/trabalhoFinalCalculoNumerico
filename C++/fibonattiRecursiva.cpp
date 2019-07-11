#include <iostream>
#include <ctime>
using namespace std;

float fibRecursivo(int i)
{
    if(i<2)
        return 1;
    else
        return fibRecursivo(i-1)+fibRecursivo(i-2);
}

int main()
{
    int t=100;
    clock_t start;
    double duration;
    start = clock();
    for(int i=1;i<=t;i++)
        fibRecursivo(i);
    duration=(clock() - start)/(double)CLOCKS_PER_SEC;
    cout<<"Duracao: "<<duration;
    return 0;
}
