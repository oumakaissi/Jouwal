#pragma once

#include "odbcinst.h"
#include "afxdb.h"

class DbConnector
{
private:
	static DbConnector *myDB;
	CDatabase database;
	CString sDriver;
	CString sFile;
	CString sDsn;

	DbConnector();
	DbConnector(const DbConnector& ) = delete;
	~DbConnector();
public:
	void operator=(const DbConnector&) = delete;
	static DbConnector* createDb();

	void setSDriver(CString s);
	void setSFile(CString s);
	void setSDsn(CString s);
	CString getSDriver();
	CString getSFile();
	CString getSDsn();
	void executeQuery(CString q);
	CRecordset *retrieveQuery(CString q);

};

