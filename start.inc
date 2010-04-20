start:
;	mov	eax,esp	     ;esp points to the end of an undocumented structure
;	mov	esi,[eax-3E0h] ;esi now points to the command line as an Unicode string
;	mov	edi,[eax-3BCh] ;esi now points to the working dir as an Unicode string

	invoke	gtk_init,NULL,NULL
	invoke	gtk_window_new,GTK_WINDOW_TOPLEVEL
	mov	[window],eax
	invoke	g_signal_connect_data,[window],signal_delete_event,delete_event,NULL,NULL,0
	invoke	g_signal_connect_data,[window],signal_destroy,destroy,NULL,NULL,0
	invoke	gtk_container_set_border_width,[window],10
	invoke	gtk_button_new_with_label,_title
	mov	[button],eax
	invoke	g_signal_connect_data,[button],signal_clicked,button_clicked,NULL,NULL,0
	invoke	g_signal_connect_data,[button],signal_clicked,[gtk_widget_destroy],[window],NULL,G_CONNECT_SWAPPED

	invoke	gtk_container_add,[window],[button]
	invoke	gtk_widget_show,[button]
	invoke	gtk_widget_show,[window]

;	invoke	g_sprintf,msgbuffer,_msg3,eax
;	invoke	MessageBox,0,msgbuffer,_title,0
;	invoke	ExitProcess,0

	invoke	gtk_main
	invoke	g_sprintf,msgbuffer,_msg3,eax
	invoke	MessageBox,0,msgbuffer,_title,0
		
;	invoke	g_mkdir,_title
	invoke	ExitProcess,0
      
proc delete_event,widget,event,data
	invoke	MessageBox,0,_msg2,_title,MB_YESNO
	sub	eax,IDYES	; If this function returns TRUE, the delete event is cancelled
	ret
endp

proc destroy,widget,data
	invoke	MessageBox,0,_msg4,_title,0
	invoke	ExitProcess,0
	invoke	gtk_main_quit
	ret
endp

proc button_clicked,widget,data
	invoke	MessageBox,0,_msg1,_title,0
	ret
endp
