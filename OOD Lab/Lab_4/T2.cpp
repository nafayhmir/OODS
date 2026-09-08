#include <iostream>
using namespace std;

class Matrix
{
    private:
        int arr[2][2];
    public:
    Matrix()
    {
        int a=0;
                arr[0][0]=a;
                arr[0][1]=a;
                arr[1][0]=a;
                arr[1][1]=a;
    }
        Matrix(int a, int b, int c, int d)
            {   
                a=0;
                arr[0][0]=a;
                arr[0][1]=b;
                arr[1][0]=c;
                arr[1][1]=d;
            }
        Matrix operator+(Matrix a) //Matrix Addition
        {
            Matrix c;
            for(int i=0;i<2;i++)
            {
                for (int j=0;j<2;j++)
                {
                    c.arr[i][j]=arr[i][j]+a.arr[i][j];
                }
            }
            return c;
        }
         Matrix operator-(Matrix a) //Matrix Subtraction
        {
            Matrix c;
            for(int i=0;i<2;i++)
            {
                for (int j=0;j<2;j++)
                {
                    c.arr[i][j]=arr[i][j]-a.arr[i][j];
                }
            }
            return c;
        }
         Matrix operator*(Matrix a) //Matrix Multiplication
        {
            Matrix c;
            for(int i=0;i<2;i++)
            {
                for (int j=0;j<2;j++)
                {
                    c.arr[i][j]=arr[i][j]*a.arr[i][j];
                }
            }
            return c;
        }
friend istream& operator>>(istream &in, Matrix &m)
        {
        Matrix c;
            for(int i=0;i<2;i++)
            {
                for (int j=0;j<2;j++)
                {
                    cin>>c.arr[i][j];
                }
            }
        }
};

int main()
{
    
}