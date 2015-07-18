#include<iostream> 
#include<string>
using namespace std;  
 
int Max(int a, int b);
void lcs(string str1, string str2);
int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	lcs(str1, str2);
	return 0;
}

void lcs(string str1, string str2)
{
	int m, n, i, j;
	m = str1.length();
	n = str2.length();
	int temp = Max(m,n);
	int **c;
	c = new int*[m];
	for (i = 0; i < m; i++)
		c[i] = new int[n];
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{

			if (str1[i] != str2[j])
			{
				if (j == 0 || i == 0)
				{
					if (i>0)
						c[i][j] = c[i - 1][j];
					else if (j>0)
						c[i][j] = c[i][j - 1];
					else
     					c[i][j] = 0;

				}
				else
					c[i][j] = Max(c[i - 1][j], c[i][j - 1]);

			}
			else
			{
				if (j == 0 || i == 0)
					c[i][j] = 1;
				else
					c[i][j] = c[i - 1][j - 1] + 1;
			}

		}
	 
	cout << c[m - 1][n - 1] << endl;
	for (i = 0; i<m; i++)
		delete[]c[i];
	delete[]c;
}

int Max(int a, int b)
{
	return (a>b ? a : b);
}
