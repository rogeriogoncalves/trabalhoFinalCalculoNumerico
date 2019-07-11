#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctime>

float Abs( float x ){
    x = ( x * x ) / -(x);
    return x;
};
int main(){
    float solucao = 0., xini = 0., xnovo = 4, Fxnovo = 0.,Fdxnovo = 0., E = 0.0001;
    int k = 0, t=100;
    clock_t start;
    double duration;
    start = clock();
    for(int i=0; i<t; i++)
    {
    	do{
       		xini = xnovo;
       		Fxnovo = (pow(xini,4)+ 2 * (pow(xini,3)) - 13 * pow(xini,2) - 14 * xini + 24);
       		Fdxnovo = ( 4 *(pow(xini,3))+ 6 * (pow(xini,2)) - 26 * xini - 14); 
       		xnovo = xini - ( Fxnovo / Fdxnovo );
        	k += 1;
        	printf( "\niteracao = %d", k );
        	printf( "\nxini = %f\nxnovo = %f", xini, xnovo );
    	} while( Abs( xnovo - xini ) >= E || Abs( Fxnovo ) >= E );
    printf( "\n\nxnovo - xini = %f\n", xnovo - xini);
    printf( "A solucao final e: %f\n", xnovo );
    }
    duration=(clock() - start)/(double)CLOCKS_PER_SEC;
    cout<<"Duracao: "<<duration;
    return 0;
}
