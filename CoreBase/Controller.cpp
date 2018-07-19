#pragma once
#include "stdafx.h"
#include "Controller.h"
#include <iostream>
#include "McGrainGrowth.h"
#include "GrainGrowth.h"
#include "NucleonsGenerator.h"
#include "Neighborhood2DVonNeumann.h"
#include "Neighborhood3DVonNeumann.h"
#include "Neighborhood2DMoore.h"
#include "Neighborhood3DMoore.h"
#include "Neighborhood2DCircular.h"
#include "Neighborhood3DCircular.h"
#include "Neighborhood2DPentagonal.h"
#include "Neighborhood3DPentagonal.h"
#include "Neighborhood2DHexagonal.h"
#include "Neighborhood3DHexagonal.h"


#include <map>

using namespace std;

Controller::~Controller()
{
	delete space;
	delete simulation;
}

Controller::Controller()
{

}

void Controller::StartProcess()
{
	simulation->simulateContinuously();
}

void Controller::PrepareProcess(int* argc, char** argv[])
{
	int sizeX = 10;
	int sizeY = 10;
	int sizeZ = 1;
	space = new Space(sizeX, sizeY, sizeZ, new Neighborhood2DPentagonal(sizeX, sizeY, Absorbent));
	
	//simulation = new McGrainGrowth(space, 10, 2, 0.3);
	
	simulation = new GrainGrowth(space);
	NucleonsGenerator* nucleonsGenerator = new NucleonsGenerator();
	nucleonsGenerator->putNucleonsRandomly(space, 5);

}


void Controller::CloseProcess()
{
	cout << "Finalize" << endl;

	//Just for test
	for (int k = 0; k < space->getZsize(); k++)
	{
		for (int i = 0; i < space->getXsize(); i++)
		{
			for (int j = 0; j < space->getYsize(); j++)
			{
				cout << space->getCells()[i][j][k]->getId() << " ";
			}
			cout << endl;
		}
		cout << endl;
	}




	getchar();
}