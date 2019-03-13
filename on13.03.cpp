#include <iostream>

using namespace std;

int ValidNumber();
double TeylorCos(double);
double FindAccuracy();
void MassiveTeylor(double*, int);
void MassiveFunction(double*, int);
void MiddleMassive(double*, int, double*, double*);
void MaxElement(double*, int , double*);
void MaxElementInMassive(double*, int );

int main()
{
	int n = ValidNumber();
	double** first = new double*[n];
	double** second = new double*[n];
	double** middle = new double*[n];
	double* max = new double[n];
	for (int i = 0; i < n; i++)
	{
		first[i] = new double[n];
		second[i] = new double[n];
	}

	FindAccuracy();

	MaxElementInMassive(max, n);

	system("pause");
}
int ValidNumber()
{
	int n;
	cout << "Enter size of massive ";
	cin >> n;
	if (n < 0)
	{
		cout << "Invalid number ";
	}
	return n;
}
double TeylorCos(double x)
{
	double accuracy = FindAccuracy();

	double q = 1, f=4, z = -1, fact = 2, x1 = x * x;
	while ((x*x / fact) >= accuracy)
	{
		q = q + z * x*x / fact;
		x1 = x1 * x*x;
		f = f + 2;
		fact = fact * (f - 1)*f;
		z = z * (-1);
	}
	return q;
}
double FindAccuracy()
{
	double accuracy;
	cout << "Enter accuracy ";
	cin >> accuracy;
	if (accuracy < 0)
	{
		cout << "Invalid number ";
	}
	return accuracy;
}
void MassiveTeylor(double* first, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				first[j] = (i + j);
			}
			else
			{
				double a = TeylorCos(2 * i);
				double b = TeylorCos(2 * j);
				double c = TeylorCos(i + j);
				first[j] = ((i + j)*(i + j) - a + b) / (c + (i + j)*(i + j));
			}
		}
	}
}
void MassiveFunction(double* second, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				second[j] = (i + j);
			}
			else
			{
				second[j] = ((i + j)*(i + j) - cos(2 * i) + cos(2 * j)) / (cos(i + j) + (i + j)*(i + j));
			}
		}
	}
}
void MiddleMassive(double* middle, int n, double* first, double* second)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			middle[j] = first[j] - second[j];
		}
	}
}
void MaxElement(double* middle, int n, double* max)
{
	int maximum = 0;
	for (int i = 0; i < n; i++)
	{
		int f = 0;
		for (int j = 0; j < n; j++)
		{
			if (middle[maximum] < middle[j])
			{
				maximum = j;
			}
			j = 0;
		}
		max[f] = middle[maximum];
		f++;
	}
}
void MaxElementInMassive(double* max, int n)
{
	int maxi = 0;
	for (int i = 0; i < n; i++)
	{
		if (max[maxi] < max[i])
		{
			maxi = i;
		}
		i = 0;
	}
	cout << " Maximum element of the array of difference of elements = " << abs(max[maxi]);
}