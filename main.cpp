#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class techChain 		// ����� ��� �������� �� � �� � ������� ������������
{
public:					// ������������ ������� public

    int i; 				// ������������ ������ ���������

    void getProb() 		// ������� ��� ������� ������������
    {
        double sum = 0; // ����� ������������

        for (int j = 0; j <= i; j++)
        {

        }

        if (sum != 1)
        {
            cout << "������ ������� ������������, ������������� ��������� �� ����� 1"
                 << "����� ������������ = " << sum;
        }
    }

    void printProb() 	// ������� ��� ������ �� ������ ����������� ������������
    {
        cout << "����������� �����������: \n";
        
		for (int j = 0; j <= i; j++)
        {
            cout << "P(0," << P[j] << ")";
        }
        // �������� ���� ��� (��-0
        // � �� ��������� ��� ��������� ��
        // �� ���������� ����������� ����� � ������, ���� �� �������� � ��������� 
        
    }


private: 					// ������������ ������� private

    vector <double> T,		// ������ ������� ������������������ t
					Tau, 	// ������ ������� ������������������ tau
					Lam, 	// ������ �������������� �� ������
					Mu, 	// ������ �������������� �� ��
					P;     	// ������ ������������

	//double inserter = 0;
    
	double getLam (double t, int k) 	// ������� ��� ������� �������������� �� ������
    {
        Lam[k] = 1 / t;
        return Lam[k];
    }

    double getMu (double tau, int k) 	// ������� ��� ������� �������������� �� ��
    {
        Mu[k] = 1 / tau;
        return Mu[k];
    }
};

    void getInfo() 		// ������� ��� ������� � ������� �������� ������
    {
        for (int j = 0; j <= i; j++)
        {
            
            if (j < i) 	// ��� �� � �������� �� 0 �� (i-1)
			{
				cout << "������� �(0,"<<(j + 1)<<"): ";
            	cin >> T[j];
			
            	cout << "\n��������������� ����� �������� Lam(0,"<<(j + 1)<<"): "<< getLam(T[j], j) << "\n";

            	cout << "\n������� �au("<<(j + 1)<<",0): ";
            	cin >> Tau[j];

            	cout << "\n��������������� ����� �������� Mu("<<(j + 1)<<",0): "<< getMu(Tau[j], j) << "\n";
             }
             
             else 		// ��� �� � �������� i
             {
            	cout << "������� �(1,"<<j<<"): ";
            	cin >> T[j];
            	cout << "\n";
			
            	cout << "��������������� ����� �������� Lam(1,"<<j<<"): "<< getLam(T[j], j) << "\n";

            	cout << "������� �au("<<j<<",1): ";
            	cin >> Tau[j];
            	cout << "\n";

            	cout << "��������������� ����� �������� Mu("<<j<<",1): "<< getMu(Tau[j], j) << "\n";
			 } 
        }
    };


	
int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian"); 	// ��������� ������

    int i = 0;
    cout << "������� ������������ ������ ��������� ����� ��: ";
    cin >> i; 						// ������� ������������� ������� ��������� ��
    cout << "\n";
    
	techChain ourChain; 			// �������� ���������� ������
    ourChain.i = i;
    ourChain.getInfo();
    ourChain.getProb();
    ourChain.printProb();

    return 0;
}



