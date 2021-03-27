#pragma once
#include "DbConnector.h"


// CountriesView dialog

class CountriesView : public CDialogEx
{
	DECLARE_DYNAMIC(CountriesView)

public:
	CountriesView(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CountriesView();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Countries_View };
#endif

protected:
	BOOL OnInitDialog();
	void retrieveData(CString q);
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	DbConnector* db;
	CRecordset* recset;
	CMFCButton searchButton;
	CMFCButton addButton;
	CMFCButton editButton;
	CMFCButton deleteOneButton;
	CMFCButton deleteAllButton;
	CMFCButton refreshButton;
	CEdit countriesFieldControl;
	CString countiresFieldValue;
	afx_msg
		HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	BOOL OnEraseBkgnd(CDC* pDC);
	void OnEnChangeSearchCountriesField();
	afx_msg void OnBnClickedSearchCountriesButton();
	afx_msg void OnBnClickedAddCountry();
	afx_msg void OnBnClickedEditCountry();
	afx_msg void OnBnClickedDeleteOneActivitie();
	afx_msg void OnBnClickedDeleteAllActivities();
	afx_msg void OnBnClickedRefresh();
	void OnSearchChange();
	CListCtrl countriesList;
	afx_msg void OnEnChangeSearchCountries();
	CString continentNumberValue;
};
