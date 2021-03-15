#pragma once


// CountryCreate dialog

class CountryCreate : public CDialogEx
{
	DECLARE_DYNAMIC(CountryCreate)

public:
	CountryCreate(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CountryCreate();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Country_Create };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString countryNomValue;
	afx_msg
		BOOL OnEraseBkgnd(CDC* pDC);
	void OnBnClickedActivityCreate();
	afx_msg void OnBnClickedActivityCancel();
	CString continentNumberFieldValue;
};
