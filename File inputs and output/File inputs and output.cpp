// File inputs and output.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

// in this main we create a file and output to it and read it

int main()
{
	std::string fileName;
	std::string textToStore;
	std::string textToRead;
	std::ofstream fileWriter;
	std::ifstream fileReader;

	cout << "Enter file name to create file: ";
	getline(cin, fileName);
	
	
	fileWriter.open(fileName, std::ofstream::app);
	
	auto thePosition = fileWriter.tellp();	//It says zero because until after it writes, its position is defaulted to 0 i guess
	cout << "position of pointer to output to file: " << thePosition << endl;
	cout << "Enter text to write to the file." << endl;

	while (!cin.eof())	// type ctrl-Z to insert an eof character on windows to end the loop. Mac and linux use ctrl-D
	{
		getline(cin, textToStore);
		fileWriter << textToStore;
		if (!cin.eof())		//This is to avoid an extra end line after eof is entered so we don't have a white line between existing data and new data that we enter the 
		{						// next time the program is run.
			fileWriter << endl;
		}
	}
	
	fileWriter.close();
	cin.clear();	// To clear the eof flag from the buffer and not go through the pause at the end

	fileReader.open(fileName);

	cout << endl << "Output: " << endl;

	while (getline(fileReader, textToRead))	
	{
		cout << textToRead << endl;
	}

	fileReader.close();


	
	
	char pause;
	cout << endl << endl << "type anything to quit.";
	cin >> pause;

    return 0;
}


//This main just outputs file text
/*
int main()
{
	std::ifstream fileReader2;
	fileReader2.open("input output test2.txt");

	std::string textToRead2;

	while (fileReader2 >> textToRead2)
	{
		cout << textToRead2 << " ";
	}

	fileReader2.close();



	char pause;
	cout << endl << endl << "type anything to quit.";
	cin >> pause;

	return 0;
}
*/
