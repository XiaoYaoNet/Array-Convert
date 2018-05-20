#include <iostream>
#include "vld.h"

using namespace std;

void convert1(int a[], int n, int m)
{
	int *b = new int[m];                 //������ʱ����
	for (int i = 0; i < m; i++)          //��ǰm��Ԫ�ظ��Ƶ���ʱ������
		*(b + i) = a[i];
	for (int i = m; i < n; i++)          //�����µ�n-m��Ԫ�������ƶ�m��λ��
		a[i - m] = a[i];
	for (int i = 0; i < m; i++)          //�������m��Ԫ�ش���ʱ�����и��Ƶ�a�����µ�λ��
		a[n-m + i] = b[i];
	delete[]b;                           //�ǵû�����ʱ������ڴ�
}
int gcd(int a, int b)
{
	int c;
	c = (a>b) ? b : a;
	while (a%c != 0 || b%c != 0)
	{
		c--;
	}
	return c;
}
void convert2(int a[],int n,int m)
{
	int temp;
	for (int i = 0; i < gcd(m,n); i++)
	{
		int temp = a[i];
		int j=i;
		for (; ;)
		{
			int k = j + m;
			if (k>=n)
				k -= n;
			if (k == i)
				break;
			a[j] = a[k];
			j = k;
		}	
		a[j] = temp;
	}
}

void convert3(int a[], int n, int m)
{
	
	if ((m - n) % 2 == 0)
	{

		for (int i = 0; i < (m - n) / 2; i++)
		{
			a[m - i] = a[m - i] ^ a[n + i];
			a[n + i] = a[n + i] ^ a[m - i];
			a[m - i] = a[m - i] ^ a[n + i];
		}
	}
	else{
		for (int i = 0; i <=(m - n) / 2; i++)
		{
			a[m - i] = a[m - i] ^ a[n + i];
			a[n + i] = a[n + i] ^ a[m - i];
			a[m - i] = a[m - i] ^ a[n + i];
		}
	}
		
}

int main()
{
	int a[10];
	for (int i = 0; i < 10; i++)
		a[i] = i;

	//convert1(a, 10, 5);

	//convert2(a, 10, 5);

	
	convert3(a, 0, 4);
	convert3(a, 5, 9);
	convert3(a, 0, 9);
	

	for (int i = 0; i < 9; i++)
		cout << a[i] << ",";
	cout << a[9] << endl;
	return 0;
}