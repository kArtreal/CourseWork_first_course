#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;
void Crypt()
{
	srand(time(NULL));
	char pass[65];
	for (int i = 0; i < 64; ++i) {
		switch (rand() % 3) {
		case 0:
			pass[i] = rand() % 10 + '0';
			break;
		case 1:
			pass[i] = rand() % 26 + 'A';
			break;
		case 2:
			pass[i] = rand() % 26 + 'a';
		}
	}
	pass[64] = '\0';
	string command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -salt -in DataBase.bin -out DataBase.bin.enc -pass pass:";
	command += pass;
	system(command.c_str());
	if (remove("DataBase.bin") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
	ofstream file;
	file.open("key.txt", ios::binary);
	file.write(pass, 64);
	file.close();
	command = "openssl\\bin\\openssl.exe rsautl -encrypt -inkey rsa.public -pubin -in key.txt -out key.txt.enc";
	system(command.c_str());
	if (remove("key.txt") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
	system("cls");
}
void Decrypt()
{
	string command = "openssl\\bin\\openssl.exe rsautl -decrypt -inkey rsa.private -in key.txt.enc -out key.txt";
	system(command.c_str());
	if (remove("key.txt.enc") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
	char pass[65];
	ifstream file;
	file.open("key.txt", ios::binary);
	file.read(pass, 64);
	file.close();
	pass[64] = '\0';
	if (remove("key.txt") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
	command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -d -in DataBase.bin.enc -out DataBase.bin -pass pass:";
	command += pass;
	
	system(command.c_str());
	if (remove("DataBase.bin.enc") != 0) {
		cout << "[ERROR] - deleting file" << endl;
	}
	system("cls");
}

