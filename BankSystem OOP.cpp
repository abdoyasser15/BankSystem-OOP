#include <iostream>
#include "clsLoginScreen.h"
#include "clsLoginRegister.h"
using namespace std;
int main()
{
	while (true) 
	{
		if (clsLoginScreen::ShowLoginScreen());
		else break;
	}
	return 0;
}
