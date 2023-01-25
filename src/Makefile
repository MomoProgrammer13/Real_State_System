all : saida
	@echo " "
	@echo "Copilacao concluida!!"
	@echo " "

saida :  main.o alterarCliente.o alterarImobiliaria.o atualizaAvaliacaoCliente.o avaliarImobiliaria.o cadastraCliente.o cadastraImobiliaria.o gravarCliente.o gravarImobiliaria.o gravarNewLogingInfo.o listarClientes.o listarImobiliarias.o logAsNormalUser.o logAsRoot.o menuCliente.o menuLog.o menuRoot.o removerCliente.o removerImobiliaria.o setaCategoria.o tryLogin.o visualizaDadosCliente.o visualizarAvaliacoes.o



		gcc -o saida  main.o alterarCliente.o alterarImobiliaria.o atualizaAvaliacaoCliente.o avaliarImobiliaria.o cadastraCliente.o cadastraImobiliaria.o gravarCliente.o gravarImobiliaria.o gravarNewLogingInfo.o listarClientes.o listarImobiliarias.o logAsNormalUser.o logAsRoot.o menuCliente.o menuLog.o menuRoot.o removerCliente.o removerImobiliaria.o setaCategoria.o tryLogin.o visualizaDadosCliente.o visualizarAvaliacoes.o




main.o : main.c
		   	gcc -o main.o -c main.c

alterarCliente.o: alterarCliente.c
			gcc -o alterarCliente.o -c alterarCliente.c

alterarImobiliaria.o: alterarImobiliaria.c
			gcc -o alterarImobiliaria.o -c alterarImobiliaria.c

atualizaAvaliacaoCliente.o: atualizaAvaliacaoCliente.c
			gcc -o atualizaAvaliacaoCliente.o -c atualizaAvaliacaoCliente.c

avaliarImobiliaria.o: avaliarImobiliaria.c
			gcc -o avaliarImobiliaria.o -c avaliarImobiliaria.c

cadastraCliente.o: cadastraCliente.c
			gcc -o cadastraCliente.o -c cadastraCliente.c

cadastraImobialiaria.o: cadastraImobiliaria.c
			gcc -o cadastraImobiliaria.o -c cadastraImobiliaria.c

gravarCliente.o: gravarCliente.c
			gcc -o gravarCliente.o -c gravarCliente.c

gravarImobiliaria.o: gravarImobiliaria.c
			gcc -o gravarImobiliaria.o -c gravarImobiliaria.c

gravarNewLogingInfo.o: gravarNewLogingInfo.c
			gcc -o gravarNewLogingInfo.o -c gravarNewLogingInfo.c

listarClientes.o: listarClientes.c
			gcc -o listarClientes.o -c listarClientes.c

listarImobiliarias.o: listarImobiliarias.c
			gcc -o listarImobiliarias.o -c listarImobiliarias.c

logAsNormalUser.o: logAsNormalUser.c
			gcc -o logAsNormalUser.o -c logAsNormalUser.c

logAsRoot.o: logAsRoot.c
			gcc -o logAsRoot.o -c logAsRoot.c

menuCliente.o: menuCliente.c
			gcc -o menuCliente.o -c menuCliente.c

menuLog.o: menuLog.c
			gcc -o menuLog.o -c menuLog.c

menuRoot.o: menuRoot.c
			gcc -o menuRoot.o -c menuRoot.c

removerCliente.o: removerCliente.c
			gcc -o removerCliente.o -c removerCliente.c

removerImobiliaria.o: removerImobiliaria.c
			gcc -o removerImobiliaria.o -c removerImobiliaria.c

setaCategoria.o: setaCategoria.c
			gcc -o setaCategoria.o -c setaCategoria.c

tryLogin.o: tryLogin.c
			gcc -o tryLogin.o -c tryLogin.c

visualizaDadosCliente.o: visualizaDadosCliente.c
			gcc -o visualizaDadosCliente.o -c visualizaDadosCliente.c

visualizarAvaliacoes.o: visualizarAvaliacoes.c
			gcc -o visualizarAvaliacoes.o -c visualizarAvaliacoes.c

clean:
	rm -f *.o

execClean:
	rm -f saida
