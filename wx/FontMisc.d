//-----------------------------------------------------------------------------
// wxD - FontMisc.d
// (C) 2005 bero <berobero@users.sourceforge.net>
// based on
// wx.NET - FontMapper.cs
//
/// The wxFontMapper wrapper class.
//
// Written by Alexander Olk (xenomorph2@onlinehome.de)
// (C) 2003 Alexander Olk
// Licensed under the wxWidgets license, see LICENSE.txt for details.
//
// $Id$
//-----------------------------------------------------------------------------

module wx.FontMisc;
import wx.common;
import wx.Font;
import wx.Window;
import wx.ArrayString;

		//! \cond EXTERN
		static extern (C) IntPtr wxFontMapper_ctor();
		static extern (C) void   wxFontMapper_dtor(IntPtr self);
		
		static extern (C) IntPtr wxFontMapper_Get();
		static extern (C) IntPtr wxFontMapper_Set(IntPtr mapper);
		static extern (C) int    wxFontMapper_GetSupportedEncodingsCount();
		static extern (C) int    wxFontMapper_GetEncoding(int n);
		static extern (C) string wxFontMapper_GetEncodingName(int encoding);
		static extern (C) string wxFontMapper_GetEncodingDescription(int encoding);
		static extern (C) int    wxFontMapper_GetEncodingFromName(string name);
		
		static extern (C) int    wxFontMapper_CharsetToEncoding(IntPtr self, string charset, bool interactive);
		static extern (C) bool   wxFontMapper_IsEncodingAvailable(IntPtr self, int encoding, string facename);
		static extern (C) bool   wxFontMapper_GetAltForEncoding(IntPtr self, int encoding, out int alt_encoding, string facename, bool interactive);
		
		static extern (C) void   wxFontMapper_SetDialogParent(IntPtr self, IntPtr parent);
		static extern (C) void   wxFontMapper_SetDialogTitle(IntPtr self, string title);
		//! \endcond
		
		//---------------------------------------------------------------------
		
	alias FontMapper wxFontMapper;
	public class FontMapper : wxObject
	{
		private static FontMapper staticFontMapper;
		
		static this()
		{
			staticFontMapper = new FontMapper(wxFontMapper_Get());
		}
		
		//---------------------------------------------------------------------
		
		public this(IntPtr wxobj)
		{
			super(wxobj);
		}
			
		private this(IntPtr wxobj, bool memOwn)
		{ 
			super(wxobj);
			this.memOwn = memOwn;
		}
			
		public this()
			{ this(wxFontMapper_ctor(), true);}
			
		//---------------------------------------------------------------------
				
		override private void dtor() { wxFontMapper_dtor(wxobj); }
			
		//---------------------------------------------------------------------
		
		static FontMapper Get() { return staticFontMapper; }
		
		//---------------------------------------------------------------------
		
		public static FontMapper Set(FontMapper mapper)
		{
			return new FontMapper(wxFontMapper_Set(wxObject.SafePtr(mapper)));
		}
		
		//---------------------------------------------------------------------
		
		static int SupportedEncodingsCount() { return wxFontMapper_GetSupportedEncodingsCount(); }
		
		//---------------------------------------------------------------------
		
		public static FontEncoding GetEncoding(int n)
		{
			return cast(FontEncoding)wxFontMapper_GetEncoding(n);
		}
		
		//---------------------------------------------------------------------
		
		public static string GetEncodingName(FontEncoding encoding)
		{
			return wxFontMapper_GetEncodingName(cast(int)encoding).dup;
		}
		
		//---------------------------------------------------------------------
		
		public static FontEncoding GetEncodingFromName(string name)
		{
			return cast(FontEncoding)wxFontMapper_GetEncodingFromName(name);
		}
		
		//---------------------------------------------------------------------
		
		public FontEncoding CharsetToEncoding(string charset)
		{
			return cast(FontEncoding)CharsetToEncoding(charset, true);
		}
		
		public FontEncoding CharsetToEncoding(string charset, bool interactive)
		{
			return cast(FontEncoding)wxFontMapper_CharsetToEncoding(wxobj, charset, interactive);
		}
		
		//---------------------------------------------------------------------
		
		public bool IsEncodingAvailable(FontEncoding encoding)
		{
			return IsEncodingAvailable(encoding, "");
		}
		
		public bool IsEncodingAvailable(FontEncoding encoding, string facename)
		{
			return wxFontMapper_IsEncodingAvailable(wxobj, cast(int)encoding, facename);
		}
		
		//---------------------------------------------------------------------
		
		public bool GetAltForEncoding(FontEncoding encoding, out FontEncoding alt_encoding)
		{
			return GetAltForEncoding(encoding, alt_encoding, "", true);
		}
		
		public bool GetAltForEncoding(FontEncoding encoding, out FontEncoding alt_encoding, string facename)
		{
			return GetAltForEncoding(encoding, alt_encoding, facename, true);
		}
		
		public bool GetAltForEncoding(FontEncoding encoding, out FontEncoding alt_encoding, string facename, bool interactive)
		{
			return wxFontMapper_GetAltForEncoding(wxobj, cast(int)encoding, alt_encoding, facename, interactive);
		}
		
		//---------------------------------------------------------------------
		
		public static string GetEncodingDescription(FontEncoding encoding)
		{
			return wxFontMapper_GetEncodingDescription(cast(int)encoding).dup;
		}
		
		//---------------------------------------------------------------------
		
		public void SetDialogParent(Window parent)
		{
			wxFontMapper_SetDialogParent(wxobj, wxObject.SafePtr(parent));
		}
		
		//---------------------------------------------------------------------
		
		public void SetDialogTitle(string title)
		{
			wxFontMapper_SetDialogTitle(wxobj, title);
		}
	}
	
	//---------------------------------------------------------------------
	
		//! \cond EXTERN
		static extern (C) IntPtr wxEncodingConverter_ctor();
		static extern (C) bool wxEncodingConverter_Init(IntPtr self, int input_enc, int output_enc, int method);
		static extern (C) string wxEncodingConverter_Convert(IntPtr self, string input);
		//! \endcond
		
		//---------------------------------------------------------------------
		
	alias EncodingConverter wxEncodingConverter;
	public class EncodingConverter : wxObject
	{
		enum CONVERT
		{
			 wxCONVERT_STRICT,
			 wxCONVERT_SUBSTITUTE
		}
		
		public this(IntPtr wxobj)
			{ super(wxobj);}
			
		public this()
			{ super(wxEncodingConverter_ctor());}
			
		//---------------------------------------------------------------------
		
		public bool Init(FontEncoding input_enc, FontEncoding output_enc)
		{
			return Init(input_enc, output_enc, cast(int)CONVERT.wxCONVERT_STRICT);
		}
		
		public bool Init(FontEncoding input_enc, FontEncoding output_enc, int method)
		{
			return wxEncodingConverter_Init(wxobj, cast(int)input_enc, cast(int)output_enc, method);
		}
		
		//---------------------------------------------------------------------
		
		public string Convert(string input)
		{
			return wxEncodingConverter_Convert(wxobj, input).dup;
		}
	}
	
	//---------------------------------------------------------------------
	
		//! \cond EXTERN
		extern (C) {
		alias bool function(FontEnumerator obj, int encoding, bool fixedWidthOnly) Virtual_EnumerateFacenames;
		alias bool function(FontEnumerator obj, string facename) Virtual_EnumerateEncodings;
		alias bool function(FontEnumerator obj, string facename) Virtual_OnFacename;
		alias bool function(FontEnumerator obj, string facename, string encoding) Virtual_OnFontEncoding;
		}

		static extern (C) IntPtr wxFontEnumerator_ctor();
		static extern (C) void wxFontEnumerator_dtor(IntPtr self);
		static extern (C) void wxFontEnumerator_RegisterVirtual(IntPtr self, FontEnumerator obj,Virtual_EnumerateFacenames enumerateFacenames, Virtual_EnumerateEncodings enumerateEncodings, Virtual_OnFacename onFacename, Virtual_OnFontEncoding onFontEncoding);
		static extern (C) IntPtr wxFontEnumerator_GetFacenames(IntPtr self);
		static extern (C) IntPtr wxFontEnumerator_GetEncodings(IntPtr self);
		static extern (C) bool wxFontEnumerator_OnFacename(IntPtr self, string facename);
		static extern (C) bool wxFontEnumerator_OnFontEncoding(IntPtr self, string facename, string encoding);
		static extern (C) bool wxFontEnumerator_EnumerateFacenames(IntPtr self, int encoding, bool fixedWidthOnly);
		static extern (C) bool wxFontEnumerator_EnumerateEncodings(IntPtr self, string facename);
		//! \endcond
		
		//---------------------------------------------------------------------
		
	alias FontEnumerator wxFontEnumerator;
	public class FontEnumerator : wxObject
	{
		public this()
		{
			this(wxFontEnumerator_ctor(), true);

			wxFontEnumerator_RegisterVirtual(wxobj,this,
				&staticDoEnumerateFacenames,
				&staticDoEnumerateEncodings,
				&staticDoOnFacename,
				&staticDoOnFontEncoding);			
		}
		
		public this(IntPtr wxobj)
		{
			super(wxobj);
		}
		
		private this(IntPtr wxobj, bool memOwn)
		{ 
			super(wxobj);
			this.memOwn = memOwn;
		}
		
		//---------------------------------------------------------------------
				
		override private void dtor() { wxFontEnumerator_dtor(wxobj); }
			
		//---------------------------------------------------------------------
		
		public string[] Facenames()
		{
			return (new ArrayString(wxFontEnumerator_GetFacenames(wxobj), true)).toArray();
		}
		
		//---------------------------------------------------------------------
		
		public string[] Encodings()
		{
			return (new ArrayString(wxFontEnumerator_GetEncodings(wxobj), true)).toArray();
		}
		
		//---------------------------------------------------------------------
		
		public /+virtual+/ bool OnFacename(string facename)
		{
			return wxFontEnumerator_OnFacename(wxobj, facename);
		}
		
		extern(C) private static bool staticDoOnFacename(FontEnumerator obj, string facename)
		{
			return obj.OnFacename(facename);
		}
		
		//---------------------------------------------------------------------
		
		public /+virtual+/ bool OnFontEncoding(string facename, string encoding)
		{
			return wxFontEnumerator_OnFontEncoding(wxobj, facename, encoding);
		}
		
		extern(C) private static bool staticDoOnFontEncoding(FontEnumerator obj, string facename, string encoding)
		{
			return obj.OnFontEncoding(facename, encoding);
		}
		
		//---------------------------------------------------------------------
		
		/*public /+virtual+/ bool EnumerateFacenames()
		{
			return EnumerateFacenames(cast(int)FontEncoding.wxFONTENCODING_SYSTEM, false);
		}
		
		public /+virtual+/ bool EnumerateFacenames(FontEncoding encoding)
		{
			return EnumerateFacenames(cast(int)encoding, false);
		}*/
		
		public /+virtual+/ bool EnumerateFacenames(FontEncoding encoding, bool fixedWidthOnly)
		{
			return wxFontEnumerator_EnumerateFacenames(wxobj, cast(int)encoding, fixedWidthOnly);
		}
		
		extern(C) private static bool staticDoEnumerateFacenames(FontEnumerator obj, int encoding, bool fixedWidthOnly)
		{
			return obj.EnumerateFacenames(cast(FontEncoding)encoding, fixedWidthOnly);
		}
		
		//---------------------------------------------------------------------
		
		/*public /+virtual+/ bool EnumerateEncodings()
		{
			return EnumerateEncodings(IntPtr.init);
		}*/
		
		public /+virtual+/ bool EnumerateEncodings(string facename)
		{
			return wxFontEnumerator_EnumerateEncodings(wxobj, facename);
		}
		
		extern(C) private static bool staticDoEnumerateEncodings(FontEnumerator obj, string facename)
		{
			return obj.EnumerateEncodings(facename);
		}
	}
