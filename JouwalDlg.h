
// JouwalDlg.h : header file
//

#pragma once
#include "ActivitiesView.h"
#include "DrawerView.h"
#include "HomeView.h"
#include "VillagesView.h"
#include "LanguagesView.h"
#include "SettingsView.h"
#include "CountriesView.h"
#include "ContinentsView.h"

#ifdef UWM_CUSTOM
#define UWM_CUSTOM (WM_APP+1)
#endif

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
	void OnBnClickedQuit();
	void OnBnClickedActivities();
	LRESULT OnCustom(WPARAM wparam, LPARAM lparam);
	void OnBnClickedHome();
	void OnBnClickedSettings();
	void destroyAllChilds();
	void OnBnClickedVillages();
	void OnBnClickedLanguages();
	void OnBnClickedCountries();
	void OnBnClickedContinents();
	DECLARE_MESSAGE_MAP()
public:
	// Views
	//## This is responsable for changing the views
	CRect rc;

	CRect drawerRect;

	// ## Different Views of the application
	DrawerView* drawerView;
	HomeView* homeView;
	ActivitiesView* activitiesView;
	SettingsView* settingsView;
	VillagesView* villagesView;
	LanguagesView* languagesView;
	CountriesView* countriesView;
	ContinentsView* continentsView;
	// Components

	// Buttons

};
