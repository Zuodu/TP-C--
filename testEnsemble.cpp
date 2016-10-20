#include <iostream>
#include "Ensemble.h"
using namespace std;

static void testConstructeurDefaut() 
{
	Ensemble test;
	Ensemble test1(0);
	Ensemble test2(15);
	test.Afficher();
	test1.Afficher();
	test2.Afficher();
}
static void testConstructeur2() 
{
	int t2[] = { 1 };
	int t3[] = { 0,2,2,3 };
	int t5[] = { -3,0,1,4,5 };
	Ensemble test2(t2, 1);
	Ensemble test3(t3, 3);
	Ensemble test5(t5, 5);
	test2.Afficher();
	test3.Afficher();
	test5.Afficher();
}

static void testEstEgal() 
{
	int t3[] = {0,4,5,6};
	int t4[] = {0,4,5,6};
	int t5[] = {-12,4,5,6};
	Ensemble test1;
	Ensemble test2(3);
	Ensemble test3(t3,3);
	Ensemble test4(t4,4);
	Ensemble test5(t5,4);
	test1.Afficher();
	test2.Afficher();
	test3.Afficher();
	test4.Afficher();
	test5.Afficher();
	bool testeur;
	testeur = test1.EstEgal(test2);
	cout << testeur << "\r\n";
	testeur = test1.EstEgal(test3);
	cout << testeur << "\r\n";
	testeur = test3.EstEgal(test4);
	cout << testeur << "\r\n";
	testeur = test5.EstEgal(test4);
	cout << testeur << "\r\n";
	testeur = test5.EstEgal(test3);
	cout << testeur << "\r\n";
}

static void testEstInclus() 
{
	int t2[] = { 0,4,5,9 };
	int t3[] = { 0,4,5,6 };
	int t4[] = { 0,4,5,6 };
	int t5[] = { -12,4,5,6,0};
	int t6[] = { 0,0,0,0 };
	Ensemble test1(3);
	Ensemble test1bis;
	Ensemble test2(t2,4);
	Ensemble test3(t3, 4);
	Ensemble test4(t4, 4);
	Ensemble test5(t5, 5);
	Ensemble test6(t6, 3);
/*	test1bis.Afficher();
	test2.Afficher();
	test3.Afficher();
	test4.Afficher();
	test5.Afficher();
	test6.Afficher();*/
	crduEstInclus test = test3.EstInclus(test4);
	cout << test << "\r\n";
	test = test3.EstInclus(test5);
	cout << test << "\r\n";
	test = test5.EstInclus(test3);
	cout << test << "\r\n";
	test = test2.EstInclus(test5);
	cout << test << "\r\n";
	test = test2.EstInclus(test3);
	cout << test << "\r\n";
	test = test1.EstInclus(test2);
	cout << test << "\r\n";
	test = test1bis.EstInclus(test1);
	cout << test << "\r\n";
	test = test1bis.EstInclus(test6);
	cout << test << "\r\n";
	test = test6.EstInclus(test1bis);
	cout << test << "\r\n";
}

static void testAjouter() 
{
	int t3[] = { 0,4,5,6 };
	Ensemble test1(3);
	Ensemble test3(t3, 4);
	crduAjouter test = test1.Ajouter(0);
	test1.Afficher();
	cout << test << "\r\n";
	test = test1.Ajouter(1);
	test1.Afficher();
	cout << test << "\r\n";
	test = test1.Ajouter(0);
	test1.Afficher();
	cout << test << "\r\n";
	test = test1.Ajouter(5);
	test1.Afficher();
	cout << test << "\r\n";
	test = test1.Ajouter(6);
	test1.Afficher();
	cout << test << "\r\n";
	test = test3.Ajouter(4);
	test3.Afficher();
	cout << test << "\r\n";
}

static void testAjuster() 
{
	int t3[] = { 0,4,5,6 };
	Ensemble test;
	Ensemble test3(t3, 4);
	int cMax = test.Ajuster(1);
	cout << cMax << "\r\n";
	test.Afficher();
	cMax = test.Ajuster(-4);
	cout << cMax << "\r\n";
	test.Afficher();
	cMax = test.Ajuster(-5);
	cout << cMax << "\r\n";
	test.Afficher();
	cMax = test.Ajuster(-5);
	cout << cMax << "\r\n";
	test.Afficher();
	cMax = test3.Ajuster(-1);
	cout << cMax << "\r\n";
	test3.Afficher();
	cMax = test3.Ajuster(-6);
	cout << cMax << "\r\n";
	test3.Afficher();
	cMax = test3.Ajuster(+8);
	cout << cMax << "\r\n";
	test3.Afficher();
}

static void testRetirer() 
{
	int t3[] = { 0,4,5,6,6,4,5,6,4 };
	Ensemble test;
	Ensemble test3(t3, 7);
	bool retirer = test.Retirer(0);
	cout << retirer << "\r\n";
	test.Afficher();
	retirer = test3.Retirer(5);
	cout << retirer << "\r\n";
	test3.Afficher();
	retirer = test3.Retirer(4);
	cout << retirer << "\r\n";
	test3.Afficher();
	retirer = test3.Retirer(0);
	cout << retirer << "\r\n";
	test3.Afficher();
	retirer = test3.Retirer(6);
	cout << retirer << "\r\n";
	test3.Afficher();
}
int main() {
	//testConstructeurDefaut();
	//testConstructeur2();
	//testEstEgal();
	testEstInclus();
	//testAjouter();
	//testAjuster();
	//testRetirer();
	return 0;
}
