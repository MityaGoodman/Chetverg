#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void r(vector < vector <char> > &arr,int a, int b, int c, int h, char d)
{

    for(int i = a; i != a+ c; i ++)
        arr[i][b] = d;

    for(int i = b; i != b + h; i ++)
    {
    arr[a][i] = d;
    }
    for(int i = b; i != b + h; i ++)
    {
    arr[a + c][i] = d;
    }
    for(int i = a; i != a + c; i ++)
    {
    arr[i][b + h] = d;
    }
    arr[a+c][b+h] = d;
}
void R (vector < vector <char> > &arr,int a, int b, int c, int h, char d)
{
for(int i = a; i != a+ c; i ++)
        arr[i][b] = d;

    for(int i = b; i != b + h; i ++)
    {
    arr[a][i] = d;
    }
    for(int i = b; i != b + h; i ++)
    {
    arr[a + c][i] = d;
    }
    for(int i = a; i != a + c; i ++)
    {
    arr[i][b + h] = d;
    }
    arr[a+c][b+h] = d;
    for(int i = b + 1; i != b + h; i ++)
        {
            for(int y = a + 1; y != a + c; y ++)
                {
                    arr[y][i] = d;
                }
        }
}

void my_line( vector < vector <char> > &arr, int x0, int y0, int x1, int y1,char ch)
    {
      int A, B, sign;
      A = y1 - y0;
      B = x0 - x1;
      if (abs(A) > abs(B))
        sign = 1;
      else
        sign = -1;
      int signa, signb;
      if (A < 0)
        signa = -1;
      else
        signa = 1;
      if (B < 0)
        signb = -1;
      else
        signb = 1;
      int f = 0;
      arr[y0][x0] = ch;
      int x = x0, y = y0;
      if (sign == -1)
      {
        do {
          f += A*signa;
          if (f > 0)
          {
            f -= B*signb;
            y += signa;
          }
          x -= signb;
          arr[y][x] = ch;
        } while (x != x1 || y != y1);
      }
      else
      {
        do {
          f += B*signb;
          if (f > 0) {
            f -= A*signa;
            x -= signb;
          }
          y += signa;
          arr[y][x] = ch;
        } while (x != x1 || y != y1);
      }
}

int main()
{
   setlocale(LC_ALL, "ru");
   char *a;
   string abc;
   cin>>a;
   ifstream fin;
   fin.open(a);
   if (!fin.is_open())
   {
       cout<<"-"<<endl;
   }
   else
    cout<<"+"<<endl;
    while (getline(fin, abc))
        {
            cout << abc << endl;
        }
   fin.close();
      int h, w;
      cin >> h >> w; // вводим размеры пол€
      char sym;
      cin >> sym;  // вводим символ, которым заполн€ем поле
      vector < vector <char> > arr(h, vector <char> (w));
      for (int i = 0; i < w; i++)
      {
        for (int j = 0; j < h; j++)
          arr[i][j] = sym;
      }
      char func; //  вводим символ, определ€ющий дальнейший рисунок
      cin >> func;
      if (func == 'L')
      {
        int x0,y0,x1,y1;
        char symbol;
        cin >> x0 >> y0 >> x1 >> y1 >> symbol;
        my_line(arr,x0,y0,x1,y1,symbol);
      }
      else if (func == 'r')
      {
          int a,b,c,d;
          char ch;
          cin >> a >> b >> c >> d >> ch;
          r(arr,a,b,c,d,ch);
      }
      else if (func == 'R')
      {
          int a,b,c,d;
          char ch;
          cin >> a >> b >> c >> d >> ch;
          R(arr,a,b,c,d,ch);
      }




      for (int i = 0; i < w; i++)
      {
        for (int j = 0; j < h; j++)
          cout << arr[i][j] << " ";
        cout << endl;
      }
      cin.get();
      cin.get();
      return 0;
}
