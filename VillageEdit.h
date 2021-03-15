#pragma once
#include "DbConnector.h"


// VillageEdit dialog

class VillageEdit : public CDialogEx
{
	DECLARE_DYNAMIC(VillageEdit)

public:
	VillageEdit(CWnd* pParent = nullptr);   // standard constructor
	virtual ~VillageEdit();

	BOOL OnInitDialog();

	void retrieveLanguages(CString q);

	void retrieveVillages(CString q);

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VILLAGE_EDIT };
#endif

protected:
	void retrieveActivities(CString q);
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg
		BOOL OnEraseBkgnd(CDC* pDC);
	void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedMfcbutton4();
	afx_msg void OnBnClickedMfcbutton5();
	afx_msg void OnBnClickedMfcbutton2();
	afx_msg void OnBnClickedMfcbutton3();
	afx_msg void OnBnClickedVillageEditButton();
	afx_msg void OnEnChangeVillageNumberField();
	CString villageNumberValue;
	CString villageNameValue;
	CString countryNumberValue;
	CString activityNumberValue;
	CString activityGratuiteValue;
	CString languageNumberValue;
	CEdit villageActivityNumberEditField;
	CEdit villageActivityGratuiteEditField;
	CEdit villageLanguageNumberEditField;
	CMFCButton addActivityButton;
	CMFCButton removeActivityButton;
	CMFCButton addLanguageButton;
	CMFCButton removeLanguageButton;
	afx_msg void OnBnClickedaddlanguagetovillage();
	afx_msg void OnBnClickedremoveLanguagefromvillage();
	afx_msg void OnBnClickedaddaactivitytovillagebutton();
	afx_msg void OnBnClickedremoveactivityfromvillage();
	CMFCButton editButton;
	CListCtrl languagesList;
	CListCtrl activitiesList;
	CEdit villageNameControl;
	CEdit villageCountryNumberControl;
	CEdit villageNumberControl;
	DbConnector* db;
	CRecordset* recset;

	
};
