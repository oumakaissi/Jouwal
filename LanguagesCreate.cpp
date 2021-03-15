// LanguagesCreate.cpp : implementation file
//

#include "pch.h"
#include "Jouwal.h"
#include "LanguagesCreate.h"
#include "afxdialogex.h"
#include "DbConnector.h"


// LanguagesCreate dialog

IMPLEMENT_DYNAMIC(LanguagesCreate, CDialogEx)

LanguagesCreate::LanguagesCreate(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Language_Create, pParent)
	, designationField(_T(""))
{

}

LanguagesCreate::~LanguagesCreate()
{
}

void LanguagesCreate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_language_DESIGNATION_FIELD, designationField);
}


BEGIN_MESSAGE_MAP(LanguagesCreate, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_CREATE, &LanguagesCreate::OnBnClickedCreate)
	ON_BN_CLICKED(IDC_ACTIVITY_CANCEL, &LanguagesCreate::OnBnClickedActivityCancel)
END_MESSAGE_MAP()


BOOL LanguagesCreate::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	CBrush myBrush(RGB(41, 8, 31));    // dialog background color
	CBrush* pOld = pDC->SelectObject(&myBrush);
	BOOL bRes = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOld);    // restore old brush
	return bRes;                       // CDialog::OnEraseBkgnd(pDC);
}


// LanguagesCreate message handlers


void LanguagesCreate::OnBnClickedCreate()
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_language_DESIGNATION_FIELD, designationField);
	CString insertSQL = L"INSERT INTO languages (designation) VALUES ('" + designationField + "');";
	DbConnector* db = DbConnector::createDb();
	db->executeQuery(insertSQL);
	OnOK();
}


void LanguagesCreate::OnBnClickedActivityCancel()
{
	// TODO: Add your control notification handler code here
	OnOK();

}
