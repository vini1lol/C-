#ifndef _CIRCUITO_H_
#define _CIRCUITO_H_

#include <iostream>
#include <string>
#include <vector>
#include "bool3S.h"

using namespace std;

//
// A CLASSE PORT
//

#define NUM_MAX_INPUTS_PORT 4

class Port;
typedef Port *ptr_Port;

class Port {
protected:
  // O numero de entradas da porta
  unsigned Nin;
  // As ids das entradas da porta:
  // se id_in[i]>0: a i-esima entrada da porta vem da saida da porta cuja id eh o
  // valor desse elemento do array
  // se id_in[i]<0: a i-esima entrada da porta vem da entrada do circuito cuja id eh o
  // valor desse elemento do array
  int id_in[NUM_MAX_INPUTS_PORT];
  // O valor da saida da porta (F, T ou ?)
  bool3S saida;
public:
  // Construtor (recebe como parametro o numero de entradas da porta)
  // Depois de checar o parametro, faz Nin <- NI e inicializa os elementos do
  // array id_in com valor invalido (0) e saida com UNDEF
  inline Port(unsigned NI=2){if(NI>=1){Nin=NI;}Nin=1;}
  // Construtor por copia
  Port(const Port &){};
  // Destrutor virtual
  inline virtual ~Port() {}

  // Essa funcao virtual pura deve criar e retornar um ponteiro para Port que aponta para
  // uma copia de si mesma, do tipo correto.
  // Por exemplo, se for chamada com um objeto Port_AND, retorna um ponteiro que aponta para
  // uma area que contem uma Port_AND cujo valor eh uma copia de *this
  // Deve ser utilizada no construtor por copia da classe Circuito
  virtual ptr_Port clone() const = 0;

  // Funcao virtual pura que retorna a sigla correta da Port (AN, NT, OR, NX, etc.)
  // Deve ser utilizada para imprimir uma porta
  virtual string getName() const = 0;

  // Funcoes de consulta
  inline unsigned getNumInputs() const {return Nin;}
  inline bool3S getOutput() const {return saida;}
  // Depois de testar o parametro, retorna o valor de id_in[i] ou 0 se indice invalido
  int getId_in(unsigned i) const;

  // Funcoes de modificacao

  // Fixa o numero de entradas da porta como sendo N, entre 2 e
  // NUM_MAX_INPUTS_PORT; portanto, vale para todas as ports, exceto NOT.
  // O metodo virtual setNumInputs tem que ser refeito para a NOT.
  // Nao precisa ser reimplementado nas demais ports
  // Depois de testar o parametro, faz: Nin <- N
  virtual void setNumInputs(unsigned N);
  // Fixa o valor logico da saida da porta (F, T ou ?)
  // Depois de testar o parametro, faz: saida <- s
  void setOutput(bool3S s);
  // Fixa a origem do sinal da i-esima entrada da porta como sendo Id
  // Depois de testar os parametros, faz: id_in[i] <- Id
  void setId_in(unsigned i, int Id);

  // Leh uma porta do teclado
  // Este metodo para digitar uma porta com numero variavel de entradas (entre 2 e
  // NUM_MAX_INPUTS_PORT) vale para todas as ports, exceto NOT.
  // O metodo virtual digitar tem que ser refeito para a NOT.
  // Nao precisa ser reimplementado nas demais ports
  // ATENÇÃO: o metodo NAO vai solicitar que o usuario digite o tipo de porta
  // (NT,AN,NA,OR,NO,XO,NX). Esse valor jah deve ter sido digitado previamente e a porta
  // criada dinamicamente (new) do tipo certo, para que seja chamado o metodo virtual
  // digitar apropriado para o tipo de porta.
  // O metodo digitar pede que o usuario digite o numero de entradas da porta (Nin) e, em
  // seguida, a origem (id_in[i]) de cada uma das entradas
  virtual void digitar();

  // Leh uma porta da stream I. Retorna true se tudo OK, false se houve erro
  // Este metodo para ler uma porta com numero variavel de entradas (entre 2 e
  // NUM_MAX_INPUTS_PORT) vale para todas as ports, exceto NOT.
  // O metodo virtual ler tem que ser refeito para a NOT.
  // Nao precisa ser reimplementado nas demais ports
  // ATENÇÃO: o metodo NAO vai ler do arquivo o tipo de porta
  // (NT,AN,NA,OR,NO,XO,NX). Esse valor jah deve ter sido lido previamente e a porta
  // criada dinamicamente do tipo certo, para que seja chamado o metodo virtual ler
  // apropriado para o tipo de porta.
  // O metodo ler leh do arquivo o numero de entradas da porta (Nin) e, em
  // seguida, a origem (id_in[i]) de cada uma das entradas
  virtual bool ler(istream &I);

  // Imprime a porta na ostrem O (cout ou uma stream de arquivo, tanto faz)
  // Imprime a string com o nome da porta, o numero de entradas, um ": " e as ids
  // de cada uma das entradas
  // Este metodo nao eh virtual, pois pode ser feito generico de forma a servir para
  // todas as ports.
  // Basta que o metodo imprima o resultado da chamada aa funcao virtual getName()
  // Retorna a propria ostream O recebida como parametro de entrada, para que possa
  // ser encadeada
  ostream &imprimir(ostream &O) const;

  // Simula uma porta logica
  // Recebe um array de bool3S com os valores logicos atuais das entradas da porta
  // Retorna um bool3S com o resultado (saida da porta), alem de armazenar o valor no
  // dado saida da porta
  // Se baseia nos operadores AND, OR, etc da classe bool3S
  virtual bool3S simular(const bool3S in[]) = 0;
};

// Operador << com comportamento polimorfico
// Serve para todas as ports (NO, AND, NOR, etc.)
inline ostream &operator<<(ostream &O, const Port &X) {return (&X)->imprimir(O);};

//
// As outras PORTS
//

class Port_NOT: public Port {
public:
  inline Port_NOT(): Port(1) {}
  inline ~Port_NOT() {}
  inline ptr_Port clone() const {return new Port_NOT(*this);}
  inline string getName() const {return "NT";};

  void setNumInputs(unsigned N);

  void digitar();
  bool ler(istream &I);

  bool3S simular(const bool3S in[]);
};

class Port_AND: public Port {
public:
  inline Port_AND(): Port() {}
  inline ~Port_AND() {}
  inline ptr_Port clone() const {return new Port_AND(*this);}
  inline string getName() const {return "AN";};

  bool3S simular(const bool3S in[]);
};

class Port_NAND: public Port {
public:
  inline Port_NAND(): Port() {}
  inline ~Port_NAND() {}
  inline ptr_Port clone() const {return new Port_NAND(*this);}
  inline string getName() const {return "NA";};

  bool3S simular(const bool3S in[]);
};

class Port_OR: public Port {
public:
  inline Port_OR(): Port() {}
  inline ~Port_OR() {}
  inline ptr_Port clone() const {return new Port_OR(*this);}
  inline string getName() const {return "OR";};

  bool3S simular(const bool3S in[]);
};

class Port_NOR: public Port {
public:
  inline Port_NOR(): Port() {}
  inline ~Port_NOR() {}
  inline ptr_Port clone() const {return new Port_NOR(*this);}
  inline string getName() const {return "NO";};

  bool3S simular(const bool3S in[]);
};

class Port_XOR: public Port {
public:
  inline Port_XOR(): Port() {}
  inline ~Port_XOR() {}
  inline ptr_Port clone() const {return new Port_XOR(*this);}
  inline string getName() const {return "XO";};

  bool3S simular(const bool3S in[]);
};

class Port_NXOR: public Port {
public:
  inline Port_NXOR(): Port() {}
  inline ~Port_NXOR() {}
  inline ptr_Port clone() const {return new Port_NXOR(*this);}
  inline string getName() const {return "NX";};

  bool3S simular(const bool3S in[]);
};

//
// A CLASSE CIRCUIT
//

class Circuit {
private:
  // Nao precisa manter variaveis para guardar o numero de entradas, saidas e ports.
  // Essas informacoes estao armazenadas nos tamanhos (size) dos vetores correspondentes:
  // inputs, id_out e ports
  // Os metodos de consulta getNumInputs, getNumOutputs e getNumPorts dao acesso a essas
  // informacoes de maneira eficiente
  vector<bool3S> inputs;   // vetor que deve ser alocado com dimensao "Nin"
  vector<int> id_out;      // vetor que deve ser alocado com dimensao "Nout"
  vector<ptr_Port> ports;  // vetor que deve ser alocado com dimensao "Nports"

  // ATENCAO: fora de um construtor, sempre chamar clean() antes de utilizar a funcao alloc()
  // Esta funcao redimensiona (resize) os vetores inputs, id_out e ports
  // Os vetores sao inicializados com valores iniciais neutros ou invalidos:
  // inputs[i] <- UNDEF
  // id_out[i] <- 0
  // ports[i] <- nullptr
  void alloc(unsigned NI, unsigned NO, unsigned NP);
  // ATENCAO: fora de um construtor, sempre chamar clean() antes de utilizar a funcao copy()
  // A funcao copy chama a funcao alloc e depois copia os elementos dos vetores
  // Serah necessario utilizar a funcao virtual clone para criar copias das portas
  void copy(const Circuit &C);
public:
  // As variaveis do tipo Circuit sao sempre criadas sem nenhum dado
  // A definicao do numero de entradas, saidas e ports eh feita ao ler do teclado ou arquivo
  // ou ao executar o metodo realloc
  inline Circuit():inputs(),id_out(),ports() {}
  // Construtor por copia: apenas chama a funcao copy()
  inline Circuit(const Circuit &C) {copy(C);}
  // Limpa todo o conteudo do circuito
  // Utiliza o metodo STL clean para limpar os vetores inputs, id_out e ports
  // ATENCAO: antes de dar um clean no vetor ports, tem que liberar (delete) as areas
  // de memoria para as quais cada ponteiro desse vetor aponta.
  void clean();
  // Destrutor: apenas chama a funcao clean()
  inline ~Circuit() {clean();}
  // Operador de atribuicao: apenas chama as funcoes copy() e clean()
  inline void operator=(const Circuit &C) {if (this!=&C) {clean(); copy(C);}}

  // Funcoes de consulta

  // Caracteristicas do circuito
  inline unsigned getNumInputs() const {return inputs.size();}
  inline unsigned getNumOutputs() const {return id_out.size();}
  inline unsigned getNumPorts() const {return ports.size();}
  // Retorna true se o circuito eh valid (estah com todos os dados corretos):
  // numero de entradas, saidas e portas valido
  // todas as portas com nome e numero de entradas valido
  // todas as entradas de todas as portas com id valido
  // todas as saidas com id valido
  // Essa funcao deve ser usada antes de salvar ou simular um circuito
  bool valid() const;

  // Caracteristicas das entradas
  // Retorna o valor logico atual da entrada cuja id eh IdIn
  // Depois de testar o parametro, retorna o valor de inputs[-IdIn - 1]
  // ou UNDEF se parametro invalido
  bool3S getInput(int IdIn) const;

  // Caracteristicas das saidas
  // Retorna a origem (a id) do sinal de saida cuja id eh IdOut
  // Depois de testar o parametro, retorna id_out[IdOut-1]
  // ou 0 se parametro invalido
  int getIdOutput(unsigned IdOut) const;
  // Retorna o valor logico atual da saida cuja id eh IdOut
  // Fazendo id = getIdOutput(IdOut), entao
  // Retorna ports[ id - 1 ]->getOutput() se id > 0
  // ou inputs[ -(int)id - 1 ] se id < 0
  // ou UNDEF se id==0 (invalido)
  bool3S getOutput(unsigned IdOut) const;

  // Caracteristicas das portas
  // Nome da porta: AN, NX, etc
  // Depois de testar o parametro, retorna ports[IdPort-1]->getName()
  // ou "??" se parametro invalido
  string getNamePort(unsigned IdPort) const;
  // Retorna o numero de entradas (1 a 4) da porta cuja id eh IdPort (1 a NPorts)
  // Depois de testar o parametro, retorna ports[IdPort-1]->getNumInputs()
  // ou 0 se parametro invalido
  unsigned getNumInputsPort(unsigned IdPort) const;
  // Retorna a origem (a id) da i-esima entrada da porta cuja id eh IdPort
  // Depois de testar os parametros, retorna ports[IdPort-1]->getId_in(i)
  // ou 0 se parametro invalido
  int getId_inPort(unsigned IdPort, unsigned i) const;

  // Funcoes de modificacao de valores

  // Caracteristicas do circuito
  // Redimensiona o circuito para passar a ter NI entradas, NO saidas e NP ports
  inline void realloc(unsigned NI, unsigned NO, unsigned NP) {clean(); alloc(NI,NO,NP);}

  // Caracteristicas das saidas
  // Altera a origem da saida de id "IdOut", que passa a ser "Id"
  // Depois de testar os parametros (entre outros testes, nem IdOut nem Id podem
  // ser 0), faz: id_out[IdOut-1] <- Id
  void setIdOutput(unsigned IdOut, int Id);

  // Caracteristicas das ports
  // A porta cuja id eh IdPort passa a ser do tipo T (NT, AN, etc.), com NIn entradas
  // Depois de varios testes (tipo, Id, num de entradas), faz:
  // 1) Libera a antiga area de memoria: delete ports[IdPort-1]
  // 2) Cria a nova porta: ports[IdPort-1] <- new ... (de acordo com tipo T)
  // 3) Fixa o numero de entrada: ports[IdPort-1]->setNumInputs(NIn)
  void setPort(unsigned IdPort, const string &T, unsigned NIn);
  // Altera a origem da I-esima entrada da porta cuja id eh IdPort, que passa a ser "Id"
  // Depois de VARIOS testes, faz: ports[IdPort-1]->setId_in(I,Id)
  void setId_inPort(unsigned IdPort, unsigned I, int Id) const;

  void setInput(const vector<bool3S> inputss);

  // Entrada dos dados de um circuito via teclado
  // O usuario digita o numero de entradas, saidas e portas
  // Em seguida, para cada porta o usuario digita o tipo (NT,AN,NA,OR,NO,XO,NX)
  // Apos criada dinamicamente (new) a porta do tipo correto, chama a
  // funcao digitar na porta recem-criada
  // Em seguida, o usuario digita as ids de todas as saidas
  void digitar();
  // Entrada dos dados de um circuito via arquivo
  // Leh do arquivo o cabecalho com o numero de entradas, saidas e portas
  // Em seguida, para cada porta leh e confere a id e o tipo (NT,AN,NA,OR,NO,XO,NX)
  // Apos criada dinamicamente (new) a porta do tipo correto, chama a
  // funcao ler na porta recem-criada
  // Em seguida, leh as ids de todas as saidas
  // Retorna true se deu tudo OK; false se deu erro
  bool ler(const string &arq);
  // Saida dos dados de um circuito (em tela ou arquivo, a mesma funcao serve para os dois)
  // Imprime os cabecalhos e os dados do circuito, caso o circuito seja valido
  ostream &imprimir(ostream &O=cout) const;
  // Salvar circuito em arquivo, caso o circuito seja valido
  // Abre a stream e depois chama o metodo imprimir
  // Retorna true se deu tudo OK; false se deu erro
  bool salvar(const string &arq) const;

  // Calcula a saida das ports do circuito para os valores de entrada
  // passados como parametro, caso o circuito seja valido
  // A entrada eh um vetor de bool3S, com dimensao igual ao numero de entradas do circuito.
  // Retorna true se a simulacao foi OK; false caso deh erro
  bool simular(const vector<bool3S> &Inputs_circ);
};

// Operador de impressao da classe Circuit
// Utiliza o metodo imprimir
inline ostream &operator<<(ostream &O, const Circuit &C) {return C.imprimir(O);}

#endif // _CIRCUITO_H_
