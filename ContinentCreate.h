#pragma once


// ContinentCreate dialog

class ContinentCreate : public CDialogEx
{
	DECLARE_DYNAMIC(ContinentCreate)

public:
	ContinentCreate(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ContinentCreate();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Continent_Create };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

	BOOL OnEraseBkgnd(CDC* pDC);

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedActivityCreate();
	afx_msg void OnBnClickedActivityCancel();
	CString nomValue;
};
