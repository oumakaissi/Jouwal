// ActivitiesView.cpp : implementation file
//

#include "pch.h"
#include "Jouwal.h"
#include "ActivitiesView.h"
#include "afxdialogex.h"
#include "DbConnector.h"


// ActivitiesView dialog

IMPLEMENT_DYNAMIC(ActivitiesView, CDialogEx)

ActivitiesView::ActivitiesView(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Activities_View, pParent)
	, activitySearchFieldValue(_T(""))
	, no_village(_T(""))
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
	activitiesList.InsertColumn(0, L"no_activity", LVCFMT_CENTER, 25, -1);
	activitiesList.InsertColumn(1, L"designation", LVCFMT_CENTER, 90, -1);
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
	while ((recset->IsEOF())!= false) {
		CString no = L"";
		recset->GetFieldValue(L"no_activity", no);
		
		CString field = L"";
		recset->GetFieldValue(L"designation", field);

		activitiesList.InsertItem(i, no, 0);
		activitiesList.SetItemText(i, 1, no);
		activitiesList.SetItemText(i, 2, field);
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
	DDX_Text(pDX, IDC_SEARCH_ACTIVITY_VILLAGE_NUMBER, no_village);

	DDX_Control(pDX, IDC_SEARCH_ACTIVITIE_FIELD, activityNumberEditBox);
	DDX_Control(pDX, IDC_SEARCH_ACTIVITY_VILLAGE_NUMBER, villageNumberEditBox);
	DDX_Control(pDX, IDC_STATIC_ACTIVITY_NUMBER, activityNumberStaticText);
	DDX_Control(pDX, IDC_STATIC_TEXT_ACTIVITY_VILLAGE_NUMBER, activityVillageNumberStaticText);
	DDX_Control(pDX, IDC_SEARCH_ACTIVITIES_BUTTON, searchButton);
	DDX_Control(pDX, IDC_ADD_ACTIVITIE, addButton);
	DDX_Control(pDX, IDC_EDIT_ACTIVITIE, editButton);
	DDX_Control(pDX, IDC_DELETE_ONE_ACTIVITIE, deleteOneButton);
	DDX_Control(pDX, IDC_DELETE_ALL_ACTIVITIES, deleteAllButton);
}


BEGIN_MESSAGE_MAP(ActivitiesView, CDialogEx)
	ON_WM_ERASEBKGND()

	ON_BN_CLICKED(IDC_ADD_ACTIVITIE, &ActivitiesView::OnBnClickedAddActivitie)
	ON_BN_CLICKED(IDC_EDIT_ACTIVITIE, &ActivitiesView::OnBnClickedEditActivitie)
	ON_BN_CLICKED(IDC_DELETE_ONE_ACTIVITIE, &ActivitiesView::OnBnClickedDeleteOneActivitie)
	ON_BN_CLICKED(IDC_DELETE_ALL_ACTIVITIES, &ActivitiesView::OnBnClickedDeleteAllActivities)
	ON_BN_CLICKED(IDC_SEARCH_ACTIVITIES_BUTTON, &ActivitiesView::OnBnClickedSearchActivitiesButton)
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
}


void ActivitiesView::OnBnClickedEditActivitie()
{
	// TODO: Add your control notification handler code here
}


void ActivitiesView::OnBnClickedDeleteOneActivitie()
{
	// TODO: Add your control notification handler code here
}


void ActivitiesView::OnBnClickedDeleteAllActivities()
{
	// TODO: Add your control notification handler code here
}


void ActivitiesView::OnBnClickedSearchActivitiesButton()
{
	// TODO: Add your control notification handler code here
}
