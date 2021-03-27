#pragma once


// VillageDelete dialog

class VillageDelete : public CDialogEx
{
	DECLARE_DYNAMIC(VillageDelete)

public:
	VillageDelete(CWnd* pParent = nullptr);   // standard constructor
	virtual ~VillageDelete();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VILLAGE_DELETE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg
		HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	void OnBnClickedVillageDelete();
	afx_msg void OnBnClickedCancel();
	CMFCButton deleteButton;
	CMFCButton cancelButton;
	CString villageNumberValue;
};
