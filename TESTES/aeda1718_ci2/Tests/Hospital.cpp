/*
 * Hospital.cpp
 */

#include "Hospital.h"



Hospital::Hospital(unsigned trayC):trayCapacity(trayC)
{ }

void Hospital::addDoctor(const Doctor &d1) {
	doctors.push_back(d1);
}

list<Doctor> Hospital::getDoctors() const {
	return doctors;
}

void Hospital::addTrays(stack<Patient> tray1) {
	letterTray.push_back(tray1);
}

list<stack<Patient> > Hospital::getTrays() const {
	return letterTray;
}



unsigned Hospital::numPatients(string medicalSpecialty) const
{
    unsigned int num = 0;
    auto it = doctors.begin();
    for(it; it != doctors.end(); it++){
        if((*it).getMedicalSpecialty() == medicalSpecialty){
            num += (*it).getPatients().size();
        }
    }

	return num;

}

void Hospital::sortDoctors() {


    vector<Doctor> docs;

    auto it = doctors.begin();
    for(it; it != doctors.end(); it++){
        docs.push_back((*it));
    }

	sort(docs.begin(), docs.end(), [](Doctor d1, Doctor d2){
	    if(d1.getPatients().size() < d2.getPatients().size()){
            return true;
	    }
	    else if(d1.getPatients().size() == d2.getPatients().size()){
            if(d1.getMedicalSpecialty() < d2.getMedicalSpecialty()){
                return false;
            }
            else if(d1.getMedicalSpecialty() == d2.getMedicalSpecialty()){
                if(d1.getCode() <= d2.getCode())
                    return true;
                else{
                    return false;
                }
            }
            else{
                return true;
            }
	    }
	    else{
            return false;
	    }
	});

}



bool Hospital::addDoctor(unsigned codM1, string medicalSpecialty1) {
    /* que insere um novo médico de código codM1 e especialidade medicalSpecialty1 no final da lista
    doctors, se o número de médicos dessa especialidade existente no hospital for menor que 3, caso em
    que a função retorna true. Se o número de médicos da especialidade for maior ou igual a 3, o médico
    não é adicionado à lista e a função retorna false.*/

    unsigned numMedSpecialty = 0;

    list<Doctor>::iterator it = doctors.begin();
    for(it; it != doctors.end(); it++){
        if((*it).getMedicalSpecialty() == medicalSpecialty1){
            numMedSpecialty++;
        }
    }

    if(numMedSpecialty >= 3){
        return false;
    }
    else{
        Doctor d(codM1, medicalSpecialty1);
        doctors.push_back(d);
        return true;
    }
}



queue<Patient> Hospital::removeDoctor(unsigned codM1) {
	// TODO
	queue<Patient> p1;
	return p1;

}


bool Hospital::putInLessBusyDoctor(unsigned cod1, string medicalSpecialty1) {
	// TODO
	return true;

}



void Hospital::processPatient(unsigned codM1) {
	// TODO

}


unsigned Hospital::removePatients(unsigned codP1) {
	// TODO
	return 0;

}



