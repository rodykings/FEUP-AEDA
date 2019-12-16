#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "Property.h"
#include "Client.h"
#include "REAgency.h"

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <direct.h>
#include <time.h>
int notas[7]={0,0,0,0,0,0,0};
string name, number;
using namespace std;

string getfilepath()
{
  char result[MAX_PATH];
  string epath = string( result, GetModuleFileName( NULL, result, MAX_PATH ) );
  epath = epath.substr(0, epath.rfind("\\"));
  string fpath = __FILE__;
  //cout << fpath;
  fpath = fpath.substr(0, fpath.rfind("\\"));
  char cCurrentPath[FILENAME_MAX];
  _getcwd(cCurrentPath, sizeof(cCurrentPath));
  //cout << epath;
  //cout << cCurrentPath;
  //return string(cCurrentPath)+"\\"+fpath;
  //return epath+"\\"+fpath;
  return cCurrentPath;
}

void identification()
{
    cout << "File: " << getfilepath()+"\\results.txt" << endl;
    ifstream fin;
    fin.open(getfilepath()+"\\results.txt", ios::in);
    if (fin) {
        fin >> number; getline(fin,name);
        cout << "Exame de Estudante: " << number << "  Nome:" << name << endl;
        return;
    }
    cout << "Entre o seu Nome Completo: ";    getline(cin,name);
    cout << "Entre o seu Numero de Aluno: "; cin >> number;
    ofstream fout;
    fout.open(getfilepath()+"\\results.txt");
    if (!fout) { cout << "Erro ao Criar Ficheiro!" << endl; return; }
    fout << number << " " << name << endl;
}

void evaluate()
{
    ofstream fout;
//    cout << getfilepath()+"\\results.txt" << endl;
    fout.open(getfilepath()+"\\results.txt", ios::out|ios::app);
    if (!fout) { cout << "Erro ao Abrir Ficheiro!" << endl; return; }
//    cout << number;
//    for(int i=0; i<=7; i++) cout << " ; " << notas[i];
//    cout << endl;
    fout << number;
    for(int i=0; i<=6; i++) fout << " ; " << notas[i];
    time_t ti = time(NULL);
    fout << " ; " << ctime(&ti);
}

/*void thisIsATest() {
    ASSERTM("start writing tests", false);
    notas[0]=25;
}*/

void test_A_() {
	vector<Property*> properties;
	properties.push_back(new Property("Rua Dr Roberto Frias", "Joao", "100","t2",200000));
	properties.push_back(new Property("Rua Dr Roberto Frias", "Joao", "100","t2",180000));
	properties.push_back(new Property("Rua Dr Roberto Frias", "Joao", "100","t2",150000));
	properties.push_back(new Property("Rua Dr Roberto Frias", "Joao", "100","t2",220000));
	properties.push_back(new Property("Rua do Amial", "Miguel", "200","t2",190000));
	properties.push_back(new Property("Rua do Amial", "Pedro", "220","t3",240000));
	properties.push_back(new Property("Rua do Amial", "Pedro", "220","t3",250000));
	properties.push_back(new Property("Rua do Amial", "Luis", "220","t3",130000));
	properties.push_back(new Property("Rua do Amial", "Miguel", "280","t1",120000));
	properties.push_back(new Property("Alameda das Antas", "Luis", "300","t0",100000));
	properties.push_back(new Property("Alameda das Antas", "Luis", "320","t2",200000));
	properties.push_back(new Property("Alameda das Antas", "Pedro", "340","t2",230000));
	properties.push_back(new Property("Alameda das Antas", "Miguel", "360","t4",300000));
	properties.push_back(new Property("Alameda das Antas", "Miguel", "360","t3",260000));

	REAgency agency(properties);

	agency.generateCatalog();

	PropertyTypeItem pti1 = agency.getTypeItem("Rua Dr Roberto Frias","100","t2");
	ASSERT_EQUAL(4, pti1.getItems().size());
	if(4==pti1.getItems().size()) notas[0]+=30;
	PropertyTypeItem pti2 = agency.getTypeItem("Rua do Amial","220","t3");
	ASSERT_EQUAL(3, pti2.getItems().size());
	if(3==pti2.getItems().size()) notas[0]+=30;
	PropertyTypeItem pti3 = agency.getTypeItem("Alameda das Antas", "300","t0");
	ASSERT_EQUAL(1, pti3.getItems().size());
	if(1==pti3.getItems().size()) notas[0]+=40;
}

void test_B_() {
	Property* pPtr1 = new Property("Rua Dr Roberto Frias", "Joao", "100","t2", 200000);
	Property* pPtr2 = new Property("Rua Dr Roberto Frias", "Joao", "100","t2",220000);
	Property* pPtr3 = new Property("Alameda das Antas", "Luis", "300","t0",100000);

	Client* c1 = new Client("Joao", "joao@gmail.com");
	pPtr2->setReservation(make_tuple(c1,100000));
	c1->addVisiting(pPtr2->getAddress(), pPtr2->getPostalCode(),pPtr2->getTypology(), to_string(pPtr2->getPrice()));

	Client* c2 = new Client("Maria", "maria@gmail.com");
	pPtr3->setReservation(make_tuple(c2,90000));
	c2->addVisiting(pPtr3->getAddress(), pPtr3->getPostalCode(),pPtr3->getTypology(), to_string(pPtr3->getPrice()));

	REAgency agency;

	agency.addTypeItem(pPtr1);
	agency.addTypeItem(pPtr2);
	agency.addTypeItem(pPtr3);

	vector<Property*> av1 = agency.getAvailableProperties(pPtr1);
	ASSERT_EQUAL(1, av1.size());
	if(1==av1.size()) notas[1]+=30;
	vector<Property*> av2 = agency.getAvailableProperties(pPtr2);
	ASSERT_EQUAL(1, av2.size());
	if(1==av2.size()) notas[1]+=30;
	vector<Property*> av3 = agency.getAvailableProperties(pPtr3);
	ASSERT_EQUAL(0, av3.size());
	if(0==av3.size()) notas[1]+=40;
}

void test_C_() {
	vector<Property*> properties;
	Property* pPtr1 = new Property("Rua Dr Roberto Frias", "Joao", "100","t2", 200000);
	Property* pPtr2 = new Property("Rua Dr Roberto Frias", "Joao", "100","t2",220000);
	Property* pPtr3 = new Property("Alameda das Antas", "Luis", "300","t0",100000);
	Property* pPtr4 = new Property("Rua do Amial","Joao","220","t3",260000);

	Client* c1 = new Client("Joao", "joao@gmail.com");
	Client* c2 = new Client("Maria", "maria@gmail.com");

	REAgency agency;

	agency.addTypeItem(pPtr1);
	agency.addTypeItem(pPtr2);
	agency.addTypeItem(pPtr3);

	bool loan1 = agency.reservePropertyFromCatalog(pPtr4, c1,10);
	ASSERT_EQUAL(false, loan1);
	if(!loan1) notas[2]+=10;

	bool loan2 = agency.reservePropertyFromCatalog(pPtr3, c1,20);
	ASSERT_EQUAL(true, loan2);
	if(loan2) notas[2]+=10;

	ASSERT_EQUAL("Joao", get<0>(pPtr3->getReservation())->getName());
	if("Joao"==get<0>(pPtr3->getReservation())->getName()) notas[2]+=10;

	ASSERT_EQUAL(80000, get<1>(pPtr3->getReservation()));
	if(80000==get<1>(pPtr3->getReservation())) notas[2]+=10;

	bool loan3 = agency.reservePropertyFromCatalog(pPtr3, c2,10);
	ASSERT_EQUAL(false, loan3);
	if(!loan3) notas[2]+=10;

	ASSERT_EQUAL("Joao", get<0>(pPtr3->getReservation())->getName());
	if("Joao"==get<0>(pPtr3->getReservation())->getName()) notas[2]+=10;

	bool loan4 = agency.reservePropertyFromCatalog(pPtr1, c2,20);
	ASSERT_EQUAL(true, loan4);
	if(loan4) notas[2]+=10;

	ASSERT_EQUAL("Maria", get<0>(pPtr1->getReservation())->getName());
	if("Maria"==get<0>(pPtr1->getReservation())->getName()) notas[2]+=10;

	ASSERT_EQUAL(160000, get<1>(pPtr1->getReservation()));
	if(160000==get<1>(pPtr1->getReservation())) notas[2]+=20;
}

void test_D_() {
	Client c1("Tiago", "t.silva@gmail.com");
	Client c2("Tiago", "t.silva@gmail.com");
	Client c3("Pedro", "pedro@gmail.com");
	Client c4("ana", "ana@gmail.com");
	Client c5("Maria", "maria.castro@gmail.com");
	Client c6("Tiago", "tiago@gmail.com");

	REAgency r1;
	r1.addClientRecord(&c1);
	vector<ClientRecord> cr1 = r1.getClientRecords();
	ASSERT_EQUAL(1, cr1.size());
	if(cr1.size()==1) notas[3]+=20;

	ASSERT_EQUAL("t.silva@gmail.com", cr1[0].getEMail());
	if("t.silva@gmail.com"==cr1[0].getEMail()) notas[3]+=20;

	r1.addClientRecord(&c2);
	cr1 = r1.getClientRecords();
	ASSERT_EQUAL(1, cr1.size());
	if(cr1.size()==1) notas[3]+=20;


	r1.addClientRecord(&c3);
	r1.addClientRecord(&c4);
	r1.addClientRecord(&c5);
	cr1 = r1.getClientRecords();
	ASSERT_EQUAL(4, cr1.size());
	if(cr1.size()==4) notas[3]+=20;

	r1.addClientRecord(&c6);
	cr1 = r1.getClientRecords();
	ASSERT_EQUAL(5, cr1.size());
	if(cr1.size()==5) notas[3]+=20;
}

void test_E_() {
	Client* c1 = new Client("Joao", "joao@gmail.com");
	Client* c2 = new Client("Tiago", "t.silva@gmail.com");

	c1->addVisiting("Rua Dr Roberto Frias", "100","t2", "200000");

	vector<ClientRecord> crs1;
	crs1.push_back(ClientRecord(c1));
	crs1.push_back(ClientRecord(c2));

	REAgency r1;
	r1.setClientRecords(crs1);

	r1.deleteClients();
	crs1 = r1.getClientRecords();
	ASSERT_EQUAL(1, crs1.size());
	if(crs1.size()==1) notas[4]+=40;

	ASSERT_EQUAL("Joao", crs1[0].getName());
	if("Joao"==crs1[0].getName()) notas[4]+=60;
}

void test_F_() {
	Client* c1 = new Client("Joao", "joao@gmail.com");
	Client* c2 = new Client("Maria", "maria@gmail.com");
	Client* c3 = new Client("Pedro", "pedro@gmail.com");

	vector<Property*> properties;
	Property* pPtr1 = new Property("Rua Dr Roberto Frias", "Joao", "100","t2", 200000);
	Property* pPtr2 = new Property("Rua Dr Roberto Frias", "Joao", "100","t2",220000);
	Property* pPtr3 = new Property("Alameda das Antas", "Luis", "300","t0",100000);
	Property* pPtr4 = new Property("Rua Dr Roberto Frias", "Joao", "100","t2",150000);
	Property* pPtr5 = new Property("Rua Dr Roberto Frias", "Joao", "100","t2",220000);
	Property* pPtr6 = new Property("Rua do Amial", "Miguel", "200","t2",190000);
	Property* pPtr7 = new Property("Rua do Amial", "Pedro", "220","t3",240000);

	properties.push_back(pPtr1);
	properties.push_back(pPtr2);
	properties.push_back(pPtr3);
	properties.push_back(pPtr4);
	properties.push_back(pPtr5);
	properties.push_back(pPtr6);
	properties.push_back(pPtr7);

	c1->addVisiting("Rua Dr Roberto Frias", "100","t2", "200000");
	c1->addVisiting("Alameda das Antas", "300","t0","100000");
	c1->addVisiting("Alameda das Antas", "300","t0","100000");

	pPtr1->setReservation(make_tuple(c1,100000));
	pPtr2->setReservation(make_tuple(c1,150000));
	pPtr3->setReservation(make_tuple(c1,80000));

	c2->addVisiting("Rua Dr Roberto Frias", "100","t2", "200000");
	c2->addVisiting("Rua do Amial", "220","t3","250000");
	pPtr4->setReservation(make_tuple(c2,100000));

	c3->addVisiting("Alameda das Antas", "300","t0","100000");
	c3->addVisiting("Alameda das Antas", "300","t2","180000");
	pPtr5->setReservation(make_tuple(c3,100000));
	pPtr6->setReservation(make_tuple(c3,150000));
	pPtr7->setReservation(make_tuple(c3,80000));

	vector<Client> candidates_0;
	candidates_0.push_back(*c1);

	vector<Client> candidates_1;
	candidates_1.push_back(*c2);

	vector<Client> candidates_2;
	candidates_2.push_back(*c1);
	candidates_2.push_back(*c2);
	candidates_2.push_back(*c3);

	REAgency r1(properties);
	r1.addBestClientProfiles(candidates_0, 1);
	ASSERT_EQUAL(1, r1.getClientProfiles().size());
	if(r1.getClientProfiles().size()==1) notas[5]+=20;

	ASSERT_EQUAL("Joao",r1.getClientProfiles().top().getName());
	if("Joao"==r1.getClientProfiles().top().getName()) notas[5]+=20;

	REAgency r2(properties);
	r2.addBestClientProfiles(candidates_1, 1);
	ASSERT_EQUAL(0, r2.getClientProfiles().size());
	if(r2.getClientProfiles().size()==0) notas[5]+=20;

	REAgency r3(properties);
	r3.addBestClientProfiles(candidates_2, 1);
	ASSERT_EQUAL(2, r3.getClientProfiles().size());
	if(r3.getClientProfiles().size()==2) notas[5]+=20;

	ASSERT_EQUAL("Pedro",r3.getClientProfiles().top().getName());
	if("Pedro"==r3.getClientProfiles().top().getName()) notas[5]+=20;
}

void test_G_() {
	Client c1("Joao", "joao@gmail.com");
	Client c2("Maria", "maria@gmail.com");
	Client* c1Ptr = new Client("Joao", "joao@gmail.com");

	vector<Property*> properties;
	Property* pPtr1 = new Property("Rua Dr Roberto Frias", "Joao", "100","t2", 200000);
	Property* pPtr2 = new Property("Rua Dr Roberto Frias", "Joao", "100","t2",220000);
	Property* pPtr3 = new Property("Alameda das Antas", "Miguel", "120","t2",220000);

	properties.push_back(pPtr1);
	properties.push_back(pPtr2);
	properties.push_back(pPtr3);

	c1.addVisiting("Rua Dr Roberto Frias", "100","t2", "200000");

	pPtr2->setReservation(make_tuple(c1Ptr,150000));

	priority_queue<Client> candidates;
	candidates.push(c1);

	REAgency r1(properties);
	r1.setClientProfiles(candidates);

	vector<Property*> assertProp1;
	assertProp1.push_back(pPtr3);
	vector<Property*> assertProp2 = r1.suggestProperties();
	ASSERT_EQUAL(1,assertProp2.size());
	if(assertProp2.size()==1) notas[6]+=40;

	ASSERT_EQUAL(assertProp1[0]->getAddress(), assertProp2[0]->getAddress());
	if(assertProp1[0]->getAddress()==assertProp2[0]->getAddress()) notas[6]+=60;
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	//TODO add your test here
	//s.push_back(CUTE(thisIsATest));
	s.push_back(CUTE(test_A_));
	s.push_back(CUTE(test_B_));
	s.push_back(CUTE(test_C_));
	s.push_back(CUTE(test_D_));
	s.push_back(CUTE(test_E_));
	s.push_back(CUTE(test_F_));
	s.push_back(CUTE(test_G_));
	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    identification();
    runAllTests(argc,argv);
    evaluate();
    return 0;
}
