#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <string>

using namespace std;

int FiboR(int n) // array of size n
{
	if (n == 0 || n == 1)
		return (n);
	else return (FiboR(n - 1) + FiboR(n - 2));
}

int FiboNR(int n) // array of size n
{
	if (n < 0)
		return -1; // -1 denoting error in input
	if (n == 0 || n == 1)
		return (n);

	int* F = new int[n + 1]; // the example code used a variable called 'max'; rewrote this to run using a dynamically allocated array.
	int result;
	F[0] = 0; F[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		F[i] = F[i - 1] + F[i - 2];
	}
	result = F[n];
	delete[] F;
	return (result);
}

int MODFibR(unsigned int n) // array of size n
{
	if (n == 0 || n == 1)
		return (n);

	static vector<int> F; // using a vector to allow resizing; using static to keep one 'global' storage throughout the entire recursive process
	if (F.size() < n) { // resize the vector to fit every number in the fibonacci series up to n
		F.resize(n + 1);
	}

	if (F[n] == 0) { // .resize() fills each index with the value 0
		F[n] = MODFibR(n - 1) + MODFibR(n - 2); // complete the recursion
	}

	return F[n]; // return the current answer
}

int main() {

	clock_t start;
	clock_t end;

	cout << "Fibonacci time analysis (recursive vs non-recursive)" << endl << endl;
	cout << left << setw(10) << "Integer" << left << setw(20) << "FiboR (seconds)" << left << setw(20) << "MODFibR" << left << setw(20) << "FiboNR(seconds)" << left << setw(30) << "Fibo-value" << endl;
	for (int i = 5; i <= 40; i += 5) { // Stopping at 40 because 45 takes around a minute for my machine to run
		start = clock();
		int answer = FiboNR(i);
		end = clock();
		clock_t FiboNRTime = end - start;

		start = clock();
		FiboR(i);
		end = clock();
		clock_t FiboRTime = end - start;

		start = clock();
		MODFibR(i);
		end = clock();
		clock_t MODFibRTime = end - start;

		cout << left << setw(10) << i << left << setw(20) << to_string(FiboRTime) + (string)"ms" << left << setw(20) << to_string(MODFibRTime) + (string)"ms" << left << setw(20) << to_string(FiboNRTime) + (string)"ms" << left << setw(30) << answer << endl;
	}

	system("PAUSE");
	return 0;
}
