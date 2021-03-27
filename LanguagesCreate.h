#pragma once


// LanguagesCreate dialog

class LanguagesCreate : public CDialogEx
{
	DECLARE_DYNAMIC(LanguagesCreate)

public:
	LanguagesCreate(CWnd* pParent = nullptr);   // standard constructor
	virtual ~LanguagesCreate();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Language_Create };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	BOOL OnEraseBkgnd(CDC* pDC);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCreate();
	afx_msg void OnBnClickedActivityCancel();
	CString designationField;
};
