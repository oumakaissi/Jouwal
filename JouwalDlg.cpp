/*
*Author: Taha Bouhsine
*/
// JouwalDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Jouwal.h"
#include "JouwalDlg.h"
#include "afxdialogex.h"
#include "afxbutton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)

END_MESSAGE_MAP()
//End of ABOUT Dialog
//##################################



//##################################
//Start of Jouwal dialog
// CJouwalDlg dialog



CJouwalDlg::CJouwalDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CJouwalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_QUIT, quitButton);

//	DDX_Control(pDX, IDC_DRAWER, drawerRect);
}

BEGIN_MESSAGE_MAP(CJouwalDlg, CDialogEx)
	ON_WM_ERASEBKGND()


	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_BN_CLICKED(IDC_HOME, &CJouwalDlg::OnBnClickedHome)
	//ON_BN_CLICKED(IDC_Activities, &CJouwalDlg::OnBnClickedActivities)
	//ON_BN_CLICKED(IDC_VILLAGES, &CJouwalDlg::OnBnClickedVillages)
	//ON_BN_CLICKED(IDC_COUNTRIES, &CJouwalDlg::OnBnClickedCountries)
	//ON_BN_CLICKED(IDC_CONTINENTS, &CJouwalDlg::OnBnClickedContinents)
	//ON_BN_CLICKED(IDC_SETTINGS, &CJouwalDlg::OnBnClickedSettings)
	//ON_BN_CLICKED(IDC_QUIT, &CJouwalDlg::OnBnClickedQuit)
END_MESSAGE_MAP()


// CJouwalDlg message handlers

BOOL CJouwalDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CDialogEx::CenterWindow();
	GetDlgItem(IDC_VIEWCONTROL)->GetWindowRect(rc);
	GetDlgItem(IDC_DRAWER)->GetWindowRect(drawerRect);

	drawerView = new DrawerView(this);
	activitiesView = new ActivitiesView(this);
	ScreenToClient(&rc);
	ScreenToClient(&drawerRect);
	//CenterWindow();
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	ShowWindow(SW_MINIMIZE);

	// setting up the view controller
	
	activitiesView->MoveWindow(rc);
	drawerView->MoveWindow(drawerRect);

	// TODO: Add extra initialization here
//	GetDlgItem(IDC_VIEWCONTROLLER)->GetWindowRect(rc);
//	quitButton.SetFaceColor(RGB(80, 40, 80),true);
	//quitButton.SetTextColor(RGB(255, 255, 255));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CJouwalDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CJouwalDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CJouwalDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


BOOL CJouwalDlg::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	CBrush myBrush(RGB(77, 13, 48));    // dialog background color
	CBrush* pOld = pDC->SelectObject(&myBrush);
	BOOL bRes = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOld);    // restore old brush
	return bRes;                       // CDialog::OnEraseBkgnd(pDC);
}



/// <summary>
/// Buttons Event handlers
/// </summary>

