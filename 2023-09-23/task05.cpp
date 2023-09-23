#include <iostream>

int main(int argc, char* argv[])
{
	int a = 0;
	std::cin >> a;
	
	if ( a % 100 < 10 || a % 100 > 20) {

		if (a % 10 > 1 && a % 10 < 5) {
			std::cout << a << " bochki";
		}
		else if (a % 10 == 1){
			std::cout << a << " bochka";
		}
		else {
			std::cout << a << " bochek";
		}
	}
	else {
		std::cout << a << " bochek";
	}
	return 0;
}