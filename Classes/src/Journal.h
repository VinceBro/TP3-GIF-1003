/*
 * Journal.h
 *
 *  Created on: Apr. 7, 2019
 *      Author: root
 */
#include "Reference.h"
#ifndef JOURNAL_H_
#define JOURNAL_H_


class Journal: public biblio::Reference{

public:
	Journal();
private:
	std::string m_nom;
	int m_volume, m_numero, m_page;
};




#endif /* JOURNAL_H_ */
