#include <string>

using namespace std;

#ifndef CSV_READER
#define CSV_READER

#define MAX_ROW 30000

class Reader {
public:
	Reader(const string& filename);
	~Reader();
	int getCol();
	int getRow();
	double** getContent();
	double** process();
	bool eof();
private:
	double **data;
	int row, col;
	string filename;
	fstream* fs;
};


#endif