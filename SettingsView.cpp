// SettingsView.cpp : implementation file
//

#include "pch.h"
#include "Jouwal.h"
#include "SettingsView.h"
#include "afxdialogex.h"
#include "DbConnector.h"


// SettingsView dialog

IMPLEMENT_DYNAMIC(SettingsView, CDialogEx)

SettingsView::SettingsView(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SETTINGS, pParent)
{
	Create(IDD_SETTINGS, pParent);

}

SettingsView::~SettingsView()
{
}

BOOL SettingsView::OnInitDialog() {
	CDialog::OnInitDialog();
	dbCreateButton.SetFaceColor(RGB(80, 40, 80), true);
	dbCreateButton.SetTextColor(RGB(255, 255, 255));
	fontChangeButton.SetFaceColor(RGB(80, 40, 80), true);
	fontChangeButton.SetTextColor(RGB(255, 255, 255));
	return TRUE;
}

void SettingsView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DBCREATE, dbCreateButton);
	DDX_Control(pDX, IDC_FONTCHANGER, fontChangeButton);
}


BEGIN_MESSAGE_MAP(SettingsView, CDialogEx)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_DBCREATE, &SettingsView::OnBnClickedDbcreate)
	ON_WM_ERASEBKGND()

END_MESSAGE_MAP()


HBRUSH SettingsView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	switch (nCtlColor)
	{
	case CTLCOLOR_STATIC:
		pDC->SetBkColor(RGB(41, 8, 31));
		pDC->SetTextColor(RGB(255, 255, 255));
		return (HBRUSH)GetStockObject(NULL_BRUSH);
	default:
		return CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	}
}

BOOL SettingsView::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	CBrush myBrush(RGB(41, 8, 31));    // dialog background color
	CBrush* pOld = pDC->SelectObject(&myBrush);
	BOOL bRes = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOld);    // restore old brush
	return bRes;                       // CDialog::OnEraseBkgnd(pDC);
}
// SettingsView message handlers


void SettingsView::OnBnClickedDbcreate()
{
	// TODO: Add your control notification handler code here
	CString activitesTableSQL = L"CREATE TABLE ACTIVITIES(no_activities AUTOINCREMENT PRIMARY KEY,designation VARCHAR(100));";
	CString villagesTableSQL = L"CREATE TABLE VILLAGES(no_village AUTOINCREMENT PRIMARY KEY,nom VARCHAR(100),no_country INTEGER, FOREIGN KEY (no_country) REFERENCES countries(no_country));";
	CString languagesTableSQL = L"CREATE TABLE languages(no_language AUTOINCREMENT PRIMARY KEY,designation VARCHAR(30));";
	CString countriesTableSQL = L"CREATE TABLE countries(no_country AUTOINCREMENT PRIMARY KEY,nom VARCHAR(30), no_continent INTEGER, FOREIGN KEY (no_continent) REFERENCES continents(no_continent));";
	CString continentsTableSQL = L"CREATE TABLE continents(no_continent AUTOINCREMENT PRIMARY KEY,nom VARCHAR(30));";

	CString proposerTableSQL = L"CREATE TABLE proposer(no_activities INTEGER,no_village INTEGER, gratuite BIT ,FOREIGN KEY (no_village) REFERENCES villages(no_village),FOREIGN KEY (no_activities) REFERENCES activities(no_activities))";
	CString parlerTableSQL = L"CREATE TABLE parler(no_language INTEGER,no_village INTEGER,FOREIGN KEY (no_language) REFERENCES languages(no_language),FOREIGN KEY (no_village) REFERENCES villages(no_village))";
	//CString avoirTableSQL = L"CREATE TABLE avoir(no_country INTEGER,no_village INTEGER,FOREIGN KEY (no_country) REFERENCES countries(no_country),FOREIGN KEY (no_village) REFERENCES villages(no_village))";
	//CString seTrouveTableSQL = L"CREATE TABLE setrouve(no_country INTEGER,no_continent INTEGER,FOREIGN KEY (no_country) REFERENCES countries(no_country),FOREIGN KEY (no_continent) REFERENCES continents(no_continent))";
	

	DbConnector *db = DbConnector::createDb();
	//db->executeQuery(activitesTableSQL);
	//db->executeQuery(villagesTableSQL);
	//db->executeQuery(languagesTableSQL);
	db->executeQuery(countriesTableSQL);
	//db->executeQuery(continentsTableSQL);
	//db->executeQuery(proposerTableSQL);
	//db->executeQuery(parlerTableSQL);
	//db->executeQuery(avoirTableSQL);
	//db->executeQuery(seTrouveTableSQL);

}
