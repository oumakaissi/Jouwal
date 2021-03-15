// ContinentsView.cpp : implementation file
//

#include "pch.h"
#include "Jouwal.h"
#include "ContinentsView.h"
#include "afxdialogex.h"
#include "ContinentCreate.h"


// ContinentsView dialog

IMPLEMENT_DYNAMIC(ContinentsView, CDialogEx)

ContinentsView::ContinentsView(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Continent_View, pParent)
	, contientNumberValue(_T(""))
{
	Create(IDD_Continent_View, pParent);

}

ContinentsView::~ContinentsView()
{
}

BOOL ContinentsView::OnInitDialog() {
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
	continentsList.InsertColumn(0, L"no_continent", LVCFMT_CENTER, 80, -1);
	continentsList.InsertColumn(1, L"nom", LVCFMT_CENTER, 180, -1);
	//Filling the list
	CString query = L"SELECT * FROM continents order by 1 desc";
	retrieveData(query);

	return TRUE;
}

void ContinentsView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_SEARCH_Continent_FIELD, contientNumberValue);
	DDX_Control(pDX, IDC_Countries_LIST, continentsList);
	DDX_Control(pDX, IDC_SEARCH_Contienents_BUTTON, searchButton);
	DDX_Control(pDX, IDC_REFRESH, refreshButton);
	DDX_Control(pDX, IDC_ADD_Continent, addButton);
	DDX_Control(pDX, IDC_EDIT_Continent, editButton);
	DDX_Control(pDX, IDC_DELETE_ONE_ACTIVITIE, deleteOneButton);
	DDX_Control(pDX, IDC_DELETE_ALL_ACTIVITIES, deleteAllButton);
}


BEGIN_MESSAGE_MAP(ContinentsView, CDialogEx)
	ON_WM_ERASEBKGND()

	ON_EN_CHANGE(IDC_SEARCH_Continent_FIELD, &ContinentsView::OnEnChangeSearchContinentField)
	ON_BN_CLICKED(IDC_SEARCH_Contienents_BUTTON, &ContinentsView::OnBnClickedSearchContienentsButton)
	ON_BN_CLICKED(IDC_REFRESH, &ContinentsView::OnBnClickedRefresh)
	ON_BN_CLICKED(IDC_ADD_Continent, &ContinentsView::OnBnClickedAddContinent)
	ON_BN_CLICKED(IDC_EDIT_Continent, &ContinentsView::OnBnClickedEditContinent)
	ON_BN_CLICKED(IDC_DELETE_ONE_ACTIVITIE, &ContinentsView::OnBnClickedDeleteOneActivitie)
	ON_BN_CLICKED(IDC_DELETE_ALL_ACTIVITIES, &ContinentsView::OnBnClickedDeleteAllActivities)
END_MESSAGE_MAP()

BOOL ContinentsView::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	CBrush myBrush(RGB(41, 8, 31));    // dialog background color
	CBrush* pOld = pDC->SelectObject(&myBrush);
	BOOL bRes = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOld);    // restore old brush
	return bRes;                       // CDialog::OnEraseBkgnd(pDC);
}
// CountriesView message handlers

// ContinentsView message handlers


void ContinentsView::OnEnChangeSearchContinentField()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	OnSearchChange();

}


void ContinentsView::OnBnClickedSearchContienentsButton()
{
	// TODO: Add your control notification handler code here
	OnSearchChange();

}


void ContinentsView::OnBnClickedRefresh()
{
	// TODO: Add your control notification handler code here

	// TODO: Add your control notification handler code here
	CString query = L"SELECT * FROM continents order by 1 desc";
	retrieveData(query);
}


void ContinentsView::OnBnClickedAddContinent()
{
	// TODO: Add your control notification handler code here
	ContinentCreate continentCreate = new ContinentCreate();
	continentCreate.DoModal();
}


void ContinentsView::OnBnClickedEditContinent()
{
	// TODO: Add your control notification handler code here
}


void ContinentsView::OnBnClickedDeleteOneActivitie()
{
	// TODO: Add your control notification handler code here
}


void ContinentsView::OnBnClickedDeleteAllActivities()
{
	// TODO: Add your control notification handler code here
	CString deleteAllCommand = L"TRUNCATE table countries";
	//db->executeQuery(deleteAllCommand);
}


//##############


// Search on the values depanding on the filled Fields
void ContinentsView::OnSearchChange() {
	GetDlgItemText(IDC_SEARCH_Continent_FIELD, contientNumberValue);
	CString query = L"SELECT * FROM continents";
	if (contientNumberValue != "") {
			query += L" where no_continent=" + contientNumberValue;
	}
	query += L" order by 1 desc";
	retrieveData(query);
}


void ContinentsView::retrieveData(CString q) {

	continentsList.DeleteAllItems();

	/// <summary>
	/// Creating a db instance
	/// </summary>
	db = DbConnector::createDb();
	recset = db->retrieveQuery(q);
	int i = 0;
	while (!(recset->IsEOF())) {
		CString no = L"";
		recset->GetFieldValue(L"no_continent", no);

		CString field = L"";
		recset->GetFieldValue(L"nom", field);


		continentsList.InsertItem(i, no, 0);
		continentsList.SetItemText(i, 1, field);
		i++;
		recset->MoveNext();
	}

	recset->Close();

}
