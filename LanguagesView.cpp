// LanguagesView.cpp : implementation file
//

#include "pch.h"
#include "Jouwal.h"
#include "LanguagesView.h"
#include "afxdialogex.h"
#include "LanguagesCreate.h"


// LanguagesView dialog

IMPLEMENT_DYNAMIC(LanguagesView, CDialogEx)

LanguagesView::LanguagesView(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LANGUAGES_View, pParent)
	, languageNumberValue(_T(""))
	, villageNumberValue(_T(""))
{
	Create(IDD_LANGUAGES_View, pParent);

}

LanguagesView::~LanguagesView()
{
}

BOOL LanguagesView::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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
	languagesList.InsertColumn(0, L"no_language", LVCFMT_CENTER, 80, -1);
	languagesList.InsertColumn(1, L"designation", LVCFMT_CENTER, 180, -1);
	//Filling the list
	CString query = L"SELECT * FROM languages order by 1 desc";
	retrieveData(query);
	return TRUE;
}

void LanguagesView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SEARCH, searchButton);
	DDX_Control(pDX, IDC_ADD, addButton);
	DDX_Control(pDX, IDC_EDIT, editButton);
	DDX_Control(pDX, IDC_DELETE_ONE, deleteOneButton);
	DDX_Control(pDX, IDC_DELETE_ALL, deleteAllButton);
	DDX_Control(pDX, IDC_REFRESH, refreshButton);
	DDX_Control(pDX, IDC_languages_LIST, languagesList);
	DDX_Text(pDX, IDC_SEARCH_languages_FIELD, languageNumberValue);
	DDX_Text(pDX, IDC_VILLAGE_NUMBER_FIELD_Language, villageNumberValue);
}


BEGIN_MESSAGE_MAP(LanguagesView, CDialogEx)
	ON_WM_ERASEBKGND()
ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_DELETE_ALL, &LanguagesView::OnBnClickedDeleteAll)
	ON_BN_CLICKED(IDC_DELETE_ONE, &LanguagesView::OnBnClickedDeleteOne)
	ON_BN_CLICKED(IDC_EDIT, &LanguagesView::OnBnClickedEdit)
	ON_BN_CLICKED(IDC_ADD, &LanguagesView::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_SEARCH, &LanguagesView::OnBnClickedSearch)
	ON_BN_CLICKED(IDC_REFRESH, &LanguagesView::OnBnClickedRefresh)
	ON_EN_CHANGE(IDC_SEARCH_languages_FIELD, &LanguagesView::OnEnChangeSearchlanguagesField)
	ON_EN_CHANGE(IDC_VILLAGE_NUMBER_FIELD_Language, &LanguagesView::OnEnChangeVillageNumberFieldActivity)
END_MESSAGE_MAP()

HBRUSH LanguagesView::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
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

BOOL LanguagesView::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	CBrush myBrush(RGB(41, 8, 31));    // dialog background color
	CBrush* pOld = pDC->SelectObject(&myBrush);
	BOOL bRes = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOld);    // restore old brush
	return bRes;                       // CDialog::OnEraseBkgnd(pDC);
}


// LanguagesView message handlers
void LanguagesView::retrieveData(CString q) {

	languagesList.DeleteAllItems();
	//CString query = L"SELECT * FROM activities order by 1 desc";

	/// <summary>
	/// Creating a db instance
	/// </summary>
	db = DbConnector::createDb();
	recset = db->retrieveQuery(q);
	int i = 0;
	while (!(recset->IsEOF())) {
		CString no = L"";
		recset->GetFieldValue(L"no_language", no);

		CString field = L"";
		recset->GetFieldValue(L"designation", field);

		languagesList.InsertItem(i, no, 0);
		languagesList.SetItemText(i, 1, field);
		i++;
		recset->MoveNext();
	}

	recset->Close();

}

void LanguagesView::OnSearchChange() {
	GetDlgItemText(IDC_SEARCH_languages_FIELD, languageNumberValue);
	GetDlgItemText(IDC_VILLAGE_NUMBER_FIELD_Language, villageNumberValue);

	CString query = L"SELECT * FROM languages";
	if (villageNumberValue != "") {
		if (languageNumberValue != "") {
			query += L" where no_language=" + languageNumberValue;
			query += L" and no_language in ( select no_language from parler where no_village = ";
			query += villageNumberValue;
			query += ")";
		}
		else {
			query += L" where no_language in ( select no_language from parler where no_village = ";
			query += villageNumberValue;
			query += ")";
		}
	}
	else {
		if (languageNumberValue != "") {
			query += L" where no_language=" + languageNumberValue;
		}
	}
	query += L" order by 1 desc";
	retrieveData(query);
}




void LanguagesView::OnBnClickedDeleteAll()
{
	// TODO: Add your control notification handler code here
}


void LanguagesView::OnBnClickedDeleteOne()
{
	// TODO: Add your control notification handler code here
}


void LanguagesView::OnBnClickedEdit()
{
	// TODO: Add your control notification handler code here
}


void LanguagesView::OnBnClickedAdd()
{
	// TODO: Add your control notification handler code here
	LanguagesCreate languagesCreate = new LanguagesCreate();
	languagesCreate.DoModal();
}


void LanguagesView::OnBnClickedSearch()
{
	// TODO: Add your control notification handler code here
}


void LanguagesView::OnBnClickedRefresh()
{
	// TODO: Add your control notification handler code here
	CString query = L"SELECT * FROM languages order by 1 desc";
	retrieveData(query);
}


void LanguagesView::OnEnChangeSearchlanguagesField()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	OnSearchChange();
}


void LanguagesView::OnEnChangeVillageNumberFieldActivity()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	OnSearchChange();
}
