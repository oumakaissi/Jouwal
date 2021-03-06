// VillagesView.cpp : implementation file
//

#include "pch.h"
#include "Jouwal.h"
#include "VillagesView.h"
#include "afxdialogex.h"
#include "VillageCreate.h"
#include "VillageEdit.h"


// VillagesView dialog

IMPLEMENT_DYNAMIC(VillagesView, CDialogEx)

VillagesView::VillagesView(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Villages_VIEW, pParent)
	, villageNumberValue(_T(""))
	, countryNumberValue(_T(""))
{
	Create(IDD_Villages_VIEW, pParent);

}

VillagesView::~VillagesView()
{
}
BOOL VillagesView::OnInitDialog() {
	CDialogEx::OnInitDialog();
	villagesList.InsertColumn(0, L"no_village", LVCFMT_CENTER, 80, -1);
	villagesList.InsertColumn(1, L"nom", LVCFMT_CENTER, 180, -1);
	villagesList.InsertColumn(2, L"Country Name", LVCFMT_CENTER, 180, -1);

	CString query = L"SELECT * FROM villages order by 1 desc";
	retrieveData(query);

	return TRUE;
}
void VillagesView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SEARCH_VILLAGES_BUTTON, searchButton);
	DDX_Text(pDX, IDC_SEARCH_VILLAGE_FIELD, villageNumberValue);
	DDX_Control(pDX, IDC_REFRESH, refreshButton);
	DDX_Control(pDX, IDC_VILLAGES_LIST, villagesList);
	DDX_Control(pDX, IDC_ADD_VILLAGE, addVillageButton);
	DDX_Control(pDX, IDC_EDIT_VILLAGE, editVillageButton);
	DDX_Control(pDX, IDC_DELETE_ONE_VILLAGE, deleteOneButton);
	DDX_Control(pDX, IDC_DELETE_ALL_VILLAGES, deleteAllButton);
	DDX_Text(pDX, IDC_VILLAGE_PAYS_NUMBER, countryNumberValue);
}


BEGIN_MESSAGE_MAP(VillagesView, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()

	ON_BN_CLICKED(IDC_ADD_VILLAGE, &VillagesView::OnBnClickedAddVillage)
	ON_BN_CLICKED(IDC_EDIT_VILLAGE, &VillagesView::OnBnClickedEditVillage)
	ON_BN_CLICKED(IDC_DELETE_ONE_VILLAGE, &VillagesView::OnBnClickedDeleteOneVillage)
	ON_BN_CLICKED(IDC_DELETE_ALL_VILLAGES, &VillagesView::OnBnClickedDeleteAllVillages)
	ON_EN_CHANGE(IDC_SEARCH_VILLAGE_FIELD, &VillagesView::OnEnChangeSearchVillageField)
	ON_BN_CLICKED(IDC_SEARCH_VILLAGES_BUTTON, &VillagesView::OnBnClickedSearchVillagesButton)
	ON_BN_CLICKED(IDC_REFRESH, &VillagesView::OnBnClickedRefresh)
	ON_EN_CHANGE(IDC_VILLAGE_PAYS, &VillagesView::OnEnChangeVillagePays)
	ON_EN_CHANGE(IDC_VILLAGE_PAYS_NUMBER, &VillagesView::OnEnChangeVillagePaysNumber)
END_MESSAGE_MAP()

HBRUSH VillagesView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

BOOL VillagesView::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	CBrush myBrush(RGB(41, 8, 31));    // dialog background color
	CBrush* pOld = pDC->SelectObject(&myBrush);
	BOOL bRes = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOld);    // restore old brush
	return bRes;                       // CDialog::OnEraseBkgnd(pDC);
}





void VillagesView::retrieveData(CString q) {

	villagesList.DeleteAllItems();
	//CString query = L"SELECT * FROM activities order by 1 desc";

	/// <summary>
	/// Creating a db instance
	/// </summary>
	db = DbConnector::createDb();
	recset = db->retrieveQuery(q);
	int i = 0;
	while (!(recset->IsEOF())) {
		CString no = L"";
		recset->GetFieldValue(L"no_village", no);

		CString field = L"";
		recset->GetFieldValue(L"nom", field);

		villagesList.InsertItem(i, no, 0);
		villagesList.SetItemText(i, 1, field);
		i++;
		recset->MoveNext();
	}

	recset->Close();

}

void VillagesView::onSearch() {
	GetDlgItemText(IDC_SEARCH_VILLAGE_FIELD, villageNumberValue);
	GetDlgItemText(IDC_VILLAGE_PAYS, countryNumberValue);

	CString query = L"SELECT * FROM villages ";
	if (countryNumberValue != "") {
		if (villageNumberValue != "") {
			query += L" where no_village=" + villageNumberValue;
			query += L" and no_country = ";
			query += countryNumberValue;
		}
		else {
			query += L" where no_country = ";
			query += countryNumberValue;
		}
	}
	else {
		if (villageNumberValue != "") {
			query += L" where no_village=" + villageNumberValue;
		}
	}
	query += L" order by 1 desc";
	retrieveData(query);
}


// VillagesView message handlers


void VillagesView::OnBnClickedAddVillage()
{
	// TODO: Add your control notification handler code here
	VillageCreate villagesCreate = new VillageCreate();
	villagesCreate.DoModal();
}


void VillagesView::OnBnClickedEditVillage()
{
	// TODO: Add your control notification handler code here
	VillageEdit villageEdit = new VillageEdit();
	villageEdit.DoModal();
}


void VillagesView::OnBnClickedAddActivityToVillage()
{
	// TODO: Add your control notification handler code here

}


void VillagesView::OnBnClickedEditActivityVillage()
{
	// TODO: Add your control notification handler code here
}


void VillagesView::OnBnClickedRemoveActivity()
{
	// TODO: Add your control notification handler code here
}


void VillagesView::OnBnClickedDeleteOneVillage()
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_SEARCH_VILLAGE_FIELD, villageNumberValue);
	if (villageNumberValue == "") {
		OnOK();
	}
	CString deleteCommand3 = L"delete from parler where no_village= " + villageNumberValue;
	CString deleteCommand2 = L"delete from proposer where no_village= " + villageNumberValue;
	CString deleteCommand = L"delete from villages where no_village= " + villageNumberValue;
	db->executeQuery(deleteCommand3);
	db->executeQuery(deleteCommand2);
	db->executeQuery(deleteCommand);
	OnBnClickedRefresh();
}


void VillagesView::OnBnClickedDeleteAllVillages()
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	CString deleteAllCommand = L"TRUNCATE table activities";
	//db->executeQuery(deleteAllCommand);
	deleteAllCommand = L"TRUNCATE table proposer";
	//db->executeQuery(deleteAllCommand);
}


void VillagesView::OnEnChangeSearchVillageField()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	onSearch();
}


void VillagesView::OnBnClickedSearchVillagesButton()
{
	// TODO: Add your control notification handler code here
	onSearch();
}


void VillagesView::OnBnClickedRefresh()
{
	// TODO: Add your control notification handler code here
	CString query = L"SELECT * FROM villages order by 1 desc";
	retrieveData(query);
}


void VillagesView::OnEnChangeVillagePays()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	onSearch();

}


void VillagesView::OnEnChangeVillagePaysNumber()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	onSearch();
}
