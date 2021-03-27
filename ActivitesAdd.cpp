// ActivitesAdd.cpp : implementation file
//

#include "pch.h"
#include "Jouwal.h"
#include "ActivitesAdd.h"
#include "afxdialogex.h"
#include "DbConnector.h"


// ActivitesAdd dialog

IMPLEMENT_DYNAMIC(ActivitesAdd, CDialogEx)

ActivitesAdd::ActivitesAdd(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ACTIVITES_ADD_VIEW, pParent)
	, designationField(_T(""))
{

}

ActivitesAdd::~ActivitesAdd()
{
}

void ActivitesAdd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DESIGNATION_FIELD, designationField);
}


BEGIN_MESSAGE_MAP(ActivitesAdd, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()


	ON_BN_CLICKED(IDC_ACTIVITY_CREATE, &ActivitesAdd::OnBnClickedActivityCreate)
	ON_BN_CLICKED(IDC_ACTIVITY_CANCEL, &ActivitesAdd::OnBnClickedActivityCancel)
END_MESSAGE_MAP()


HBRUSH ActivitesAdd::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

// ActivitesAdd message handlers



BOOL ActivitesAdd::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	CBrush myBrush(RGB(41, 8, 31));    // dialog background color
	CBrush* pOld = pDC->SelectObject(&myBrush);
	BOOL bRes = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOld);    // restore old brush
	return bRes;                       // CDialog::OnEraseBkgnd(pDC);
}



void ActivitesAdd::OnBnClickedActivityCreate()
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_DESIGNATION_FIELD, designationField);
	CString insertSQL = L"INSERT INTO ACTIVITIES(designation) VALUES ('" + designationField + "');";
	DbConnector* db = DbConnector::createDb();
	db->executeQuery(insertSQL);
	OnOK();
}


void ActivitesAdd::OnBnClickedActivityCancel()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
