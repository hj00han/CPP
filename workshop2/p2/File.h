#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
#define POSTALCODE_LENGTH 3
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	bool read(char postalCode[]);
	bool read(int& population);
}
#endif // !SDDS_FILE_H_
