#pragma once


// LanguageCreate dialog

class LanguageCreate : public CDialogEx
{
	DECLARE_DYNAMIC(LanguageCreate)

public:
	LanguageCreate(CWnd* pParent = nullptr);   // standard constructor
	virtual ~LanguageCreate();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ACTIVITES_ADD_VIEW1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
