// Karatsuba algorithm

#include <iostream>
#include <math.h>
#include <time.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

long long int Power(long long int x, long long int y) {
	if (y == 0)
		return (1);
	else if (y == 1)
		return(x);
	else
		return(x * Power(x, y-1));
}
 
long long int Digitos (long long int n, long long int &dig) {
	if (n < 10)	return (dig+1);
	else {
		dig++;
		return(Digitos(n/10, dig));
	}
}
long long int ultimos(long long int digitos, long long int &numero) {
	return numero % Power(10, digitos);
}
 
long long int primeros(long long int digitos, long long int &numero) {
	return numero/Power(10, digitos);
}

long long int multiplica (long long int &u, long long int &v) {
	long long int dig1=0, dig2=0;

	long long int numDigitos = max(Digitos(u, dig1), Digitos(v, dig2));

	if (numDigitos <= 1) return u*v;

	numDigitos = (numDigitos / 2) + (numDigitos % 2);

	long long int w = primeros(numDigitos, u);
	long long int x = ultimos(numDigitos, u);
	long long int y = primeros(numDigitos, v);
	long long int z = ultimos(numDigitos, v);

	long long int p=multiplica(w, y);
	long long int q=multiplica(x, z);
	long long int wMasx = w + x;
	long long int zMasy = z + y;

	long long int r=multiplica(wMasx, zMasy);

	return Power(10, 2*numDigitos)*p+Power(10, numDigitos)*(r-p-q)+q;
}
 

 
int main () {

	srand(time(NULL));
	long long int numero=0;

	cout << "Digite o numero maximo para multiplicar:";
	cin >> numero;

	long long int num1 = rand()%numero;
	long long int num2 = rand()%numero;

	cout << "\nnum1=" << num1;
	cout << "\nnum2=" << num2;

	cout << "\nO resultado eh: " << multiplica(num1, num2);
	return 0;
}
