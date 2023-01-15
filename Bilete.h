#pragma once
#include"LocatieBilete.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#pragma warning(disable:4996)


class Bilete
{
private:
	const int idBilet;
	static int contorBilet;
	LocatieBilete* locatieBilet;
	int* bilet;
	enum getdate {
		getNrCategorii,
		getNrLocuriCategorie,
		getCategorii,
		getNrRanduri,
		getNrLocuri
	};


public:
	Bilete():idBilet(contorBilet++)
	{
		this->locatieBilet = new LocatieBilete();
		this->bilet = new int[1];
		this->bilet[0] = 0;
	}
	Bilete(LocatieBilete* locatieBilet, int* bilet) :idBilet(contorBilet++)
	{
		this->locatieBilet = new LocatieBilete(*locatieBilet);
		this->bilet = new int[getNrLocuriCategorie];
		for (int i = 0; i < getNrLocuriCategorie; i++)
		{
			this->bilet[i] = bilet[i];
		}
				
	}
	Bilete(const Bilete& b) :idBilet(contorBilet++)
	{
		this->locatieBilet = new LocatieBilete(*b.locatieBilet);
		this->bilet = new int[getNrLocuriCategorie];
		for (int i = 0; i < getNrLocuriCategorie; i++)
		{
			this->bilet[i] = b.bilet[i];
		}
	}
	~Bilete()
	{
		if (this->locatieBilet != NULL)
		{
			delete this->locatieBilet;
		}
		if (this->bilet != NULL)
		{
			delete[] this->bilet;
		}
	}

	Bilete& operator=(const Bilete& b)
	{
		if (this->locatieBilet != NULL)
		{
			delete this->locatieBilet;
		}
		if (this->bilet != NULL)
		{
			delete[] this->bilet;
		}
		this->locatieBilet = new LocatieBilete(*b.locatieBilet);
		this->bilet = new int[getNrLocuriCategorie];
		for (int i = 0; i < getNrLocuriCategorie; i++)
		{
			this->bilet[i] = b.bilet[i];
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, Bilete& b)
	{
		out << b.locatieBilet << endl;
		out << "Numarul de locuri: ";
		for (int i = 0; i < getNrLocuriCategorie; i++)
		{
			out << b.bilet[i] << " ";
		}
		out << endl;
		return out;
	}
	void scriereBinar()
	{
		ofstream f("Bilete.bin", ios::binary | ios::app);
		f.write((char*)this, sizeof(Bilete));
		f.close();
	}
	void citireBinar()
	{
		ifstream f("Bilete.bin", ios::binary);
		if (f.is_open())
		{
			Bilete b;
			while (f.read((char*)&b, sizeof(Bilete)))
			{
				cout << b;
			}
		}
		f.close();
	}
	
};
int Bilete::contorBilet = 0;
