// ContinentCreate.cpp : implementation file
//

#include "pch.h"
#include "Jouwal.h"
#include "ContinentCreate.h"
#include "afxdialogex.h"
#include "DbConnector.h"


// ContinentCreate dialog

IMPLEMENT_DYNAMIC(ContinentCreate, CDialogEx)

ContinentCreate::ContinentCreate(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Continent_Create, pParent)
	, nomValue(_T(""))
{

}

ContinentCreate::~ContinentCreate()
{
}

void ContinentCreate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_Nom_FIELD, nomValue);
}


BEGIN_MESSAGE_MAP(ContinentCreate, CDialogEx)
	ON_WM_ERASEBKGND()

	ON_BN_CLICKED(IDC_ACTIVITY_CREATE, &ContinentCreate::OnBnClickedActivityCreate)
	ON_BN_CLICKED(IDC_ACTIVITY_CANCEL, &ContinentCreate::OnBnClickedActivityCancel)
END_MESSAGE_MAP()


BOOL ContinentCreate::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	CBrush myBrush(RGB(41, 8, 31));    // dialog background color
	CBrush* pOld = pDC->SelectObject(&myBrush);
	BOOL bRes = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOld);    // restore old brush
	return bRes;                       // CDialog::OnEraseBkgnd(pDC);
}

// ContinentCreate message handlers

// CountryCreate message handlers


void ContinentCreate::OnBnClickedActivityCreate()
{
	// TODO: Add your control notification handler code here
	GetDlgItemText( IDC_Nom_FIELD, nomValue);
	CString insertSQL = L"INSERT INTO Continents(nom) VALUES ('" + nomValue + "');";
	DbConnector* db = DbConnector::createDb();
	db->executeQuery(insertSQL);
	OnOK();
}





void ContinentCreate::OnBnClickedActivityCancel()
{
	// TODO: Add your control notification handler code here
	OnCancel();

}
