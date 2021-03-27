// CountriesView.cpp : implementation file
//

#include "pch.h"
#include "Jouwal.h"
#include "CountriesView.h"
#include "afxdialogex.h"
#include "CountryCreate.h"


// CountriesView dialog

IMPLEMENT_DYNAMIC(CountriesView, CDialogEx)

CountriesView::CountriesView(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Countries_View, pParent)
	, countiresFieldValue(_T(""))
	, continentNumberValue(_T(""))
{
	Create(IDD_Countries_View, pParent);

}

CountriesView::~CountriesView()
{
}

BOOL CountriesView::OnInitDialog() {
	CDialogEx::OnInitDialog();
	// Coloring the buttons
	//searchButton.SetFaceColor(RGB(80, 40, 80), true);
	//searchButton.SetTextColor(RGB(255, 255, 255));

	//addButton.SetFaceColor(RGB(80, 40, 80), true);
	//addButton.SetTextColor(RGB(255, 255, 255));

	//deleteOneButton.SetFaceColor(RGB(80, 40, 80), true);
	//deleteOneButton.SetTextColor(RGB(255, 255, 255));

	//deleteAllButton.SetFaceColor(RGB(80, 40, 80), true);
	//deleteAllButton.SetTextColor(RGB(255, 255, 255));

	//editButton.SetFaceColor(RGB(80, 40, 80), true);
	//editButton.SetTextColor(RGB(255, 255, 255));

	//Setting up the List
	countriesList.InsertColumn(0, L"no_country", LVCFMT_CENTER, 80, -1);
	countriesList.InsertColumn(1, L"nom", LVCFMT_CENTER, 180, -1);
	countriesList.InsertColumn(2, L"Continent", LVCFMT_CENTER, 180, -1);
	//Filling the list
	CString query = L"SELECT * FROM countries order by 1 desc";
	retrieveData(query);

	return TRUE;
}

void CountriesView::retrieveData(CString q) {

	countriesList.DeleteAllItems();

	/// <summary>
	/// Creating a db instance
	/// </summary>
	db = DbConnector::createDb();
	recset = db->retrieveQuery(q);
	int i = 0;
	while (!(recset->IsEOF())) {
		CString no = L"";
		recset->GetFieldValue(L"no_country", no);

		CString field = L"";
		recset->GetFieldValue(L"nom", field);

		CString field2 = L"";
		recset->GetFieldValue(L"no_continent", field2);

		countriesList.InsertItem(i, no, 0);
		countriesList.SetItemText(i, 1, field);
		countriesList.SetItemText(i, 2, field2);
		i++;
		recset->MoveNext();
	}

	recset->Close();

}
void CountriesView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SEARCH_Countries_BUTTON, searchButton);
	DDX_Control(pDX, IDC_ADD_Country, addButton);
	DDX_Control(pDX, IDC_EDIT_Country, editButton);
	DDX_Control(pDX, IDC_DELETE_ONE_ACTIVITIE, deleteOneButton);
	DDX_Control(pDX, IDC_DELETE_ALL_ACTIVITIES, deleteAllButton);
	DDX_Control(pDX, IDC_REFRESH, refreshButton);
	DDX_Control(pDX, IDC_SEARCH_Countries_FIELD, countriesFieldControl);
	DDX_Text(pDX, IDC_SEARCH_Countries_FIELD, countiresFieldValue);
	DDX_Control(pDX, IDC_Countries_LIST, countriesList);
	DDX_Text(pDX, IDC_SEARCH_Countries__Continent_FIELD, continentNumberValue);
}


BEGIN_MESSAGE_MAP(CountriesView, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()

	ON_EN_CHANGE(IDC_SEARCH_Countries_FIELD, &CountriesView::OnEnChangeSearchCountriesField)
	ON_BN_CLICKED(IDC_SEARCH_Countries_BUTTON, &CountriesView::OnBnClickedSearchCountriesButton)
	ON_BN_CLICKED(IDC_ADD_Country, &CountriesView::OnBnClickedAddCountry)
	ON_BN_CLICKED(IDC_EDIT_Country, &CountriesView::OnBnClickedEditCountry)
	ON_BN_CLICKED(IDC_DELETE_ONE_ACTIVITIE, &CountriesView::OnBnClickedDeleteOneActivitie)
	ON_BN_CLICKED(IDC_DELETE_ALL_ACTIVITIES, &CountriesView::OnBnClickedDeleteAllActivities)
	ON_BN_CLICKED(IDC_REFRESH, &CountriesView::OnBnClickedRefresh)
	ON_EN_CHANGE(IDC_SEARCH_Countries__Continent_FIELD, &CountriesView::OnEnChangeSearchCountries)
END_MESSAGE_MAP()


HBRUSH CountriesView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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


BOOL CountriesView::OnEraseBkgnd(CDC* pDC)
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


void CountriesView::OnEnChangeSearchCountriesField()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	OnSearchChange();
}


void CountriesView::OnBnClickedSearchCountriesButton()
{
	// TODO: Add your control notification handler code here
	OnSearchChange();
}


void CountriesView::OnBnClickedAddCountry()
{
	// TODO: Add your control notification handler code here
	CountryCreate countryCreate = new CountryCreate();
	countryCreate.DoModal();
}


void CountriesView::OnBnClickedEditCountry()
{
	// TODO: Add your control notification handler code here
}


void CountriesView::OnBnClickedDeleteOneActivitie()
{
	// TODO: Add your control notification handler code here

}


void CountriesView::OnBnClickedDeleteAllActivities()
{
	// TODO: Add your control notification handler code here
	CString deleteAllCommand = L"TRUNCATE table countries";
	db->executeQuery(deleteAllCommand);
}


void CountriesView::OnBnClickedRefresh()
{
	// TODO: Add your control notification handler code here
	CString query = L"SELECT * FROM countries order by 1 desc";
	retrieveData(query);
}

// Search on the values depanding on the filled Fields
void CountriesView::OnSearchChange() {
	GetDlgItemText(IDC_SEARCH_Countries_FIELD, countiresFieldValue);
	GetDlgItemText(IDC_SEARCH_Countries__Continent_FIELD, continentNumberValue);
	CString query = L"SELECT * FROM countries";
	if (continentNumberValue != "") {
		if (countiresFieldValue != "") {
			query += L" where no_country=" + countiresFieldValue;
			query += L" and no_continent= ";
			query += continentNumberValue;
		}
		else {
			query += L" where no_continent  = ";
			query += continentNumberValue;
		}
	}
	else {
		if (countiresFieldValue != "") {
			query += L" where no_country = " + countiresFieldValue;
		}
	}
	query += L" order by 1 desc";
	retrieveData(query);
}


void CountriesView::OnEnChangeSearchCountries()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	// TODO:  Add your control notification handler code here
	OnSearchChange();
}
