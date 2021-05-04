## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,64P linker.cmd package/cfg/hello_p64P.o64P

linker.cmd: package/cfg/hello_p64P.xdl
	$(SED) 's"^\"\(package/cfg/hello_p64Pcfg.cmd\)\"$""\"/home/david/Documents/ULL/4/Arquitecturas/proyecto_base/Proyecto_base/Release/configPkg/\1\""' package/cfg/hello_p64P.xdl > $@
