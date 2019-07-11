#include <iostream>
#include <complex>
#include <ctime>
#include <fstream>
using namespace std;

float width =  600;
float height = 600;
int value (int x, int y)
{
    complex<float> point((float)x/width-1.5, (float)y/height-0.5);
    complex<float> z(0, 0);
    unsigned int nb_iter = 0;
    while (abs (z) < 2 && nb_iter <= 34)
    {
        z = z * z + point;
        nb_iter++;
    }
    if (nb_iter < 34)
        return (255*nb_iter)/33;
    else
        return 0;
}
int main()
{
    int t=100;
    clock_t start;
    double duration;
    start = clock();
    for(int i=0; i<t; i++)
    {
        ofstream my_Image ("mandelbrot.ppm");
        if (my_Image.is_open ())
        {
            my_Image << "P3\n" << width << " " << height << " 255\n";
            for (int i = 0; i < width; i++)
            {	for (int j = 0; j < height; j++)
                {
                    int val = value(i, j);
                    my_Image << val<< ' ' << 0 << ' ' << 0 << "\n";
                }
            }
            my_Image.close();
        }
        else
            cout << "Could not open the file";
    }
    duration=(clock() - start)/(double)CLOCKS_PER_SEC;
    cout<<"Duracao: "<<duration;
    return 0;
}
