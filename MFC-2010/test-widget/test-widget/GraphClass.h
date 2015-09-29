#pragma once


// CGraphClass

class CGraphClass : public CStatic
{
	DECLARE_DYNAMIC(CGraphClass)

public:
	CGraphClass();
	virtual ~CGraphClass();

protected:
	DECLARE_MESSAGE_MAP()
public:
	void CraeteGraph(void);
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};


