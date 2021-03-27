#pragma once
#include "DbConnector.h"
#include <afxdb.h>


// ActivityEdit dialog

class ActivityEdit : public CDialogEx
{
	DECLARE_DYNAMIC(ActivityEdit)

public:
	ActivityEdit(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ActivityEdit();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EDIT_ACTIVITY_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg
		HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	BOOL OnInitDialog();
	BOOL OnEraseBkgnd(CDC* pDC);
	void OnBnClickedEditActivityButton();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeActivityNumberEditField();
	void getActivity();
	void retrieveData(CString q);
	CString activityNumberValue;
	CString activityDesignationValue;
	DbConnector* db;
	CRecordset* recset;
	CEdit activityNumberFieldControll;
	CEdit activityDesignationFieldControll;
	CMFCButton editButton;
	CMFCButton cancelButton;
};