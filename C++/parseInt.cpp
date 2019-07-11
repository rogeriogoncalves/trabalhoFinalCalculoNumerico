#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>
using namespace std;

string decToHex (int num)
{
    int i=0,temp;
    int numDcm = num;
    int numHexa[100];
    string strHexa;
    while(numDcm!=0)
    {
        temp = numDcm % 16;
        if(temp < 10)
            temp +=48;
        else
            temp += 55;     
        numHexa[i]= temp;
        i++;
        numDcm = numDcm / 16;
    }
    for(int j = i ; j>= 0; j--)
    {
        strHexa[j]+=numHexa[j];
    }
    return strHexa;
}
int hexToDec(string hex)
{
    double res = 0;
    for (int i=0; i<hex.length(); i++)
    {
        if (hex[i]>=48 && hex[i]<=57)
            res += (hex[i]-48)*pow(16,hex.length()-i-1);
        else if (hex[i]>=65 && hex[i]<=70)
            res += (hex[i]-55)*pow(16,hex.length( )-i-1);
        else if (hex[i]>=97 && hex[i]<=102)
            res += (hex[i]-87)*pow(16,hex.length()-i-1);
    }
    return res;
}
int main()
{
    clock_t start;
    double duration;
    start = clock();
    double soma=0.0;
    int t=10000, n=0, m=0,cont=0;
    string s;
    for(int i=0; i<t;i++)
    {
       	    n = rand();
            s = decToHex(n);
            m = hexToDec(s);
            if(m==n)
                cont++;
    }
    duration=(clock() - start)/(double)CLOCKS_PER_SEC;
    cout<<"Duracao: "<<duration;
    return 0;
}
