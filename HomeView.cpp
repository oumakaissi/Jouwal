// HomeView.cpp : implementation file
//

#include "pch.h"
#include "Jouwal.h"
#include "HomeView.h"
#include "afxdialogex.h"


// HomeView dialog

IMPLEMENT_DYNAMIC(HomeView, CDialogEx)

HomeView::HomeView(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HOME_VIEW, pParent)
{
	Create(IDD_HOME_VIEW, pParent);

}
BOOL HomeView::OnInitDialog() {
	CDialogEx::OnInitDialog();


	return TRUE;
}

BOOL HomeView::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	CBrush myBrush(RGB(49, 8, 31));    // dialog background color
	CBrush* pOld = pDC->SelectObject(&myBrush);
	BOOL bRes = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOld);    // restore old brush
	return bRes;                       // CDialog::OnEraseBkgnd(pDC);
}


HomeView::~HomeView()
{
}

void HomeView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(HomeView, CDialogEx)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// HomeView message handlers
