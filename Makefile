all:
	$(MAKE) -C sepuku
	$(MAKE) -C blow_head_off 
	$(MAKE) -C gdb_check
	$(MAKE) -C get_socket
