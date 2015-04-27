#include "Reader.h"
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;

struct comma_is_space : std::ctype<char> {
	comma_is_space() : std::ctype<char>(get_table()) {}
	static mask const* get_table()
	{
		static mask rc[table_size];
		rc[','] = std::ctype_base::space;
		rc['\n'] = std::ctype_base::space;
		return &rc[0];
	}
};

Reader::Reader(const string& filename) :filename(filename), col(1), row(0), fs(new fstream(filename, fstream::in)) {
	// initial the columns
	char line[5120];
	fs->getline(line, 5120, '\n');
	for (int i = 0; '\0' != line[i]; ++i) { if (line[i] == ',') col += 1; }

	col -= 1;

	// initial the lineData
	this->data = new double*[MAX_ROW];
	for (int i = 0; i < MAX_ROW; i++) {
		data[i] = new double[col];
	}
}


Reader::~Reader() {
	for (int i = 0; i < MAX_ROW; i++) {
		delete[]data[i];
	}
	delete[]data;
	delete fs;
}

int Reader::getCol() {
	return this->col;
}

int Reader::getRow() {
	return this->row;
}

double** Reader::process() {
	printf("Reader: file \"%s\" started.\n", filename.c_str());
	clock_t stime = clock();
	char line[5120];
	int count = 0;
	while (!fs->eof()) {
		fs->getline(line, 5120, '\n');
		string str(line);
		stringstream ss;
		ss.imbue(locale(ss.getloc(), new comma_is_space));
		ss << str;

		int id;
		ss >> id;

		for (int i = 0; i < col; i++) {
			ss >> data[count][i];
		}

		++count;
		if (count >= MAX_ROW)
			break;
	}
	this->row = count;

	clock_t etime = clock();
	printf("Reader: \"%s\" finished. (%f seconds)\n", filename.c_str(), (double)(etime - stime) / (clock_t)1000);
	printf("Reader: %d rows affected.\n\n", count);
	return data;
}

bool Reader::eof() {
	return fs->eof();
}