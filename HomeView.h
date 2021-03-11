#pragma once


// HomeView dialog

class HomeView : public CDialogEx
{
	DECLARE_DYNAMIC(HomeView)

public:
	HomeView(CWnd* pParent = nullptr);
	BOOL OnInitDialog();
	BOOL OnEraseBkgnd(CDC* pDC);
	// standard constructor
	virtual ~HomeView();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HOME_VIEW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
