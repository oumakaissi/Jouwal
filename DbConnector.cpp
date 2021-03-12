#include "pch.h"
#include "DbConnector.h"

DbConnector* DbConnector::myDB = nullptr;

DbConnector* DbConnector::createDb() {
	if (myDB == nullptr) {
		myDB = new DbConnector();
	}
	return myDB;
}

DbConnector::DbConnector() {
	sDriver = L"Microsoft Access Driver (*.mdb)";
	sFile = L"C:\\Users\\tahab\\Documents\\Jouwal2.mdb";
	sDsn.Format(L"ODBC;DRIVER={%s};DSN='';DBQ=%s", sDriver, sFile);
	TRY{
		database.Open(NULL,false,false,sDsn);

	}CATCH(CDBException, e) {
		// If a database exception occured, show error msg
		AfxMessageBox(L"Database error: " + e->m_strError);
	}
}
}
recset = new CRecordset(&database);
}
DbConnector::~DbConnector() {
	delete myDB;
	myDB = nullptr;
}

void DbConnector::setSDriver(CString s) {
	sDriver = s;
}
void DbConnector::setSFile(CString s) {
	sFile = s;
}
void DbConnector::setSDsn(CString s) {
	sDsn = s;
}
CString DbConnector::getSDriver() {
	return sDriver;
}
CString DbConnector::getSFile() {
	return sFile;
}
CString DbConnector::getSDsn() {
	return sDsn;
}
void DbConnector::executeQuery(CString q) {
	database.ExecuteSQL(q);
}
CRecordset* DbConnector::retrieveQuery(CString q) {

	recset->Open(AFX_DB_USE_DEFAULT_TYPE, q, NULL);
	return recset;
}