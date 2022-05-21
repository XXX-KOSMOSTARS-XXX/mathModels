#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class techChain 		// класс для создания ТЦ с СО и расчета вероятностей
{		

public:					// спецификатор доступа public

	techChain () 
	{ 
		starti = 1; 	// задано как исходное
	}

	techChain (int i) 
	{ 
		starti = i;
	}		
 
    void getInfo() 		// функция для задания и расчета исходных данных
    {
        for (int j = 0; j <= starti; j++)
        {
            
            if (j < starti) 	// для СО с индексом от 0 до (i-1)
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
             
             else 				// для СО с индексом i
            {
            	cout << "\nВведите Т(1,"<<j<<") = ";
				cin >> inserter;
				T.push_back(inserter);
			
            	cout << "\nЭтому значению соответствует Lam(1,"<<j<<") = "<< getLam(T[j], j) << "\n";

            	cout << "\nВведите Тau("<<j<<",1) = ";
				cin >> inserter;
				Tau.push_back(inserter);

            	cout << "\nЭтому значению соответствует Mu("<<j<<",1) = "<< getMu(Tau[j], j) << "\n";
			} 
        }
    } 
	
	void getProb() 		// функция для записи вероятностей
    {
        double sum = 0; // сумма вероятностей

        for (int j = 0; j <= starti; j++)
        {
// потом тут появится заполнение вектора 
        }

        if (sum != 1)
        {
            cout << "\nОшибка расчета вероятностей, нормировочное уравнение не равно 1"
                 << "\nСумма вероятностей = " << sum;
        }
    }

    void printProb() 	// функция для вывода на печать расчитанных вероятностей
    {
        cout << "Расчитанные вероятности: \n";
        
		for (int j = 0; j <= starti; j++)
        {
            cout << "P(0," << P[j] << ") = ";
        }
        // добавить цикл для (со-0)
        // и отдельный для конечного со
        // мб записывать вероятности сразу в стринг, чтоб не париться с индексами 
    }
    
     ~techChain() {}  


private: 					// спецификатор доступа private

    vector <double> T,		// вектор средних продолжительностей t
					Tau, 	// вектор средних продолжительностей tau
					Lam, 	// вектор интенсивностей СП лямбда
					Mu, 	// вектор интенсивностей СП мю
					P;     	// вектор вероятностей

	double inserter;		// величина для записи в вектор
	int starti;				
    
	double getLam (const double& t, const int& k) 	// функция для расчета интенсивностей СП лямбда
    {
        Lam.push_back(1/t);
        return Lam[k];
    }

    double getMu (const double& tau, const int& k) 	// функция для расчета интенсивностей СП мю
    {
        Mu.push_back(1/tau);
        return Mu[k];
    }
    
    void techGauss () 		// решение системы уравнений методом Гаусса 
    {
    
	//создаем массив
    
    int n = starti + 2;		// количество уравнений
    int m = starti + 1;		// количество неизвестных
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
// мю самое последнее - (сумма всех лямбда кроме последней)
// все мю кроме первой отдельно - (сумма последней лямбда и первой мю)
// вторая лямбда - вторая мю
// ...
// сумма всех = 1
 
            cin >> matrix[k][l];
        }
	}
 
    //метод Гаусса
    //прямой ход, приведение к верхнетреугольному виду

    float  tmp;
    int k;
    float *xx = new float [m];
 
    for (int i = 0; i < n; i++)
    {
        tmp = matrix[i][i];
        for (int j = n; j > = i; j--)
        {
            matrix[i][j] /= tmp;
        }
        
		for (int j = i + 1; j<n; j++)
        {
            tmp = matrix[j][i];
            for (k = n; k >= i; k--)
            {
                matrix[j][k] -= tmp*matrix[i][k];
            }
        }
    }
    
    // обратный ход
    xx[n - 1] = matrix[n - 1][n];
    for (i = (n - 2); i >= 0; i--)
    {
        xx[i] = matrix[i][n];
        for (j = i + 1; j < n; j++) 
		{
			xx[i] -= matrix[i][j] * xx[j];
		}
    }
 
    //сохранение решения 
    for (i = 0; i<n; i++)
        cout << xx[i] << " ";
    cout << endl;
 
    // тут надо очистить матрицу 
    
	}
};

	
int main()
{
    setlocale(LC_ALL, "Russian"); 	// установка локали

    int i = 0;
    cout << "Введите максимальный индекс состояния вашей ТЦ: ";
    cin >> i; 						
    
	techChain ourChain(i); 			// объявление объекта
	ourChain.getInfo();
    ourChain.getProb();
    ourChain.printProb();

    return 0;
}



