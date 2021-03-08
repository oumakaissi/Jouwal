#pragma once


// ActivitesAdd dialog

class ActivitesAdd : public CDialogEx
{
	DECLARE_DYNAMIC(ActivitesAdd)

public:
	ActivitesAdd(CWnd* pParent = nullptr);   // standard constructor
	virtual ~ActivitesAdd();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ACTIVITES_ADD_VIEW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:

};
