//-----------------------------------------------------------------------------
// wxD - NotebookSizer.d
// (C) 2005 bero <berobero@users.sourceforge.net>
// based on
// wx.NET - NotebookSizer.cs
//
/// The wxNotebookSizer proxy interface.
//
// Written by Bryan Bulten (bryan@bulten.ca)
// (C) 2003 Bryan Bulten
// Licensed under the wxWidgets license, see LICENSE.txt for details.
//
// $Id$
//-----------------------------------------------------------------------------

module wx.NotebookSizer;
import wx.common;
import wx.Sizer;
import wx.Notebook;

		//! \cond EXTERN
		static extern (C) IntPtr wxNotebookSizer_ctor(IntPtr nb);
		static extern (C) void wxNotebookSizer_RecalcSizes(IntPtr self);
		static extern (C) void wxNotebookSizer_CalcMin(IntPtr self, inout Size size);
		static extern (C) IntPtr wxNotebookSizer_GetNotebook(IntPtr self);
		//! \endcond

		//---------------------------------------------------------------------

	alias NotebookSizer wxNotebookSizer;
	public class NotebookSizer : Sizer
	{
		public this(IntPtr wxobj)
		{
			super(wxobj);
		}

		public this(Notebook nb)
		{
			super(wxNotebookSizer_ctor(wxObject.SafePtr(nb)));
		}

		//---------------------------------------------------------------------

		public override void RecalcSizes()
		{
			wxNotebookSizer_RecalcSizes(wxobj);
		}

		//---------------------------------------------------------------------

		public override Size CalcMin()
		{
			Size size;
			wxNotebookSizer_CalcMin(wxobj, size);
			return size;
		}

		//---------------------------------------------------------------------

		public Notebook notebook() 
			{
				return cast(Notebook)FindObject(
                                    wxNotebookSizer_GetNotebook(wxobj)
                                );
			}

		//---------------------------------------------------------------------
	}
