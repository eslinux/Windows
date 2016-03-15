#pragma once
#include <list>
#include "soapStub.h"


typedef std::list<int> SysGraphData_t;
typedef std::list<int>::iterator SysGraphDataIt_t;

// SystemGraph

class SystemGraph : public CStatic
{
	DECLARE_DYNAMIC(SystemGraph)

public:
	SystemGraph();
	virtual ~SystemGraph();

protected:
	DECLARE_MESSAGE_MAP()
public:
	void CraeteGraph(void);
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	void ChangeMode(enum SysGraphMode_t mode);
	enum SysGraphMode_t m_graphMode;

	CPen m_axisPen;
	CPen m_graphPen;
	CBrush m_hbrBkGnd;
	int m_nSave;
	RECT m_rectGraphDim;
	SysGraphData_t *m_dataList;
	void SetGraphData(SysGraphData_t * data);
};


