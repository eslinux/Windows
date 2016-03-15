#pragma once
#include <vector>
#include "soapStub.h"


typedef std::vector<std::string> AxisText_t;
class GraphAxis_t{
public:
	int xOriginCoord;
	int yOriginCoord;

	int xWidth;
	int yWidth;

	int xMaxValue;
	int yMaxValue;

	int xAxisNumPoint;
	int yAxisNumPoint;

	int xPenNumPoint;
	int yPenNumPoint;

	int xTextXoffset;
	int xTextYoffset;

	int yTextXoffset;
	int yTextYoffset;

	AxisText_t xText;
	AxisText_t yText;
};


// GraphClass

class GraphClass : public CStatic
{
	DECLARE_DYNAMIC(GraphClass)

public:
	GraphClass();
	virtual ~GraphClass();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	void DrawGraph(void);

	CBrush m_hbrBkGnd;//clear old painted
	CPen m_axisPen;
	GraphAxis_t m_axisPara;


	int m_saveDc;
	RECT m_rectGraphDim;

	enum SysGraphMode_t m_graphMode;

	std::vector<GraphData_t> *m_listData;
	CPen m_listPen[5];//Maximum 5 pen;
	int m_numPen;

};


