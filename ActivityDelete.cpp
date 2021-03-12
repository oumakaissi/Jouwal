// ActivityDelete.cpp : implementation file
//

#include "pch.h"
#include "Jouwal.h"
#include "ActivityDelete.h"
#include "afxdialogex.h"


// ActivityDelete dialog

IMPLEMENT_DYNAMIC(ActivityDelete, CDialogEx)

ActivityDelete::ActivityDelete(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ACTIVITY_DELETE, pParent)
	, activityNumberValue(_T(""))
{

}

ActivityDelete::~ActivityDelete()
{
}

void ActivityDelete::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_ACTIVITY_DELETE_NUMBER, activityNumberValue);
	DDX_Control(pDX, IDO_ACTIVITY_DELETE_BUTTON, deleteButton);
	DDX_Control(pDX, IDCANCEL, cancelButton);
}


BEGIN_MESSAGE_MAP(ActivityDelete, CDialogEx)
	ON_WM_ERASEBKGND()

	ON_BN_CLICKED(IDO_ACTIVITY_DELETE_BUTTON, &ActivityDelete::OnBnClickedActivityDeleteButton)
END_MESSAGE_MAP()

BOOL ActivityDelete::OnInitDialog() {
	CDialog::OnInitDialog();
	deleteButton.SetFaceColor(RGB(80, 40, 80), true);
	deleteButton.SetTextColor(RGB(255, 255, 255));

	cancelButton.SetFaceColor(RGB(80, 40, 80), true);
	cancelButton.SetTextColor(RGB(255, 255, 255));
	return TRUE;
}

BOOL ActivityDelete::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	CBrush myBrush(RGB(41, 8, 31));    // dialog background color
	CBrush* pOld = pDC->SelectObject(&myBrush);
	BOOL bRes = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOld);    // restore old brush
	return bRes;                       // CDialog::OnEraseBkgnd(pDC);
}
// ActivityDelete message handlers


void ActivityDelete::OnBnClickedActivityDeleteButton()
{
	// TODO: Add your control notification handler code here
	db = DbConnector::createDb();
	GetDlgItemText(IDC_ACTIVITY_DELETE_NUMBER, activityNumberValue);
	if (activityNumberValue == "") {
		OnOK();
	}
	CString deleteCommand = L"delete from activities where no_activities = " + activityNumberValue;
		//+ activityNumberValue;
	db->executeQuery(deleteCommand);
	OnOK();


}
