
// JouwalDlg.h : header file
//

#pragma once
#include "ActivitiesView.h"
#include "DrawerView.h"


// CJouwalDlg dialog
class CJouwalDlg : public CDialogEx
{
// Construction
public:
	CJouwalDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
enum { IDD = IDD_JOUWAL_DIALOG };

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_JOUWAL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();

	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedHome();
	// Views
	//## This is responsable for changing the views
	CRect rc;

	CRect drawerRect;

	// ## Different Views of the application
	ActivitiesView *activitiesView;
	DrawerView* drawerView;
	// Components

	// Buttons

};
