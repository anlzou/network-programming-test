//Download by www.cctry.com
#if !defined(AFX_BITBUTTONNL_H__413ED251_E607_4CAB_8868_B58825104543__INCLUDED_)
#define AFX_BITBUTTONNL_H__413ED251_E607_4CAB_8868_B58825104543__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//add new
#define	BTNNL_USE_SOUND				//声音可用

#define BTNNL_COLOR_FG_NORMAL	0
#define BTNNL_COLOR_FG_CLICK	1
#define BTNNL_COLOR_FG_HIGH		2

#define NL_ALIGN_LEFT			0
#define NL_ALIGN_RIGHT			1
#define NL_ALIGN_CENTER			2

// BitButtonNL.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBitButtonNL window

class CBitButtonNL : public CButton
{
// Construction
public:
	CBitButtonNL();

private:
	typedef struct _STRUCT_BITMAPS		//位图信息结构体
	{
		HBITMAP		hBitmap;
		DWORD		dwWidth;
		DWORD		dwHeight;
	} STRUCT_BITMAPS;

#ifdef	BTNNL_USE_SOUND
#pragma pack(1)
	typedef struct _STRUCT_SOUND
	{
		TCHAR		szSound[_MAX_PATH];
		LPCTSTR		lpszSound;
		HMODULE		hMod;
		DWORD		dwFlags;
	} STRUCT_SOUND;
#pragma pack()

	STRUCT_SOUND	m_csSounds[2];	// Index 0 = Over	1 = Clicked

#endif

	STRUCT_BITMAPS	m_csBitmaps[4];	// Button bitmap
	COLORREF	m_crForceColors[3];	// Colors to be used

	BOOL		m_bMouseOnButton;	// Is mouse over the button?
	POINT		m_ptPressedOffset;	// 偏移量
	BOOL		m_bIsPressed;		// Is button pressed?
	BOOL		m_bIsFocused;		// Is button focused?
	BOOL		m_bIsDisabled;		// Is button disabled?
	BOOL		m_bDrawText;		// Draw Text for button?
	BOOL		m_bDrawFlatFocus;	// Draw focus rectangle for flat button?
	int			m_iDeflateRect_x;	// DrawFlateFouse deflate rect _ x
	int			m_iDeflateRect_y;	// DrawFlateFouse deflate rect _ y
	HCURSOR		m_hCursor;			// Handle to cursor
	UINT		m_nTypeStyle;		// Button style
	BOOL		m_bIsDefault;		// Is default button?

	//与字体有关的变量
	CFont		m_font;
	LOGFONT		m_lf;
	BYTE		m_byTextAlign;		// Align text
	BOOL		m_bDrawDisableText;	// is Draw text as disable?
	BOOL		m_bFont3d;
	COLORREF	m_cr3DBKColor;
	int			m_iText3d_x, m_iText3d_y;

private:
	void FreeResources(BOOL bCheckForNULL = TRUE);
	//绘制背景图像
	virtual void DrawTheBitmap(CDC* pDC,  RECT* rpItem, 
					 BOOL bIsPressed, BOOL bIsDisabled);
	//绘制文本
	virtual void DrawTheText(CDC* pDC, LPCTSTR lpszText, RECT* rpItem,
					CRect* rpCaption, BOOL bIsPressed, BOOL bIsDisabled);
	//鼠标离开事件
	LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);

	//恢复按钮正常情况下的样子
	void CancelHover(void);
	//重构字体
	void ReconstructFont(void);

// Attributes
public:

// Operations
public:
	//设置按钮位图图像
	BOOL SetBitmaps(UINT nBitmapNormal, UINT nBitmapMouseDown = NULL, 
					UINT nBitmapHigh = NULL, UINT nBitmapDisable = NULL);
	BOOL SetBitmaps(HBITMAP hBitmapNormal, HBITMAP hBitmapMouseDown = NULL,
					HBITMAP hBitmapHigh = NULL, HBITMAP hBitmapDisable = NULL);
	//设置字体颜色
	BOOL SetForceColor(COLORREF crColorNormal, COLORREF crColorMouseDown, 
					   COLORREF crColorHigh, BOOL bRepaint = TRUE);
	//设置按钮自适应第一个位图大小
	void SizeToContent(void);
	//设置热敏鼠标指针
	BOOL SetBtnCursor(int nCursorId = NULL, BOOL bRepaint = TRUE);
	//设置是否显示按钮文字
	virtual CBitButtonNL& SetDrawText(BOOL bDraw = TRUE, BOOL bRepaint = TRUE);
	//设置 3d 字体
	virtual CBitButtonNL& SetFont3D(BOOL bSet, int i3dx = 3, int i3dy = 2, BOOL bRepaint = TRUE);
	//设置 3d 字体 阴影色彩
	virtual CBitButtonNL& SetText3DBKColor(COLORREF cr3DBKColor, BOOL bRepaint = TRUE);
	//设置字体是否为粗体
	virtual CBitButtonNL& SetFontBold(BOOL bBold, BOOL bRepaint = TRUE);
	//设置字体字号
	virtual CBitButtonNL& SetFontSize(int nSize, BOOL bRepaint = TRUE);
	//设置字体名称
	virtual CBitButtonNL& SetFontName(const CString& strFont, BYTE byCharSet = DEFAULT_CHARSET,
									  BOOL bRepaint = TRUE);
	//设置按钮文字排列方式
	BOOL SetTextAlign(BYTE byAlign, BOOL bRepaint = TRUE);

#ifdef	BTNNL_USE_SOUND

	BOOL SetSound(LPCTSTR lpszSound, HMODULE hMod = NULL, BOOL bPlayOnClick = FALSE,
				  BOOL bPlayAsync = TRUE);
#endif

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitButtonNL)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CBitButtonNL();

	// Generated message map functions
protected:
	//{{AFX_MSG(CBitButtonNL)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg BOOL OnClicked();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITBUTTONNL_H__413ED251_E607_4CAB_8868_B58825104543__INCLUDED_)
