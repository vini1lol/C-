#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <algorithm>
#include "circuito.h"
#include "bool3S.h"

using namespace std;
#define NUM_MAX_STR 256


int Port::getId_in(unsigned i) const
{
    if(i>=getNumInputs())
    {
        return 0;
    }
    return id_in[i];

}

void Port::setNumInputs(unsigned N){
    if((N>=2) && (N<=NUM_MAX_INPUTS_PORT)){
        Nin=N;
    }
}

void Port::setOutput(bool3S s)
{
    saida=s;
}

void Port::setId_in(unsigned i,int id)
{
    if((i<getNumInputs()) && (id!=0))
    {
        id_in[i]=id;
    }
}

void Port::digitar()
{
    int a,b;
    do{
        cout<<"Digite o numero de entradas"<<endl;
        cin>>a;
    }while((a>NUM_MAX_INPUTS_PORT) || (a<2));
    setNumInputs(a);
    for(int i=0;i<a;i++)
    {
        do{
        cout<<"Digite a origem da entrada"<<i+1<<endl;
        cin>>b;
        }while(b==0);
        setId_in(i,b);
    }

}

bool Port::ler(istream &I)
{
    int a,b;
    I>>a;
    if((a>NUM_MAX_INPUTS_PORT) || (a<2))
    {
        return false;
    }
    setNumInputs(a);
    I.ignore(numeric_limits<streamsize>::max(),':');
    for(int i=0;i<a;i++)
    {
        I>>b;
        if(b==0)
        {
            return false;
        }
        setId_in(i,b);
    }
    return true;
}

ostream& Port::imprimir(ostream &O) const
{
    O<<getName()<<" ";
    O<<getNumInputs()<<":";
    for(int i=0;i<(int)getNumInputs();i++)
    {
        O<<" "<<getId_in(i);
    }
    O<<endl;
    return O;
}

void Port_NOT::setNumInputs(unsigned N)
{
    Nin=1;
}

void Port_NOT::digitar()
{
    setNumInputs(1);
    int b;
    do{
    cout<<"Digite a origem da entrada"<<endl;
    cin>>b;
    }while(b==0);
    setId_in(0,b);
}

bool Port_NOT::ler(istream &I)
{
    int a,b;
    I>>a;
    if(a!=1)
    {
        return false;
    }
    setNumInputs(a);
    I.ignore(numeric_limits<streamsize>::max(),':');
    I>>b;
    if(b==0)
    {
        return false;
    }
    setId_in(0,b);
    return true;
}

bool3S Port_NOT::simular(const bool3S in[])
{
    int a = getNumInputs();
    for(int i=0;i<a;i++)
    {
        if(in[i]==bool3S::UNDEF){
            return bool3S::UNDEF;
        }else if(in[i]==bool3S::TRUE){
            return bool3S::FALSE;
        }else{
            return bool3S::TRUE;
        }
    }
}

bool3S Port_AND::simular(const bool3S in[])
{
    int a = getNumInputs();
    for(int i=0;i<a;i++)
    {
        if(in[i]==bool3S::FALSE)
        {
            return bool3S::FALSE;
        }
    }
    for(int i=0;i<a;i++)
    {
        if(in[i]==bool3S::UNDEF)
        {
            return bool3S::UNDEF;
        }
    }
    return bool3S::TRUE;
}

bool3S Port_NAND::simular(const bool3S in[])
{
    int a = getNumInputs();
    for(int i=0;i<a;i++)
    {
        if(in[i]==bool3S::FALSE)
        {
            return bool3S::TRUE;
        }
    }
    for(int i=0;i<a;i++)
    {
        if(in[i]==bool3S::UNDEF)
        {
            return bool3S::UNDEF;
        }
    }
    return bool3S::FALSE;
}

bool3S Port_OR::simular(const bool3S in[])
{
    int a = getNumInputs();
    for(int i=0;i<a;i++)
    {
        if(in[i]==bool3S::TRUE)
        {
            return bool3S::TRUE;
        }
    }
    for(int i=0;i<a;i++)
    {
        if(in[i]==bool3S::UNDEF)
        {
            return bool3S::UNDEF;
        }
    }
    return bool3S::FALSE;
}

bool3S Port_NOR::simular(const bool3S in[])
{
    int a = getNumInputs();
    for(int i=0;i<a;i++)
    {
        if(in[i]==bool3S::TRUE)
        {
            return bool3S::FALSE;
        }
    }
    for(int i=0;i<a;i++)
    {
        if(in[i]==bool3S::UNDEF)
        {
            return bool3S::UNDEF;
        }
    }
    return bool3S::TRUE;
}

bool3S Port_XOR::simular(const bool3S in[])
{
    int a = getNumInputs();
    int ct=0,cf=0;
    for(int i=0;i<a;i++)
    {
        if(in[i]==bool3S::FALSE)
        {
            cf++;
        }
        if(in[i]==bool3S::TRUE)
        {
            ct++;
        }
    }
    if((ct==a)||(cf==a)){
        return bool3S::FALSE;
    }
    for(int i=0;i<a;i++)
    {
        if(in[i]==bool3S::UNDEF)
        {
            return bool3S::UNDEF;
        }
    }
    return bool3S::TRUE;
}

bool3S Port_NXOR::simular(const bool3S in[])
{
    int a = getNumInputs();
    int ct=0,cf=0;
    for(int i=0;i<a;i++)
    {
        if(in[i]==bool3S::FALSE)
        {
            cf++;
        }
        if(in[i]==bool3S::TRUE)
        {
            ct++;
        }
    }
    if((ct==a)||(cf==a)){
        return bool3S::TRUE;
    }
    for(int i=0;i<a;i++)
    {
        if(in[i]==bool3S::UNDEF)
        {
            return bool3S::UNDEF;
        }
    }
    return bool3S::FALSE;
}

void Circuit::alloc(unsigned NI, unsigned NO, unsigned NP)
{
    inputs.resize(NI);
    id_out.resize(NO);
    ports.resize(NP);
    for(int i=0;i<(int)inputs.size();i++)
    {
        inputs[i]=bool3S::UNDEF;
    }
    for(int i=0;i<(int)id_out.size();i++)
    {
        id_out[i]=0;
    }
    for(int i=0;i<(int)ports.size();i++)
    {
        ports[i]=nullptr;
    }
}

void Circuit::copy(const Circuit &C)
{
    alloc(C.getNumInputs(),C.getNumOutputs(),C.getNumPorts());
    for(int i=0;i<(int)C.getNumPorts();i++)
    {
        ports.push_back(C.ports[i]->clone());
    }
}

void Circuit::clean()
{
    inputs.clear();
    id_out.clear();
    for (unsigned i=0; i<getNumPorts(); i++) if (ports[i]!=nullptr) delete ports[i];
    ports.clear();
}

bool Circuit::valid() const
{
    if((inputs.size()==0)||(id_out.size()==0) ||(ports.size()==0)){
        return false;
    }
    for(int i=1;i<=(int)getNumPorts();i++)
    {
        if(getNamePort(i)=="??"){
            return false;
        }
        if(getNumInputsPort(i)<2){
            if(getNamePort(i)!="NT"){
                return false;
            }else if(getNumInputsPort(i)<1){
                return false;
            }
        }
        if(getNumInputsPort(i)>NUM_MAX_INPUTS_PORT){
            cout<<endl<<"Numero max"<<endl;
            return false;
        }
        for(int j=0;j<(int)getNumInputsPort(i);j++)
        {
            if((getId_inPort(i,j)==0) && (getId_inPort(i,j)>(int)getNumPorts()) &&(getId_inPort(i,j)<-(int)getNumInputs())){
                cout<<endl<<"Id_in"<<endl;
                return false;
            }
        }
    }
    for(int i=1;i<=(int)id_out.size();i++)
    {
        if((getIdOutput(i)==0) || (getIdOutput(i)>(int)ports.size()) || (getIdOutput(i)<-(int)getNumInputs())){
            cout<<"ID_out"<<endl;
            return false;
        }
    }
    return true;
}

bool3S Circuit::getInput(int idIn) const
{
    if((-idIn>(int)getNumInputs()) || (idIn==0)){
        return bool3S::UNDEF;
    }
    return inputs[-idIn-1];
}

int Circuit::getIdOutput(unsigned idOut) const
{
    if((idOut==0) || (idOut>id_out.size())){
        return 0;
    }
    return id_out[idOut-1];
}

bool3S Circuit::getOutput(unsigned idOut) const
{
    int id= getIdOutput(idOut);
    if(id>0){
        return ports[id-1]->getOutput();
    }else if(id<0){
        return inputs[-id-1];
    }else{
        return bool3S::UNDEF;
    }
}

string Circuit::getNamePort(unsigned idPort) const
{
    if(idPort>getNumPorts() || idPort==0){
        return "??";
    }
    if(ports[idPort-1]==nullptr){
        return "??";
    }
    string a= ports[idPort-1]->getName();
    if((a!="NT") && (a!="AN") && (a!="NA") && (a!="OR") && (a!="NO") && (a!="XO") && (a!="NX")){
        return "??";
    }
    return a;
}

unsigned Circuit::getNumInputsPort(unsigned idPort) const
{
    if(idPort>getNumPorts() || idPort==0){
        return 0;
    }
    if(ports[idPort-1]==nullptr){
        return 0;
    }
    return ports[idPort-1]->getNumInputs();
}

int Circuit::getId_inPort(unsigned IdPort, unsigned i) const
{
    if(IdPort>getNumPorts() || IdPort==0){
        return 0;
    }
    return ports[IdPort-1]->getId_in(i);
}

void Circuit::setIdOutput(unsigned IdOut, int Id)
{
    if(IdOut!=0 && Id!=0 && IdOut<=id_out.size()){
        id_out[IdOut-1]=Id;
    }
}

void Circuit::setInput(const vector<bool3S> inputss)
{
    for(int i=0;i<(int)inputss.size();i++)
    {
        inputs[i]=inputss[i];
    }
}
void Circuit::setPort(unsigned IdPort, const string &T, unsigned NIn)
{
    if(IdPort!=0 && IdPort<=getNumPorts() && NIn>0 && NIn<=NUM_MAX_INPUTS_PORT){
        delete ports[IdPort-1];
        if(T=="NT"){
            ports[IdPort-1] = new Port_NOT();
            ports[IdPort-1]->setNumInputs(NIn);
        }else if(T=="AN"){
            ports[IdPort-1] = new Port_AND();
            ports[IdPort-1]->setNumInputs(NIn);
        }else if(T=="NA"){
            ports[IdPort-1] = new Port_NAND();
            ports[IdPort-1]->setNumInputs(NIn);
        }else if(T=="OR"){
            ports[IdPort-1] = new Port_OR();
            ports[IdPort-1]->setNumInputs(NIn);
        }else if(T=="NO"){
            ports[IdPort-1] = new Port_NOR();
            ports[IdPort-1]->setNumInputs(NIn);
        }else if(T=="XO"){
            ports[IdPort-1] = new Port_XOR();
            ports[IdPort-1]->setNumInputs(NIn);
        }else if(T=="NX"){
            ports[IdPort-1] = new Port_NXOR();
            ports[IdPort-1]->setNumInputs(NIn);
        }
    }
}

void Circuit::setId_inPort(unsigned IdPort, unsigned I, int Id) const
{
    if(IdPort!=0 && IdPort<=getNumPorts() && Id!=0){
        if(I<getNumInputsPort(IdPort)){
            if(Id>=-(int)getNumInputs() && Id<=(int)getNumPorts()){
                ports[IdPort-1]->setId_in(I,Id);
            }
        }
    }
}

void Circuit::digitar()
{
    int in, out, por;
    do{
        cout<<"Digite o numero de entradas"<<endl;
        cin>> in;
    }while(in<1);
    do{
        cout<<"Digite o numero de saidas"<<endl;
        cin>> out;
    }while(out<1);
    do{
        cout<<"Digite o numero de portas"<<endl;
        cin>> por;
    }while(por<1);
    clean();
    alloc(in,out,por);
    string aux;
    for(int i=0;i<por;i++)
    {
        cout<<"Digite o tipo da porta "<<i+1<<endl;
        cin>> aux;
        setPort(i+1,aux,2);
        ports[i]->digitar();
    }
    int ido;
    for(int i=0;i<out;i++)
    {
        cout<<"Digite o id da saida "<<i+1<<endl;
        cin>>ido;
        setIdOutput(i+1,ido);
    }
}

bool Circuit::ler(const string &arq)
{
    ifstream myfile(arq.c_str());
    if (!myfile.is_open()){
        cout<<"Abertura"<<endl;
        return false;
    }

    string c,teste;
    int ni,no,np;

    getline(myfile,c,':');
    transform(c.begin(),c.end(),c.begin(),::tolower);
    myfile>>ni>>no>>np;
    myfile.ignore();
    if(c!="circuito" || ni==0 || no==0 || np==0){
        cout<<"Circuito"<<endl;
        myfile.close();
        return false;
    }
    clean();
    alloc(ni,no,np);
    string porta;
    getline(myfile,porta,':');
    myfile.ignore();
    transform(porta.begin(),porta.end(),porta.begin(),::tolower);
    if(porta!="portas"){
        cout<<"Portas"<<endl;
        myfile.close();
        return false;
    }

    int id,n_in,idd,id_p=0;
    string tipo;
    for(int j=0;j<np;j++)
    {
        myfile>>id;
        if(id>np){
            cout<<"ID portas"<<endl;
            myfile.close();
            return false;
        }
        myfile.ignore(numeric_limits<streamsize>::max(),')');
        myfile>>tipo>>n_in;
        myfile.ignore(numeric_limits<streamsize>::max(),':');
        if((tipo!="NT") && (tipo!="AN") && (tipo!="NA") && (tipo!="OR") && (tipo!="NO") && (tipo!="XO") && (tipo!="NX")){
            myfile.close();
            return false;
        }
        if(tipo=="NT" && n_in!=1){
            myfile.close();
            return false;
        }
        if(id_p > id){
            myfile.close();
            return false;
        }
        setPort(id,tipo,n_in);
        id_p=id;
        for(int i=0;i<n_in;i++)
        {
            myfile>>idd;
            if(idd>(int)getNumPorts() || idd<-(int)getNumInputs() || idd==0){
                myfile.close();
                return false;
            }
            setId_inPort(id,i,idd);
            idd=0;
        }
        myfile.ignore();
    }
    string saida;
    getline(myfile,saida,':');
    myfile.ignore();;
    transform(saida.begin(),saida.end(),saida.begin(),::tolower);
    if(saida!="saidas"){
        cout<<"Saidas"<<endl;
        myfile.close();
        return false;
    }
    int num,idout,num_p=0;
    for(int i=0;i<no;i++)
    {
        myfile>>num;
        myfile.ignore(numeric_limits<streamsize>::max(),')');
        if(num>no || num<=0){
            cout<<"Numero de saidas"<<endl;
            myfile.close();
            return false;
        }
        myfile>>idout;
        if(idout==0 || idout>(int)getNumPorts() || idout<-(int)getNumInputs()){
            myfile.close();
            return false;
        }
        if(num_p>num){
            myfile.close();
            return false;
        }
        setIdOutput(num,idout);
        num_p=num;
    }
    myfile.close();
    return true;
}

ostream& Circuit::imprimir(ostream &O) const
{
    O<<"CIRCUITO: "<<getNumInputs();
    O<<" "<<getNumOutputs();
    O<<" "<<getNumPorts()<<endl;;
    O<<"PORTAS:"<<endl;
    for(int i=0;i<(int)getNumPorts();i++)
    {
        O<<i+1<<")";
        O<<" "<<getNamePort(i+1);
        O<<" "<<getNumInputsPort(i+1)<<":";
        for(int j=0;j<(int)getNumInputsPort(i+1);j++)
        {
            O<<" "<<getId_inPort(i+1,j);
        }
        O<<endl;
    }
    O<<"SAIDAS:"<<endl;
    for(int i=0;i<(int)getNumOutputs();i++)
    {
        O<<i+1<<")";
        O<<" "<<getIdOutput(i+1);
        O<<endl;
    }
    return O;
}

bool Circuit::salvar(const string &arq) const
{
    ofstream myfile(arq.c_str());
    if (!myfile.is_open()) return false;

    imprimir(myfile);
    myfile.close();
    return true;
}

bool Circuit::simular(const vector<bool3S> &Inputs_circ)
{
    bool tudo_def, algum_def;
    bool3S in[NUM_MAX_INPUTS_PORT];
    int id;
    for(int i=0;i<(int)getNumPorts();i++)
    {
        ports[i]->setOutput(bool3S::UNDEF);
    }
    do
    {
        tudo_def=true;
        algum_def=false;
        for(int i=0;i<(int)getNumPorts();i++)
        {
            if(ports[i]->getOutput()==bool3S::UNDEF)
            {
                for(int j=0;j<(int)getNumInputsPort(i+1);j++)
                {
                    id=ports[i]->getId_in(j);
                    if(id>0){
                        in[j]=ports[id-1]->getOutput();
                    }else{
                        in[j]=Inputs_circ[-id-1];
                    }
                }
                ports[i]->setOutput(ports[i]->simular(in));
                if(ports[i]->getOutput()==bool3S::UNDEF){
                    tudo_def=false;
                }else{
                    algum_def=true;
                }
            }
        }
    }while(!tudo_def && algum_def);
    return true;
}
