#pragma once
#include<string>
#include<iostream>
#include<vector>
#include<fstream>

using namespace std;


class Disk
{
	string data;
	unsigned int data_size;
	unsigned int disk_size;
	bool readable= false;
public:
	Disk();
	Disk(unsigned int disk_s) { disk_size = disk_s; }
	Disk(string& d, unsigned int data_S) { data = d; data_size = data_S; }
	
	string get_data();
	void set_data(string& dat);
	unsigned int get_disk_size();
	unsigned int get_hash();
	bool is_open();
	void set_readable(bool readab);
	
};
string Disk::get_data()
{
	return data;
}
inline void Disk::set_data(string & dat)
{
	data = dat;
}

inline unsigned int Disk::get_disk_size()
{
	return disk_size;
}

inline unsigned int Disk::get_hash()
{
	hash<string> h;
	int t = h(data);
	return t;
}

inline bool Disk::is_open()
{
	return readable;
}

inline void Disk::set_readable(bool readab)
{
	readable = readab;
}


class DVD_Drive
{
	Disk* disk=nullptr;
public:
	DVD_Drive() {};
	bool open(Disk * d);
	void read();
	bool write(string & data);

};
bool DVD_Drive::open(Disk * d)
{	
	int t = 0;
	if (t)
	{
		d->set_readable(true);
		disk = d;
		cout << "Disk is open!" << endl;
		return true;
	}
	else
	{
		d->set_readable(false);
		cout << "Disk is not open!" << endl;
		return false;
	}
	 
}

class DVD_Reader {
public:
	void read(Disk* d);
};

void DVD_Reader::read(Disk * d)
{
	string data_From;
	fstream in("hash.txt");
	if (in.is_open()) {
		in >> data_From;
	}
	in.close();
	cout << "Данные: " << data_From << endl;
	//cout << d->get_data() << endl;

}
inline void DVD_Drive::read()
{
	if (disk) {
		if (disk->is_open()) {
			DVD_Reader* readd = new DVD_Reader();
			readd->read(disk);
		}
		else cout << "чтение не возможно так как диск не открыт" << endl;
	}
	else cout << "отсутствует диск!" << endl;
}

class DVD_Write
{
public:
	bool write(Disk* disk, string& data, int unsigned & data_size);
};

bool DVD_Write::write(Disk * disk, string & data, int unsigned & shash)
{
	if (disk) {
		if (disk->is_open()) {
			disk->set_data(data);
			ofstream out;
			out.open("hash.txt");
			if (out.is_open()) {
				out << data;
				cout << "Запись сделана на диск" << endl;
			}
			out.close();

			string data_From;
			fstream in("hash.txt");
			if (in.is_open()) {
				in >> data_From;
			}

			in.close();
			hash<string> h;
			int hash_from_disk = h(data_From);
			if (hash_from_disk == disk->get_hash()) {
				cout << "данные не поврежденны!" << endl;
			}
			return true;
		}

		
	}
	else
	{
		cout << "невозможно записать так как диск закрыт!" << endl;
		return false;
	}

}
inline bool DVD_Drive::write(string & data)
{
	hash<string> h;
	unsigned int hash = h(data);
	DVD_Write * writee = new DVD_Write;
	
	if (writee->write(disk, data, hash))
		return true;
	else return false;
	
}



