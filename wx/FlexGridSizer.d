//-----------------------------------------------------------------------------
// wxD - FlexGridSizer.d
// (C) 2005 bero <berobero@users.sourceforge.net>
// based on
// wx.NET - FlexGridSizer.cs
//
/// The wxFlexGridSizer proxy interface.
//
// Written by Bryan Bulten (bryan@bulten.ca)
// (C) 2003 Bryan Bulten
// Licensed under the wxWidgets license, see LICENSE.txt for details.
//
// $Id$
//-----------------------------------------------------------------------------

module wx.FlexGridSizer;
import wx.common;
import wx.GridSizer;

		//! \cond EXTERN
		static extern (C) IntPtr wxFlexGridSizer_ctor(int rows, int cols, int vgap, int hgap);
		static extern (C) void wxFlexGridSizer_dtor(IntPtr self);
		static extern (C) void wxFlexGridSizer_RecalcSizes(IntPtr self);
		static extern (C) void wxFlexGridSizer_CalcMin(IntPtr self, inout Size size);
		static extern (C) void wxFlexGridSizer_AddGrowableRow(IntPtr self, uint idx);
		static extern (C) void wxFlexGridSizer_RemoveGrowableRow(IntPtr self, uint idx);
		static extern (C) void wxFlexGridSizer_AddGrowableCol(IntPtr self, uint idx);
		static extern (C) void wxFlexGridSizer_RemoveGrowableCol(IntPtr self, uint idx);
		//! \endcond

		//---------------------------------------------------------------------

	alias FlexGridSizer wxFlexGridSizer;
	public class FlexGridSizer : GridSizer
	{
		public this(IntPtr wxobj)
			{ super(wxobj); }

        public this(int cols, int vgap, int hgap)
            { this(0, cols, vgap, hgap); }

		public this(int rows, int cols, int vgap, int hgap)
			{ super(wxFlexGridSizer_ctor(rows, cols, vgap, hgap)); }

		//---------------------------------------------------------------------

		public override void RecalcSizes()
		{
			wxFlexGridSizer_RecalcSizes(wxobj);
		}

		//---------------------------------------------------------------------

		public override Size CalcMin()
		{
			Size size;
			wxFlexGridSizer_CalcMin(wxobj, size);
			return size;
		}

		//---------------------------------------------------------------------

		public void AddGrowableRow(int idx)
		{
			wxFlexGridSizer_AddGrowableRow(wxobj, cast(uint)idx);
		}

		public void RemoveGrowableRow(int idx)
		{
			wxFlexGridSizer_RemoveGrowableRow(wxobj, cast(uint)idx);
		}

		//---------------------------------------------------------------------

		public void AddGrowableCol(int idx)
		{
			wxFlexGridSizer_AddGrowableCol(wxobj, cast(uint)idx);
		}

		public void RemoveGrowableCol(int idx)
		{
			wxFlexGridSizer_RemoveGrowableCol(wxobj, cast(uint)idx);
		}

		//---------------------------------------------------------------------
	}
