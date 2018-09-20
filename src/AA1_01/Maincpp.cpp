#include "../../dep/inc/xml/rapidxml.hpp"
#include "../../dep/inc/xml/rapidxml_utils.hpp"
#include "../../dep/inc/xml/rapidxml_iterators.hpp"
#include "../../dep/inc/xml/rapidxml_print.hpp"
#include <iostream>
#include <sstream>
#include <map>



class arma {
public:
	std::string tipo;
	int alcance;
};


class enemigo {
public:
	//constructor
	enemigo(std::string a, std::string b, std::string c, std::string d, std::string e);
	std::string vitalidad;
	std::string daño;
	std::string defensa;
	std::string frecuencia;
	std::string experiencia;
	std::map<std::string, arma > conjunto;
};



int main()
{

	std::map<std::string, enemigo> enemigos;
	enemigo Enemigos();
	std::string nombre;

	rapidxml::xml_document<> doc;
	std::ifstream file("../../res/config.xml");
	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	std::string content(buffer.str());
	doc.parse<0>(&content[0]);

	//std::cout << "Nombre de la raíz: " << doc.first_node()->name() << "\n";
	//std::cout << "Value: " << doc.first_node()->value() << "\n";

	rapidxml::xml_node<> *pRoot = doc.first_node();
	for (rapidxml::xml_node<> *pNode = pRoot->first_node("enemigo"); pNode; pNode = pNode->next_sibling()) //iterar a través dels chils
	{
		std::cout << pNode->name() << ':' << '\n';

		for (rapidxml::xml_node<> *pNodeI = pNode->first_node(); pNodeI; pNodeI = pNodeI->next_sibling()) //iterar a través dels subchilds
		{
			std::cout << pNodeI->name() << ':' << pNodeI->value() << '\n';
			nombre = pNodeI->value();

			enemigo Enemigos(nombre, nombre, nombre, nombre, nombre);
		}



		std::cout << Enemigos << '\n';
	}
	system("pause");

}