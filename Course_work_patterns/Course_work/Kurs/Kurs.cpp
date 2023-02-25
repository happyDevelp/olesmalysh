// Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "SceneController.h"

using namespace std;

int main(int argc, char** argv)
{
	SceneController* sc = SceneController::getInstance();
	
	
	
	sc->initMain(argc, argv);
	return 0;
}