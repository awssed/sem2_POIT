#include<iostream>
#include <iomanip>
#include<time.h>
int f(int n);
void main() {
	long double l, sw;
	setlocale(LC_CTYPE, "rus");
		std::cout << "1-Цикл" << std::endl;
		std::cout << "2-Рекурсия"<<std::endl;
		int q;
		std::cin >> q;
		if (q == 1) {
			 clock_t start ;
			 clock_t end;
			start = clock();
			int n;
			std::cin >> n;
			int a = 0;
			int b = 1;
			long int c;
			if (n == 1)
				std::cout << 1;
			for (int i = 1; i < n; i++) {
				c = a + b;
				a = b;
				b = c;
			}
			end=clock();
			std::cout << c << std::endl;
			 long double seconds= (long double)(end - start) / CLOCKS_PER_SEC;
			 std::cout << std::fixed << std::setprecision(6);
			 if (seconds > 60) {
				 l = seconds / 60;
				 sw = seconds - l * 60;
			 }
			 else {
				 l = 0;
				 sw = seconds;
			 }
			 std::cout << "Расчетное время циклом:" <<l<<" Минут "<< sw<<" секунд "<<std::endl;
		}
		if (q == 2) {
			long double time_spent = 0.0;
			clock_t start;
			clock_t end;
			start = clock();
			int n;
			std::cin >> n;
			std::cout << f(n)<<std::endl;
			end=clock(); 
			long double seconds = (long double)(end - start) / CLOCKS_PER_SEC;
			std::cout << std::fixed << std::setprecision(6);
			if (seconds > 60) {
				l = seconds / 60;
				sw = seconds - l * 60;
			}
			else {
				l = 0;
				sw = seconds;
			}
			std::cout << std::fixed << std::setprecision(10);
			std::cout << "Расчетное время рекурсией" << l << " Минут " << sw << " секунд " << std::endl;

		}
} 
int f(int n)
{
	if (n == 1 || n == 2)
		return 1;
	if (n == 0)
		return 0;
	return f(n - 1) + f(n - 2);
}
