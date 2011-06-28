#ifndef _DTIATLASFIBERANALYZERGUIWINDOW_H_
#define _DTIATLASFIBERANALYZERGUIWINDOW_H_


//QT librairies
#include <QFileDialog>
#include <QScrollArea>
#include <QScrollBar>
#include <QMessageBox>
#include <QInputDialog>
#include <QListWidgetItem>
#include <QBrush>
#include <QTableWidgetItem>
#include <QString>
#include <QList>

/* itksys */
#include <itksys/Process.h>
#include <itksys/SystemTools.hxx>
#include <itksys/Directory.hxx>

//Specific librairies
#include "ui_DTIAtlasFiberAnalyzerguiwindow.h"
#include "CSVClass.h"

typedef vector<std::string> vstring;

class DTIAtlasFiberAnalyzerguiwindow : public QMainWindow, public Ui::MainWindow 
{
	Q_OBJECT
	public:
		DTIAtlasFiberAnalyzerguiwindow(bool debug=false, QWidget * parent = 0, Qt::WFlags f = 0 );
		
		
	private slots:
		void NextStep();
		void PreviousStep();
		void BrowserCSVFilename();
		void EnteronCSVFilename();
		void applyNewCSV();
		void DeleteCSV();
		void BrotherSaveCSV();
		void AddC();
		void DeleteC();
		void AddR();
		void DeleteR();
		void SetDataColumn();
		void SetDeformationColumn();
		void SetNameColumn();
		void SetCurrentRow();
		void SetCurrentColumn();
		void ChangeHeader(int col);
		void CellAsBrowser(int row,int col);
		void BrowserIndividualData(int row);
		void BrowserDeformationField(int row);
		void BrowserAtlasFiberFolder();
		void EnteronAtlasFiberFolder();
		void AddFiberInList();
		void SelectAllFiber();
		void RemoveFiberInList();
		void RemoveAllFiber();
		void BrowserOutputFolder();
		void EnterOutputFolder();
		void Computefiberprocess();
		void Computedti_tract_stat();
		void saveparamaction();
		void openparam();
		
	protected:
		QWidget* stepwidget(int numberstep);
		void FillCSVFileOnQTable();
		std::string HeaderLine();
		std::string LineItemsToString(int row);
		void PutDataonQTable(int row, int column, std::string word);
		void AddColumnWithHearderName(std::string header);
		void setParam();
		void clearCSV();
		void FillFiberFrame();
		void ColorCol(int type);
		void DecolorCol(int type);
		void paintForeGround(int R,int G,int B,int col,int type);
		void SaveCSV();
		void AutoSaveCSV();
		void AddDataFromTableToCSV();
		void checkBoxProfile(std::string parameters);
		
	private:
		/* debug */
		bool m_debug;
		
		/* CSVClass item */
		CSVClass* m_CSV;
		bool m_CSVcreated;
		
		/* Input */
		vstring m_Fibername;
		vstring m_Fibersplane;
		vstring m_FiberSelectedname;
		vstring m_FibersplaneSelected;
		std::string m_csvfilename;
		std::string m_OutputFolder;
		std::string m_AtlasFiberDir;
		std::string m_parameters;
		int m_DataCol;
		int m_DeformationCol;
		int m_NameCol;
		int m_NumberOfParameters;
		
		/* step */
		int m_numberstep;
		int m_laststep;
		bool m_nextStep;
		
		/* current Row/Column */
		int m_currentRow;
		int m_currentColumn;
		int m_transposeColRow; //just for the gathering spreadsheet
};

#endif
