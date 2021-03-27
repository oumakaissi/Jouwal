#pragma once


// SettingsView dialog

class SettingsView : public CDialogEx
{
	DECLARE_DYNAMIC(SettingsView)

public:
	SettingsView(CWnd* pParent = nullptr);   // standard constructor
	virtual ~SettingsView();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SETTINGS };
#endif

protected:
	BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg
		HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	BOOL OnEraseBkgnd(CDC* pDC);
	void OnBnClickedDbcreate();
	CMFCButton dbCreateButton;
	CMFCButton fontChangeButton;
};
