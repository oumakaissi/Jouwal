#pragma once
#include "DbConnector.h"


// ContinentsView dialog

class ContinentsView : public CDialogEx
{
	DECLARE_DYNAMIC(ContinentsView)

public:
	ContinentsView(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ContinentsView();

	BOOL OnInitDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Continent_View };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString contientNumberValue;
	CListCtrl continentsList;
	DbConnector* db;
	CRecordset* recset;
	afx_msg void OnEnChangeSearchContinentField();
	afx_msg void OnBnClickedSearchContienentsButton();
	afx_msg void OnBnClickedRefresh();
	afx_msg void OnBnClickedAddContinent();
	afx_msg void OnBnClickedEditContinent();
	afx_msg void OnBnClickedDeleteOneActivitie();
	afx_msg void OnBnClickedDeleteAllActivities();
	void OnSearchChange();
	void retrieveData(CString q);
	HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	BOOL OnEraseBkgnd(CDC* pDC);
	CMFCButton searchButton;
	CMFCButton refreshButton;
	CMFCButton addButton;
	CMFCButton editButton;
	CMFCButton deleteOneButton;
	CMFCButton deleteAllButton;
};
