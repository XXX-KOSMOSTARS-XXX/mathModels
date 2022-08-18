#include "techchain.h"

#include "iostream"
#include "QVector"

techChain::techChain()
{
    starti = 1;             // задано как исходное
}

void techChain::getInfo()
{
    double inserter = 0;    // величина для записи в вектор

    for (int j = 0; j <= starti; j++)
    {

        if (j < starti)     // для СО с индексом от 0 до (i-1)
        {
            std::cout << "\nВведите t(0," << (j + 1) << ") = ";
            std::cin >> inserter;
            t.push_back(inserter);

            std::cout << "\nЭтому значению соответствует Lam(0," << (j + 1) << ") = " << getLam(t[j], j) << "\n";

            std::cout << "\nВведите Тau(" << (j + 1) << ",0) = ";
            std::cin >> inserter;
            tau.push_back(inserter);

            std::cout << "\nЭтому значению соответствует Mu(" << (j + 1) << ",0) = " << getMu(tau[j], j) << "\n";
        }

        else                // для СО с индексом i
        {
            std::cout << "\nВведите Т(1," << j << ") = ";
            std::cin >> inserter;
            t.push_back(inserter);

            std::cout << "\nЭтому значению соответствует Lam(1," << j << ") = " << getLam(t[j], j) << "\n";

            std::cout << "\nВведите Тau(" << j << ",1) = ";
            std::cin >> inserter;
            tau.push_back(inserter);

            std::cout << "\nЭтому значению соответствует Mu(" << j << ",1) = " << getMu(tau[j], j) << "\n";
        }
    }
}

void techChain::getProb()
{
    /* for (int j = 0; j <= starti; j++)
{
// потом тут появится заполнение вектора
}
*/
    techGauss();
}

void techChain::printProb()
{
    std::cout << "Расчитанные вероятности: ";

    for (int j = 0; j <= starti; j++)
    {

        std::cout << "\n P(" << j << ") = " << p[j];

    }
    // добавить цикл для (со-0)
    // и отдельный для конечного со
    // мб записывать вероятности сразу в стринг, чтоб не париться с индексами
}

double techChain::getLam (const double& t, const int& k)
{
    lam.push_back(1/t);
    return lam[k];
}

double techChain::getMu (const double& tau, const int& k)
{
    mu.push_back(1/tau);
    return mu[k];
}

void techChain::techGauss()
{
    //создаем массив

    int numberEquat = starti + 1;     // количество уравнений
    int numberUnkn = starti + 2;      // количество неизвестных
    float **matrix = new float *[numberEquat];

    for (int k = 0; k < numberEquat; k++)
    {
        matrix[k] = new float[numberUnkn];
    }

    //инициализируем

    for (int k = 0; k < numberEquat; k++)
    {
        for (int l = 0; l < numberUnkn; l++)
        {
            // см маткад
            // мю самое последнее - (сумма всех лямбда кроме последней)
            // все мю кроме первой отдельно - (сумма последней лямбда и первой мю)
            // вторая лямбда - вторая мю
            // ...
            // сумма всех = 1

            double sum = 0;

            if (k == 0)                         // первое уравнение
            {
                if (l == 0)                     // для р0
                {
                    sum = 0;
                    for (int h = 0; h < (lam.size()-1); h++)
                    {
                        sum += lam[h];
                    }
                    sum *= -1;
                    matrix[k][l] = sum;
                }

                else if (l == 1)                // для р1
                {
                    matrix[k][l] = mu[0]; //mu[starti]; проверь здесь, реал мб старти
                }

                else if ((l != 0) && (l != 1))  // для остальных р
                {
                    matrix[k][l] = 0;
                }
            }

            else if (k == 1)                    // второе уравнение
            {
                if (l == 0)                     // для р0
                {
                    matrix[k][l] = 0;
                }

                else
                {
                    if (l == 1)                 // для р1
                    {
                        sum = 0;
                        sum += mu[0]; //mu[starti];
                        sum += lam[starti];
                        sum *= -1;
                        matrix[k][l] = sum;
                    }

                    else                        // для остальных р
                    {
                        sum = 0;
                        sum += mu[l];
                        matrix[k][l] = sum;
                    }
                }
            }

            else if ((k != 0) && (k != 1) && (k < (numberEquat - 1) )) // уравнения кроме первого, второго, предпоследнего, последнего
            {
                if (l == 0)
                {
                    sum = 0;
                    sum += lam[k];
                    matrix[k][l] = sum;
                }

                else if (l == k)
                {
                    sum = 0;
                    sum += mu[k];
                    matrix[k][l] = sum;
                }

                else if ( l != k )
                {
                    matrix[k][l] = 0;
                }
            }

            else if (k == (numberEquat - 1)) // предпоследнее уравнение
            {
                if (l == 1)
                {
                    sum = 0;
                    sum += lam[starti];
                    matrix[k][l] = sum;
                }

                else if (l == starti)
                {
                    sum = 0;
                    sum += mu[starti];
                    matrix[k][l] = sum;
                }

                else if ( (l > 1) && (l != starti) )
                {
                    matrix[k][l] = 0;
                }
            }

            else if (k == (numberEquat - 1)) // последнее уравнение
            {
                sum = 0;
                sum += 1;
                matrix[k][l] = sum;
            }
        }

        //метод Гаусса
        //прямой ход, приведение к верхнетреугольному виду

        float tmp;
        float *xx = new float [numberUnkn];

        for (int i = 0; i < numberEquat; i++)
        {
            tmp = matrix[i][i];
            for (int j = numberEquat; j >= i; j--)
            {
                matrix[i][j] /= tmp;
            }

            for (int j = (i + 1); j < numberEquat; j++)
            {
                tmp = matrix[j][i];
                for (int k = numberEquat; k >= i; k--)
                {
                    matrix[j][k] -= tmp*matrix[i][k];
                }
            }
        }

        // обратный ход

        xx[numberEquat - 1] = matrix[numberEquat - 1][numberEquat];
        for (int i = (numberEquat - 2); i >= 0; i--)
        {
            xx[i] = matrix[i][numberEquat];
            for (int j = (i + 1); j < numberEquat; j++)
            {
                xx[i] -= matrix[i][j] * xx[j];
            }
        }

        // запись решения

        for (int i = 0; i < numberEquat; i++)
        {
            p.push_back(xx[i]); // проверь, что оно выводится в нужном порядке
        }

        // очистка памяти

        memset(matrix, 0, k);

//        if (matrix)
//        {
//            for (int k = 0; k < numberEquat; k++)
//            {
//                for (int l = 0; l < numberUnkn; l++)
//                {
//                    delete matrix[k][l];
//                }
//            }
//            delete [] matrix;
//        }

    }
};
