/**
 * \file Util.h
 * \brief Fonctions du namespace util
 * \author Vincent Breault
 * \date
 */
#ifndef UTIL_H_
#define UTIL_H_
#include <string>
namespace util{

bool validerFormatNom(const std::string& p_nom);
bool validerCodeIssn (const std::string& p_issn);
bool validerCodeIsbn (const std::string& p_isbn);

}

#endif /* UTIL_H_ */
