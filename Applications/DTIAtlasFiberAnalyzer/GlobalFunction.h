#ifndef _GLOBALFUNCTION_H_
#define _GLOBALFUNCTION_H_

/* Specific librairies */
#include "DTIAtlasFiberAnalyzerguiwindow.h"

/* Functions defined in, exported from Globalfunc.cxx */
/* Call when there is nogui */
bool CommandLine(std::string CSVFilename, std::string parametersfile, bool debug);
		 
/* Create a Directory */
bool CreateDirectoryForData(std::string outputfolder, std::string name);

/* Compute fiber process : take the parameters and call the software for every fiber/data */
bool Applyfiberprocess(CSVClass* CSV, std::string pathFiberProcess, std::string AtlasFiberDir, 
		       std::string OutputFolder, int DataCol, int DefCol, int NameCol, vstring fibers, 
		       std::string parameters, bool transposeColRow, bool nogui, QWidget* parent=NULL);

/* Check if the header existed */
int HeaderExisted(CSVClass* CSV, std::string header);
/* Check if there is a data */
bool DataExistedInFiberColumn(CSVClass* CSV, int row, int column, std::string outputname);
/* Check if the file existed */
bool FileExisted(std::string Filename);
/* Give the name of the case */
std::string NameOfCase(CSVClass* CSV, int row, int NameCol, int DataCol);
/* Give the choice of the user about skip the computation */
vector<bool> MessageExistedFile(bool nogui, std::string nameoffile, QWidget*parent=NULL);

/* Call fiberprocess */
int CallFiberProcess(std::string pathFiberProcess, std::string AtlasFolder, std::string outputname, 
		     std::string Data, std::string DeformationField, std::string Fiber, std::string nameofcase);

/* Read the files in the folder and keep the one with the extension ".vtk" */
void ReadFiberNameInAtlasDirectory(vstring &fibers, vstring &fibersplane, std::string AtlasFiberDir);

/* Take off the extension of the filename */
std::string takeoffExtension(std::string filename);

/* Take off the path of the filename */
std::string takeoffPath(std::string filename);

/* Keep just the extension of the filename */
std::string ExtensionofFile(std::string filename);

/* Compute dti_tract_stat : take the parameters and call the software for every fiber selected with its plane */
bool Applydti_tract_stat(CSVClass* CSV, std::string pathdti_tract_stat, std::string AtlasDirectory,
			 std::string OutputFolder, vstring fibers, vstring fibersplane, std::string parameters, 
			 int DataCol, int DefCol, int NameCol, bool transposeColRow,bool nogui, QWidget *parent=NULL);

/* Call dti_tract_stat */
int Calldti_tract_stat(std::string pathdti_tract_stat, std::string AtlasDirectory, std::string Input_fiber_file,
		       std::string Output_fiber_file, std::string plane, std::string parameter);

/* Gather the fiber profile in different output file */
void GatheringFiberProfile(CSVClass* CSV, std::string OutputFolder, int NumberOfParameters, int DataCol, int NameCol, 
			   bool transposeColRow);


/* Read the fiber profile information from .fvp file */
bool ReadProfileInformation(std::string fibername, std::string filename, v2string &Profiles);

/* Write Profile information in an csv file */
void WriteProfile(CSVClass* CSV, std::string filename,vector< v2string > FiberProfiles,int DataCol,int NameCol,
		  int ParamCol, bool transposeColRow);

/* Write the parameters in a file */
void saveparam(std::string filename,std::string CSVFilename, int DataCol, int DefCol, int NameCol,
	       std::string OutputFolder, std::string AtlasFiberFolder, vstring FiberSelectedname, 
	       std::string parameters, bool transposeColRow);

/* Read the parameters from a file */
bool ReadParametersFromFile(std::string filename, std::string &CSVfilename, std::string &AtlasFiberDir,
			    std::string &OutputFolder, std::string &parameters, int &DataCol, int &DefCol,
			    int &NameCol, vstring &SelectedFibers, bool &transposeColRow);

/* Calcul the number of profiles parameters : FA,MD ... */
int CalculNumberOfProfileParam(std::string parameters);

/* look for a plane associated to fiber */
int PlaneAssociatedToFiber(std::string fibername,int type, vstring fibersplane, vstring Selectedfibersplane);

#endif
