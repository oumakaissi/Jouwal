#pragma once
#include "DbConnector.h"


// ActivityDelete dialog

class ActivityDelete : public CDialogEx
{
	DECLARE_DYNAMIC(ActivityDelete)

public:
	ActivityDelete(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ActivityDelete();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ACTIVITY_DELETE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg
		BOOL OnInitDialog();
	BOOL OnEraseBkgnd(CDC* pDC);
	void OnBnClickedActivityDeleteButton();
	CString activityNumberValue;
	CMFCButton deleteButton;
	CMFCButton cancelButton;
	DbConnector* db;
	CRecordset* recset;
};
