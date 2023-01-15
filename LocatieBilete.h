#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#pragma warning(disable:4996)


class LocatieBilete
{
private:
	int NrCategorii;
	int* Categorii;
	int* nrRanduri;
	int* nrlocuri;
	int* pret;
	int* nrLocuriCategorie;
	
public:
	LocatieBilete()
	{
		this->NrCategorii = 0;
		this->Categorii = NULL;
		this->nrRanduri = NULL;
		this->nrlocuri = NULL;
		this->pret = NULL;
		this->nrLocuriCategorie = NULL;
	}
	LocatieBilete(int nrCategorii, int* categorii, int* nrRanduri, int* nrlocuri, int* pret, int*nrLocuriCategorie)
	{
	
		this->NrCategorii = nrCategorii;
		this->Categorii = new int[nrCategorii];
		this->nrRanduri = new int[nrCategorii];
		this->nrlocuri = new int[nrCategorii];
		this->pret = new int[nrCategorii];
		this->nrLocuriCategorie = new int[nrCategorii];
		for (int i = 0; i < nrCategorii; i++)
		{
			this->Categorii[i] = categorii[i];
			this->nrRanduri[i] = nrRanduri[i];
			this->nrlocuri[i] = nrlocuri[i];
			this->pret[i] = pret[i];
			this->nrLocuriCategorie[i] = this->nrRanduri[i] * this->nrlocuri[i];
		}
		
	
	}
	LocatieBilete(const LocatieBilete& l)
	{
		this->NrCategorii = l.NrCategorii;
		this->Categorii = new int[l.NrCategorii];
		this->nrRanduri = new int[l.NrCategorii];
		this->nrlocuri = new int[l.NrCategorii];
		this->pret = new int[l.NrCategorii];
		this->nrLocuriCategorie = new int[l.NrCategorii];
		for (int i = 0; i < l.NrCategorii; i++)
		{
			this->Categorii[i] = l.Categorii[i];
			this->nrRanduri[i] = l.nrRanduri[i];
			this->nrlocuri[i] = l.nrlocuri[i];
			this->pret[i] = l.pret[i];
			this->nrLocuriCategorie[i] = l.nrLocuriCategorie[i];
		}
		
	}
	~LocatieBilete()
	{
		if (this->Categorii != NULL)
		{
			delete[] this->Categorii;
		}
		if (this->nrRanduri != NULL)
		{
			delete[] this->nrRanduri;
		}
		if (this->nrlocuri != NULL)
		{
			delete[] this->nrlocuri;
		}
		if (this->pret != NULL)
		{
			delete[] this->pret;
		}
		if (this->nrLocuriCategorie != NULL)
		{
			delete[] this->nrLocuriCategorie;
		}
		
	}
	LocatieBilete& operator=(const LocatieBilete& l)
	{
		this->NrCategorii = l.NrCategorii;
		if (this->Categorii != NULL)
		{
			delete[] this->Categorii;
		}
		this->Categorii = new int[l.NrCategorii];
		for (int i = 0; i < l.NrCategorii; i++)
		{
			this->Categorii[i] = l.Categorii[i];
		}
		if (this->nrRanduri != NULL)
		{
			delete[] this->nrRanduri;
		}
		this->nrRanduri = new int[l.NrCategorii];
		for (int i = 0; i < l.NrCategorii; i++)
		{
			this->nrRanduri[i] = l.nrRanduri[i];
		}
		if (this->nrlocuri != NULL)
		{
			delete[] this->nrlocuri;
		}
		this->nrlocuri = new int[l.NrCategorii];
		for (int i = 0; i < l.NrCategorii; i++)
		{
			this->nrlocuri[i] = l.nrlocuri[i];
		}
		this->pret = new int[l.NrCategorii];
		for (int i = 0; i < l.NrCategorii; i++)
		{
			this->pret[i] = l.pret[i];
		}
		if (this->nrLocuriCategorie != NULL)
		{
			delete[] this->nrLocuriCategorie;
		}
		this->nrLocuriCategorie = new int[l.NrCategorii];
		for (int i = 0; i < l.NrCategorii; i++)
		{
			this->nrLocuriCategorie[i] = l.nrLocuriCategorie[i];
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, const LocatieBilete& l)
	{
		out << "Numarul de categorii este: " << l.NrCategorii << endl;
		out << "Categoriile sunt: ";
		for (int i = 0; i < l.NrCategorii; i++)
		{
			out << l.Categorii[i] << " ";
		}
		out << endl;
		out << "Numarul de randuri este: ";
		for (int i = 0; i < l.NrCategorii; i++)
		{
			out << l.nrRanduri[i] << " ";
		}
		out << endl;
		out << "Numarul de locuri este: ";
		for (int i = 0; i < l.NrCategorii; i++)
		{
			out << l.nrlocuri[i] << " ";
		}
		out << endl;
		out << "Pretul este: " << l.pret;
		for (int i = 0; i < l.NrCategorii; i++)
		{
			out << l.pret[i] << " ";
		}
		out << endl;
		out << "Numarul de locuri este: ";
		for (int i = 0; i < l.NrCategorii; i++)
		{
			out << l.nrLocuriCategorie[i] << " ";
		}
		out << endl;
		return out;
	}
	friend istream& operator>>(istream& in, LocatieBilete& l)
	{
		cout << "Numarul de categorii este: ";
		in >> l.NrCategorii;
		if (l.Categorii != NULL)
		{
			delete[] l.Categorii;
		}
		l.Categorii = new int[l.NrCategorii];
		cout << "Categoriile sunt: ";
		for (int i = 0; i < l.NrCategorii; i++)
		{
			in >> l.Categorii[i];
		}
		if (l.nrRanduri != NULL)
		{
			delete[] l.nrRanduri;
		}
		l.nrRanduri = new int[l.NrCategorii];
		cout << "Numarul de randuri este: ";
		for (int i = 0; i < l.NrCategorii; i++)
		{
			in >> l.nrRanduri[i];
		}
		if (l.nrlocuri != NULL)
		{
			delete[] l.nrlocuri;
		}
		l.nrlocuri = new int[l.NrCategorii];
		cout << "Numarul de locuri este: ";
		for (int i = 0; i < l.NrCategorii; i++)
		{
			in >> l.nrlocuri[i];
		}
		l.pret = new int[l.NrCategorii];
		cout << "Pretul este: ";
		for (int i = 0; i < l.NrCategorii; i++)
		{
			in >> l.pret[i];
		}
		if (l.nrLocuriCategorie != NULL)
		{
			delete[] l.nrLocuriCategorie;
		}
		l.nrLocuriCategorie = new int[l.NrCategorii];
		cout << "Numarul de locuri este: ";
	}
	int getNrCategorii()
	{
		return this->NrCategorii;
	}
	int* getCategorii()
	{
		return this->Categorii;
	}
	int* getNrRanduri()
	{
		return this->nrRanduri;
	}
	int* getNrLocuri()
	{
		return this->nrlocuri;
	}
	int* getPret()
	{
		return this->pret;
	}
	int* getNrLocuriCategorie()
	{
		for (int i = 0; i < NrCategorii; i++)
		{
			this->nrLocuriCategorie[i] = this->nrRanduri[i] * this->nrlocuri[i];
		};
	}
	void setNrCategorii(int nrCategorii)
	{
		if (nrCategorii > 0)
		this->NrCategorii = nrCategorii;
	}
	void setCategorii(int* categorii)
	{
		if (categorii != NULL)
		{
			if (this->Categorii != NULL)
			{
				delete[] this->Categorii;
			}
			this->Categorii = new int[this->NrCategorii];
			for (int i = 0; i < this->NrCategorii; i++)
			{
				this->Categorii[i] = categorii[i];
			}
		}
	}
	void setNrRanduri(int* nrRanduri)
	{
		if (nrRanduri != NULL)
		{
			if (this->nrRanduri != NULL)
			{
				delete[] this->nrRanduri;
			}
			this->nrRanduri = new int[this->NrCategorii];
			for (int i = 0; i < this->NrCategorii; i++)
			{
				this->nrRanduri[i] = nrRanduri[i];
			}
		}
	}
	void setNrLocuri(int* nrLocuri)
	{
		if (nrLocuri != NULL)
		{
			if (this->nrlocuri != NULL)
			{
				delete[] this->nrlocuri;
			}
			this->nrlocuri = new int[this->NrCategorii];
			for (int i = 0; i < this->NrCategorii; i++)
			{
				this->nrlocuri[i] = nrLocuri[i];
			}
		}
	}
	void setPret(int* pret)
	{
		if (pret != NULL)
		{
			if (this->pret != NULL)
			{
				delete[] this->pret;
			}
			this->pret = new int[this->NrCategorii];
			for (int i = 0; i < this->NrCategorii; i++)
			{
				this->pret[i] = pret[i];
			}
		}
	}
	void setNrLocuriCategorie(int* nrLocuriCategorie)
	{
		if (nrLocuriCategorie != NULL)
		{
			if (this->nrLocuriCategorie != NULL)
			{
				delete[] this->nrLocuriCategorie;
			}
			this->nrLocuriCategorie = new int[this->NrCategorii];
			for (int i = 0; i < this->NrCategorii; i++)
			{
				this->nrLocuriCategorie[i] = nrLocuriCategorie[i];
			}
		}
	}
	

	void citire()
	{
		cout << "Numarul de categorii este: ";
		cin >> this->NrCategorii;
		if (this->Categorii != NULL)
		{
			delete[] this->Categorii;
		}
		this->Categorii = new int[this->NrCategorii];
		if (this->nrRanduri != NULL)
		{
			delete[] this->nrRanduri;
		}
		this->nrRanduri = new int[this->NrCategorii];
		if (this->nrlocuri != NULL)
		{
			delete[] this->nrlocuri;
		}
		this->nrlocuri = new int[this->NrCategorii];
		if (this->pret != NULL)
		{
			delete[] this->pret;
		}
		this->pret = new int[this->NrCategorii];
		if (this->nrLocuriCategorie != NULL)
		{
			delete[] this->nrLocuriCategorie;
		}
		this->nrLocuriCategorie = new int[this->NrCategorii];
		for (int i = 0; i < this->NrCategorii; i++)
		{	
			cout << "Categoria" << " "<<i + 1 << " se numeste ";
			cin >> this->Categorii[i];
			cout << "Categoria" << " " << i + 1 << " are numarul de randuri: ";
			cin >> this->nrRanduri[i];
			cout << "Categoria" << " " << i + 1 << " are numarul de locuri pe rand ";
			cin >> this->nrlocuri[i];
			cout << "Categoria" << " " << i + 1 << " are pretul/bilet ";
			cin >> this->pret[i];
			
			
		}
		
		
	
	}
	void afisare()
	{
		cout << "Numarul de categorii este: " << this->NrCategorii << endl;
		for (int i = 0; i < this->NrCategorii; i++)
		{
			cout  << "Categoria" << " " << i + 1 << " se numeste ";
			cout << this->Categorii[i] << endl;
			cout << "Categoria" << " " << i + 1 << " are numarul de randuri: ";
			cout << this->nrRanduri[i] << endl;
			cout << "Categoria" << " " << i + 1 << " are numarul de locuri pe rand ";
			cout << this->nrlocuri[i] << endl;
			cout << "Categoria" << " " << i + 1 << " are pretul/bilet " ;
			cout << this->pret[i]<<endl;
			cout << "Categoria" << " " << i + 1 << " are numarul de locuri :";
			this->nrLocuriCategorie[i] = this->nrRanduri[i] * this->nrlocuri[i];
			cout << this->nrLocuriCategorie[i];
			
		}
		cout << endl;
	}
	void scrieBinar()
	{
		ofstream out("Sala.txt", ios::binary);
		out.write((char*)&this->NrCategorii, sizeof(int));
		for (int i = 0; i < this->NrCategorii; i++)
		{
			out.write((char*)&this->Categorii[i], sizeof(int));
		}
		for (int i = 0; i < this->NrCategorii; i++)
		{
			out.write((char*)&this->nrRanduri[i], sizeof(int));
		}
		for (int i = 0; i < this->NrCategorii; i++)
		{
			out.write((char*)&this->nrlocuri[i], sizeof(int));
		}
		for (int i = 0; i < this->NrCategorii; i++)
		{
			out.write((char*)&this->pret[i], sizeof(int));
		}
		out.close();
	}
	void citireBinar()
	{
		ifstream in("Sala.txt", ios::binary);
		in.read((char*)&this->NrCategorii, sizeof(int));
		if (this->Categorii != NULL)
		{
			delete[] this->Categorii;
		}
		this->Categorii = new int[this->NrCategorii];
		if (this->nrRanduri != NULL)
		{
			delete[] this->nrRanduri;
		}
		this->nrRanduri = new int[this->NrCategorii];
		if (this->nrlocuri != NULL)
		{
			delete[] this->nrlocuri;
		}
		this->nrlocuri = new int[this->NrCategorii];
		if (this->pret != NULL)
		{
			delete[] this->pret;
		}
		this->pret = new int[this->NrCategorii];
		for (int i = 0; i < this->NrCategorii; i++)
		{
			in.read((char*)&this->Categorii[i], sizeof(int));
		}
		for (int i = 0; i < this->NrCategorii; i++)
		{
			in.read((char*)&this->nrRanduri[i], sizeof(int));
		}
		for (int i = 0; i < this->NrCategorii; i++)
		{
			in.read((char*)&this->nrlocuri[i], sizeof(int));
		}
		for (int i = 0; i < this->NrCategorii; i++)
		{
			in.read((char*)&this->pret[i], sizeof(int));
		}
		in.close();
	}
};
