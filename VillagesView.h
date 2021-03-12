#pragma once
#include "DbConnector.h"
#include <afxdb.h>


// VillagesView dialog

class VillagesView : public CDialogEx
{
	DECLARE_DYNAMIC(VillagesView)

public:
	VillagesView(CWnd* pParent = nullptr);   // standard constructor
	virtual ~VillagesView();

	BOOL OnInitDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Villages_VIEW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	DbConnector* db;
	CRecordset* recset;
	CMFCButton searchButton;
	CString villageNumberValue;
	CMFCButton refreshButton;
	CListCtrl villagesList;
	CMFCButton addVillageButton;
	CMFCButton editVillageButton;
	CMFCButton addActivityButton;
	CMFCButton editActivityButton;
	CMFCButton removeActivityButton;
	CMFCButton deleteOneButton;
	CMFCButton deleteAllButton;
	afx_msg
		BOOL OnEraseBkgnd(CDC* pDC);
	void retrieveData(CString q);
	void onSearch();
	void OnBnClickedAddVillage();
	afx_msg void OnBnClickedEditVillage();
	afx_msg void OnBnClickedAddActivityToVillage();
	afx_msg void OnBnClickedEditActivityVillage();
	afx_msg void OnBnClickedRemoveActivity();
	afx_msg void OnBnClickedDeleteOneVillage();
	afx_msg void OnBnClickedDeleteAllVillages();
	afx_msg void OnEnChangeSearchVillageField();
	afx_msg void OnBnClickedSearchVillagesButton();
	afx_msg void OnBnClickedRefresh();
	CString countryNumberValue;
	afx_msg void OnEnChangeVillagePays();
};
