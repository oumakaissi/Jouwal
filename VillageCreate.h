#pragma once


// VillageCreate dialog

class VillageCreate : public CDialogEx
{
	DECLARE_DYNAMIC(VillageCreate)

public:
	VillageCreate(CWnd* pParent = nullptr);   // standard constructor
	virtual ~VillageCreate();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VILLAGE_CREATE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg
		HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	void OnBnClickedCreate();
	afx_msg void OnBnClickedCancel();
	CString villageNameValue;
	CString countryNumberValue;
};
