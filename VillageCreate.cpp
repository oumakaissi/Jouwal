// VillageCreate.cpp : implementation file
//

#include "pch.h"
#include "Jouwal.h"
#include "VillageCreate.h"
#include "afxdialogex.h"
#include "DbConnector.h"


// VillageCreate dialog

IMPLEMENT_DYNAMIC(VillageCreate, CDialogEx)

VillageCreate::VillageCreate(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_VILLAGE_CREATE, pParent)
	, villageNameValue(_T(""))
	, countryNumberValue(_T(""))
{

}

VillageCreate::~VillageCreate()
{
}

void VillageCreate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_VILLAGE_NAME_CREATE_FIELD, villageNameValue);
	DDX_Text(pDX, IDC_VILLAGE_COUNTRY_NUMBER_FIELD, countryNumberValue);
}


BEGIN_MESSAGE_MAP(VillageCreate, CDialogEx)
	ON_BN_CLICKED(IDO_CREATE, &VillageCreate::OnBnClickedCreate)
	ON_BN_CLICKED(IDCANCEL, &VillageCreate::OnBnClickedCancel)
ON_WM_CTLCOLOR()
END_MESSAGE_MAP()

HBRUSH VillageCreate::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


// VillageCreate message handlers


void VillageCreate::OnBnClickedCreate()
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_VILLAGE_NAME_CREATE_FIELD, villageNameValue);
	GetDlgItemText(IDC_VILLAGE_COUNTRY_NUMBER_FIELD, countryNumberValue);

	CString insertSQL = L"INSERT INTO villages(nom, no_country) VALUES ('" + villageNameValue + "', " + countryNumberValue + ");";
	DbConnector* db = DbConnector::createDb();
	db->executeQuery(insertSQL);
	OnOK();
}


void VillageCreate::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}
