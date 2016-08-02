#include <stdio.h>
#include <stdlib.h>

int secondDigitBigger(int n);
int digit_cancel(int n);

int main() {

	int i, denom;
	int numerators = 1, denominators = 1;
	float simplified = 1.0;
	int case1 = 1;

	for (i = 10; i < 100; i++) {
		if (secondDigitBigger(i)) {
			if ((denom = digit_cancel(i)) != 0) {
				numerators *= i;
				denominators *= denom;
				simplified *= (float)denom/(i+0.0);
				printf("Case %d: %d/%d\n",case1++,i,denom);
			}
		}
	}
	
	printf("Original product of these %d numbers: %d/%d\n",case1-1,numerators,denominators);
	printf("Simplified form: %d/%d\n",1,(int)simplified);
	return 0;
}

int secondDigitBigger(int n) {

	int first = n/10;
	int second = n%10;

	if (second > first) return 1;
	return 0; 
}

int digit_cancel(int n) {

	int i;
	int first = n/10;
	int second = n%10;
	int newNumber = 10*second;

	for (i = first+1; i < 10; i++) {
		newNumber += i;
		if ((float)n/(newNumber+0.0) == (float)first/(i+0.0)) {
			return newNumber;
		}
		newNumber -= i;
	}

	return 0;
}
