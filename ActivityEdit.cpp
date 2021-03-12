// ActivityEdit.cpp : implementation file
//

#include "pch.h"
#include "Jouwal.h"
#include "ActivityEdit.h"
#include "afxdialogex.h"


// ActivityEdit dialog

IMPLEMENT_DYNAMIC(ActivityEdit, CDialogEx)

ActivityEdit::ActivityEdit(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EDIT_ACTIVITY_DIALOG, pParent)
	, activityNumberValue(_T(""))
	, activityDesignationValue(_T(""))
{
//	Create(IDD_EDIT_ACTIVITY_DIALOG, pParent);

}

ActivityEdit::~ActivityEdit()
{
}

void ActivityEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ACTIVITY_NUMBER_EDIT_FIELD, activityNumberValue);
	DDX_Text(pDX, IDC_DESIGNATION_ACTIVITY_EDIT_FIELD, activityDesignationValue);
	DDX_Control(pDX, IDC_ACTIVITY_NUMBER_EDIT_FIELD, activityNumberFieldControll);
	DDX_Control(pDX, IDC_DESIGNATION_ACTIVITY_EDIT_FIELD, activityDesignationFieldControll);
	DDX_Control(pDX, IDC_EDIT_ACTIVITY_BUTTON, editButton);
	DDX_Control(pDX, IDCANCEL, cancelButton);
}


BEGIN_MESSAGE_MAP(ActivityEdit, CDialogEx)
	ON_WM_ERASEBKGND()

	ON_BN_CLICKED(IDC_EDIT_ACTIVITY_BUTTON, &ActivityEdit::OnBnClickedEditActivityButton)
	ON_BN_CLICKED(IDCANCEL, &ActivityEdit::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_ACTIVITY_NUMBER_EDIT_FIELD, &ActivityEdit::OnEnChangeActivityNumberEditField)
END_MESSAGE_MAP()

BOOL ActivityEdit::OnInitDialog() {
	CDialog::OnInitDialog();
	editButton.SetFaceColor(RGB(80, 40, 80), true);
	editButton.SetTextColor(RGB(255, 255, 255));
	
	cancelButton.SetFaceColor(RGB(80, 40, 80), true);
	cancelButton.SetTextColor(RGB(255, 255, 255));
	return TRUE;
}

BOOL ActivityEdit::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	CBrush myBrush(RGB(41, 8, 31));    // dialog background color
	CBrush* pOld = pDC->SelectObject(&myBrush);
	BOOL bRes = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOld);    // restore old brush
	return bRes;                       // CDialog::OnEraseBkgnd(pDC);
}

// ActivityEdit message handlers


void ActivityEdit::OnBnClickedEditActivityButton()
{
	// TODO: Add your control notification handler code here
	GetDlgItemText(IDC_ACTIVITY_NUMBER_EDIT_FIELD, activityNumberValue);
	GetDlgItemText(IDC_DESIGNATION_ACTIVITY_EDIT_FIELD, activityDesignationValue);
	CString activityNumber = L"";
	CString activityDesignation = L"";
	activityDesignationFieldControll.GetWindowTextW(activityDesignation);
	activityNumberFieldControll.GetWindowTextW(activityNumber);
	if (activityNumberValue == L"") {
		//TODO show warning
		return;
	}
	if (activityDesignationValue == L"Not Found" ) {
		//TODO show warning
		return;
	}
	// TODO UPDATE sql commande
	CString updateCommand = L"UPDATE ACTIVITIES SET designation = '" + activityDesignationValue + "' WHERE no_activities = " + activityNumber;
	db->executeQuery(updateCommand);
	OnOK();
}


void ActivityEdit::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void ActivityEdit::OnEnChangeActivityNumberEditField()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	getActivity();
}
void ActivityEdit::getActivity() {
	GetDlgItemText(IDC_ACTIVITY_NUMBER_EDIT_FIELD, activityNumberValue);
	if (activityNumberValue == "") {
		activityDesignationFieldControll.SetWindowTextW(TEXT("Not Found"));
		return;
	}
	CString query = L"SELECT * FROM activities";
		query += " where no_activities = ";
		query += activityNumberValue;
		query += " order by 1 desc";
	retrieveData(query);
}


void ActivityEdit::retrieveData(CString q) {

	//CString query = L"SELECT * FROM activities order by 1 desc";
	GetDlgItemText(IDC_ACTIVITY_NUMBER_EDIT_FIELD, activityNumberValue);
	/// Creating a db instance
	db = DbConnector::createDb();
	recset = db->retrieveQuery(q);

	if(!(recset->IsEOF())) {
		CString no = L"";
		recset->GetFieldValue(L"no_activities", no);

		CString field = L"";
		recset->GetFieldValue(L"designation", field);
		activityDesignationFieldControll.SetWindowTextW(field);

	}
	else {
		activityDesignationFieldControll.SetWindowTextW(TEXT("Not Found"));
	}

	recset->Close();

}
