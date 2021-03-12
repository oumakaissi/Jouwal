#pragma once


// DrawerView dialog

class DrawerView : public CDialogEx
{
	DECLARE_DYNAMIC(DrawerView)

public:
	DrawerView(CWnd* pParent = nullptr);   // standard constructor
	BOOL OnInitDialog();
	virtual ~DrawerView();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DRAWER_VIEW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	BOOL OnEraseBkgnd(CDC* pDC);

	DECLARE_MESSAGE_MAP()
public:
	CMFCButton homeButton;
	CMFCButton activitesButton;
	CMFCButton villagesButton;
	CMFCButton countriesButton;
	CMFCButton continentsButton;
	CMFCButton languagesButton;
	CMFCButton settingsButton;
	CMFCButton quitButton;
	CRect rc;

	afx_msg void OnBnClickedQuit();
	afx_msg void OnBnClickedHome();
	afx_msg void OnBnClickedActivities();
	afx_msg void OnBnClickedSettings();
	afx_msg void OnBnClickedVillages();
};
