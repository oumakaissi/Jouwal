// VillageDelete.cpp : implementation file
//

#include "pch.h"
#include "Jouwal.h"
#include "VillageDelete.h"
#include "afxdialogex.h"
#include "DbConnector.h"


// VillageDelete dialog

IMPLEMENT_DYNAMIC(VillageDelete, CDialogEx)

VillageDelete::VillageDelete(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_VILLAGE_DELETE, pParent)
	, villageNumberValue(_T(""))
{

}

VillageDelete::~VillageDelete()
{
}

void VillageDelete::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDO_VILLAGE_DELETE, deleteButton);
	DDX_Control(pDX, IDCANCEL, cancelButton);
	DDX_Text(pDX, IDC_VILLAGE_NUMBER_FIELD, villageNumberValue);
}


BEGIN_MESSAGE_MAP(VillageDelete, CDialogEx)
	ON_BN_CLICKED(IDO_VILLAGE_DELETE, &VillageDelete::OnBnClickedVillageDelete)
	ON_BN_CLICKED(IDCANCEL, &VillageDelete::OnBnClickedCancel)
END_MESSAGE_MAP()


// VillageDelete message handlers


void VillageDelete::OnBnClickedVillageDelete()
{
	// TODO: Add your control notification handler code here
	DbConnector *db = DbConnector::createDb();
	GetDlgItemText(IDC_VILLAGE_NUMBER_FIELD, villageNumberValue);
	if (villageNumberValue == "") {
		OnOK();
	}
	CString deleteCommand = L"delete from avoir where no_village = " + villageNumberValue;
	db->executeQuery(deleteCommand);

	deleteCommand = L"delete from parler where no_village = " + villageNumberValue;
	db->executeQuery(deleteCommand);

	deleteCommand = L"delete from villages where no_village = " + villageNumberValue;
	db->executeQuery(deleteCommand);

	OnOK();
}


void VillageDelete::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}
