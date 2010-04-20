window	dd 0
button	dd 0

msgbuffer	rb 100h

_title	db 'GTK+ Multiplatfom template',0
_msg1	db 'Me hundieron!',13,10,0
_msg2	db '¿Me quieres matar?',13,10,0
_msg3	db 'Esto botó %u',13,10,0
_msg4	db 'Me mataste!',13,10,0

signal_clicked		db 'clicked',0
signal_delete_event	db 'delete-event',0
signal_destroy		db 'destroy',0
