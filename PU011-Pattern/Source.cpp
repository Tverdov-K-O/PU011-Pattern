#include<iostream>
#include"Builder.h"
using namespace std;
 
int main() {
	setlocale(0, "");
	Director * director = new Director;
	MusicCenterBuilder * mcBuilder = new MusicCenterBuilder;
	director->setBuilder(mcBuilder);
	director->BuildMegaMC();

	MusicCenter * mc = mcBuilder->getResult();
	mc->print();

	ManualMCBuilder * manbilder = new ManualMCBuilder;
	director->setBuilder(manbilder);
	director->BuildMegaMC();
	ManualMC * manual = manbilder->getResult();
	cout << manual->getText() << endl;


	system("pause");
}