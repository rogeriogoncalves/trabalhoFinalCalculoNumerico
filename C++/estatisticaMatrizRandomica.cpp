#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <string.h>
#include <unistd.h>
#include <ctime>
#include "Eigen/Dense"

using namespace Eigen;
using namespace std;

int n=5;
int t=10;
MatrixXf v(t,t);
MatrixXf w(t,t);
int somaV=0, somaW=0;
double stdDevV=0, stdDevW=0, meanV=0, meanW=0;

double randNormal()
{
    this_thread::sleep_for(chrono::milliseconds(10)); ///Sleep for 10 milliseconds
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator (seed);
    normal_distribution<double> distribution (0.0,1.0);
    return distribution(generator);
}
int main()
{
    clock_t start;
    double duration;
    start = clock();
    MatrixXf a(n,n);
    MatrixXf b(n,n);
    MatrixXf c(n,n);
    MatrixXf d(n,n);
    MatrixXf P(a.rows(), a.cols() + b.cols() + c.cols() + d.cols());
    MatrixXf Q(a.rows() + b.rows(), c.cols() + d.cols());
    MatrixXf pTransposta(P.cols(), P.rows());
    MatrixXf qTransposta(Q.cols(), Q.rows());
    int tracoP = 0, tracoQ = 0,aux=0;
    for (int k=0; k<t; k++)
    {
        for (int l=0; l<t; l++)
        {
            for (int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    a(i,j) = randNormal();
                    b(i,j) = randNormal();
                    c(i,j) = randNormal();
                    d(i,j) = randNormal();
                }
            }
            for (int i = 0; i < t; i++)
            {
                for(int j=0; j< t; j++)
                {
                    v(i,j) = 0;
                    w(i,j) = 0;
                }
            }

            P<< a, b, c, d;
            Q<< a, b,
                c, d;
            for(int i=0; i<P.rows(); i++)
            {
                for(int j=0; j<P.cols(); j++)
                    pTransposta(j,i) = P(i,j);
            }
            for(int i=0; i<Q.rows(); i++)
            {
                for(int j=0; j<Q.cols(); j++)
                    qTransposta(j,i) = Q(i,j);
            }
            for(int i=0; i<P.rows(); i++)
            {
                for(int j=0; j<P.cols(); j++)
                {
                    if(i==j)
                    {
                        tracoP +=pTransposta(i,j);
                        aux +=P(i,j);
                    }
                }
            }
            tracoP*=aux;
            aux=0;
            for(int i=0; i< Q.rows(); i++)
            {
                for(int j=0; j< Q.cols(); j++)
                {
                    if(i==j)
                    {
                        tracoQ +=qTransposta(i,j);
                        aux +=Q(i,j);
                    }
                }
            }
            tracoQ *=aux;
            v(k,l)= pow(tracoP,4);
            somaV += v(k,l);
            w(k,l)= pow(tracoQ,4);
            somaW += w(k,l);
        }
    }
    meanV = somaV/(t*t);
    meanW = somaW/(t*t);
    for (int k=0; k<t; k++)
    {
        for (int l=0; l<t; l++)
        {
            stdDevV += pow(v(k,l) - meanV, 2);
            stdDevW += pow(w(k,l) - meanW, 2);
        }
    }
    stdDevV = sqrt(stdDevV/t);
    stdDevW = sqrt(stdDevW/t);
    cout<<stdDevV/ meanV<<endl;
    cout<<stdDevW/ meanW;
    duration=(clock() - start)/(double)CLOCKS_PER_SEC;
    cout<<"Duracao: "<<duration;
    return 0;
}
