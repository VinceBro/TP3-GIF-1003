/*
 * Bibliographie.cpp
 *
 *  Created on: Apr. 7, 2019
 *      Author: root
 */
#include "Bibliographie.h"
using namespace std;
using namespace biblio;

Bibliographie::Bibliographie(const Reference& p_nouvelleReference){
	m_vReferences.push_back(p_nouvelleReference.clone());
}
string Bibliographie::reqBibliographieFormate() const{
	ostringstream os;
	os << "Bibliographie\n" << "===============================\n" << endl;
	for (unsigned int i = 0; i < m_vReferences.size(); i++){
		os << "[" << i << "]" <<  m_vReferences[i]->reqReferenceFormate()<< "\n";
	}
	return os.str();
}
