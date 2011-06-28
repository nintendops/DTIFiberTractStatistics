#ifndef _CSVCLASS_H_
#define _CSVCLASS_H_

//Standard librairies
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <fstream.h>
#include <vector.h>

typedef vector<std::string> vstring;
typedef vector<vstring> v2string;

class CSVClass
{
	public:
		CSVClass(std::string filename, bool debug=false);
		bool loadCSVFile(std::string csvfilename);
		void LineInVector(std::string line);
		void SaveFile(std::string filename);
		void clearData();
		vector< vstring >* getData();
		void AddData(std::string StringColumn, int row, int column);
		void SetFilename(std::string filename);
		std::string getFilename();
		unsigned int getRowSize();
		unsigned int getColSize(int row);
		
	private:
		/* debug */
		bool m_debug;
		
		/*vector with data */
		vector< vstring > m_data;
		
		/* Input */
		std::string m_csvfilename;
};

#endif
