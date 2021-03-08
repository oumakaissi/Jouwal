#pragma once
#include "DbConnector.h"


// ActivitiesView dialog

class ActivitiesView : public CDialogEx
{
	DECLARE_DYNAMIC(ActivitiesView)

public:
	ActivitiesView(CWnd* pParent = nullptr);   // standard constructor
	BOOL OnInitDialog();
	void retrieveData(CString q);
	void retrieveData();
	virtual ~ActivitiesView();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Activities_View };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	DECLARE_MESSAGE_MAP()
public:
	DbConnector *db;
	CRecordset *recset;
	afx_msg void OnBnClickedAddActivitie();
	afx_msg void OnBnClickedEditActivitie();
	afx_msg void OnBnClickedDeleteOneActivitie();
	afx_msg void OnBnClickedDeleteAllActivities();
	afx_msg void OnBnClickedSearchActivitiesButton();
	CString activitySearchFieldValue;
	CListCtrl activitiesList;
	CString no_village;
	CRect rc;

	CEdit activityNumberEditBox;
	CEdit villageNumberEditBox;
	CStatic activityNumberStaticText;
	CStatic activityVillageNumberStaticText;
	CMFCButton searchButton;
	CMFCButton addButton;
	CMFCButton editButton;
	CMFCButton deleteOneButton;
	CMFCButton deleteAllButton;
};
