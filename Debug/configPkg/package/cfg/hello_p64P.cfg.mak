# invoke SourceDir generated makefile for hello.p64P
hello.p64P: .libraries,hello.p64P
.libraries,hello.p64P: package/cfg/hello_p64P.xdl
	$(MAKE) -f /home/david/Documents/ULL/4/Arquitecturas/proyecto_base/Proyecto_base/src/makefile.libs

clean::
	$(MAKE) -f /home/david/Documents/ULL/4/Arquitecturas/proyecto_base/Proyecto_base/src/makefile.libs clean

