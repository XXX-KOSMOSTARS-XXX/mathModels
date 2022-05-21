#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class techChain 		// ����� ��� �������� �� � �� � ������� ������������
{		

public:					// ������������ ������� public

	techChain () 
	{ 
		starti = 1; 	// ������ ��� ��������
	}

	techChain (int i) 
	{ 
		starti = i;
	}		
 
    void getInfo() 		// ������� ��� ������� � ������� �������� ������
    {
        for (int j = 0; j <= starti; j++)
        {
            
            if (j < starti) 	// ��� �� � �������� �� 0 �� (i-1)
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
             
             else 				// ��� �� � �������� i
            {
            	cout << "\n������� �(1,"<<j<<") = ";
				cin >> inserter;
				T.push_back(inserter);
			
            	cout << "\n����� �������� ������������� Lam(1,"<<j<<") = "<< getLam(T[j], j) << "\n";

            	cout << "\n������� �au("<<j<<",1) = ";
				cin >> inserter;
				Tau.push_back(inserter);

            	cout << "\n����� �������� ������������� Mu("<<j<<",1) = "<< getMu(Tau[j], j) << "\n";
			} 
        }
    } 
	
	void getProb() 		// ������� ��� ������ ������������
    {
        double sum = 0; // ����� ������������

        for (int j = 0; j <= starti; j++)
        {
// ����� ��� �������� ���������� ������� 
        }

        if (sum != 1)
        {
            cout << "\n������ ������� ������������, ������������� ��������� �� ����� 1"
                 << "\n����� ������������ = " << sum;
        }
    }

    void printProb() 	// ������� ��� ������ �� ������ ����������� ������������
    {
        cout << "����������� �����������: \n";
        
		for (int j = 0; j <= starti; j++)
        {
            cout << "P(0," << P[j] << ") = ";
        }
        // �������� ���� ��� (��-0)
        // � ��������� ��� ��������� ��
        // �� ���������� ����������� ����� � ������, ���� �� �������� � ��������� 
    }
    
     ~techChain() {}  


private: 					// ������������ ������� private

    vector <double> T,		// ������ ������� ������������������ t
					Tau, 	// ������ ������� ������������������ tau
					Lam, 	// ������ �������������� �� ������
					Mu, 	// ������ �������������� �� ��
					P;     	// ������ ������������

	double inserter;		// �������� ��� ������ � ������
	int starti;				
    
	double getLam (const double& t, const int& k) 	// ������� ��� ������� �������������� �� ������
    {
        Lam.push_back(1/t);
        return Lam[k];
    }

    double getMu (const double& tau, const int& k) 	// ������� ��� ������� �������������� �� ��
    {
        Mu.push_back(1/tau);
        return Mu[k];
    }
    
    void techGauss () 		// ������� ������� ��������� ������� ������ 
    {
    
	//������� ������
    
    int n = starti + 2;		// ���������� ���������
    int m = starti + 1;		// ���������� �����������
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
// �� ����� ��������� - (����� ���� ������ ����� ���������)
// ��� �� ����� ������ �������� - (����� ��������� ������ � ������ ��)
// ������ ������ - ������ ��
// ...
// ����� ���� = 1
 
            cin >> matrix[k][l];
        }
	}
 
    //����� ������
    //������ ���, ���������� � ������������������ ����

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
    
    // �������� ���
    xx[n - 1] = matrix[n - 1][n];
    for (i = (n - 2); i >= 0; i--)
    {
        xx[i] = matrix[i][n];
        for (j = i + 1; j < n; j++) 
		{
			xx[i] -= matrix[i][j] * xx[j];
		}
    }
 
    //���������� ������� 
    for (i = 0; i<n; i++)
        cout << xx[i] << " ";
    cout << endl;
 
    // ��� ���� �������� ������� 
    
	}
};

	
int main()
{
    setlocale(LC_ALL, "Russian"); 	// ��������� ������

    int i = 0;
    cout << "������� ������������ ������ ��������� ����� ��: ";
    cin >> i; 						
    
	techChain ourChain(i); 			// ���������� �������
	ourChain.getInfo();
    ourChain.getProb();
    ourChain.printProb();

    return 0;
}



