// CountryCreate.cpp : implementation file
//

#include "pch.h"
#include "Jouwal.h"
#include "CountryCreate.h"
#include "afxdialogex.h"
#include "DbConnector.h"


// CountryCreate dialog

IMPLEMENT_DYNAMIC(CountryCreate, CDialogEx)

CountryCreate::CountryCreate(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Country_Create, pParent)
	, countryNomValue(_T(""))
	, continentNumberFieldValue(_T(""))
{

}

CountryCreate::~CountryCreate()
{
}

void CountryCreate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Nom_FIELD, countryNomValue);
	DDX_Text(pDX, IDC_Continent_Number_Field, continentNumberFieldValue);
}


BEGIN_MESSAGE_MAP(CountryCreate, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()

	ON_BN_CLICKED(IDC_ACTIVITY_CREATE, &CountryCreate::OnBnClickedActivityCreate)
	ON_BN_CLICKED(IDC_ACTIVITY_CANCEL, &CountryCreate::OnBnClickedActivityCancel)
END_MESSAGE_MAP()


HBRUSH CountryCreate::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

BOOL CountryCreate::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	CBrush myBrush(RGB(41, 8, 31));    // dialog background color
	CBrush* pOld = pDC->SelectObject(&myBrush);
	BOOL bRes = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOld);    // restore old brush
	return bRes;                       // CDialog::OnEraseBkgnd(pDC);
}

// CountryCreate message handlers


void CountryCreate::OnBnClickedActivityCreate()
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_Nom_FIELD, countryNomValue);
	GetDlgItemText(IDC_Continent_Number_Field, continentNumberFieldValue);
	CString insertSQL = L"INSERT INTO Countries(nom,no_continent) VALUES ('" + countryNomValue + "',"+ continentNumberFieldValue +");";
	DbConnector* db = DbConnector::createDb();
	db->executeQuery(insertSQL);
	OnOK();
}


void CountryCreate::OnBnClickedActivityCancel()
{
	// TODO: Add your control notification handler code here
	OnCancel();
}
