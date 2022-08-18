#ifndef TECHCHAIN_H
#define TECHCHAIN_H
#include "QVector"

class techChain             // класс для создания ТЦ с СО и расчета вероятностей
{
public:

    ~techChain() {};

    techChain();

    techChain (int i)
    {
        starti = i;
    }

    void getInfo();         // функция для задания и расчета исходных данных
    void getProb();         // функция для записи вероятностей
    void printProb();       // функция для вывода на печать рассчитанных вероятностей

private:

    QVector <double> t,     // вектор средних продолжительностей Т
            tau,            // вектор средних продолжительностей Тау
            lam,            // вектор интенсивностей СП Лямбда
            mu,             // вектор интенсивностей СП Мю
            p;              // вектор вероятностей Р

    int starti;             // максимальный индекс состояния ТЦ

    double getLam (const double& t, const int& k);  // функция для расчета интенсивностей СП Лямбда
    double getMu (const double& tau, const int& k); // функция для расчета интенсивностей СП Мю
    void techGauss ();                              // решение системы уравнений методом Гаусса

};

#endif // TECHCHAIN_H
