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
{

}

VillageCreate::~VillageCreate()
{
}

void VillageCreate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_VILLAGE_NAME_CREATE_FIELD, villageNameValue);
}


BEGIN_MESSAGE_MAP(VillageCreate, CDialogEx)
	ON_BN_CLICKED(IDO_CREATE, &VillageCreate::OnBnClickedCreate)
	ON_BN_CLICKED(IDCANCEL, &VillageCreate::OnBnClickedCancel)
END_MESSAGE_MAP()


// VillageCreate message handlers


void VillageCreate::OnBnClickedCreate()
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_VILLAGE_NAME_CREATE_FIELD, villageNameValue);
	CString insertSQL = L"INSERT INTO villages(nom) VALUES ('" + villageNameValue + "');";
	DbConnector* db = DbConnector::createDb();
	db->executeQuery(insertSQL);
}


void VillageCreate::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}
