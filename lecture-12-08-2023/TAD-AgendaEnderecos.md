# TAD Agenda de Endereços

## Dados

Cada estabelecimento tem:

- ID do estabelecimento será a ordem em que ele foi inserido (int)
- Nome fantasia
	> Implementado com char array dinamico
- Endereços
	- ID do endereço será a ordem em que ele foi inserido (int)
	- Rua
		> Implementado com char array dinamico
	- Bairro
		> Implementado com char array dinamico
	- Cidade
		> Implementado com char array dinamico
	- Estado (2 letras)
		> Implementado com char array 2
	- CEP (8 dígitos)
		> Implementado com int array 8
 - Nome do representante
	> Implementado com char array dinamico
- Telefones
	- ID do telefone será a ordem em que ele foi inserido (int)
	- Tipo do telefone (fixo ou móvel)
		> Implementado com int 0 ou 1 (0=fixo, 1=móvel)
	- Número (se fixo, tem 2 ddd + 8 numeros, se móvel, 2 ddd + 9 digitos)
		> Implementado com array int 11

## Operações
 - Criar estabelecimento ``newEstabelecimento(nomeFantasia, nomeRepresentante)``
 - Deletar estabelecimento ``delEstabelecimento(id)``
 - Mudar endereço ``changeAddress(idEstabelecimento, idEndereco, novoEndereco)``
 - Mudar nome fantasia ``changeNomeFantasia(idEstabelecimento, novoNomeFantasia)``
 - Mudar telefone ``changeTelefone(idEstabelecimento, idTelefone, novoTelefone)``
 - Mudar nome do representante ``changeRepresentante(idEstabelecimento, novoRepresentante)``
 - Adicionar telefone ``addTelefone(idEstabelecimento, novoTelefone)``
 - Adicionar endereço ``addAddress(idEstabelecimento, novoEndereco)``
 - Remover endereço ``delAddress(idEstabelecimento, idEndereco)``
 - Remover telefone ``delTelefone(idEstabelecimento, idTelefone)``
 - Pesquisar por nome do estabelecimento ``searchEstabelecimentoByName(name)``, retorna array of ids that match name, if none, returns Null


