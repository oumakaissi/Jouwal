#pragma once
#include "DbConnector.h"


// LanguagesView dialog

class LanguagesView : public CDialogEx
{
	DECLARE_DYNAMIC(LanguagesView)

public:
	LanguagesView(CWnd* pParent = nullptr);   // standard constructor
	virtual ~LanguagesView();
	BOOL OnInitDialog();
	void retrieveData(CString q);

	void OnSearchChange();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LANGUAGES_View };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	afx_msg
		HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	BOOL OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()
	DbConnector* db;
	CRecordset* recset;
public:
	CMFCButton searchButton;
	CMFCButton addButton;
	CMFCButton editButton;
	CMFCButton deleteOneButton;
	CMFCButton deleteAllButton;
	CMFCButton refreshButton;
	CListCtrl languagesList;
	afx_msg void OnBnClickedDeleteAll();
	afx_msg void OnBnClickedDeleteOne();
	afx_msg void OnBnClickedEdit();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedSearch();
	afx_msg void OnBnClickedRefresh();
	afx_msg void OnEnChangeSearchlanguagesField();
	afx_msg void OnEnChangeVillageNumberFieldActivity();
	CString languageNumberValue;
	CString villageNumberValue;
};
