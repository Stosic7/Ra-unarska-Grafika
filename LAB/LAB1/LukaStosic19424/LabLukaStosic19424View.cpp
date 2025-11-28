
// LabLukaStosic19424View.cpp : implementation of the CLabLukaStosic19424View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "LabLukaStosic19424.h"
#endif

#include "LabLukaStosic19424Doc.h"
#include "LabLukaStosic19424View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CLabLukaStosic19424View

IMPLEMENT_DYNCREATE(CLabLukaStosic19424View, CView)

BEGIN_MESSAGE_MAP(CLabLukaStosic19424View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CLabLukaStosic19424View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CLabLukaStosic19424View construction/destruction

CLabLukaStosic19424View::CLabLukaStosic19424View() noexcept
{
	// TODO: add construction code here

}

CLabLukaStosic19424View::~CLabLukaStosic19424View()
{
}

BOOL CLabLukaStosic19424View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}


void CLabLukaStosic19424View::DrawPinkTriangle(CDC* pDC, int x, int y, int size, COLORREF borderColor, int borderWidth, COLORREF fillColor) {
	int endX = x + size;
	int endY = y + size;

	POINT pts[3] = { CPoint(x, y), CPoint(endX, endY), CPoint(x, endY) };

	LOGBRUSH lb;
	lb.lbStyle = BS_SOLID;
	lb.lbColor = borderColor;

	CPen* pen = new CPen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_FLAT | PS_JOIN_ROUND, borderWidth, &lb);
	CPen* pOldPen = pDC->SelectObject(pen);

	CBrush brush(fillColor);
	CBrush* pOldBrush = pDC->SelectObject(&brush);

	pDC->Polygon(pts, 3);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

void CLabLukaStosic19424View::DrawYellowTriangle(CDC* pDC, int x, int y, int size, COLORREF borderColor, int borderWidth, COLORREF fillColor) {
	int endX = x + size;
	int endY = y + size;

	POINT pts[3] = { CPoint(x, y), CPoint(endX, endY), CPoint(endX, y) };

	LOGBRUSH lb;
	lb.lbStyle = BS_SOLID;
	lb.lbColor = borderColor;

	CPen* pen = new CPen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_FLAT | PS_JOIN_ROUND, borderWidth, &lb);
	CPen* pOldPen = pDC->SelectObject(pen);

	CBrush brush(fillColor);
	CBrush* pOldBrush = pDC->SelectObject(&brush);

	pDC->Polygon(pts, 3);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

void CLabLukaStosic19424View::DrawOrangeTriangle(CDC* pDC, int x, int y, int size, COLORREF borderColor, int borderWidth, COLORREF fillColor) {
	int cx = x + size / 2;
	int by = y + size / 2;
	int endX = x + size;
	int endY = y + size;

	POINT pts[3] = { CPoint(endX, by), CPoint(endX, endY), CPoint(cx, endY) };

	LOGBRUSH lb;
	lb.lbStyle = BS_SOLID;
	lb.lbColor = borderColor;

	CPen* pen = new CPen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_FLAT | PS_JOIN_ROUND, borderWidth, &lb);
	CPen* pOldPen = pDC->SelectObject(pen);

	CBrush brush(fillColor);
	CBrush* pOldBrush = pDC->SelectObject(&brush);

	pDC->Polygon(pts, 3);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

void CLabLukaStosic19424View::DrawRedSquare(CDC* pDC, int x, int y, int size, COLORREF borderColor, int borderWidth, COLORREF fillColor) {
	int cx = x + size / 2;
	int by = y + size / 2;
	int end = x + size;

	LOGBRUSH lb;
	lb.lbStyle = BS_SOLID;
	lb.lbColor = borderColor;

	CPen* pen = new CPen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_FLAT | PS_JOIN_ROUND, borderWidth, &lb);
	CPen* pOldPen = pDC->SelectObject(pen);

	CBrush brush(fillColor);
	CBrush* pOldBrush = pDC->SelectObject(&brush);

	pDC->Rectangle(cx, y, end, by);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

void CLabLukaStosic19424View::DrawPurpleTriange(CDC* pDC, int x, int y, int size, COLORREF borderColor, int borderWidth, COLORREF fillColor) {
	int cx = x + size / 2;

	POINT pts[3] = { CPoint(x,y), CPoint(cx, cx), CPoint(cx, y) };

	LOGBRUSH lb;
	lb.lbStyle = BS_SOLID;
	lb.lbColor = borderColor;

	CPen* pen = new CPen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_FLAT | PS_JOIN_ROUND, borderWidth, &lb);
	CPen* pOldPen = pDC->SelectObject(pen);

	CBrush brush(fillColor);
	CBrush* pOldBrush = pDC->SelectObject(&brush);

	pDC->Polygon(pts, 3);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

void CLabLukaStosic19424View::DrawBigGreenTriangle(CDC* pDC, int x, int y, int size, COLORREF borderColor, int borderWidth, COLORREF fillColor) {
	int cx = x + size / 2;
	int by = y + size;

	POINT pts[3] = { CPoint(x,y), CPoint(cx, cx), CPoint(x, by) };

	LOGBRUSH lb;
	lb.lbStyle = BS_SOLID;
	lb.lbColor = borderColor;                   

	CPen* pen = new CPen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_FLAT | PS_JOIN_ROUND, borderWidth, &lb);
	CPen* pOldPen = pDC->SelectObject(pen);

	CBrush brush(fillColor);
	CBrush* pOldBrush = pDC->SelectObject(&brush);

	pDC->Polygon(pts, 3);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

void CLabLukaStosic19424View::DrawSquare(CDC* pDC, int x, int y, int size, COLORREF borderColor, int borderWidth, COLORREF fillColor) {
	LOGBRUSH logBrush;
	logBrush.lbStyle = BS_SOLID;
	logBrush.lbColor = RGB(0, 255, 255);
	CPen* pen = new CPen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_FLAT | PS_JOIN_ROUND, borderWidth, &logBrush);
	CPen* pOldPen = pDC->SelectObject(pen);

	CBrush brush(HS_CROSS, RGB(200, 220, 255));
	CBrush* pOldBrush = pDC->SelectObject(&brush);

	pDC->Rectangle(x, y, x + size, y + size);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);
}

void CLabLukaStosic19424View::FillBackground(CDC* pDC, COLORREF backColor) {
	CRect rcClient;
	GetClientRect(&rcClient);

	CBrush brush(backColor);
	CBrush* pOldBrush = pDC->SelectObject(&brush);
	pDC->Rectangle(rcClient);

	pDC->SelectObject(pOldBrush);
}

void CLabLukaStosic19424View::DrawGrid(CDC* pDC, int cellSize, COLORREF color) {
	const int width = 500;
	const int height = 500;

	CPen pen(PS_SOLID, 1, color);
	CPen* oldPen = pDC->SelectObject(&pen);

	// vertikalne
	for (int x = 0; x <= width; x += cellSize) {
		pDC->MoveTo(x, 0);
		pDC->LineTo(x, height);
	}

	// horizontalne
	for (int y = 0; y <= height; y += cellSize) {
		pDC->MoveTo(0, y);
		pDC->LineTo(width, y);
	}

	pDC->SelectObject(oldPen);
}

void CLabLukaStosic19424View::OnDraw(CDC* pDC)
{
	CLabLukaStosic19424Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	FillBackground(pDC, RGB(180, 180, 180));
	DrawGrid(pDC, 20, RGB(240, 240, 240));

	const int sizeBlock = 12 * 20;
	int centerXgreen = 10 + (sizeBlock / 2) / 2;
	int centerYgreen = 20 + sizeBlock / 2;

	DrawSquare(pDC, 20, 20, sizeBlock , RGB(0, 255, 255), 3, RGB(0, 255, 255));
	DrawBigGreenTriangle(pDC, 20, 20, sizeBlock, RGB(0, 255, 255), 3, RGB(0, 200, 0));
	DrawPurpleTriange(pDC, 20, 20, sizeBlock, RGB(0, 255, 255), 3, RGB(150, 0, 150));
	DrawRedSquare(pDC, 20, 20, sizeBlock, RGB(0, 255, 255), 3, RGB(255, 0, 0));
	DrawOrangeTriangle(pDC, 20, 20, sizeBlock, RGB(0, 255, 255), 3, RGB(255, 165, 0));
	
	const int sizeBlock2 = 11 * 20;
	DrawSquare(pDC, 260, 260, sizeBlock2, RGB(0, 255, 255), 3, RGB(0, 255, 255));
	DrawYellowTriangle(pDC, 260, 260, sizeBlock2, RGB(0, 255, 255), 3, RGB(255, 255, 0));
	DrawPinkTriangle(pDC, 260, 260, sizeBlock2, RGB(0, 255, 255), 3, RGB(255, 105, 180));

}


// CLabLukaStosic19424View printing


void CLabLukaStosic19424View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CLabLukaStosic19424View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLabLukaStosic19424View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLabLukaStosic19424View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CLabLukaStosic19424View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CLabLukaStosic19424View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CLabLukaStosic19424View diagnostics

#ifdef _DEBUG
void CLabLukaStosic19424View::AssertValid() const
{
	CView::AssertValid();
}

void CLabLukaStosic19424View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLabLukaStosic19424Doc* CLabLukaStosic19424View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLabLukaStosic19424Doc)));
	return (CLabLukaStosic19424Doc*)m_pDocument;
}
#endif //_DEBUG


// CLabLukaStosic19424View message handlers
