#include #include #include #include using namespace std;

class techChain // класс для создания ТЦ с СО и расчета вероятностей
{

public:// спецификатор доступа public

techChain ()
{
starti = 1; // задано как исходное
}

techChain (int i)
{
starti = i;
}

void getInfo() // функция для задания и расчета исходных данных
{
for (int j = 0; j <= starti; j++)
{

if (j < starti) // для СО с индексом от 0 до (i-1)
{
cout << "\nВведите Т(0,"<<(j + 1)<<") = ";
cin >> inserter;
T.push_back(inserter);

cout << "\nЭтому значению соответствует Lam(0,"<<(j + 1)<<") = "<< getLam(T[j], j) << "\n";

cout << "\nВведите Тau("<<(j + 1)<<",0) = ";
cin >> inserter;
Tau.push_back(inserter);

cout << "\nЭтому значению соответствует Mu("<<(j + 1)<<",0) = "<< getMu(Tau[j], j) << "\n";
}

else // для СО с индексом i
{
cout << "\nВведите Т(1,"<<j<<") =="" ";
cin >> inserter;
T.push_back(inserter);

cout << "\nЭтому значению соответствует Lam(1,"<<j<<") =="" "<<="" getlam(t[j],="" j)="" <<="" "\n";

cout << "\nВведите Тau("<<j<<",1) =="" ";
cin >> inserter;
Tau.push_back(inserter);

cout << "\nЭтому значению соответствует Mu("<<j<<",1) =="" "<<="" getmu(tau[j],="" j)="" <<="" "\n";
}
}
}

void getProb() // функция для записи вероятностей
{

/* for (int j = 0; j <= starti; j++)
{
// потом тут появится заполнение вектора
}
*/
techGauss();

}

void printProb() // функция для вывода на печать расчитанных вероятностей
{
cout << "Расчитанные вероятности: ";

for (int j = 0; j <= starti; j++)
{

		cout << "\nP(" << j << ") = " << P[j];

}
// добавить цикл для (со-0)
// и отдельный для конечного со
// мб записывать вероятности сразу в стринг, чтоб не париться с индексами
}

~techChain() {}


private: // спецификатор доступа private

vector <double> T,// вектор средних продолжительностей t
Tau, // вектор средних продолжительностей tau
Lam, // вектор интенсивностей СП лямбда
Mu, // вектор интенсивностей СП мю
P; // вектор вероятностей

double inserter;// величина для записи в вектор
int starti;

double getLam (const double& t, const int& k) // функция для расчета интенсивностей СП лямбда
{
Lam.push_back(1/t);
return Lam[k];
}

double getMu (const double& tau, const int& k) // функция для расчета интенсивностей СП мю
{
Mu.push_back(1/tau);
return Mu[k];
}

void techGauss () // решение системы уравнений методом Гаусса
{

//создаем массив

int n = starti + 2;// количество уравнений
int m = starti + 2;// количество неизвестных
float **matrix = new float *[n];

for (int k = 0; k < n; k++)
{
matrix[i] = new float[m];
}

//инициализируем

for (int k = 0; k < n; k++)
{
for (int l = 0; l < m; l++)
{
// см маткад
// мю самое последнее - (сумма всех лямбда кроме последней)
// все мю кроме первой отдельно - (сумма последней лямбда и первой мю)
// вторая лямбда - вторая мю
// ...
// сумма всех = 1

double sum = 0;

if (k == 0) // первое уравнение
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

else if (k == 1) // второе уравнение
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

else if ((k != 0) && (k !=1) && (k != (n-1)) // все остальные уравнения 
{
	if (l == 0)
	{
		sum = 0;
		sum += Lam[l];
		matrix[k][l] = sum;
	}
	
	if (l ==)
	
	
}

else if (k == (n-1)) // последнее уравнение
{
	sum = 0;
	
	for (int y = 0; y <= )
}

matrix[k][l];
}
}

//метод Гаусса
//прямой ход, приведение к верхнетреугольному виду

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

// обратный ход
xx[n - 1] = matrix[n - 1][n];
for (int i = (n - 2); i >= 0; i--)
{
xx[i] = matrix[i][n];
for (int j = (i + 1; j < n; j++)
{
xx[i] -= matrix[i][j] * xx[j];
}
}

// запись решения
for (int i = 0; i < n; i++)
{
P.push_back(xx[i]); // проверь, что оно выводится в нужном порядке
}

// очистка памяти

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
setlocale(LC_ALL, "Russian"); // установка локали

int i = 0;
cout << "Введите максимальный индекс состояния вашей ТЦ: ";
cin >> i;

techChain ourChain(i); // объявление объекта
ourChain.getInfo();
ourChain.getProb();
ourChain.printProb();

return 0;
}</j<<",1)></j<<",1)></j<<")></j<<")>

