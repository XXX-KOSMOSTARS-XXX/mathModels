#include #include #include #include using namespace std;

class techChain // ����� ��� �������� �� � �� � ������� ������������
{

public:// ������������ ������� public

techChain ()
{
starti = 1; // ������ ��� ��������
}

techChain (int i)
{
starti = i;
}

void getInfo() // ������� ��� ������� � ������� �������� ������
{
for (int j = 0; j <= starti; j++)
{

if (j < starti) // ��� �� � �������� �� 0 �� (i-1)
{
cout << "\n������� �(0,"<<(j + 1)<<") = ";
cin >> inserter;
T.push_back(inserter);

cout << "\n����� �������� ������������� Lam(0,"<<(j + 1)<<") = "<< getLam(T[j], j) << "\n";

cout << "\n������� �au("<<(j + 1)<<",0) = ";
cin >> inserter;
Tau.push_back(inserter);

cout << "\n����� �������� ������������� Mu("<<(j + 1)<<",0) = "<< getMu(Tau[j], j) << "\n";
}

else // ��� �� � �������� i
{
cout << "\n������� �(1,"<<j<<") =="" ";
cin >> inserter;
T.push_back(inserter);

cout << "\n����� �������� ������������� Lam(1,"<<j<<") =="" "<<="" getlam(t[j],="" j)="" <<="" "\n";

cout << "\n������� �au("<<j<<",1) =="" ";
cin >> inserter;
Tau.push_back(inserter);

cout << "\n����� �������� ������������� Mu("<<j<<",1) =="" "<<="" getmu(tau[j],="" j)="" <<="" "\n";
}
}
}

void getProb() // ������� ��� ������ ������������
{

/* for (int j = 0; j <= starti; j++)
{
// ����� ��� �������� ���������� �������
}
*/
techGauss();

}

void printProb() // ������� ��� ������ �� ������ ����������� ������������
{
cout << "����������� �����������: ";

for (int j = 0; j <= starti; j++)
{

		cout << "\nP(" << j << ") = " << P[j];

}
// �������� ���� ��� (��-0)
// � ��������� ��� ��������� ��
// �� ���������� ����������� ����� � ������, ���� �� �������� � ���������
}

~techChain() {}


private: // ������������ ������� private

vector <double> T,// ������ ������� ������������������ t
Tau, // ������ ������� ������������������ tau
Lam, // ������ �������������� �� ������
Mu, // ������ �������������� �� ��
P; // ������ ������������

double inserter;// �������� ��� ������ � ������
int starti;

double getLam (const double& t, const int& k) // ������� ��� ������� �������������� �� ������
{
Lam.push_back(1/t);
return Lam[k];
}

double getMu (const double& tau, const int& k) // ������� ��� ������� �������������� �� ��
{
Mu.push_back(1/tau);
return Mu[k];
}

void techGauss () // ������� ������� ��������� ������� ������
{

//������� ������

int n = starti + 2;// ���������� ���������
int m = starti + 2;// ���������� �����������
float **matrix = new float *[n];

for (int k = 0; k < n; k++)
{
matrix[i] = new float[m];
}

//��������������

for (int k = 0; k < n; k++)
{
for (int l = 0; l < m; l++)
{
// �� ������
// �� ����� ��������� - (����� ���� ������ ����� ���������)
// ��� �� ����� ������ �������� - (����� ��������� ������ � ������ ��)
// ������ ������ - ������ ��
// ...
// ����� ���� = 1

double sum = 0;

if (k == 0) // ������ ���������
{
	if (l == 0)
	{
		sum = 0;
		for (int h = 0; h < (Lam.size()-1); h++)
		{
			sum += Lam[h];
		}
		sum *= -1;
		matrix[k][l] = sum;
	}
	
	else if (l == 1)
	{
		matrix[k][l] = Mu[starti];
	}
	
	else if ((l != 0) && (l != 1))
	{
		matrix[k][l] = 0;
	}
}

else if (k == 1) // ������ ���������
{
	if (l == 0)
	{
		matrix[k][l] = 0;
	}
	
	else 
	{
		if (l == 1)
		{
			sum = 0;
			sum += Mu[starti];
			sum += Lam[starti];
			sum *= -1;
			matrix[k][l] = sum;
		}
		
		else 
		{
			sum = 0;
			sum += Mu[l];
			matrix[k][l] = sum;
		}
	}
}

else if ((k != 0) && (k !=1) && (k != (n-1)) // ��� ��������� ��������� 
{
	if (l == 0)
	{
		sum = 0;
		sum += Lam[l];
		matrix[k][l] = sum;
	}
	
	if (l ==)
	
	
}

else if (k == (n-1)) // ��������� ���������
{
	sum = 0;
	
	for (int y = 0; y <= )
}

matrix[k][l];
}
}

//����� ������
//������ ���, ���������� � ������������������ ����

float tmp;
float *xx = new float [m];

for (int i = 0; i < n; i++)
{
tmp = matrix[i][i];
for (int j = n; j >= i; j--)
{
matrix[i][j] /= tmp;
}

for (int j = (i + 1; j < n; j++)
{
tmp = matrix[j][i];
for (int k = n; k >= i; k--)
{
matrix[j][k] -= tmp*matrix[i][k];
}
}
}

// �������� ���
xx[n - 1] = matrix[n - 1][n];
for (int i = (n - 2); i >= 0; i--)
{
xx[i] = matrix[i][n];
for (int j = (i + 1; j < n; j++)
{
xx[i] -= matrix[i][j] * xx[j];
}
}

// ������ �������
for (int i = 0; i < n; i++)
{
P.push_back(xx[i]); // �������, ��� ��� ��������� � ������ �������
}

// ������� ������

if (matrix)
{
for (int k = 0; k < n; k++)
{
for (int l = 0; l < m; l++)
{
delete [] matrix[k][l];
}
}
delete [] matrix;
}

}
};


int main()
{
setlocale(LC_ALL, "Russian"); // ��������� ������

int i = 0;
cout << "������� ������������ ������ ��������� ����� ��: ";
cin >> i;

techChain ourChain(i); // ���������� �������
ourChain.getInfo();
ourChain.getProb();
ourChain.printProb();

return 0;
}</j<<",1)></j<<",1)></j<<")></j<<")>

