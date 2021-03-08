// DrawerView.cpp : implementation file
//

#include "pch.h"
#include "Jouwal.h"
#include "DrawerView.h"
#include "afxdialogex.h"


// DrawerView dialog

IMPLEMENT_DYNAMIC(DrawerView, CDialogEx)

DrawerView::DrawerView(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DRAWER_VIEW, pParent)
{
	Create(IDD_DRAWER_VIEW, pParent);

}
BOOL DrawerView::OnInitDialog() {
	CDialogEx::OnInitDialog();
	
	return TRUE;
}
DrawerView::~DrawerView()
{
}

void DrawerView::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BOOL DrawerView::OnEraseBkgnd(CDC* pDC)
{
	CRect rect;
	GetClientRect(&rect);
	CBrush myBrush(RGB(41, 2, 38));    // dialog background color
	CBrush* pOld = pDC->SelectObject(&myBrush);
	BOOL bRes = pDC->PatBlt(0, 0, rect.Width(), rect.Height(), PATCOPY);
	pDC->SelectObject(pOld);    // restore old brush
	return bRes;                       // CDialog::OnEraseBkgnd(pDC);
}

BEGIN_MESSAGE_MAP(DrawerView, CDialogEx)
	ON_WM_ERASEBKGND()

END_MESSAGE_MAP()


// DrawerView message handlers
