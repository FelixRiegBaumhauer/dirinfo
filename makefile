dirinfo: dir_info.c
	gcc dir_info.c -o dirinfo

run: dirinfo
	./dirinfo

clean:
	rm dirinfo
	rm *~
