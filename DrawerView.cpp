// DrawerView.cpp : implementation file
//

#include "pch.h"
#include "Jouwal.h"
#include "DrawerView.h"
#include "afxdialogex.h"


#define UWM_CUSTOM (WM_APP+1)

// DrawerView dialog

IMPLEMENT_DYNAMIC(DrawerView, CDialogEx)

DrawerView::DrawerView(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DRAWER_VIEW, pParent)
{
	Create(IDD_DRAWER_VIEW, pParent);

}
BOOL DrawerView::OnInitDialog() {
	CDialogEx::OnInitDialog();
	
	homeButton.SetFaceColor(RGB(60, 6, 31), true);
	homeButton.SetTextColor(RGB(255, 255, 255));
	
	countriesButton.SetFaceColor(RGB(60, 6, 31), true);
	countriesButton.SetTextColor(RGB(255, 255, 255));
	
	continentsButton.SetFaceColor(RGB(60, 6, 31), true);
	continentsButton.SetTextColor(RGB(255, 255, 255));
	
	languagesButton.SetFaceColor(RGB(60, 6, 31), true);
	languagesButton.SetTextColor(RGB(255, 255, 255));

	activitesButton.SetFaceColor(RGB(60, 6, 31), true);
	activitesButton.SetTextColor(RGB(255, 255, 255));

	villagesButton.SetFaceColor(RGB(60, 6, 31), true);
	villagesButton.SetTextColor(RGB(255, 255, 255));

	settingsButton.SetFaceColor(RGB(201, 221, 255), true);
	settingsButton.SetTextColor(RGB(42, 45, 52));

	quitButton.SetFaceColor(RGB(222, 108, 131),true);
	quitButton.SetTextColor(RGB(255, 255, 255));




	return TRUE;
}
DrawerView::~DrawerView()
{
}

void DrawerView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_HOME, homeButton);
	DDX_Control(pDX, IDC_Activities, activitesButton);
	DDX_Control(pDX, IDC_VILLAGES, villagesButton);
	DDX_Control(pDX, IDC_COUNTRIES, countriesButton);
	DDX_Control(pDX, IDC_CONTINENTS, continentsButton);
	DDX_Control(pDX, IDC_LANGUAGES, languagesButton);
	DDX_Control(pDX, IDC_SETTINGS, settingsButton);
	DDX_Control(pDX, IDC_QUIT, quitButton);
}

BOOL DrawerView::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	CBrush myBrush(RGB(49, 2, 31));    // dialog background color
	CBrush* pOld = pDC->SelectObject(&myBrush);
	BOOL bRes = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOld);    // restore old brush
	return bRes;                       // CDialog::OnEraseBkgnd(pDC);
}


BEGIN_MESSAGE_MAP(DrawerView, CDialogEx)
	ON_WM_ERASEBKGND()

	ON_BN_CLICKED(IDC_QUIT, &DrawerView::OnBnClickedQuit)
	ON_BN_CLICKED(IDC_HOME, &DrawerView::OnBnClickedHome)
	ON_BN_CLICKED(IDC_Activities, &DrawerView::OnBnClickedActivities)
	ON_BN_CLICKED(IDC_SETTINGS, &DrawerView::OnBnClickedSettings)
	ON_BN_CLICKED(IDC_VILLAGES, &DrawerView::OnBnClickedVillages)
END_MESSAGE_MAP()


// DrawerView message handlers


void DrawerView::OnBnClickedQuit()
{
	// TODO: Add your control notification handler code here
	//GetParent()->DestroyWindow();
	CString str = _T("Quit");
	GetParent()->SendMessage(UWM_CUSTOM, (WPARAM)&str, 0);
	
}


void DrawerView::OnBnClickedHome()
{
	// TODO: Add your control notification handler code here
	CString str = _T("Home");
	GetParent()->SendMessage(UWM_CUSTOM, (WPARAM)&str, 0);

}


void DrawerView::OnBnClickedActivities()
{

	// TODO: Add your control notification handler code here

	CString str = _T("Activities");
	GetParent()->SendMessage(UWM_CUSTOM, (WPARAM)&str, 0);
}


void DrawerView::OnBnClickedSettings()
{
	// TODO: Add your control notification handler code here

	CString str = _T("Settings");
	GetParent()->SendMessage(UWM_CUSTOM, (WPARAM)&str, 0);
}


void DrawerView::OnBnClickedVillages()
{
	// TODO: Add your control notification handler code here

	CString str = _T("Villages");
	GetParent()->SendMessage(UWM_CUSTOM, (WPARAM)&str, 0);
}
