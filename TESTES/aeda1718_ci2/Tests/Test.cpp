#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Doctor.h"
#include "Hospital.h"
#include <vector>
#include <string>

using testing::Eq;

/*
// numPatients
TEST(test_1, a){
	Hospital hosp;
	queue<Patient> q1;
	q1.push(Patient(123,"medicalSpecialtyX"));
	q1.push(Patient(456,"medicalSpecialtyX"));
	q1.push(Patient(456,"medicalSpecialtyX"));
	Doctor d1(1,"medicalSpecialtyX",q1);
	hosp.addDoctor(d1);
	Doctor d2(2,"medicalSpecialtyZ");
	hosp.addDoctor(d2);
	queue<Patient> q3;
	q3.push(Patient(111,"medicalSpecialtyA"));
	q3.push(Patient(666,"medicalSpecialtyA"));
	q3.push(Patient(777,"medicalSpecialtyA"));
	Doctor d3(3,"medicalSpecialtyA",q3);
	hosp.addDoctor(d3);
	queue<Patient> q4;
	q4.push(Patient(456,"medicalSpecialtyX"));
	Doctor d4(4,"medicalSpecialtyX",q4);
	hosp.addDoctor(d4);
    EXPECT_EQ(0,hosp.numPatients("medicalSpecialtyZ"));
    EXPECT_EQ(4,hosp.numPatients("medicalSpecialtyX"));
    EXPECT_EQ(3,hosp.numPatients("medicalSpecialtyA"));
}
*/

/*
//sortDoctors
TEST(test_1, b){

	Hospital hosp;

	queue<Patient> q1;
	q1.push(Patient(123,"medicalSpecialtyZ"));
	q1.push(Patient(456,"medicalSpecialtyZ"));
	Doctor d1(1,"medicalSpecialtyZ",q1);
	hosp.addDoctor(d1);

	queue<Patient> q2;
	q2.push(Patient(321,"medicalSpecialtyZ"));
	Doctor d2(2,"medicalSpecialtyZ",q2);
	hosp.addDoctor(d2);

	queue<Patient> q3;
	q3.push(Patient(111,"medicalSpecialtyZ"));
	q3.push(Patient(666,"medicalSpecialtyZ"));
	Doctor d3(3,"medicalSpecialtyZ",q3);
	hosp.addDoctor(d3);

	queue<Patient> q4;
	Doctor d4(4,"medicalSpecialtyX",q4);
	hosp.addDoctor(d4);

	queue<Patient> q5;
	q5.push(Patient(341,"medicalSpecialtyB"));
	Doctor d5(5,"medicalSpecialtyB",q5);
	hosp.addDoctor(d5);

	hosp.sortDoctors();
	list<Doctor> res = hosp.getDoctors();
    EXPECT_EQ(5, res.size());

    EXPECT_EQ(4,res.front().getCode());
    EXPECT_EQ(0,res.front().getPatients().size());
	res.pop_front();
    EXPECT_EQ(5,res.front().getCode());
    EXPECT_EQ(1,res.front().getPatients().size());
	res.pop_front();
    EXPECT_EQ(2,res.front().getCode());
    EXPECT_EQ(1,res.front().getPatients().size());
	res.pop_front();
    EXPECT_EQ(1,res.front().getCode());
    EXPECT_EQ(2,res.front().getPatients().size());
	res.pop_front();
    EXPECT_EQ(3,res.front().getCode());
    EXPECT_EQ(2,res.front().getPatients().size());
	res.pop_front();
}

*/

//moveToFront
TEST(test_1, c){
	Doctor d1(1,"medicalSpecialtyX");
	d1.moveToFront(111);
	queue<Patient> res = d1.getPatients();
    EXPECT_EQ(0,res.size());

	queue<Patient> q1;
	q1.push(Patient(123,"medicalSpecialtyX"));
	q1.push(Patient(456,"medicalSpecialtyX"));
	q1.push(Patient(789,"medicalSpecialtyX"));
	Doctor d2(2,"medicalSpecialtyX",q1);

	d2.moveToFront(789);
	res = d2.getPatients();
    EXPECT_EQ(3,res.size());
    EXPECT_EQ(789,res.front().getCode());
	res.pop();
    EXPECT_EQ(123,res.front().getCode());
	res.pop();
    EXPECT_EQ(456,res.front().getCode());

	Doctor d3(3,"medicalSpecialtyX",q1);
	d3.moveToFront(111);
	res = d3.getPatients();
    EXPECT_EQ(3,res.size());
    EXPECT_EQ(123,res.front().getCode());
	res.pop();
    EXPECT_EQ(456,res.front().getCode());
	res.pop();
    EXPECT_EQ(789,res.front().getCode());

}



