// VillageEdit.cpp : implementation file
//

#include "pch.h"
#include "Jouwal.h"
#include "VillageEdit.h"
#include "afxdialogex.h"


// VillageEdit dialog

IMPLEMENT_DYNAMIC(VillageEdit, CDialogEx)

VillageEdit::VillageEdit(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_VILLAGE_EDIT, pParent)
	, villageNumberValue(_T(""))
	, villageNameValue(_T(""))
	, countryNumberValue(_T(""))
	, activityNumberValue(_T(""))
	, activityGratuiteValue(_T(""))
	, languageNumberValue(_T(""))
{

}

VillageEdit::~VillageEdit()
{
}
BOOL VillageEdit::OnInitDialog() {
	CDialogEx::OnInitDialog();
	// Coloring the buttons
	addLanguageButton.SetFaceColor(RGB(80, 40, 80), true);
	addLanguageButton.SetTextColor(RGB(255, 255, 255));

	removeLanguageButton.SetFaceColor(RGB(80, 40, 80), true);
	removeLanguageButton.SetTextColor(RGB(255, 255, 255));

	addActivityButton.SetFaceColor(RGB(80, 40, 80), true);
	addActivityButton.SetTextColor(RGB(255, 255, 255));

	removeActivityButton.SetFaceColor(RGB(80, 40, 80), true);
	removeActivityButton.SetTextColor(RGB(255, 255, 255));

	editButton.SetFaceColor(RGB(80, 40, 80), true);
	editButton.SetTextColor(RGB(255, 255, 255));

	//Setting up the List
	activitiesList.InsertColumn(0, L"no_activity", LVCFMT_CENTER, 80, -1);
	activitiesList.InsertColumn(1, L"designation", LVCFMT_CENTER, 180, -1);

	languagesList.InsertColumn(0, L"no_language", LVCFMT_CENTER, 80, -1);
	languagesList.InsertColumn(1, L"nom", LVCFMT_CENTER, 180, -1);

	//Filling the list

	//retrieveActivites(query);

	return TRUE;
}
void VillageEdit::retrieveVillages(CString q) {
	db = DbConnector::createDb();
	recset = db->retrieveQuery(q);
	int i = 0;
	if(!(recset->IsEOF())) {
		CString no = L"";
		recset->GetFieldValue(L"no_village", no);

		CString field = L"";
		recset->GetFieldValue(L"nom", field);
		villageNameControl.SetWindowTextW(field);

		CString field2 = L"";
		recset->GetFieldValue(L"no_country", field2);
		villageCountryNumberControl.SetWindowTextW(field2);
	}

	recset->Close();
}
void VillageEdit::retrieveLanguages(CString q) {

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

void VillageEdit::retrieveActivities(CString q) {

	activitiesList.DeleteAllItems();
	//CString query = L"SELECT * FROM activities order by 1 desc";

	/// <summary>
	/// Creating a db instance
	/// </summary>
	db = DbConnector::createDb();
	recset = db->retrieveQuery(q);
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
void VillageEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_VILLAGE_NUMBER_FIELD, villageNumberValue);
	DDX_Text(pDX, IDC_VILLAGE_NAME_FIELD, villageNameValue);
	DDX_Text(pDX, IDC_VILLAGE_COUNTRY_NUMBER_FIELD, countryNumberValue);
	DDX_Text(pDX, IDC_ACTIVITY_NUMBER_FIELD, activityNumberValue);
	DDX_Text(pDX, IDC_GRATUITE_FIELD, activityGratuiteValue);
	DDX_Text(pDX, IDC_LANGUAGE_NUMBER_FIELD, languageNumberValue);
	DDX_Control(pDX, IDC_ACTIVITY_NUMBER_FIELD, villageActivityNumberEditField);
	DDX_Control(pDX, IDC_GRATUITE_FIELD, villageActivityGratuiteEditField);
	DDX_Control(pDX, IDC_LANGUAGE_NUMBER_FIELD, villageLanguageNumberEditField);
	DDX_Control(pDX, IDC_add_language_to_village, addLanguageButton);
	DDX_Control(pDX, IDC_remove_Language_from_village, removeLanguageButton);
	DDX_Control(pDX, IDC_add_aactivity_to_village_button, addActivityButton);
	DDX_Control(pDX, IDC_remove_activity_from_village, removeActivityButton);
	DDX_Control(pDX, IDC_VILLAGE_EDIT_BUTTON, editButton);
	DDX_Control(pDX, IDC_VILLAGE_LANGUAGES_LIST, languagesList);
	DDX_Control(pDX, IDC_VILLAGE_ACTIVITY_LIST, activitiesList);
	DDX_Control(pDX, IDC_VILLAGE_NAME_FIELD, villageNameControl);
	DDX_Control(pDX, IDC_VILLAGE_COUNTRY_NUMBER_FIELD, villageCountryNumberControl);
	DDX_Control(pDX, IDC_VILLAGE_NUMBER_FIELD, villageNumberControl);
}


BEGIN_MESSAGE_MAP(VillageEdit, CDialogEx)
	ON_WM_ERASEBKGND()

	ON_BN_CLICKED(IDCANCEL, &VillageEdit::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &VillageEdit::OnBnClickedOk)
	ON_BN_CLICKED(IDC_VILLAGE_EDIT_BUTTON, &VillageEdit::OnBnClickedVillageEditButton)
	ON_EN_CHANGE(IDC_VILLAGE_NUMBER_FIELD, &VillageEdit::OnEnChangeVillageNumberField)
	ON_BN_CLICKED(IDC_add_language_to_village, &VillageEdit::OnBnClickedaddlanguagetovillage)
	ON_BN_CLICKED(IDC_remove_Language_from_village, &VillageEdit::OnBnClickedremoveLanguagefromvillage)
	ON_BN_CLICKED(IDC_add_aactivity_to_village_button, &VillageEdit::OnBnClickedaddaactivitytovillagebutton)
	ON_BN_CLICKED(IDC_remove_activity_from_village, &VillageEdit::OnBnClickedremoveactivityfromvillage)
END_MESSAGE_MAP()


BOOL VillageEdit::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	CBrush myBrush(RGB(41, 8, 31));    // dialog background color
	CBrush* pOld = pDC->SelectObject(&myBrush);
	BOOL bRes = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOld);    // restore old brush
	return bRes;                       // CDialog::OnEraseBkgnd(pDC);
}
// VillageEdit message handlers


void VillageEdit::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void VillageEdit::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void VillageEdit::OnBnClickedMfcbutton4()
{
	// TODO: Add your control notification handler code here
}


void VillageEdit::OnBnClickedMfcbutton5()
{
	// TODO: Add your control notification handler code here
}


void VillageEdit::OnBnClickedMfcbutton2()
{
	// TODO: Add your control notification handler code here
}


void VillageEdit::OnBnClickedMfcbutton3()
{
	// TODO: Add your control notification handler code here
}


void VillageEdit::OnBnClickedVillageEditButton()
{
	// TODO: Add your control notification handler code here
}


void VillageEdit::OnEnChangeVillageNumberField()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	GetDlgItemText(IDC_VILLAGE_NUMBER_FIELD, villageNumberValue);
	
	CString q = L"select * from villages";
	if (villageNumberValue != L"") {
		q += L" where no_village = " + villageNumberValue;
	}
	else {
		q += " where no_village = -1";
	}
	retrieveVillages(q);

	CString query = L"SELECT * FROM activities";
	if (villageNumberValue != L"") {

		query += " where no_activities in (select no_activities from proposer where no_village = ";
		query += villageNumberValue;
		query += " )";
	}
	else {
		query += " where no_activities = -1";
	}
	query += " order by 1 desc";
	retrieveActivities(query);

	// Languages Retrieve
	query = L"SELECT * FROM languages";
	if (villageNumberValue != L"") {

		query += " where no_language in (select no_language from parler where no_village = ";
		query += villageNumberValue;
		query += " )";
	}
	else {
		query += " where no_language = -1";
	}
	query += " order by 1 desc";
	retrieveLanguages(query);

	// TODO:  Add your control notification handler code here
}


void VillageEdit::OnBnClickedaddlanguagetovillage()
{
	// TODO: Add your control notification handler code here
}


void VillageEdit::OnBnClickedremoveLanguagefromvillage()
{
	// TODO: Add your control notification handler code here
}


void VillageEdit::OnBnClickedaddaactivitytovillagebutton()
{
	// TODO: Add your control notification handler code here
}


void VillageEdit::OnBnClickedremoveactivityfromvillage()
{
	// TODO: Add your control notification handler code here
}
