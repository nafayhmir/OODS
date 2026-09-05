#include <iostream>
using namespace std;
#ifndef CLASS_H
#define CLASS_H

class matrix
{
private:
    int arr[3][3];

public:
    matrix()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                arr[i][j] = 0;
            }
        }
    }
    matrix(int a, int b, int c, int d, int e, int f, int g, int h, int i)
    {
        arr[0][0] = a;
        arr[0][1] = b;
        arr[0][2] = c;
        arr[1][0] = d;
        arr[1][1] = e;
        arr[1][2] = f;
        arr[2][0] = g;
        arr[2][1] = h;
        arr[2][2] = i;
    }
    matrix operator+(matrix a)
    {
        matrix temp;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp.arr[i][j] = arr[i][j] + a.arr[i][j];
                
            }
        }
        return temp;
    }
    matrix operator-(matrix a)
    {
        matrix temp;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp.arr[i][j] = arr[i][j] - a.arr[i][j];
                
            }
        }
        return temp;
    }
    matrix operator*(matrix a)
    {
        matrix temp;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for(int k=0;k<3;k++)
                {
                temp.arr[i][j] = arr[i][k] * a.arr[k][j];
                
                }
            }
        }
        return temp;
    }
    matrix operator*(int a)
    {
        matrix temp;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                temp.arr[i][j] = arr[i][j] * a;

            }
        }
        return temp;

    }
    bool operator==(matrix a)
    {
        bool b;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j] == a.arr[i][j])
                {
                    b=1;
                }
                else
                {
                    b=0;
                }
            }
        }
        return b;
    }
    bool operator<(matrix a)
    {
        int s1 = 0;
        int s2 = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                s1 += arr[i][j];
                s2 += a.arr[i][j];
            }
        }
        if (s1 > s2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    friend ostream &operator<<(ostream &a, matrix b)
    {

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                a<< b.arr[i][j] << "\t";
            }
            cout << endl;
        }
        return a;
    }
    matrix operator+=(matrix a)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                a.arr[i][j] += arr[i][j];
            }
        }
        return a;
    }
    matrix operator-=(matrix a)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                a.arr[i][j] -= arr[i][j];
            }
        }
        return a;
    }
    bool operator!()
    {
        bool a=1;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (i == j)
                {
                    if (arr[i][j] != 1)
                    {
                        a = 0;
                    }
                }
                else
                {
                    if (arr[i][j] != 0)
                    {
                        a = 0;
                    }
                }
            }
        }
        return a;
    }
};

 #endif