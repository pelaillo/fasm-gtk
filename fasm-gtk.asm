; Fasm template for multiplatform GTK+
; CopyLeft 2010 pelaillo 
;
; git clone git@github.com:pelaillo/fasm-gtk.git

include 'gtk.inc'

if defined LINUX
	display 'Assembling Linux ELF version'

	format ELF executable 3
	entry start
	
	interpreter '/lib/ld-linux.so.2'
	
	needed  'libc.so.6',\
	        'libglib-2.0.so.0',\
	        'libgmodule-2.0.so.0',\
	        'libgobject-2.0.so.0',\
	        'libgtk-x11-2.0.so.0',\
	        'libgdk-x11-2.0.so.0',\
	        'libatk-1.0.so.0'
	
	import  exit,\
	        gtk_container_get_type,\
	        gtk_container_set_border_width,\
	        gtk_button_new_with_label,\
	        gtk_container_add,\
	        g_signal_connect_data,\
	        gtk_widget_destroy,\
	        gtk_window_new,\
	        gtk_main,\
	        gtk_widget_show,\
	        gtk_main_quit,\
	        gtk_init,\
	        g_print
	
	segment readable executable
		include 'start.inc'
	
	segment readable writeable
		include 'data.inc'
else
	display 'Assembling Win32 version'

	format PE GUI 4.0
	entry start
	
	section '.text' code readable executable
		include 'start.inc'
	section '.data' data readable writeable
		include 'data.inc'
			
	section '.idata' import data readable writeable
	
	  library kernel,'KERNEL32.DLL',\
	          glib,'libglib-2.0-0.DLL',\
	          gobject,'libgobject-2.0-0.DLL',\
	          gtk,'libgtk-win32-2.0-0.DLL',\
	          user,'USER32.DLL'
	
	  import kernel,\
	         ExitProcess,'ExitProcess'
	
	  import glib,\
	         g_mkdir,'g_mkdir',\
	         g_print,'g_print',\
	         g_sprintf,'g_sprintf'
	         
	  import gobject,\       
	         g_signal_connect_data,'g_signal_connect_data'
	
	  import gtk,\
	         gtk_button_new_with_label,'gtk_button_new_with_label',\
	         gtk_container_add,'gtk_container_add',\
	         gtk_container_set_border_width,'gtk_container_set_border_width',\
	         gtk_init,'gtk_init',\
	         gtk_main,'gtk_main',\
	         gtk_main_quit,'gtk_main_quit',\
	         gtk_widget_destroy,'gtk_widget_destroy',\
	         gtk_widget_show,'gtk_widget_show',\
	         gtk_window_new,'gtk_window_new'
	
	  import user,\
	         MessageBox,'MessageBoxA'
end if