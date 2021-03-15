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
	ON_BN_CLICKED(IDCANCEL, &VillageEdit::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &VillageEdit::OnBnClickedOk)
	ON_BN_CLICKED(IDC_VILLAGE_EDIT_BUTTON, &VillageEdit::OnBnClickedVillageEditButton)
	ON_EN_CHANGE(IDC_VILLAGE_NUMBER_FIELD, &VillageEdit::OnEnChangeVillageNumberField)
	ON_BN_CLICKED(IDC_add_language_to_village, &VillageEdit::OnBnClickedaddlanguagetovillage)
	ON_BN_CLICKED(IDC_remove_Language_from_village, &VillageEdit::OnBnClickedremoveLanguagefromvillage)
	ON_BN_CLICKED(IDC_add_aactivity_to_village_button, &VillageEdit::OnBnClickedaddaactivitytovillagebutton)
	ON_BN_CLICKED(IDC_remove_activity_from_village, &VillageEdit::OnBnClickedremoveactivityfromvillage)
END_MESSAGE_MAP()


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
