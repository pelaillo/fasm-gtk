; GTK programming with Fasm

include 'macro/struct.inc'
include 'macro/import32.inc'
include 'macro/proc32.inc'

if defined LINUX
	NULL	= 0
	TRUE	= 1
	FALSE	= 0
else
	struc TCHAR [val] { common match any, val \{ . db val \}
	                           match , val \{ . db ? \} }
	sizeof.TCHAR = 1
	include 'equates/kernel32.inc'
	include 'equates/user32.inc'
	include 'equates/gdi32.inc'
	include 'equates/comctl32.inc'
	include 'equates/comdlg32.inc'
	include 'equates/shell32.inc'
	include 'equates/wsock32.inc'
end if


GTK_WINDOW_TOPLEVEL = 0
GTK_WINDOW_POPUP = 1
G_CONNECT_SWAPPED = 2

struct GDate
  julian_days	dd ?
  cal_data	dd ?
       ;  julian :1
       ;  dmy    :1
       ;  day    :6
       ;  month  :4
       ;  year   :16
ends

