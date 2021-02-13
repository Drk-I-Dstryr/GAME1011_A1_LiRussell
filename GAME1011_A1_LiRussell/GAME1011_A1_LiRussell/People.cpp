#include "People.h"
#include <string>
#include <iostream>
#include <ctime>
using namespace std;


int main()
{
	int randAge;
	int age;

	int randName;
	string name;

	int randColl;
	string college;

	int randEnroll;
	string progEnroll;

	int randCurrSem;
	int sem;

	int randPrefStream;
	string prefStream;

	int randHrsStream;
	int hrsStream;

	int randPrefGDevice;
	string prefGdevice;

	int randhrsGm;
	int hrsGm;

	bool streamer = false;
	bool gamer = false;

	Person participants[500];
	NonGamingStudent people[500];
	GamingStudent people2[500];

	Survey survey;

	int randStreamOrGame;

	int numPar;

	int numStreamers = 0;
	int numGamers = 0;

	int ready;

	int nSwitch = 0;
	int xbox = 0;
	int playstation = 0;

	int netflix = 0;
	int hulu = 0;
	int disney = 0;

	int hrsGam = 0;
	int hrsStrem = 0;

	int totAgeS = 0;
	int totAgeG = 0;

	double avgGam = 0;
	double avgStrem = 0;
	double avgAgeS = 0;
	double avgAgeG = 0;


	string favDev;
	string favMode;

	cout << "Welcome to this survey simulator!" << endl;
	cout << "How many participants do you want? (Up to 500)" << endl;
	cin >> numPar;
	srand((unsigned)time(0));
	for (int i = 0; i < numPar; i++)
	{
		streamer = false;
		gamer = false;
		randStreamOrGame = rand() % 2;
		if (randStreamOrGame == 0)
		{
			streamer = true;
		}
		else if (randStreamOrGame == 1)
		{
			gamer = true;
		}
		age = rand() % 22 + 18;
		randName = rand() % 4 + 1;
		if (randName == 1)
		{
			name = "Bob";
		}
		else if (randName == 2)
		{
			name = "Tadyam";
		}
		else if (randName == 3)
		{
			name = "Layla";
		}
		else if (randName == 4)
		{
			name = "Mary";
		}
		else if (randName == 5)
		{
			name = "Chadwick";
		}

		randColl = rand() % 3 + 1;
		if (randColl == 1)
		{
			college = "George Brown";
		}
		else if (randColl == 2)
		{
			college = "Seneca";
		}
		else if (randColl == 3)
		{
			college = "Massey";
		}

		randCurrSem = rand() % 4 + 1;
		sem = randCurrSem;

		randPrefStream = rand() % 2 + 1;
		if (randPrefStream == 1)
		{
			prefStream = "Netflix";
		}
		else if (randPrefStream == 2)
		{
			prefStream = "Hulu";
		}
		else if (randPrefStream == 3)
		{
			prefStream = "Disney+";
		}

		randHrsStream = rand() % 49 + 1;
		hrsStream = randHrsStream;

		randPrefGDevice = rand() % 2 + 1;
		if (randPrefGDevice == 1)
		{
			prefGdevice = "Xbox";
		}
		else if (randPrefGDevice == 2)
		{
			prefGdevice = "Playstation";
		}
		else if (randPrefGDevice == 3)
		{
			prefGdevice = "Switch";
		}

		randhrsGm = rand() % 49 + 1;
		hrsGm = randhrsGm;

		if (streamer == true)
		{
			numStreamers++;
			people[i] = NonGamingStudent(prefStream, hrsStream, college, progEnroll, sem, name, age, gamer);
			participants[i] = people[i];
		}
		else if (gamer == true)
		{
			numGamers++;
			people2[i] = GamingStudent(prefGdevice, hrsGm, college, progEnroll, sem, name, age, gamer);
			participants[i] = people2[i];
		}
	}
	survey = Survey(numPar, participants);

	cout << "Are you ready to process the survey? (1 = yes, 2 = no)" << endl;
	cin >> ready;
	if (ready == 1)
	{
		cout << "\nProcessing Survey..." << endl << endl;
		for (int i = 0; i < numStreamers; i++)
		{
			if (people[i].GetPrefStream() == "Netflix")
			{
				netflix++;
			}
			else if (people[i].GetPrefStream() == "Hulu")
			{
				hulu++;
			}
			else if (people[i].GetPrefStream() == "Disney+")
			{
				disney++;
			}

			hrsStrem = people[i].GetHrsNonGm() + hrsStrem;
			totAgeS = people[i].GetAge() + totAgeS;
		}

		for (int b = 0; b < numGamers; b++)
		{
			if (people2[b].GetPrefGameDev() == "Xbox")
			{
				xbox++;
			}
			else if (people2[b].GetPrefGameDev() == "Playstation")
			{
				playstation++;
			}
			else if (people2[b].GetPrefGameDev() == "Switch")
			{
				nSwitch++;
			}

			hrsGam = people2[b].GetHrsGame() + hrsGam;
			totAgeG = people2[b].GetAge() + totAgeG;
		}

		avgStrem = hrsStrem / numStreamers;
		avgGam = hrsGam / numGamers;
		avgAgeS = totAgeS / numStreamers;
		avgAgeG = totAgeG / numGamers;

		if (netflix > hulu && netflix > disney)
		{
			favMode = "Netflix";
		}
		else if (hulu > netflix && hulu > disney)
		{
			favMode = "Hulu";
		}
		else if (disney > netflix && disney > hulu)
		{
			favMode = "Disney+";
		}

		if (xbox > playstation && xbox > nSwitch)
		{
			prefGdevice = "Xbox";
		}
		else if (playstation > xbox && playstation > nSwitch)
		{
			prefGdevice = "Playstation";
		}
		else if (nSwitch > xbox && nSwitch > playstation)
		{
			prefGdevice = "Switch";
		}
	}

	cout << "\nNumber of non gamers: " << numStreamers << endl;
	cout << "Average age: " << avgAgeS << endl;
	cout << "Prefered streaming service: " << favMode << endl;
	cout << "Average hours spent streaming: " << avgStrem << endl << endl;

	cout << "\nNumber of gamers: " << numGamers << endl;
	cout << "Average age: " << avgAgeG << endl;
	cout << "Prefered game device: " << prefGdevice << endl;
	cout << "Average hours spent streaming: " << avgGam << endl << endl;

	return 0;
}