// ActivitiesView.cpp : implementation file
//

#include "pch.h"
#include "Jouwal.h"
#include "ActivitiesView.h"
#include "afxdialogex.h"
#include "DbConnector.h"
#include "ActivitesAdd.h"
#include "ActivityEdit.h"
#include "ActivityDelete.h"


// ActivitiesView dialog

IMPLEMENT_DYNAMIC(ActivitiesView, CDialogEx)

ActivitiesView::ActivitiesView(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Activities_View, pParent)
	, activitySearchFieldValue(_T(""))
	, no_village(_T(""))
	, villageNumber(_T(""))
	, villageNumberValue(_T(""))
{
	Create(IDD_Activities_View, pParent);

}
BOOL ActivitiesView::OnInitDialog() {
	CDialogEx::OnInitDialog();
	// Coloring the buttons
	searchButton.SetFaceColor(RGB(80, 40, 80), true);
	searchButton.SetTextColor(RGB(255, 255, 255));

	addButton.SetFaceColor(RGB(80, 40, 80), true);
	addButton.SetTextColor(RGB(255, 255, 255));

	deleteOneButton.SetFaceColor(RGB(80, 40, 80), true);
	deleteOneButton.SetTextColor(RGB(255, 255, 255));

	deleteAllButton.SetFaceColor(RGB(80, 40, 80), true);
	deleteAllButton.SetTextColor(RGB(255, 255, 255));

	editButton.SetFaceColor(RGB(80, 40, 80), true);
	editButton.SetTextColor(RGB(255, 255, 255));

	//Setting up the List
	activitiesList.InsertColumn(0, L"no_activity", LVCFMT_CENTER, 80, -1);
	activitiesList.InsertColumn(1, L"designation", LVCFMT_CENTER, 180, -1);
	//Filling the list
	CString query = L"SELECT * FROM activities order by 1 desc";
	retrieveData(query);

	return TRUE;
}


void ActivitiesView::retrieveData(CString q) {

	activitiesList.DeleteAllItems();
	//CString query = L"SELECT * FROM activities order by 1 desc";

	/// <summary>
	/// Creating a db instance
	/// </summary>
	db = DbConnector::createDb();
	recset = db->retrieveQuery(q);
	CString V_no, V_designation;
	int i = 0;
	while (!(recset->IsEOF())) {
		CString no = L"";
		recset->GetFieldValue(L"no_activities", no);
		
		CString field = L"";
		recset->GetFieldValue(L"designation", field);

		activitiesList.InsertItem(i, no, 0);
		activitiesList.SetItemText(i, 1, field);
		i++;
		recset->MoveNext();
	}

	recset->Close();

}
ActivitiesView::~ActivitiesView()
{

}

void ActivitiesView::DoDataExchange(CDataExchange* pDX)
{

	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SEARCH_ACTIVITIE_FIELD, activitySearchFieldValue);
	DDX_Control(pDX, IDC_ACTIVITIES_LIST, activitiesList);

	DDX_Control(pDX, IDC_SEARCH_ACTIVITIE_FIELD, activityNumberEditBox);
	DDX_Control(pDX, IDC_STATIC_ACTIVITY_NUMBER, activityNumberStaticText);
	DDX_Control(pDX, IDC_SEARCH_ACTIVITIES_BUTTON, searchButton);
	DDX_Control(pDX, IDC_ADD_ACTIVITIE, addButton);
	DDX_Control(pDX, IDC_EDIT_ACTIVITIE, editButton);
	DDX_Control(pDX, IDC_DELETE_ONE_ACTIVITIE, deleteOneButton);
	DDX_Control(pDX, IDC_DELETE_ALL_ACTIVITIES, deleteAllButton);
	DDX_Text(pDX, IDC_VILLAGE_NUMBER_FIELD_ACTIVITY, villageNumberValue);
}


BEGIN_MESSAGE_MAP(ActivitiesView, CDialogEx)
	ON_WM_ERASEBKGND()

	ON_BN_CLICKED(IDC_ADD_ACTIVITIE, &ActivitiesView::OnBnClickedAddActivitie)
	ON_BN_CLICKED(IDC_EDIT_ACTIVITIE, &ActivitiesView::OnBnClickedEditActivitie)
	ON_BN_CLICKED(IDC_DELETE_ONE_ACTIVITIE, &ActivitiesView::OnBnClickedDeleteOneActivitie)
	ON_BN_CLICKED(IDC_DELETE_ALL_ACTIVITIES, &ActivitiesView::OnBnClickedDeleteAllActivities)
	ON_BN_CLICKED(IDC_SEARCH_ACTIVITIES_BUTTON, &ActivitiesView::OnBnClickedSearchActivitiesButton)
	ON_BN_CLICKED(IDC_REFRESH, &ActivitiesView::OnBnClickedRefresh)
	ON_EN_CHANGE(IDC_SEARCH_ACTIVITIE_FIELD, &ActivitiesView::OnEnChangeSearchActivitieField)
	ON_EN_CHANGE(IDC_VILLAGE_NUMBER_FIELD_ACTIVITY, &ActivitiesView::OnEnChangeVillageNumberFieldActivity)
END_MESSAGE_MAP()


BOOL ActivitiesView::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	CBrush myBrush(RGB(41, 8, 31));    // dialog background color
	CBrush* pOld = pDC->SelectObject(&myBrush);
	BOOL bRes = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOld);    // restore old brush
	return bRes;                       // CDialog::OnEraseBkgnd(pDC);
}



// ActivitiesView message handlers


void ActivitiesView::OnBnClickedAddActivitie()
{
	// TODO: Add your control notification handler code here
	ActivitesAdd activitiesAdd = new ActivitesAdd();
	activitiesAdd.DoModal();

}


void ActivitiesView::OnBnClickedEditActivitie()
{
	// TODO: Add your control notification handler code here
	ActivityEdit activityEdit = new ActivityEdit();
	activityEdit.DoModal();
}


void ActivitiesView::OnBnClickedDeleteOneActivitie()
{
	// TODO: Add your control notification handler code here
	ActivityDelete activityDelete = new ActivityDelete();
	activityDelete.DoModal();
}


void ActivitiesView::OnBnClickedDeleteAllActivities()
{
	// TODO: Add your control notification handler code here
	CString deleteAllCommand = L"TRUNCATE table activities";
	//db->executeQuery(deleteAllCommand);
}


void ActivitiesView::OnBnClickedSearchActivitiesButton()
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_SEARCH_ACTIVITIE_FIELD, activitySearchFieldValue);

	CString query = L"SELECT * FROM activities where no_activities=" + activitySearchFieldValue + " order by 1 desc";
	retrieveData(query);
}


void ActivitiesView::OnBnClickedRefresh()
{
	// TODO: Add your control notification handler code here
	CString query = L"SELECT * FROM activities order by 1 desc";
	retrieveData(query);
}

// Search on the values depanding on the filled Fields
void ActivitiesView::OnSearchChange() {
	GetDlgItemText(IDC_SEARCH_ACTIVITIE_FIELD, activitySearchFieldValue);
	GetDlgItemText(IDC_VILAGE_NUMBER_ACTIVITY, villageNumberValue);

	CString query = L"SELECT * FROM activities";
	if (villageNumberValue != "") {
		if (activitySearchFieldValue != "") {
			query += L" where no_activities=" + activitySearchFieldValue;
			query += L" and no_activities in ( select no_activities from Villages where no_village = ";
			query += villageNumberValue;
			query += ")";
		}
		else {
			query += L" where no_activities in ( select no_activities from Villages where no_village = ";
			query += villageNumberValue;
			query += ")";
		}
	}
	else {
		if (activitySearchFieldValue != "") {
			query += L" where no_activities=" + activitySearchFieldValue;
		}
	}
	query += L" order by 1 desc";
	retrieveData(query);
}



void ActivitiesView::OnEnChangeSearchActivitieField()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	OnSearchChange();
}

void ActivitiesView::OnEnChangeVillageNumberFieldActivity()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	OnSearchChange();
}
